import Button from "./Button";
import styles from "./App.module.css";
import { useState, useEffect } from "react";

function Hello() {
  const byFn = () => console.log("destroyed");
  function hiFn() {
    console.log("created");
    return byFn;
  }
  useEffect(hiFn, []);

  /*
  useEffect(() => {
    console.log("I am calling Hello");
    return () => console.log("destroyed");
  }, []);*/
  return <h1>Hello</h1>;
}

function App() {
  const [counter, setValue] = useState(0);
  const [keyword, setKeyword] = useState("");
  const [showing, setShowing] = useState(false);

  const onClick_show = () => setShowing((prev) => !prev);
  const onClick = () => setValue((prev) => prev + 1);
  const onChange = (event) => setKeyword(event.target.value);
  //console.log("i run all the time");
  useEffect(() => {
    console.log("call api once");
  }, []);
  useEffect(() => {
    if (keyword !== "" && keyword.length > 5)
      console.log("Searching for ", keyword);
  }, [keyword]);
  return (
    <div>
      <h1 className={styles.title}>Counter</h1>
      <input
        value={keyword}
        onChange={onChange}
        type="text"
        placeholder="Search here..."
      />
      <h2 className={styles.title}>{counter}</h2>
      <button onClick={onClick}>Click me</button>
      <Button onClick={onClick} text={"Click Me"} />
      {showing ? <Hello /> : null}
      <button onClick={onClick_show}>{showing ? "Hide" : "Show"}</button>
    </div>
  );
}

export default App;
