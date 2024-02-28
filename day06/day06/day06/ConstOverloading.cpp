#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    // 생성자: 객체를 초기화합니다.
    SoSimple(int n) : num(n) {}

    // 멤버 함수: num에 n을 더한 후 객체의 참조를 반환합니다.
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    // 일반 멤버 함수: 객체의 num을 출력합니다.
    void SimpleFunc()
    {
        cout << "SimpleFunc: " << num << endl;
    }

    // 상수 멤버 함수: 객체의 num을 출력합니다. 객체를 수정하지 않으므로 상수 함수로 선언됩니다.
    void SimpleFunc() const
    {
        cout << "const SimpleFunc: " << num << endl;
    }
};

// 전역 함수: SoSimple 객체의 상수 참조를 인자로 받아 상수 멤버 함수를 호출합니다.
void YourFunc(const SoSimple& obj)
{
    obj.SimpleFunc();
}

int main(void)
{
    // 객체 생성
    SoSimple obj1(2);
    const SoSimple obj2(7);

    // 객체의 일반 멤버 함수 호출
    obj1.SimpleFunc();
    obj2.SimpleFunc();

    // 전역 함수 호출: 상수 객체의 상수 멤버 함수가 호출됩니다.
    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}

/*
SoSimple 클래스:

SoSimple 클래스는 하나의 private 멤버 변수 num을 가지고 있습니다.
AddNum 멤버 함수는 num에 인자로 받은 값을 더한 후 객체의 참조를 반환합니다.
SimpleFunc 멤버 함수는 객체의 num을 출력합니다.
const SimpleFunc 멤버 함수는 객체의 num을 출력하며, 객체를 수정하지 않으므로 상수 멤버 함수로 선언됩니다.

YourFunc 함수:

YourFunc 함수는 SoSimple 클래스의 상수 참조를 인자로 받아 상수 멤버 함수를 호출합니다.

main 함수:

main 함수에서는 일반 객체 obj1과 상수 객체 obj2를 생성합니다.
객체의 일반 멤버 함수와 상수 멤버 함수를 호출하여 각각의 결과를 확인합니다.
전역 함수를 호출하여 상수 객체의 상수 멤버 함수가 호출되는 것을 확인합니다.
프로그램을 실행하면, 일반 멤버 함수와 상수 멤버 함수가 각각 호출되며, 상수 객체의 상수 멤버 함수를 호출할 때 객체를 수정하지 않음을 확인할 수 있습니다.
*/