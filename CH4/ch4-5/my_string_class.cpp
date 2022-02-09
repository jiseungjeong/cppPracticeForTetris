#include <iostream>

class string {
  int len;
  char *str;

public:
  string(char c, int length);
  string(const char *s);
  int CalStringLength() { return len; }
  void AddString(string subj);
  void StringSearch(string subj);
  void CompareStringContent(string a);
  void CompareStringDict(string a);
  void PrintStr();
};

string::string(char c, int length) {
  len = length;
  str = new char[length + 1];
  for (int i = 0; i < length; i++) {
    str[i] = c;
  }
}

string::string(const char *s) {
  int i = 0;
  while (s[i] != 0) {
    i++;
  }
  len = i;
  str = new char[len + 1];
  for (int i = 0; i < len; i++) {
    str[i] = s[i];
  }
}

void string::AddString(string subj) {
  int total_len = len + subj.len;
  for (int i = len; i < total_len; i++) {
    str[i] = subj.str[i - len];
  }
  len = total_len;
}

void string::StringSearch(string subj) {
  for (int i = 0; i < len; i++) {
    if (str[i] == subj.str[0]) {
      for (int j = 0; j < subj.len; j++) {
        static int fake_i = i;
        if (str[fake_i] == subj.str[j]) {
          fake_i++;
          if (j == subj.len - 1) {
            std::cout << "안에 있음요." << std::endl;
            return;
          }
        } else
          break;
      }
    }
  }
  std::cout << "안에 없음요." << std::endl;
  return;
}
void string::CompareStringContent(string a) {
  if (len == a.len) {
    for (int i = 0; i < len; i++) {
      if (str[i] != a.str[i]) {
        std::cout << "다른 문자열임." << std::endl;
        return;
      }
    }
    std::cout << "같은 문자열임." << std::endl;
  } else
    std::cout << "다른 문자열임." << std::endl;
}

void string::CompareStringDict(string a) {
  for (int i = 0; i < len; i++) {
    if (str[i] > a.str[i]) {
      std::cout << a.str << " " << str << std::endl;
      return;
    } else if (str[i] < a.str[i]) {
      std::cout << str << " " << a.str << std::endl;
      return;
    } else {
      continue;
    }
  }
  std::cout << str << " " << a.str << std::endl;
}

void string::PrintStr() { std::cout << "문자열 : " << str << std::endl; }

int main() {
  string a('a', 5);
  string b("bbbbb");
  string c("abcde");
  a.PrintStr();
  b.PrintStr();
  std::cout << a.CalStringLength() << std::endl;
  std::cout << b.CalStringLength() << std::endl;
  c.AddString(b);
  c.PrintStr();
  std::cout << c.CalStringLength() << std::endl;
  c.AddString(a);
  c.PrintStr();
  std::cout << c.CalStringLength() << std::endl;
  a.StringSearch(b);
  a.CompareStringContent(c);
  c.CompareStringDict(a);
}