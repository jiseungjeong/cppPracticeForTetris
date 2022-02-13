#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("test.txt");
    char buf[100];

    if(!in.is_open()) {
        std::cout<<"파일을 찾을 수 없습니다!"<<std::endl;
        return 0;
    }

    while(in) {
        in.getline(buf, 100); //in.getline(buf,100, '.'); 은 마침표가 나올 때 까지 입력받음.
        std::cout<<buf<<std::endl;
    }

    return 0;
}