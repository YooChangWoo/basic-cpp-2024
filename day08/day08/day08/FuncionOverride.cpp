#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() // 가상 함수로 선언됨
    {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First
{
public:
    void MyFunc() // 가상 함수를 오버라이딩하지 않음
    {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public:
    void MyFunc() // 가상 함수를 오버라이딩하지 않음
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    Third* tptr = new Third(); // Third 클래스의 객체를 동적으로 할당
    Second* sptr = tptr; // Second 클래스의 포인터로 Third 클래스의 객체를 가리킴
    First* fptr = sptr; // First 클래스의 포인터로 Third 클래스의 객체를 가리킴
    /*
     객체 포인터 타입을 기준으로 접근 범위가 결정된다.
     오버라이딩 된 경우는 부모것을 자식것으로 가려진다.
    */
    fptr->MyFunc(); // First 클래스의 MyFunc()을 호출
    sptr->MyFunc(); // Second 클래스의 MyFunc()을 호출
    tptr->MyFunc(); // Third 클래스의 MyFunc()을 호출

    tptr->Second::MyFunc(); // Second 클래스의 MyFunc()을 호출하려 했지만 오버라이딩하지 않았으므로 Third 클래스의 MyFunc()이 호출됨

    delete tptr; // 동적으로 할당된 메모리 해제

    return 0;
}
/*
가상 함수와 다형성 :

MyFunc() 함수는 First, Second, Third 클래스에서 모두 정의되어 있습니다.
MyFunc() 함수가 가상 함수로 선언되었기 때문에 실행 시간에 객체의 실제 형태에 따라 적절한 함수가 호출됩니다.

가상 함수의 오버라이딩 :

Second와 Third 클래스에서는 MyFunc()을 오버라이딩하지 않았습니다.
이는 Second와 Third의 MyFunc()이 First의 MyFunc()을 가려버리는 현상을 일으킵니다.

함수 호출 시 동적 바인딩 :

포인터가 가리키는 객체의 실제 형태에 따라 함수가 호출됩니다.
tptr->Second::MyFunc()에서 MyFunc()은 Second 클래스의 것으로 예상되지만,
실제로는 Third 클래스에서 오버라이딩한 함수가 호출됩니다.
*/