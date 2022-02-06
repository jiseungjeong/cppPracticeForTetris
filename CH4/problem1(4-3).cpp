#include <iostream>

class string {
  char *str;
  int len;

public:
  string(char c, int n);
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);
  void copy_string(const string &s);
  int strlen();

  void print_string();
};

string::string(char c, int n) {
  len = n;
  str = new char[len + 1];
  for (int i = 0; i < len; i++) {
    str[i] = 'c';
  }
}

string::string(const char *s) {
  int i = 0;
  while (s[i] != 0) {
    i++;
  }
  len = i;
  str = new char[len];
  for (int i = 0; i < len; i++) {
    str[i] = s[i];
  }
}

string::string(const string &s) { copy_string(s); }

string::~string() {
  if (str)
    delete[] str;
}

void string::add_string(const string &s) {
  int now_len = len + s.len;
  for (int i = len; i < now_len; i++) {
    str[i] = s.str[i - len];
  }
  len = now_len;
}

void string::copy_string(const string &s) {
  len = s.len;
  str = new char[len + 1];
  for (int i = 0; i < len; i++) {
    str[i] = s.str[i];
  }
}

int string::strlen() { return len; }

void string::print_string() { std::cout << "문자열: " << str << std::endl; }

int main() {
  string str1('a', 5);
  string str2("abcde");
  string str3(str2);
  string str4 = str1;
  str4.add_string(str3);

  str1.print_string();
  str2.print_string();
  str3.print_string();
  str4.print_string();

  std::cout << "str1 len: " << str1.strlen() << std::endl;
  std::cout << "str2 len: " << str2.strlen() << std::endl;
  std::cout << "str3 len: " << str3.strlen() << std::endl;
  std::cout << "str4 len: " << str4.strlen() << std::endl;
}
