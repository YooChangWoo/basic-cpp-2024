#include <iostream>
using namespace std;

class First
{
public:
    // 가상 함수 MyFunc()를 선언하고 FirstFunc을 출력합니다.
    virtual void MyFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First
{
public:
    // 가상 함수 MyFunc()를 오버라이딩하여 SecondFunc을 출력합니다.
    virtual void MyFunc() override
    {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public:
    // 가상 함수 MyFunc()를 오버라이딩하여 ThirdFunc을 출력합니다.
    virtual void MyFunc() override
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    // Third 클래스의 객체 포인터를 생성합니다.
    Third* tptr = new Third();
    // Second 클래스의 객체 포인터 sptr에 tptr을 대입합니다.
    Second* sptr = tptr;
    // First 클래스의 객체 포인터 fptr에 sptr을 대입합니다.
    First* fptr = sptr;

    // fptr의 MyFunc()를 호출하면 가상 함수의 동적 바인딩이 발생하여 실제 객체의 MyFunc()가 호출됩니다.
    fptr->MyFunc(); // "ThirdFunc" 출력
    // sptr의 MyFunc()를 호출하면 sptr이 가리키는 객체의 MyFunc()가 호출됩니다.
    sptr->MyFunc(); // "ThirdFunc" 출력
    // tptr의 MyFunc()를 호출하면 tptr이 가리키는 객체의 MyFunc()가 호출됩니다.
    tptr->MyFunc(); // "ThirdFunc" 출력

    // 메모리 누수를 방지하기 위해 tptr이 가리키는 객체를 삭제합니다.
    delete tptr;
    return 0;
}

/*
가상 함수와 다형성:
클래스 First, Second, Third에서 모두 MyFunc() 함수를 가상 함수로 선언하고 있습니다.
이는 파생 클래스에서 해당 함수를 재정의할 수 있게 합니다.
이러한 기능을 통해 동일한 함수 호출이 다른 동작을 수행할 수 있습니다.

객체 포인터의 다형성:
Third 클래스의 객체 포인터를 생성하고, 이를 Second 클래스의 포인터로 대입하고,
다시 이를 First 클래스의 포인터로 대입하여 다형성을 보여줍니다.
이렇게 함으로써 같은 함수 호출이 서로 다른 클래스의 함수를 실행할 수 있습니다.

동적 바인딩:
MyFunc() 함수는 가상 함수이므로, 객체 포인터가 실제로 가리키는 객체의 함수가 호출됩니다.
이것을 동적 바인딩이라고 합니다. 프로그램이 실행 중에 호출될 함수가 결정되는 것을 의미합니다.

메모리 관리:
new 연산자로 동적으로 할당된 메모리는 delete 연산자를 사용하여 명시적으로 해제되어야 합니다.
이는 메모리 누수를 방지하기 위해 필요한 중요한 절차입니다.
*/