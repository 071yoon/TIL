import { addEntryToDb, clearAllEntries } from "../../database.js";

const addProfileEventListener = () => {
  //1. document.querySelector()를 사용해서 "addPhotoInput"을 할당하세요.
  const photoInput = document.querySelector("#test");
  const profileSection = document.querySelector(".profile");

  //2. document.querySelector()`를 사용해서 "gallerySection"의 렌더링될 갤러리를 gallerySection에 할당합니다.

  photoInput.addEventListener("change", () => {
    // 이미지 파일 내용을 읽어들이는 FileReader 객체를 reader 에 할당
    const reader = new FileReader();

    //바이너리 파일을 Base64 Encode 문자열로 반환
    reader.readAsDataURL(photoInput.files[0]);

    //읽기 동작이 완료되었을 때
    reader.addEventListener("load", () => {
      //3. addEntryToDb 함수를 사용해서 반환된 파일 내용을 gallery 테이블에 저장하세요
      clearAllEntries("profile");
      addEntryToDb("profile", reader.result);

      const newItem = `
      <img src="${reader.result}" alt="profile-photo" style="width: 160px; height: 160px; border-radius: 70%;">
    `;
      profileSection.innerHTML = newItem;
    });
  });
};

const addBioEventListeners = () => {
  const editBioButton = document.querySelector(".edit-bio-button");
  const editBioForm = document.querySelector(".edit-bio-form");
  const cancelFormButton = document.querySelector(".cancel-edit-bio");

  editBioButton.addEventListener("click", () => {
    editBioForm.style.display = "block";
  });

  editBioForm.addEventListener("submit", () => {
    //4. document.querySelector()를 이용해서 name과 about에 해당하는 값을 변수에 할당하세요.
    const name = document.querySelector("#name").value;
    const about = document.querySelector("#about").value;
    const age = document.querySelector("#age").value;
    const tel = document.querySelector("#tel").value;
    const hide = document.querySelector("#hide").checked;

    const nameElement = document.querySelector(".name");
    const aboutElement = document.querySelector(".about");
    const ageElement = document.querySelector(".age");
    const telElement = document.querySelector(".tel");

    clearAllEntries("bio");
    //5. name과 about에 해당하는 값을 bio 테이블에 저장하세요.
    addEntryToDb("bio", { name, about, age, tel, hide });

    nameElement.innerText = name;
    aboutElement.innerText = about;
    ageElement.innerText = age;
    telElement.innerText = tel;

    if (hide) {
      ageElement.innerText = "User don't want to show this information";
      telElement.innerText = "User don't want to show this information";
    }
    editBioForm.style.display = "none";
  });

  cancelFormButton.addEventListener("click", () => {
    editBioForm.style.display = "none";
  });
};

export { addBioEventListeners, addProfileEventListener };
