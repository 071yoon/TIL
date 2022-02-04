import { useEffect, useState } from "react";
import { useParams } from "react-router-dom";

function Detail() {
  const [loading, setLoading] = useState(true);
  const [details, setDetail] = useState([""]);
  const { id } = useParams();

  const getMovie = async () => {
    const json = await (
      await fetch(`https://yts.mx/api/v2/movie_details.json?movie_id=${id}`)
    ).json();
    setDetail(json.data.movie);
    setLoading(false);
  };

  /*
  function getMovie() {
    async () => {
      const json = await (
        await fetch(`https://yts.mx/api/v2/movie_details.json?movie_id=${id}`)
      ).json();
    };
  }
*/
  useEffect(() => {
    getMovie();
  }, []);
  return (
    <div>
      {loading ? (
        <h1>Loading...</h1>
      ) : (
        <div>
          <h1>{details.title}</h1>
          {console.log(details)}
          <div key={details.id}>
            <p>{details.description_full}</p>
            <div>Rating : {details.rating}</div>
            <div>Year : {details.year}</div>
            <div>
              Runtime : {parseInt(details.runtime / 60)} hrs{" "}
              {details.runtime % 60} mins
            </div>
            <div>Like Count : {details.like_count}</div>
            <div>
              Download Link1 :
              <a href="${details.torrents[0].url}">Torrent Link</a>
            </div>
            <div>
              Download Link2 :
              <a href="${details.torrents[1].url}">Torrent Link</a>
            </div>
          </div>
        </div>
      )}
    </div>
  );
}
export default Detail;
