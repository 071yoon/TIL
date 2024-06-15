## Go 데이터 구조 분석

### 선언

> 만능 var

유형 알아보기

```go
// O
var var1 int = 10

var var2 = "string"

var (
    var3 = 40
    var4 string = "string"
)

// string 으로 추론
fmt.Println(reflect.TypeOf(var2))


// X
var4 string := "string_variable"
var(
    var5 := "test"
)
```

똑같이 const 로 불변 단어를 지정할 수 도 있음.

> 만약 타입을 강제로 바꿔보려하면 컴파일에서 오류를 받는다

```go
var var6 = 10
var6 = "20"
// ./variable.go:25:9: cannot use "20" (untyped string constant) as int value in assignment
```

### 데이터 유형

- int, int8, int32, int64
- uint, uint8, uint32, uint64
- float32, float64
- complex64, complex128
- string
- bool
- byte
- rune
