import EditBioForm from "./EditBio.js";
import { getEntryFromDb } from "../../database.js";

//1. database.js에서 사용자가 입력한 정보를 데이터베이스에서 가져오는 getEntryFromDb 함수를 import하세요.

const Bio = async () => {
  //2. getEntryFromDb를 사용해서 bio라는 객체저장소에서 json 데이터를 가져와 userInfo라는 변수에 넣으세요.
  const userInfo = await getEntryFromDb("bio");
  function getTel() {
    try {
      if (userInfo[0].hide) {
        return "User don't want to show this information";
      }
      if (userInfo[0]) {
        return userInfo[0].tel;
      }
      return "User did not enter a value";
    } catch {
      return "User did not enter a value";
    }
  }
  function getAge() {
    try {
      if (userInfo[0].hide) {
        return "User don't want to show this information";
      }
      if (userInfo[0]) {
        return userInfo[0].age;
      }
      return "User did not enter a value";
    } catch {
      return "User did not enter a value";
    }
  }
  const profileInfo = await getEntryFromDb("profile");
  const getProfile = () => {
    if (profileInfo.length !== 0) {
      return profileInfo;
    } else
      return "https://t4.ftcdn.net/jpg/00/64/67/63/360_F_64676383_LdbmhiNM6Ypzb3FM4PPuFP9rHe7ri8Ju.jpg";
  };
  //3. p태그로 감싸진 name과 about을 렌더링하세요.
  return `
  <section class="bio">
  <div style="display:flex">
    <div class="profile-photo" style="position: relative;">
      <input type="file" name="photo" id="test" accept="image/*" style="display: none;">
	    <label for="test">
	  	  <i class="fa fa-plus" aria-hidden="true" style="position:absolute; bottom:0; right:0"></i>
	    </label>
      <div class="profile">
        <img src="${getProfile()}" style="width: 160px; height: 160px; border-radius: 70%;">
      </div>
    </div>
    <div class="profile-info">
      <p class="name">${
        userInfo[0] ? userInfo[0].name : "Please update your bio"
      }</p>
      <p class="about" style="font-size: 20px">${
        userInfo[0] ? userInfo[0].about : "About bio"
      }</p>
      
      <button class="edit-bio-button"}>Edit bio</button>
    </div>
    <div class="additional-info" style="font-size: 20px">
      <h4>Age</h4>
      <p class="age">${getAge()}</p>
      <h4>Tel</h4>
      <p class="tel">${getTel()}</p>
    </div>
    ${EditBioForm()}
    </div>
  </section>
`;
};

export default Bio;
