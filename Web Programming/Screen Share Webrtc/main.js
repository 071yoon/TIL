let socket = io.connect("http://localhost:4000");
let UserVideo = document.querySelector("#localVideo");
let partnerVideo = document.querySelector("#remoteVideo");
let call_container = document.querySelector("#call_container");
let incoming_call = document.querySelector("#incoming_call");
let yourID;
let candidate_to_add;
let otherPerson;
let pc = new RTCPeerConnection({
  configuration: {
    offerToReceiveAudio: false,
    offerToReceiveVideo: true,
  },
});

// setup pc for webRTC
pc.onicecandidate = (e) => {
  if (e.candidate) {
    if (otherPerson == yourID) {
      console.log("shouldn't send any here");
    } else {
      socket.emit("candidate", { candidate: JSON.stringify(e.candidate) });
    }
  }
};

pc.oniceconnectionstatechange = (e) => {};

pc.ontrack = (e) => {
  partnerVideo.srcObject = e.streams[0];
};

const success = (stream) => {
  UserVideo.srcObject = stream;
  pc.addStream(stream);
};

let displayMediaOptions = {
  video: {
    cursor: "always",
  },
  audio: false,
};

navigator.mediaDevices
  .getDisplayMedia(displayMediaOptions)
  .then(success)
  .catch(() => {
    console.log("errors with the media device");
  });

// call a user
function createOffer(person_to_call) {
  pc.createOffer({
    mandatory: {
      offerToReceiveAudio: false,
      offerToReceiveVideo: true,
    },
  }).then(
    (sdp) => {
      socket.emit("callUser", {
        sdp: JSON.stringify(sdp),
        userToCall: person_to_call,
        from: yourID,
      });

      pc.setLocalDescription(sdp);
    },
    (e) => {}
  );
}

// new RTC description
function setRemoteDescription(sdp) {
  const desc = JSON.parse(sdp);

  pc.setRemoteDescription(new RTCSessionDescription(desc));
}

//accept call
function createAnswer(guy_I_accepted_call_from) {
  pc.createAnswer({
    mandatory: {
      offerToReceiveAudio: false,
      offerToReceiveVideo: true,
    },
  }).then(
    (sdp) => {
      socket.emit("acceptedCall", {
        sdp: JSON.stringify(sdp),
        guy_I_accepted_call_from: guy_I_accepted_call_from,
      });

      pc.setLocalDescription(sdp);
    },
    (e) => {}
  );
}

function call_user(person_to_call) {
  createOffer(person_to_call);
}

socket.on("yourID", (id) => {
  yourID = id;
});

// when call -> do for everyone else
socket.on("allUsers", (users) => {
  call_container.innerHTML = "";
  let all_users = Object.keys(users);

  all_users.forEach((user_id) => {
    call_container.innerHTML += `
    <button class="call_button" data-person_to_call=${user_id}>Call</button>
    `;
  });
  let call_buttons = document.querySelectorAll(".call_button");
  call_buttons.forEach((call_button) => {
    call_button.addEventListener("click", (e) => {
      call_user(call_button.dataset.person_to_call);
    });
  });
});

// when accept call
function acceptCall(sdp, guy_I_accepted_call_from) {
  setRemoteDescription(sdp);
  createAnswer(guy_I_accepted_call_from);
  const candidate = JSON.parse(candidate_to_add);
  pc.addIceCandidate(new RTCIceCandidate(candidate));
}

//recv from other
socket.on("recv", (data) => {
  if (data.id == yourID) {
    otherPerson = data.id;
  } else {
    otherPerson = data.id;
    candidate_to_add = data.candidate;
  }
});

// call from other
socket.on("hey", (data) => {
  incoming_call.innerHTML = `
    <h1>Someone is calling you</h1>
    <div>
      <button id="answer">Answer</button>
      <button id="decline">Decline</button>
    </div>
  `;

  let answer = document.querySelector("#answer");
  let decline = document.querySelector("#decline");

  answer.addEventListener("click", (e) => {
    acceptCall(data.sdp, data.from);
  });
  decline.addEventListener("click", (e) => {
    console.log("Declined call");
  });
});

socket.on("callAccepted", (data) => {
  pc.setRemoteDescription(JSON.parse(data.sdp));
});

function addCandidate() {
  const candidate = JSON.parse(candidate_to_add);

  pc.addIceCandidate(new RTCIceCandidate(candidate));
}
