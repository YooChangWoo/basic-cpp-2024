#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc()
    {
        cout << "FirstFunc()" << endl;
    }
    virtual void SimpleFunc() // ���� �Լ��� �����
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
    virtual void SimpleFunc() // ���� �Լ��� �����
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
    virtual void SimpleFunc() // ���� �Լ��� �����
    {
        cout << "Third's SimpleFunc()" << endl;
    }
};

int main(void)
{
    Third obj;

    // Third Ŭ������ ��ü�� ���� ȣ��
    obj.FirstFunc(); // First Ŭ������ ��� �Լ� ȣ��
    obj.SecondFunc(); // Second Ŭ������ ��� �Լ� ȣ��
    obj.ThirdFunc(); // Third Ŭ������ ��� �Լ� ȣ��
    obj.SimpleFunc(); // Third Ŭ�������� �������̵��� SimpleFunc() ȣ��

    // Second Ŭ������ ������ Third ��ü ����
    Second& sref = obj;
    sref.FirstFunc(); // First Ŭ������ ��� �Լ� ȣ��
    sref.SecondFunc(); // Second Ŭ������ ��� �Լ� ȣ��
    sref.SimpleFunc(); // Third Ŭ�������� �������̵��� SimpleFunc() ȣ��

    // First Ŭ������ ������ Third ��ü ����
    First& fref = obj;
    fref.FirstFunc(); // First Ŭ������ ��� �Լ� ȣ��
    fref.SimpleFunc(); // Third Ŭ�������� �������̵��� SimpleFunc() ȣ��

    return 0;
}

/*
���� �Լ��� ������:

First, Second, Third Ŭ�������� SimpleFunc()�̶�� ���� �Լ��� �ֽ��ϴ�.
SimpleFunc()�� �� Ŭ�������� �ٸ� ������ ������ �� �ֽ��ϴ�.

���� �Լ� ȣ���� ������:

obj�� Third Ŭ������ ��ü�Դϴ�. 
���� obj.SimpleFunc()�� Third Ŭ�������� �����ǵ� SimpleFunc()�� ȣ���մϴ�.
sref�� Second Ŭ������ ������ obj�� �����մϴ�. 
�׷��� sref.SimpleFunc()�� Third Ŭ�������� �������̵��� SimpleFunc()�� ȣ���մϴ�.
�̰��� ���� �Լ��� �������Դϴ�.
fref�� First Ŭ������ ������ obj�� �����մϴ�.
fref.SimpleFunc() ���� Third Ŭ�������� �������̵��� SimpleFunc()�� ȣ���մϴ�.

��� ����� ��� �Լ� ȣ��:

��ü�� ���� ���¿� ���� ��� �Լ��� ȣ��˴ϴ�. ���� ��ü�� � Ŭ������ ����ߴ����� ���� ȣ�� ����� �޶����ϴ�.
*/