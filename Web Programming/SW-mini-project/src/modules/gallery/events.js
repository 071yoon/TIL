import { addEntryToDb, getEntryFromDb } from "../../database.js";

var cnt = 0;

const addGalleryEventListeners = () => {
  //1. document.querySelector()를 사용해서 "addPhotoInput"을 할당하세요.
  const photoInput = document.querySelector("#addPhotoInput");

  //2. document.querySelector()`를 사용해서 "gallerySection"의 렌더링될 갤러리를 gallerySection에 할당합니다.
  const gallerySection = document.querySelector(".gallery");

  photoInput.addEventListener("change", () => {
    // 이미지 파일 내용을 읽어들이는 FileReader 객체를 reader 에 할당
    const reader = new FileReader();

    //바이너리 파일을 Base64 Encode 문자열로 반환
    reader.readAsDataURL(photoInput.files[0]);

    //읽기 동작이 완료되었을 때
    reader.addEventListener("load", () => {
      //3. addEntryToDb 함수를 사용해서 반환된 파일 내용을 gallery 테이블에 저장하세요
      addEntryToDb("gallery", reader.result);

      cnt += 1;
      const newItem = `
      <a href="#" class="item" style="color: black; text-decoration: none;">
      
        <img alt="stuff" src=${reader.result}>

        <p>게시글 번호: ${cnt}</p>
      </a>
    `;
      gallerySection.innerHTML = newItem + gallerySection.innerHTML;
    });
  });
};

const addImagesToGallery = async () => {
  const gallerySection = document.querySelector(".gallery");
  //4. getEntryFromDb()를 사용해서 gallery 테이블에 담긴 데이터를 galleryData에 할당하세요. await 뒤에 작성하세요.
  const galleryData = await getEntryFromDb("gallery");
  cnt = galleryData.length + 1;
  const galleryItems = galleryData.reverse().map((singlePhoto) => {
    cnt -= 1;
    return `
      <a href="#" class="item" style="color: black; text-decoration: none;">
        <img alt="stuff" src=${singlePhoto} style="border: 3px solid white">
        <p>게시글 번호: ${cnt}</p>
      </a>
    `;
  });
  cnt = galleryData.length;
  gallerySection.style.display = "grid";
  gallerySection.innerHTML = galleryItems.join("");
};

export { addGalleryEventListeners, addImagesToGallery };
