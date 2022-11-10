// my react app
const MyReact = (function () {
  let hooks = [],
    currentHook = 0; // hook iterator
  return {
    render(Component) {
      const Comp = Component(); // run effect
      Comp.render();
      currentHook = 0; // init for next render
      return Comp;
    },
    useEffect(callback, depArray) {
      const hasNoDeps = !depArray; // if dependency is [] run once first time
      const deps = hooks[currentHook]; // closure hook
      const hasChangedDeps = deps // check closure hook and depArray
        ? !depArray.every((el, i) => el === deps[i])
        : true;
      if (hasNoDeps || hasChangedDeps) {
        // call callback when depArray changed or dependency is []
        callback();
        hooks[currentHook] = depArray; // set hook to current dependency
      }
      currentHook++; // increase hook iterator
    },
    useState(initialValue) {
      hooks[currentHook] = hooks[currentHook] || initialValue;
      const setStateHookIndex = currentHook; // for setState closure
      const setState = (newState) => (hooks[setStateHookIndex] = newState);
      return [hooks[currentHook++], setState];
    },
  };
})();

// counter function implements useState and useEffect
function Counter() {
  const [count, setCount] = MyReact.useState(0);
  const [text, setText] = MyReact.useState("foo"); // second hook state
  MyReact.useEffect(() => {
    console.log("effect", count, text);
  }, [count, text]);
  return {
    click: () => setCount(count + 1),
    type: (txt) => setText(txt),
    noop: () => setCount(count),
    render: () => console.log("render", { count, text }),
  };
}

// usage
let App;
App = MyReact.render(Counter); // render {count: 0, text: 'foo'}
App.click();
App = MyReact.render(Counter); // render {count: 1, text: 'foo'}
App.type("bar");
App = MyReact.render(Counter); // render {count: 1, text: 'bar'}
App.noop();
App = MyReact.render(Counter); // render {count: 1, text: 'bar'}
App.click();
App = MyReact.render(Counter); // render {count: 2, text: 'bar'}
