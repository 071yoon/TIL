const $screen = document.querySelector("#screen");
const $result = document.querySelector("#result");
let startTime;
let endTime;
const records = [];
let timmeoutId;

$screen.addEventListener("click", function () {
  if ($screen.classList.contains("waiting")) {
    //waiting screen
    $screen.classList.remove("waiting");
    $screen.classList.add("ready");
    $screen.textContent = "Click when Green";
    timeoutId = setTimeout(function () {
      startTime = new Date();
      $screen.classList.remove("ready");
      $screen.classList.add("now");
      $screen.textContent = "Click!";
    }, Math.floor(Math.random() * 1000) + 2000);
  } else if ($screen.classList.contains("ready")) {
    //ready screen
    clearTimeout(timeoutId);
    $screen.classList.remove("ready");
    $screen.classList.add("waiting");
    $screen.textContent = "too quick!";
  } else if ($screen.classList.contains("now")) {
    //click screen
    endTime = new Date();
    const current = endTime - startTime;
    records.push(current);
    const average = records.reduce((a, c) => a + c) / records.length;
    $result.textContent = `Now ${current}ms, average : ${average}ms`;
    startTime = null;
    endTime = null;
    $screen.classList.remove("now");
    $screen.classList.add("waiting");
    $screen.textContent = "Click";
  }
});
