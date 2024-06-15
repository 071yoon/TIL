public class Main {

  public static void main(String[] args) {
    int a = 3, b = 4, c = 3, d = 5;
    //    true & true & true => true
    if ((a == 2 | a == c) & !(c > d) & (1 == b ^ c != d)) {
      // a = 7
      a = b + c;
      // false ^ false => false
      if (7 == b ^ c != a) {
        System.out.println(a);
      } else {
        // 4
        System.out.println(b);
      }
    } else {
      a = c + d;
      if (7 == c ^ d != a) {
        System.out.println(a);
      } else {
        System.out.println(d);
      }
    }
  }
}
