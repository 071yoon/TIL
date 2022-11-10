// useState function
function useState(init) {
  var val = init;
  function state() {
    return val;
  }
  function setState(newVal) {
    val = newVal;
  }
  return [state, setState];
}
var [foo, setFoo] = useState(0);
console.log(foo()); // 0
setFoo(1);
console.log(foo()); // 1

// use useState as Counter function
function Counter() {
  const [count, setCount] = useState(0);
  return {
    click: () => setCount(count() + 1),
    render: () => console.log("render:", { count: count() }),
  };
}
const C = Counter();
C.render(); // render: { count: 0 }
C.click();
C.render(); // render: { count: 1 }
