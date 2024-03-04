#include <iostream>
using namespace std;

int simObjCnt = 0; // SoSimple Ŭ������ ��ü ���� �����ϴ� ����
int cmxObjCnt = 0; // SoComplex Ŭ������ ��ü ���� �����ϴ� ����

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++; // SoSimple ��ü�� ������ ������ ��ü ���� ������Ŵ
        cout << simObjCnt << "��° SoSimple ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++; // SoComplex ��ü�� ������ ������ ��ü ���� ������Ŵ
        cout << cmxObjCnt << "��° SoComplex ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
    SoComplex(SoComplex& copy)
    {
        cmxObjCnt++; // SoComplex ��ü�� ������ ������ ��ü ���� ������Ŵ
        cout << cmxObjCnt << "��° SoComplex ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
};

int main(void)
{
    SoSimple sim1; // SoSimple Ŭ������ ��ü ����
    SoSimple sim2; // SoSimple Ŭ������ ��ü ����

    SoComplex com1; // SoComplex Ŭ������ ��ü ����
    SoComplex com2 = com1; // SoComplex Ŭ������ ���� ������ ȣ���� ���� ��ü ����
    SoComplex(); // �͸��� SoComplex ��ü�� ����������, ���� �� �ƹ� �۾��� �������� ����

    return 0;
}

/*
�� �ڵ�� �� ���� Ŭ������ �����մϴ�. 
SoSimple Ŭ������ ��ü�� ������ ������ ��ü�� ���� ������Ű�� ���� �޽����� ����մϴ�.
SoComplex Ŭ������ ����� ����� �����մϴ�.

�׸��� main() �Լ������� �� Ŭ������ ��ü�� �����ϰ�, 
���� �����ڸ� ȣ���ϸ�, ���������� �͸��� ��ü�� �����ϴ� ���� �۾��� �����մϴ�.

���� �� �ڵ�� ��ü�� ������ ���õ� ������ ������ �����ִ� �����Դϴ�.
*/