use std::io;
// Rng는 정수 생성기가 구현한 메소드들을 정의한 trait이며 해당 메소드
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("Please input your guess.");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    loop {
        // mut 로 선언 시 -> mutable 변수
        // ::new 는 연관함수라고 부름
        let mut guess = String::new();

        // &mut guess 는 guess 변수에 대한 참조를 생성
        // 여기서 guess 가 mutable 이 아닌 경우 read line을 할 수 없음
        // Result 타입은 열거형으로 Ok, Err 두 가지의 값이 있음
        // expect 를 호출하지 않으면 compile 과정에서 경고 발생
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        println!("You guessed: {}", guess);

        // parse 메소드는 문자열을 숫자로 변환
        let guess: u32 = match guess.trim().parse() {
            // expect 메소드 호출을 match 표현식으로 바꾸는 것은 에러 발생 시 종료
            Ok(num) => num,
            Err(_) => continue,
        };

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
