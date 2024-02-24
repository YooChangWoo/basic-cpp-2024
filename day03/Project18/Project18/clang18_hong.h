#pragma once
#ifndef HONG_CLASS_H
#define HONG_CLASS_H

#include <string>

class Hong {
public:
    Hong(const std::string& name, int age); // 생성자
    void ShowInfo(); // 정보 출력 메서드

private:
    std::string name;
    int age;
};

#endif
/*
1. #pragma once: 
-> 이는 헤더 파일이 한 번만 포함되도록 하는 전처리 지시문. 
-> #ifndef, #define, #endif를 사용하는 대신에 #pragma once만으로도 중복 포함을 방지

2. #ifndef clang18_hong.h 및 #define clang18_hong.h: 헤더 가디언을 정의. 
-> 이는 중복 포함을 방지하는데 사용. 
-> 헤더 파일이 처음으로 포함될 때는 clang18_hong.h가 정의되지 않았으므로, ifndef 블록 안의 코드가 처리

3.#include <string>: 표준 라이브러리의 string 헤더 파일을 포함. 
-> 이는 std::string을 사용하기 위해 필요.

4. class Hong { ... };: Hong 클래스의 정의를 시작. 
-> 이 클래스에는 생성자와 정보 출력 메서드.

5. public: 클래스 멤버의 접근 지정자를 지정. 
-> 이 경우 생성자와 ShowInfo 메서드는 public으로 선언되어 외부에서 접근.

6. Hong(const std::string& name, int age);: 
-> 생성자는 클래스의 객체를 초기화하는 역할. 
--> 이 생성자는 문자열 name과 정수 age를 매개변수로 받아들임.

7. void ShowInfo();: 
-> 이 메서드는 Hong 클래스의 객체 정보를 출력.

8. private:: 
-> 이 접근 지정자는 이후에 나오는 멤버 변수들을 클래스 내부에서만 접근 가능하도록 지정.

9. std::string name; 및 int age;: 
-> 이들은 Hong 클래스의 멤버 변수. 
--> name은 홍길동의 이름을 저장하는 문자열이며, age는 홍길동의 나이를 저장하는 정수.

10. #endif: 
-> 헤더 가디언의 끝을 나타냄. 
--> 이로써 중복 포함 방지 지시문의 영향이 이 부분까지만 적용.

4.

*/