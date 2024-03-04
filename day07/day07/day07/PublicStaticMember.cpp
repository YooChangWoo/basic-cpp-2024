#include <iostream>
using namespace std;

class SoSimple
{
public:                   //���������� public
    static int simObjCnt; // static ������� ����(Ŭ���� ���)
public:
    SoSimple()
    {
        simObjCnt++; // ��ü�� ������ ������ ���� ��� ������ ������Ŵ
    }
};
int SoSimple::simObjCnt = 0; // static ��������� �ʱ�ȭ

int main(void)
{
    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl; // Ŭ���� �̸����� ���� ��� ������ �����Ͽ� ���
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl; // Ŭ�����̸����� static ����� ������ �����Ͽ� ���
    cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl; // ��ü�� ���� ���� ��� ������ �����Ͽ� ��� (������� �ʴ� ���)
    cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl; // ��ü�� ���� ���� ��� ������ �����Ͽ� ��� (������� �ʴ� ���)
    return 0;
}
/*
�� �ڵ忡���� SoSimple Ŭ������ ���� ��� ���� simObjCnt�� �����ϰ�,
Ŭ���� �ܺο��� �ʱ�ȭ�մϴ�.SoSimple�� �����ڿ��� ��ü�� ������ ������ simObjCnt�� ������ŵ�ϴ�.

main() �Լ������� �پ��� ������� simObjCnt�� �����մϴ�.
Ŭ���� �̸��� ���� �����ϴ� ���� ���� �ٶ����ϸ�,
��ü�� ���ؼ��� ������ ���������� ����Ǵ� ����� �ƴմϴ�.

����(static) ��� ������ Ŭ������ ��� ��ü�� �����ϴ� �����̹Ƿ�,
Ŭ���� �̸��� ���� �����ϴ� ���� ���� ��Ȯ�ϰ� �Ϲ����� ����Դϴ�.
*/