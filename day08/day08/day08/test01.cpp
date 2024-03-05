#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void on()
    {
        cout << "TV키자" << endl;
    }
};

class SamsungTv : public RemoteControl
{
public:
    void on() override
    {
        cout << "삼성 TV를 켭니다." << endl;
    }
};

class LgTv : public RemoteControl
{
public:
    void on() override
    {
        cout << "엘지 TV를 켭니다." << endl;
    }
};

int main(void)
{
    RemoteControl* remote = new SamsungTv(); // RemoteControl 클래스의 포인터를 사용하여 SamsungTv 객체를 가리킴
    remote->on(); // SamsungTv 클래스의 on() 함수 호출

    delete remote; // 동적으로 할당된 메모리를 해제

    remote = new LgTv(); // RemoteControl 클래스의 포인터를 사용하여 LgTv 객체를 가리킴
    remote->on(); // LgTv 클래스의 on() 함수 호출

    delete remote; // 동적으로 할당된 메모리를 해제

    return 0;
}