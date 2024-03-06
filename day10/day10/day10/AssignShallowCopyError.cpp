#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name; // 문자열을 저장할 동적 메모리를 가리키는 포인터
    int age; // 나이를 저장하는 변수
public:
    // 생성자 정의
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1; // 문자열 길이 계산
        name = new char[len]; // 동적 메모리 할당
        strcpy(name, myname); // 문자열 복사
        age = myage; // 나이 설정
    }

    Person& operator=(const Person& ref)
    {
        delete[]name;

        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }

    // 개인 정보 출력 함수 (상수 멤버 함수로 선언)
    void ShowPersonInfo() const
    {
        cout << "이름 :" << name << endl;
        cout << "나이 :" << age << endl;
    }
    // 소멸자 정의
    ~Person()
    {
        delete[] name; // 동적으로 할당된 메모리 해제
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong Woo", 29); // Person 클래스의 객체 man1 생성 및 초기화
    Person man2("Yoon ji yul", 22); // Person 클래스의 객체 man2 생성 및 초기화
    man2 = man1; // 객체 man1을 객체 man2에 대입

    man1.ShowPersonInfo(); // man1의 정보 출력
    man2.ShowPersonInfo(); // man2의 정보 출력
    return 0;
}

/*
깊은 복사(Depth Copy):

Person 클래스는 동적으로 할당된 문자열을 포인터로 가지고 있습니다.
따라서 복사 생성자와 할당 연산자가 없으면 얕은 복사가 이루어집니다.
man2 = man1;과 같은 대입 연산에서는 객체의 주소가 복사됩니다.
이것은 두 객체가 동일한 메모리 영역을 가리키게 되는 얕은 복사로 이어집니다.

소멸자(Destructor):

클래스에 동적 할당된 메모리가 있으면 소멸자를 정의하여 메모리 누수를 방지해야 합니다.
Person 클래스의 소멸자에서는 동적으로 할당된 name 배열을 삭제합니다.
이 프로그램에서는 man1과 man2가 스코프를 벗어날 때 소멸자가 호출되어 메모리 누수를 방지합니다.

문자열 처리:

strcpy 함수를 사용하여 문자열을 복사합니다. 이 함수는 널 종료 문자까지 복사합니다.
문자열을 다룰 때 메모리 할당과 해제에 주의해야 합니다.

대입 연산자의 동작:

클래스에 대입 연산자가 정의되지 않았으므로 기본 대입 연산자가 사용됩니다.
이 경우 얕은 복사가 수행되어 name 포인터만 복사되므로 두 객체가 동일한 메모리를 가리키게 됩니다.
*/