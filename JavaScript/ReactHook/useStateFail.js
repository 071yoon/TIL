// fail version of useState

function useStateFail(initialValue) {
  var _val = initialValue;
  function setState(newVal) {
    _val = newVal;
  }
  return [_val, setState];
}
var [foo, setFoo] = useStateFail(0);
console.log(foo); // 0
setFoo(1);
console.log(foo); // 0
