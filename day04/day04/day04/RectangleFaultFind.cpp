#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
    Point pos1;
    // pos1�� ��ǥ�� �ʱ�ȭ�ϰ�, �ʱ�ȭ�� �����ϸ� ���� �޽��� ���
    if (!pos1.InitMembers(-2, 4))
        cout << "�ʱ�ȭ ����" << endl;
    // pos1�� ��ǥ�� �ʱ�ȭ�ϰ�, �ʱ�ȭ�� �����ϸ� ���� �޽��� ���
    if (!pos1.InitMembers(2, 4))
        cout << "�ʱ�ȭ ����" << endl;

    Point pos2;
    // pos2�� ��ǥ�� �ʱ�ȭ�ϰ�, �ʱ�ȭ�� �����ϸ� ���� �޽��� ���
    if (!pos1.InitMembers(5, 9))
        cout << "�ʱ�ȭ ����" << endl;

    Rectangle rec;
    // ���簢���� ��� ��ǥ�� ���ϴ� ��ǥ�� �ʱ�ȭ�ϰ�, �ʱ�ȭ�� �����ϸ� ���� �޽��� ���
    if (!rec.InitMembers(pos2, pos1))
        cout << "���簢�� �ʱ�ȭ ����" << endl;

    // ���簢���� ��� ��ǥ�� ���ϴ� ��ǥ�� �ʱ�ȭ�ϰ�, �ʱ�ȭ�� �����ϸ� ���� �޽��� ���
    if (!rec.InitMembers(pos1, pos2))
        cout << "���簢�� �ʱ�ȭ ����" << endl;

    // ���簢�� ���� ���
    rec.ShowRecInfo();
    return 0;
}
/*
��ü�� �ʱ�ȭ �������� �߻��ϴ� ���и� ó���ϴ� ����� �߿���.
��ü ���� ����� ���� ��ȯ�� ���� ���ذ� �ʿ��ϰ�,
�� Ŭ������ �ʱ�ȭ �޼ҵ�(InitMembers())�� ȣ��Ǵµ�,
�� �޼ҵ���� ��ü�� ��� ������ ������ �ʱ�ȭ�ϴ��� Ȯ���� �ʿ䰡 ����
*/