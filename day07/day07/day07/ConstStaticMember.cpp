#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA = 1707540; // ���þ��� ������ ��Ÿ���� ��� ��� ����
    const static int CANADA = 998467;  // ĳ������ ������ ��Ÿ���� ��� ��� ����
    const static int CHINA = 957290;   // �߱��� ������ ��Ÿ���� ��� ��� ����
    const static int SOUTH_KOREA = 9922; // �ѱ��� ������ ��Ÿ���� ��� ��� ����
};

int main(void)
{
    cout << "���þ� ����: " << CountryArea::RUSSIA << "��" << endl;  // Ŭ���� �̸��� ���� ��� ������ �����Ͽ� ���
    cout << "ĳ���� ����: " << CountryArea::CANADA << "��" << endl;  // Ŭ���� �̸��� ���� ��� ������ �����Ͽ� ���
    cout << "�߱� ����: " << CountryArea::CHINA << "��" << endl;   // Ŭ���� �̸��� ���� ��� ������ �����Ͽ� ���
    cout << "�ѱ� ����: " << CountryArea::SOUTH_KOREA << "��" << endl; // Ŭ���� �̸��� ���� ��� ������ �����Ͽ� ���
    return 0;
}

/*
�� �ڵ忡���� CountryArea Ŭ���� ���� �� ������ ������ ��Ÿ���� ���(static constant) ��� �������� �����մϴ�
. �̷��� ��� �������� ��ü ���� ���� Ŭ���� �̸��� ���� ���� ������ �� �ֽ��ϴ�.

main() �Լ������� Ŭ���� �̸��� ���� �� ������ ������ ����մϴ�.
�̷��� ��� ��� ������ ��ü�� �������� �ʾƵ� ����� �� ������,
�ڵ带 �а� �����ϱ� ���� ����� �ݴϴ�.
*/