#define _CRT_SECURE_NO_
#include <iostream>
using namespace std;

// Person 클래스 정의
class Person
{
private:
    char name[50]; // 이름을 저장하는 문자열 배열
    int age;       // 나이를 저장하는 정수 변수

public:
    // 생성자: 이름과 나이를 받아 멤버 변수를 초기화
    Person(const char* myname, int myage)
    {
        age = myage;
        strcpy(name, myname);
    }

    // 이름을 출력하는 멤버 함수
    void whatYouName() const {
        cout << "My name is " << name << endl;
    }

    // 나이를 출력하는 멤버 함수
    void howOldArtYou() const {
        cout << "I'm " << age << " years old" << endl;
    }
};

// UnivStudent 클래스 정의, Person 클래스를 상속
class UnivStudent : public Person {
    string major; // 전공을 저장하는 문자열 변수

public:
    // 생성자: 이름, 나이, 전공을 받아 초기화, 부모 클래스의 생성자 호출
    UnivStudent(char* myname, int myage, string major) : Person(myname, myage) {
        cout << "자식 생성자 호출" << endl;
        this->major = major;
    }

    // 자신의 이름과 나이를 출력하는 함수를 호출하는 함수
    void WhoAreYour() const {
        whatYouName(); // 부모 클래스의 이름 출력 함수 호출
        howOldArtYou(); // 부모 클래스의 나이 출력 함수 호출
    }
};

int main()
{
    // UnivStudent 객체 생성 및 초기화
    UnivStudent s("홍길동", 50, "백수");

    // 객체의 이름과 나이를 출력하는 함수 호출
    s.WhoAreYour();

    return 0;
}

/*
Person 클래스:

이름과 나이를 저장하는 멤버 변수를 가지고 있습니다.
생성자를 통해 이름과 나이를 받아 멤버 변수를 초기화합니다.
이름과 나이를 출력하는 멤버 함수를 제공합니다.

UnivStudent 클래스:

Person 클래스를 상속받습니다.
전공을 추가적으로 저장하는 멤버 변수를 가지고 있습니다.
생성자를 통해 이름, 나이, 전공을 받아 초기화합니다.
이때, 부모 클래스의 생성자를 호출합니다.
부모 클래스에서 상속받은 멤버 함수를 호출하여 이름과 나이를 출력하는 함수를 제공합니다.

main() 함수:

UnivStudent 클래스의 객체를 생성하고 초기화합니다.
객체의 이름과 나이를 출력하는 함수를 호출합니다.
이때, 부모 클래스인 Person 클래스의 멤버 함수가 호출됩니다.
이 예제에서는 클래스와 상속을 통해 객체 지향 프로그래밍의 기본 개념을 보여줍니다.
클래스의 상속을 통해 코드의 재사용성과 유연성이 높아지며,
객체의 관계를 명확하게 표현할 수 있습니다.
*/