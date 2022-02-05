#include <iostream>

class Date {
  int year_;
  int month_;
  int day_;

public:
  void SetDate(int year, int month, int date) {
    year_ = year;
    month_ = month;
    day_ = date;
  }

  void AddDay(int inc) {
    int total_day = day_ + inc;
    switch (month_) {
    case 12:
      if (total_day > 31) {
        total_day -= 31;
        month_ = 1;
        year_++;
      }
      break;
    case 1:
    case 3:
    case 7:
    case 8:
    case 10:
      if (total_day > 31) {
        total_day -= 31;
        month_++;
      }
      break;
    case 2:
      if (year_ % 4 == 0) {
        if (total_day > 29) {
          total_day -= 29;
          month_++;
        }
      } else if (total_day > 28) {
        total_day -= 28;
        month_++;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (total_day > 30) {
        total_day -= 30;
        month_++;
      }
      break;
    }
    day_ = total_day;
  }

  void AddMonth(int inc) {
    int total_month = inc + month_;
    if (total_month > 12) {
      total_month -= 12;
      year_++;
    }
    month_ = total_month;
  }
  void AddYear(int inc) { year_ += inc; }

  void ShowDate() {
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
  }
};

int main() {
  Date date;
  date.SetDate(2022, 02, 05);
  date.AddYear(0);
  date.AddMonth(0);
  date.AddDay(31);
  date.ShowDate();
}