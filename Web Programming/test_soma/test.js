var button = document.querySelector("#changer");
const cadet = document.getElementById("cadet");
const byukim = document.getElementById("byukim");
button.innerHTML = button.getAttribute("val");

function stateChange(event) {
  console.log(this);
  if (this.getAttribute("val") === "first") {
    this.innerHTML = "second";
    this.setAttribute("val", "second");
    console.log(this.getAttribute("val"));
    //    this.setAttribute("val", "second");
  } else {
    this.innerHTML = "first";
    this.setAttribute("val", "first");
    console.log(this);
    //    this.setAttribute("val", "first");
  }
}
// button.addEventListener("click", stateChange);
// button.onclick = stateChange;
cadet.removeChild(byukim);
const newDiv = document.createElement("div");
newDiv.innerHTML = "good";
document.body.insertBefore(newDiv, cadet);
cadet.appendChild(byukim);
const junseo = document.createElement("li");
junseo.innerText = "junseo";
cadet.appendChild(junseo);
const tmp = document.querySelectorAll("form#frm1 .tester");
tmp[0].style.backgroundColor = "red";
tmp[0].style.width = "100px";
