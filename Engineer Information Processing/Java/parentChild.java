class Parent {

  public int compute(int num) {
    if (num <= 1) return num;
    return compute(num - 1) + compute(num - 2);
  }
}

class Child extends Parent {

  public int compute(int num) {
    if (num <= 1) return num;
    return compute(num - 1) + compute(num - 3);
  }
}

class Main {

  public static void main(String[] args) {
    Parent obj = new Child();
    System.out.print(obj.compute(4));
  }
}
