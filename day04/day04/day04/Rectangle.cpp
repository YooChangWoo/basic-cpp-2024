#include <iostream>
#include "Rectangle.h"
using namespace std;

// Rectangle Ŭ���� ��� �Լ� ����

// ���簢�� ��� ���� �ʱ�ȭ �Լ�
bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
    // ��� ��ǥ�� x���� ���ϴ� ��ǥ�� x������ ũ�ų�, ��� ��ǥ�� y���� 0���� Ŭ ���
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        cout << "�߸��� ��ġ���� ����" << endl;
        return false; // �ʱ�ȭ ���и� ��ȯ�մϴ�.
    }
    // ��� ��ǥ�� ���ϴ� ��ǥ�� ��� ������ �����մϴ�.
    upLeft = ul;
    lowRight = lr;
    return true; // �ʱ�ȭ ������ ��ȯ�մϴ�.
}

// ���簢�� ���� ��� �Լ�
void Rectangle::ShowRecInfo() const
{
    // ���簢���� ��� ��ǥ�� ���ϴ� ��ǥ�� ����մϴ�.
    cout << "��� ��ǥ: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;
    cout << "�� �ϴ� ��ǥ: " << '[' << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << ']' << endl << endl;
}