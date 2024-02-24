#include "clang18_hong.h"
#include <iostream>

Hong::Hong(const std::string& name, int age) : name(name), age(age) {}

void Hong::ShowInfo() {
    std::cout << "나는 " << age << " 백수 " << name << "!" << std::endl;
}


/*
1. #include "clang18_hong.h": 
-> 이는 이전에 작성한 헤더 파일인 "clang18_hong.h"를 포함. 
-> 이 헤더 파일에는 Hong 클래스의 선언.

2. #include <iostream>: 
-> 이는 표준 라이브러리의 iostream 헤더 파일을 포함. 
-> 이는 표준 입출력 스트림을 사용하기 위해 필요.

3. Hong::Hong(const std::string& name, int age) : 
-> name(name), age(age) {}: 
-> 이는 Hong 클래스의 생성자를 정의. 
-> 생성자는 클래스의 객체를 초기화하는 역할. 
-> 이 생성자는 문자열 name과 정수 age를 매개변수로 받아들이고, 
-> 초기화 리스트를 사용하여 멤버 변수 name과 age를 초기화.

4. void Hong::ShowInfo() { ... }: 
-> 이는 Hong 클래스의 ShowInfo 메서드를 정의. 
-> 이 메서드는 객체의 정보를 출력하는 역할. 
-> 이름과 나이를 출력하는 간단한 출력문이 포함.


*/