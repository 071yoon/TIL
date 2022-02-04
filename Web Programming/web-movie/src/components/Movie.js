import PropTypes from "prop-types";
import { Link } from "react-router-dom";
import styles from "./Movie.module.css";

function Movie({ movies }) {
  console.log(movies);
  return (
    <div className={styles.movie}>
      <div key={movies.id}>
        <img
          src={movies.medium_cover_image}
          alt={movies.title}
          className={styles.movie__img}
        />
        <h2 className={styles.movie__title}>
          <Link to={`/movie/${movies.id}`}> {movies.title}</Link>
        </h2>
        <h3 key={movies.year} className={styles.movie__year}>
          {movies.year}
        </h3>
        <p>
          {movies.summary.length > 235
            ? `${movies.summary.slice(0, 235)}...`
            : movies.summary}
        </p>
        <ul className={styles.movie__genres}>
          {movies.genres.map((g) => (
            <li key={g}>{g}</li>
          ))}
        </ul>
      </div>
    </div>
  );
}

Movie.propTpes = {
  movies: PropTypes.arrayOf(PropTypes.string).isRequired,
};
export default Movie;
