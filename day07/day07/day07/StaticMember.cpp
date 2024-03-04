#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt; // ���� ��� ������ ����� SoSimple ��ü�� ���� �����ϴ� ����
public:
    SoSimple()
    {
        simObjCnt++; // ��ü�� ������ ������ ī��Ʈ�� ������Ŵ
        cout << simObjCnt << "��° SoSimple ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
};
int SoSimple::simObjCnt = 0; // ���� ��� ������ �ʱ�ȭ

class SoComplex
{
private:
    static int cmxObjCnt; // ���� ��� ������ ����� SoComplex ��ü�� ���� �����ϴ� ����
public:
    SoComplex()
    {
        cmxObjCnt++; // ��ü�� ������ ������ ī��Ʈ�� ������Ŵ
        cout << cmxObjCnt << "��° SoComplex ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
    SoComplex(SoComplex& copy)
    {
        cmxObjCnt++; // ���� �����ڰ� ȣ��� ������ ī��Ʈ�� ������Ŵ
        cout << cmxObjCnt << "��° SoComplex ��ü" << endl; // ��ü�� ������ ������ ��ȣ�� ���
    }
};
int SoComplex::cmxObjCnt = 0; // ���� ��� ������ �ʱ�ȭ

int main(void)
{
    SoSimple sim1; // SoSimple ��ü ����
    SoSimple sim2; // SoSimple ��ü ����

    SoComplex cmx1; // SoComplex ��ü ����
    SoComplex cmx2 = cmx1; // SoComplex ��ü�� ���� ������ ȣ���� ���� ��ü ����
    SoComplex cmx3; // SoComplex ��ü ����

    return 0;
}

/*
�ش� �ڵ�� �� ���� Ŭ������ �����ϰ�, �� Ŭ�������� ���� ��� ������ ����Ͽ� ��ü�� ���� �����մϴ�.
SoSimple Ŭ������ SoComplex Ŭ���� ��� ���ο� ���� ��� ������ ����Ǿ� �ֽ��ϴ�.
�̵� ������ ��ü�� ������ ������ �����Ǹ�, ��ü ���� �� ��ȣ�� ��µ˴ϴ�.

main() �Լ������� �� Ŭ������ ��ü�� �����ϰ�, ���� �����ڸ� ȣ���Ͽ� ��ü�� �����ϸ�,
���������� ���ο� SoComplex ��ü�� �����մϴ�.
*/