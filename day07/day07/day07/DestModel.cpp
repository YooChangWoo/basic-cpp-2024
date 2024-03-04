#include <iostream>
#include <cstring>
using namespace std;

// 사람 정보를 표현하는 Person 클래스 정의
class Person {
private:
    char* name; // 이름을 저장하는 문자열 포인터

public:
    // 생성자: 이름을 받아서 동적으로 메모리 할당하여 저장
    Person(char* myname)
    {
        name = new char[strlen(myname) + 1]; // 문자열 길이 + 널 문자('\0') 공간 할당
        strcpy(name, myname); // 받은 이름을 복사하여 저장
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Person()
    {
        delete[] name; // 동적으로 할당된 메모리 해제
    }

    // 이름을 출력하는 함수
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
};

// 대학생 정보를 표현하는 UnivStudent 클래스 정의, Person 클래스를 상속
class UnivStudent : public Person {
private:
    char* major; // 전공을 저장하는 문자열 포인터

public:
    // 생성자: 이름과 전공을 받아 초기화, Person 클래스의 생성자 호출
    UnivStudent(char* myname, char* mymajor)
        : Person(myname) // Person 클래스의 생성자 호출
    {
        major = new char[strlen(mymajor) + 1]; // 문자열 길이 + 널 문자('\0') 공간 할당
        strcpy(major, mymajor); // 받은 전공을 복사하여 저장
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~UnivStudent()
    {
        delete[] major; // 동적으로 할당된 메모리 해제
    }

    // 자신의 이름과 전공을 출력하는 함수
    void WhoAreYou() const
    {
        WhatYourName(); // 상속받은 Person 클래스의 함수 호출
        cout << "My major is " << major << endl << endl;
    }
};

// 메인 함수
int main(void)
{
    // 대학생 객체 생성 및 초기화
    UnivStudent st1("Kim", "Mathematics");
    st1.WhoAreYou(); // 객체의 이름과 전공 출력

    // 다른 대학생 객체 생성 및 초기화
    UnivStudent st2("Hong", "Physics:)");
    st2.WhoAreYou(); // 객체의 이름과 전공 출력

    return 0;
}

/*
Person 클래스:

이름을 동적으로 할당받아 저장하는 클래스입니다.
생성자에서 이름을 받아 동적으로 메모리를 할당하고 복사하여 저장하며,
소멸자에서 동적으로 할당된 메모리를 해제합니다.

UnivStudent 클래스:

대학생 정보를 표현하는 클래스로, Person 클래스를 상속합니다.
생성자에서 이름과 전공을 받아 초기화하고,
소멸자에서 동적으로 할당된 메모리를 해제합니다.

WhoAreYou() 함수를 통해 객체의 이름과 전공을 출력합니다.
이 코드는 동적으로 할당된 문자열을 다루는 예제로,
객체가 생성될 때 할당된 메모리를 적절하게 해제하는 것이 중요합니다.
클래스의 소멸자를 사용하여 메모리 누수를 방지합니다.
*/