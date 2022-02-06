#include <iostream>

class A {
  int x;

public:
  A(int c) : x(c) {}
  A(const A &a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

public:
  B(int c) : a(c) {}
  B(const B &b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main() {
  B b(10);

  std::cout << "---------" << std::endl;
  A al = b.get_A();
}
//실행하면 "복사생성" 문구는 딱 한 번 나온다.