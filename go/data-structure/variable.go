package main

import (
	"fmt"
	"reflect"
)

func main() {
    var var1 int = 10
	var var2 = "string_variable"
	var3 := "string_variable2"
	
	var(
		var4 int = 10
		var5 = "string_variable3"
	)

	fmt.Println(reflect.TypeOf(var1))
	fmt.Println(reflect.TypeOf(var2))
	fmt.Println(reflect.TypeOf(var3))
	fmt.Println(reflect.TypeOf(var4))
	fmt.Println(reflect.TypeOf(var5))

	// var var6 = 10
	// var6 = "20"
}