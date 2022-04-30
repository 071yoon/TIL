import { onRequest } from "./database.js";
import Bio from "./modules/bio/Bio.js";
import {
  addBioEventListeners,
  addProfileEventListener,
} from "./modules/bio/events.js";
import {
  addGalleryEventListeners,
  addImagesToGallery,
} from "./modules/gallery/events.js";
import Gallery from "./modules/gallery/Gallery.js";
import Nav from "./modules/nav/Nav.js";

const App = async () => {
  return `
    ${Nav()}
    <div class="container">
   ${await Bio()}
      ${Gallery()}
    </div>
  `;
};

onRequest.onsuccess = async () => {
  document.getElementById("root").innerHTML = await App();
  addBioEventListeners();
  addProfileEventListener();
  addGalleryEventListeners();
  addImagesToGallery();
};
