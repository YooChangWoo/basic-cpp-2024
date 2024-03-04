#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() // ���� �Լ��� �����
    {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First
{
public:
    void MyFunc() // ���� �Լ��� �������̵����� ����
    {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public:
    void MyFunc() // ���� �Լ��� �������̵����� ����
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    Third* tptr = new Third(); // Third Ŭ������ ��ü�� �������� �Ҵ�
    Second* sptr = tptr; // Second Ŭ������ �����ͷ� Third Ŭ������ ��ü�� ����Ŵ
    First* fptr = sptr; // First Ŭ������ �����ͷ� Third Ŭ������ ��ü�� ����Ŵ
    /*
     ��ü ������ Ÿ���� �������� ���� ������ �����ȴ�.
     �������̵� �� ���� �θ���� �ڽİ����� ��������.
    */
    fptr->MyFunc(); // First Ŭ������ MyFunc()�� ȣ��
    sptr->MyFunc(); // Second Ŭ������ MyFunc()�� ȣ��
    tptr->MyFunc(); // Third Ŭ������ MyFunc()�� ȣ��

    tptr->Second::MyFunc(); // Second Ŭ������ MyFunc()�� ȣ���Ϸ� ������ �������̵����� �ʾ����Ƿ� Third Ŭ������ MyFunc()�� ȣ���

    delete tptr; // �������� �Ҵ�� �޸� ����

    return 0;
}
/*
���� �Լ��� ������ :

MyFunc() �Լ��� First, Second, Third Ŭ�������� ��� ���ǵǾ� �ֽ��ϴ�.
MyFunc() �Լ��� ���� �Լ��� ����Ǿ��� ������ ���� �ð��� ��ü�� ���� ���¿� ���� ������ �Լ��� ȣ��˴ϴ�.

���� �Լ��� �������̵� :

Second�� Third Ŭ���������� MyFunc()�� �������̵����� �ʾҽ��ϴ�.
�̴� Second�� Third�� MyFunc()�� First�� MyFunc()�� ���������� ������ ����ŵ�ϴ�.

�Լ� ȣ�� �� ���� ���ε� :

�����Ͱ� ����Ű�� ��ü�� ���� ���¿� ���� �Լ��� ȣ��˴ϴ�.
tptr->Second::MyFunc()���� MyFunc()�� Second Ŭ������ ������ ���������,
�����δ� Third Ŭ�������� �������̵��� �Լ��� ȣ��˴ϴ�.
*/