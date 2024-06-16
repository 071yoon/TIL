use std::any::type_name_of_val;

fn main() {
    let mut x = String::from("hello");
    x.push_str(", world!");
    //alloc::string::String
    println!("{}", type_name_of_val(&x));

    let y = "world";
    //&str
    println!("{}", type_name_of_val(&y));

    // s1 의 소유권을 pointer로 calculate_length 함수로 넘김
    let mut s1 = String::from("hello");
    // pointer로 소유권을 넘기면 수정도 가능
    let len = calculate_length(&mut s1);
    // pointer로 넘겼기에 사용 가능
    println!("1:: The length of '{}' is {}.", s1, len);
    // 소유권 받고 수정 가능
    s1.push_str(", world2!");
    println!("2:: The length of '{}' is {}.", s1, len);
    // 요건 소유권을 넘긴게 아니라, 불변 참조로 넘긴거라서 사용 가능
    let s4 = &s1;
    // println!("3:: The length of s4 '{}' is {}.", s4, len);
    // 위에 불변 참조기 때문에 새로운 참조 가능
    let s5 = &mut s1;
    println!("4:: The length of s5 '{}' is {}.", s5, len);
    // let s3 = s1;
    // 소유권을 넘겼기에 사용 불가
    // 주석해제시 에러
    // println!("The length of '{}' is {}.", s1, len);
    // let s4 = s1;

    // s2 의 소유권을 그냥 넘기는 경우
    let s2 = String::from("hi");
    let len2 = calculate_length2(s2);
    println!("The length is {}.", len2);
    // s2 는 이후 사용 불가
    // 아래 주석 해제시 에러
    // println!("The length of '{}' is {}.", s2, len2);
}

fn calculate_length(s: &mut String) -> usize {
    s.push_str(", world!");

    s.len()
}

fn calculate_length2(s: String) -> usize {
    s.len()
}
