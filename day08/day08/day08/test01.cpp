#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void on()
    {
        cout << "TVŰ��" << endl;
    }
};

class SamsungTv : public RemoteControl
{
public:
    void on() override
    {
        cout << "�Ｚ TV�� �մϴ�." << endl;
    }
};

class LgTv : public RemoteControl
{
public:
    void on() override
    {
        cout << "���� TV�� �մϴ�." << endl;
    }
};

int main(void)
{
    RemoteControl* remote = new SamsungTv(); // RemoteControl Ŭ������ �����͸� ����Ͽ� SamsungTv ��ü�� ����Ŵ
    remote->on(); // SamsungTv Ŭ������ on() �Լ� ȣ��

    delete remote; // �������� �Ҵ�� �޸𸮸� ����

    remote = new LgTv(); // RemoteControl Ŭ������ �����͸� ����Ͽ� LgTv ��ü�� ����Ŵ
    remote->on(); // LgTv Ŭ������ on() �Լ� ȣ��

    delete remote; // �������� �Ҵ�� �޸𸮸� ����

    return 0;
}