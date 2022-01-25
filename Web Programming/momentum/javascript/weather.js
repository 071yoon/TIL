const MY_API = "5a2c96bfc5cdf3efbcbee78021d7c0c3";
function onGeoOK(position) {
  console.log(position);
  const lat = position.coords.latitude;
  const lon = position.coords.longitude;
  const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${MY_API}&units=metric`;
  fetch(url)
    .then((response) => response.json())
    .then((data) => {
      const weather = document.querySelector("#weather span:first-child");
      const city = document.querySelector("#weather span:last-child");
      city.innerText = data.name;
      weather.innerText = data.weather[0].main;
    });
}

function onGeoError() {
  alert("Can't find your location.");
}
//api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API key}
navigator.geolocation.getCurrentPosition(onGeoOK, onGeoError);
