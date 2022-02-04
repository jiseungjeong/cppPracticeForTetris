#include <iostream>

int main() {
  int *p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;//new를 통해서 할당한 공간만 해제 가능! 다른 변수의 메모리는 힙이 아닌 공간(like 스택)에 있어 조정 불가!
  return 0;
}