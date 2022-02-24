let img;
let x = 300,
  y = 400;

function setup() {
  createCanvas(600, 400);
  img = loadImage("yg.jpg", circlePixel);
}

function draw() {
  background(0);
  circlePixel();
  fill(255, 0, 0, 100);
  circle(x, y, 50);
  if (y < 0) {
    x = random(600);
    y = 400;
  }
  x = x + random(-2, 2);
  y -= 3;
}

function circlePixel() {
  img.loadPixels();
  for (let y = 0; y < img.height; y++) {
    for (let x = 0; x < img.width; x++) {
      let xyColor = img.get(x, y);
      fill(xyColor);
      noStroke();
      square(x * 10, y * 10, 8);
    }
  }
  image(img, 0, 0);
}
