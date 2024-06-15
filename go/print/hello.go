package main

import "fmt"

func main() {
    fmt.Println("Input two variables")

    var var1 string;
    var var2 string;
    // 입력받기
    fmt.Scan(&var1, &var2);
    fmt.Println(var1, var2);

    // 포맷 지정 입력
    fmt.Scanf("%s %s", &var1, &var2);
    fmt.Println(var1, var2);
}