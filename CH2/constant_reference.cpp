#include <iostream>

int main() {
  //   int &ref = 4; 리터털 참조 오류
  const int &ref = 4;
  int a = ref;
  std::cout << ref << std::endl;
}