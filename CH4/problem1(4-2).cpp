#include <iostream>

class Date {
  int year_;
  int month_;
  int day_;

public:
  void ShowDate();

  Date() {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "인자 3개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }

  Date(char ch) {
      std::cout << "문자 인자를 받는 생성자 호출!"<<std::endl<<ch<<"받음"<<std::endl;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() {
  Date day = Date();
  Date day2(2012, 10, 31);
  Date day3('B');

  day.ShowDate();
  day2.ShowDate();

  return 0;
}