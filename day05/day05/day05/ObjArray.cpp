#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Human {
    char name[30]; // 이름을 저장하는 문자열 배열
    int age; // 나이를 저장하는 정수 변수

public:
    Human(char* pname, int age) // 생성자: 이름과 나이를 받아 객체를 초기화
    {
        cout << "생성자 호출: " << endl; // 생성자 호출을 출력
        strcpy(name, pname); // 이름 복사
        this->age = age; // 나이 저장  // 전달받은 매게변수 저장
    }
    void HumanInfo() // 객체 정보 출력
    {
        cout << "이름: " << name << " "; // 이름 출력
        cout << "나이: " << age << endl; // 나이 출력
    }
    ~Human() // 소멸자: 객체가 소멸될 때 호출되며, 메모리 해제 등의 정리 작업을 수행
    {
        cout << "소멸자 호출" << endl; // 소멸자 호출을 출력
    }
};

int main()
{
    // Human 클래스의 객체 배열 생성 및 초기화
    Human h[3] = { Human("홍길동", 50), Human("김정자", 60), Human("유규복", 60) };

    // 객체 배열을 순회하면서 객체 정보 출력
    for (int i = 0; i < 3; i++) {
        h[i].HumanInfo();
    }

    Human* h1 = new Human("홍길동", 50);  // 힙 영역에 객체 생성, 포인터 변수 h1으로 주소값 전달받음
    h1->HumanInfo();               // h1은 포인터 객체 이므로 간접 참조 -> 를 통해 데이터에 접근 
    // 객체포인터가 가리키는 멤버에 접근
    Human h1("김정자", 60);
    h2.HumanInfo();                     // 일반 객체 이므로 직접 참조 . 를 통해 데이터에 접근, 포인터가 아닌 집적적인 객체를 참조
    return 0;