#include <iostream>

using namespace std;

// 2���� ��ǥ�� ǥ���ϴ� Ŭ����
class Point
{
public:
    int x; // x ��ǥ
    int y; // y ��ǥ
};

// ���簢���� ǥ���ϴ� Ŭ����
class Rectangle
{
public:
    Point upLeft;    // �� ��� ������
    Point lowright;  // �� �ϴ� ������

public:
    // ���簢���� ������ ����ϴ� �Լ�
    void ShowRecInfo()
    {
        cout << "�� ���: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "�� �ϴ�: " << '[' << lowright.x << ", ";
        cout << lowright.y << ']' << endl << endl;
    }
};

// ���α׷��� ������
int main(void)
{
    Point pos1 = { -2, 4 };            // ù ��° ���� ��ǥ
    Point pos2 = { 5, 9 };             // �� ��° ���� ��ǥ
    Rectangle rec = { pos2, pos1 };    // ���簢�� ��ü ���� �� �ʱ�ȭ
    rec.ShowRecInfo();                 // ���簢�� ���� ���
    return 0;                          // ���α׷� ����
}

/*
1. Point Ŭ����:
    -> Point Ŭ������ 2���� ������ �� ���� ��Ÿ���� Ŭ����.
    -> ��� ������ x�� y�� ������ �ֽ��ϴ�. �̴� ���� x��� y���� ��ǥ�� ��Ÿ��.

2. Rectangle Ŭ����:
    -> Rectangle Ŭ������ ���簢���� ��Ÿ���� Ŭ����.
    -> ��� ������ upLeft�� lowRight�� ������ �ֽ��ϴ�.
        =>�̴� ���簢���� �»�ܰ� ���ϴ� ���� ��Ÿ��.
    -> ShowRecInfo �Լ��� ���簢���� ������ ����ϴ� �޼���.

3. ���� �Լ�:

    -> main �Լ������� �� ���� Point ��ü�� �����ϰ�, �̸� �̿��Ͽ� Rectangle ��ü�� ����.
    -> ù ��° Point ��ü pos1�� (-2, 4) ��ǥ.
    -> �� ��° Point ��ü pos2�� (5, 9) ��ǥ.
    -> �� �� ���� ������ ���ǵ� ���簢���� �����Ͽ� Rectangle ��ü rec�� save.
    -> rec.ShowRecInfo()�� ȣ���Ͽ� ���簢���� ������ ���.

*/
