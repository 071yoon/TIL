struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

// 필드가 없는 구조체
// 유사 유닛 구조체라 부름
struct AlwaysEqual;

// debug 켜주면 println 등 가능
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// &self -> self: &Self 를 줄인 것
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn width(&self) -> bool {
        self.width > 0
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };

    // X
    // mut 이 없어서 변경 불가
    // user1.email = String::from("anotheremail@example.com");

    let mut user2 = User {
        active: true,
        username: String::from("anotherusername567"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };

    // O
    // mut 이 있어서 변경 가능
    user2.email = String::from("someoneelse@example.com");

    let user3 = build_user(
        String::from("someone@example.com"),
        String::from("anotherusername567"),
    );
    println!("user3: {}", user3.email);

    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    println!(
        "The area of the rectangle is {} square pixels.",
        area(&rect1)
    );

    println!("rect1 is {:?}", rect1);
    println!("debugging====================\n");
    dbg!(&rect1);

    println!("this is area ===> {}", rect1.area());

    if rect1.width() {
        println!("The rectangle has a nonzero width; it is {}", rect1.width);
    }

    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    let sq = Rectangle::square(3);
    println!("sq is {:?}", sq);
}

// username: username
// email: email
// 이렇게 되면 같은 이름이라서 생략 가능
fn build_user(email: String, username: String) -> User {
    User {
        active: true,
        username,
        email,
        sign_in_count: 1,
    }
}

fn area(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
