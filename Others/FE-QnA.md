# 프론트엔드 질문지

## 코드관련

- useEffect어떻게 사용해야 되는지

  - dependency [] 이면 렌더링 되고 1회이지만, 이게 맞는 선택인지
  - 무작정 dependency 들이 여러개 중 하나라도 변경되면 useEffect rendering 시키는게 맞는건지
  - dependency 별로 촘촘하게 useEffect를 구현해야되는지

- 폴더 구조 어떻게 분할해야될지

  - 지금은 컴포넌트에서, page 별로 쪼개며, 중복되는 컴포넌트만 atoms에 넣어서 관리
  - atomic design으로 구조를 짜는게 맞는지
  - 장단점이 어떻게 있을지

- Next.js어디까지 공부해야될지

  - serverside props, staticside props 지정해주면서 구조를 짜는게 좋을지, 아니면 프레임워크를 사용한다는 자체로 유용한지

- svg 같은것도 다 cdn으로 관리 해야되는지? 리소스를 그렇게 많이 먹는것 같지 않은데

- 컴포넌트를 분리하는 기준이 있다면?
  - 지금은 한 5개 넘으면 분할해서 가시적으로 만들기 위해 노력하는중
- styled vs emotion, 취향차이?
- unit test 어디까지 해야되는지?
  - 실제로 request보내고, json 어떤식으로 보내는지 확인 하는것 까지? (mocking)
  - 원하는 컴포넌트나 tag가 존재하는지 까지?
- e2e 테스트는 어디부터 어디까지 해야되는지?

## 비개발 관련

- FE 비전이 있는지?

  - 코테를 js로 공부해야될지? 지금은 C++만 하는중

- Web vs Mobile

  - 코틀린이나 Swift를 지금부터 시작할지?

- BackEnd

  - 지금은 http request나 express 쓰는정도인데, nest나 spring같은거 쓰면서 제대로 익혀야 되는지?

- 네트워크 어디까지 알아야 될지? cs 지식??
