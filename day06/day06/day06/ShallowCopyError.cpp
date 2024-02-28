#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name; // 이름을 저장하는 문자열 포인터
    int age;    // 나이를 저장하는 정수

public:
    // 생성자
    Person(const char* myname, int myage) : age(myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy_s(name, len, myname);
    }

    // 복사 생성자
    Person(const Person& other) : age(other.age) {
        int len = strlen(other.name) + 1;
        name = new char[len];
        strcpy_s(name, len, other.name);
    }

    // 소멸자
    ~Person() {
        delete[] name;
        cout << "소멸자 호출됨!!" << endl;
    }

    // 개인 정보 출력
    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << endl;
    }
};

int main() {
    Person man1("Hong", 29);
    Person man2 = man1; // 복사 생성자 호출
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}

    /* 추가 설명
    1. 생성자 (Constructor):
        - Person 클래스의 생성자는 이름과 나이를 매개변수로 받음.
        -먼저 입력된 이름의 길이에 1을 더한 만큼 동적으로 메모리를 할당함.
            --> 이는 문자열의 끝을 표시하는 널 문자('\0')를 고려한 것.
        - 그 후, strcpy_s 함수를 사용하여 입력된 이름을 동적으로 할당된 메모리에 복사.


    2. 소멸자 (Destructor):
        - Person 클래스의 소멸자는 동적으로 할당된 메모리를 해제함.
            --> delete[]를 사용하여 name이 가리키는 메모리를 해제함.

    3. 복사 생성자 (Copy Constructor):
        - 복사 생성자는 객체를 다른 객체로 초기화할 때 호출됨.
        - Person 클래스의 복사 생성자는 다른 객체의 이름과 나이를 가져와서 새로운 메모리를 할당하고, 해당 정보를 복사함.

    4. 개인 정보 출력 (ShowPersonInfo):
        - ShowPersonInfo 함수는 객체의 이름과 나이를 출력함.

    5. 주요 포인트:
        - 동적으로 할당된 메모리를 사용하는 경우, 반드시 메모리를 해제해야 함.
            --> 이를 위해 소멸자를 사용함.
        - 복사 생성자를 구현할 때는 얕은 복사(shallow copy)가 아닌 깊은 복사(deep copy)를 해야함.
            --> 이 예제에서는 동적으로 할당된 문자열을 다루고 있으므로, 깊은 복사를 수행함.

    */