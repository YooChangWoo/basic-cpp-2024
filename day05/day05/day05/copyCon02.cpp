#include <iostream>
#include <iostream>
using namespace std;

class AA {
    int a;
    int b;

public:
    // 생성자: 멤버 변수 a와 b를 인자로 받아 초기화합니다.
    AA(int a, int b) {
        this->a = a; // this 포인터를 사용하여 멤버 변수에 접근합니다.
        this->b = b;
    }

    // 객체 정보를 출력하는 메서드
    void AAInfo() {
        cout << a << " " << b << endl;
    }
};

int main() {
    AA obj1(10, 20); // AA 클래스의 객체 obj1을 생성하고 (10, 20)으로 초기화합니다.
    obj1.AAInfo(); // obj1의 정보를 출력합니다.

    // obj1을 복사하여 obj2를 생성합니다.
    // 복사 생성자를 정의하지 않았지만, 컴파일러가 자동으로 생성해줍니다.
    AA obj2(obj1);
    obj2.AAInfo(); // obj2의 정보를 출력합니다.

    return 0;
}
