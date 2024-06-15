use std::any::type_name_of_val;

fn main() {
    let x = 5;
    println!("The value of x is: {}", x);
    // 이건 안됨
    // x = 6;

    let mut y = 5;
    println!("The value of y is: {}", y);
    println!("this is address {:p}", &y);

    // 이건 됨
    y = 6;
    println!("The value of y is: {}", y);
    // get address of y and print
    println!("this is address {:p}", &y);

    // type 바꾸려면 재선언 해야됨
    // address 도 바뀌는걸 볼 수 있음
    let y: String = "test".to_string();
    println!("The value of y is: {}", y);
    println!("this is address {:p}", &y);

    // shadowing 은 변수를 재선언하는것
    let x = 5;
    let x = x + 1;
    let x = x * 2;

    println!("The value of x is: {}", x);

    // 여러 타입이 올 수 있는 경우 명시하지 않는다면 에러
    // let err_type = "test".parse().expect("Not a number!");
    let _err_type: u32 = "45".parse().expect("Not a number!");

    // 복합 타입
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);
    // 각각 i32, f64, i32 로 자동 할당
    println!(
        "all tuple types: {}, {}, {}",
        type_name_of_val(&x),
        type_name_of_val(&y),
        type_name_of_val(&z)
    );

    // 배열은 복합 타입 지원X
    // X
    // let arr = [500, 6.4, 1];
    // O
    let _arr = [500, 6, 1];

    // method 실험
    test_func(5, 6.4);

    // X
    // test_func(6.4, 5);

    // X
    // test_func(5, 5);

    // X
    // test_func(6.4 6,4);
}

fn test_func(x: i32, y: f64) {
    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
}

// 이건 안됨
// expected `i32`, found `()`
// fn plus_one(x: i32) -> i32 {
//     x + 1;
// }

fn plus_one(x: i32) -> i32 {
    return x + 1;
}
