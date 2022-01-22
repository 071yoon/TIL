const images = ["10-5.png", "10-6.png", "10-7.png", "10-8.jpg"];

const chosenImage = images[Math.floor(Math.random() * images.length)];

console.log(chosenImage);
const bgImage = document.createElement("img");

bgImage.src = `img/${chosenImage}`;
bgImage.style = "width:1000px;height:600px";
document.body.appendChild(bgImage);
