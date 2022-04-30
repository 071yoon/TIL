const EditBio = () => {
  return `
	  <form class="edit-bio-form">
		<input type="text" id="name" placeholder="Name" required />
		<input type="text" id="about" placeholder="about" / required> </br>
		<input type="number" id="age" placeholder="age" min=0 max=120 required />
		<input type="tel" id="tel" placeholder="Phone number" pattern="[0-9]{3}-[0-9]{3,4}-[0-9]{4}"/>
		<label>Do you want to hide your private info?</label>
		<input type="checkbox" id="hide" />
		<button type="button" class="cancel-edit-bio">Cancel</button>
		<button type="submit">Submit</button>
	  </form>
	`;
};

export default EditBio;
