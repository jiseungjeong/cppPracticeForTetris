#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("test.txt", std::ios::app);

    std::string s;
    if(out.is_open()) {
        out<<"덧붙이기";
    }

    return 0;
}