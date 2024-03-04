#include <iostream>
using namespace std;

class First
{
public:
    // ���� �Լ� MyFunc()�� �����ϰ� FirstFunc�� ����մϴ�.
    virtual void MyFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First
{
public:
    // ���� �Լ� MyFunc()�� �������̵��Ͽ� SecondFunc�� ����մϴ�.
    virtual void MyFunc() override
    {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public:
    // ���� �Լ� MyFunc()�� �������̵��Ͽ� ThirdFunc�� ����մϴ�.
    virtual void MyFunc() override
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    // Third Ŭ������ ��ü �����͸� �����մϴ�.
    Third* tptr = new Third();
    // Second Ŭ������ ��ü ������ sptr�� tptr�� �����մϴ�.
    Second* sptr = tptr;
    // First Ŭ������ ��ü ������ fptr�� sptr�� �����մϴ�.
    First* fptr = sptr;

    // fptr�� MyFunc()�� ȣ���ϸ� ���� �Լ��� ���� ���ε��� �߻��Ͽ� ���� ��ü�� MyFunc()�� ȣ��˴ϴ�.
    fptr->MyFunc(); // "ThirdFunc" ���
    // sptr�� MyFunc()�� ȣ���ϸ� sptr�� ����Ű�� ��ü�� MyFunc()�� ȣ��˴ϴ�.
    sptr->MyFunc(); // "ThirdFunc" ���
    // tptr�� MyFunc()�� ȣ���ϸ� tptr�� ����Ű�� ��ü�� MyFunc()�� ȣ��˴ϴ�.
    tptr->MyFunc(); // "ThirdFunc" ���

    // �޸� ������ �����ϱ� ���� tptr�� ����Ű�� ��ü�� �����մϴ�.
    delete tptr;
    return 0;
}

/*
���� �Լ��� ������:
Ŭ���� First, Second, Third���� ��� MyFunc() �Լ��� ���� �Լ��� �����ϰ� �ֽ��ϴ�.
�̴� �Ļ� Ŭ�������� �ش� �Լ��� �������� �� �ְ� �մϴ�.
�̷��� ����� ���� ������ �Լ� ȣ���� �ٸ� ������ ������ �� �ֽ��ϴ�.

��ü �������� ������:
Third Ŭ������ ��ü �����͸� �����ϰ�, �̸� Second Ŭ������ �����ͷ� �����ϰ�,
�ٽ� �̸� First Ŭ������ �����ͷ� �����Ͽ� �������� �����ݴϴ�.
�̷��� �����ν� ���� �Լ� ȣ���� ���� �ٸ� Ŭ������ �Լ��� ������ �� �ֽ��ϴ�.

���� ���ε�:
MyFunc() �Լ��� ���� �Լ��̹Ƿ�, ��ü �����Ͱ� ������ ����Ű�� ��ü�� �Լ��� ȣ��˴ϴ�.
�̰��� ���� ���ε��̶�� �մϴ�. ���α׷��� ���� �߿� ȣ��� �Լ��� �����Ǵ� ���� �ǹ��մϴ�.

�޸� ����:
new �����ڷ� �������� �Ҵ�� �޸𸮴� delete �����ڸ� ����Ͽ� ��������� �����Ǿ�� �մϴ�.
�̴� �޸� ������ �����ϱ� ���� �ʿ��� �߿��� �����Դϴ�.
*/