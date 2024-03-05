#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc()
    {
        cout << "FirstFunc()" << endl;
    }
    virtual void SimpleFunc() // 가상 함수로 선언됨
    {
        cout << "First's SimpleFunc()" << endl;
    }
};

class Second : public First
{
public:
    void SecondFunc()
    {
        cout << "SecondFunc()" << endl;
    }
    virtual void SimpleFunc() // 가상 함수로 선언됨
    {
        cout << "Second's SimpleFunc()" << endl;
    }
};

class Third : public Second
{
public:
    void ThirdFunc()
    {
        cout << "ThirdFunc()" << endl;
    }
    virtual void SimpleFunc() // 가상 함수로 선언됨
    {
        cout << "Third's SimpleFunc()" << endl;
    }
};

int main(void)
{
    Third obj;

    // Third 클래스의 객체로 직접 호출
    obj.FirstFunc(); // First 클래스의 멤버 함수 호출
    obj.SecondFunc(); // Second 클래스의 멤버 함수 호출
    obj.ThirdFunc(); // Third 클래스의 멤버 함수 호출
    obj.SimpleFunc(); // Third 클래스에서 오버라이딩된 SimpleFunc() 호출

    // Second 클래스의 참조로 Third 객체 참조
    Second& sref = obj;
    sref.FirstFunc(); // First 클래스의 멤버 함수 호출
    sref.SecondFunc(); // Second 클래스의 멤버 함수 호출
    sref.SimpleFunc(); // Third 클래스에서 오버라이딩된 SimpleFunc() 호출

    // First 클래스의 참조로 Third 객체 참조
    First& fref = obj;
    fref.FirstFunc(); // First 클래스의 멤버 함수 호출
    fref.SimpleFunc(); // Third 클래스에서 오버라이딩된 SimpleFunc() 호출

    return 0;
}

/*
가상 함수와 다형성:

First, Second, Third 클래스에는 SimpleFunc()이라는 가상 함수가 있습니다.
SimpleFunc()은 각 클래스에서 다른 동작을 제공할 수 있습니다.

가상 함수 호출의 다형성:

obj는 Third 클래스의 객체입니다. 
따라서 obj.SimpleFunc()은 Third 클래스에서 재정의된 SimpleFunc()을 호출합니다.
sref는 Second 클래스의 참조로 obj를 참조합니다. 
그러나 sref.SimpleFunc()은 Third 클래스에서 오버라이딩된 SimpleFunc()을 호출합니다.
이것이 가상 함수의 다형성입니다.
fref는 First 클래스의 참조로 obj를 참조합니다.
fref.SimpleFunc() 역시 Third 클래스에서 오버라이딩된 SimpleFunc()을 호출합니다.

상속 관계와 멤버 함수 호출:

객체의 실제 형태에 따라 멤버 함수가 호출됩니다. 따라서 객체가 어떤 클래스를 상속했는지에 따라 호출 결과가 달라집니다.
*/