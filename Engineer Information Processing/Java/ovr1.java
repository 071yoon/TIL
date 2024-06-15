public class ovr1 {

  public static void main(String[] args) {
    ovr1 a1 = new ovr1();
    ovr2 a2 = new ovr2();
    System.out.println(a1.sun(3, 2) + a2.sun(3, 2));
    // a1 -> 5
    // a2 -> 3 - 2 + (3 + 2) = 6
  }

  int sun(int x, int y) {
    return x + y;
  }

  static class ovr2 extends ovr1 {

    int sun(int x, int y) {
      return x - y + super.sun(x, y);
    }
  }
}
