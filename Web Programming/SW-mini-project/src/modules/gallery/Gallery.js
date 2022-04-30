const Gallery = () => {
  return `
  <div style="position:relative;">
	  <input type="file" name="photo" id="addPhotoInput" accept="image/*">
	  <label for="addPhotoInput">
	  	<i class="fa fa-plus" aria-hidden="true" style="position:absolute; bottom:0; right:0"></i>
	  </label>
	  <div class="gallery-nav"></div>
	  <section class="gallery">
		<div class="gallery-loader">
		  <img src="./loader.svg" alt="">
		</div>
	  </section>
	  </div>
	`;
};

export default Gallery;
