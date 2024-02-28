#include <iostream>
#include <cstring>
using namespace std;

// ���� ����: PointOP Ŭ������ Point Ŭ������ friend�� �����ϱ� ���� �ʿ���.
class Point;

// PointOP Ŭ���� ����
class PointOP
{
private:
    int opcnt; // ���� Ƚ���� �����ϴ� private ����

public:
    PointOP() : opcnt(0) // ������: opcnt�� �ʱ�ȭ
    { }

    // �� Point ��ü�� ���Ͽ� ���ο� Point ��ü�� ��ȯ�ϴ� �Լ�
    Point PointAdd(const Point&, const Point&);

    // �� Point ��ü�� ���� ���ο� Point ��ü�� ��ȯ�ϴ� �Լ�
    Point PointSub(const Point&, const Point&);

    // �Ҹ���: ���� Ƚ���� ����ϴ� ����
    ~PointOP()
    {
        cout << "Operation times: " << opcnt << endl;
    }
};

// Point Ŭ���� ����
class Point {
private:
    int x; // x ��ǥ�� �����ϴ� private ����
    int y; // y ��ǥ�� �����ϴ� private ����

public:
    // ������: x ��ǥ�� y ��ǥ�� �ʱ�ȭ
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos)
    {}

    // PointOP Ŭ������ PointAdd �Լ��� PointSub �Լ��� friend�� �����Ͽ� �̵� �Լ��� Point�� private ����� ������ �� �ֵ��� ��
    friend Point PointOP::PointAdd(const Point&, const Point&);
    friend Point PointOP::PointSub(const Point&, const Point&);

    // ��ǥ�� ����ϴ� �Լ�
    friend void ShowPointPos(const Point&);
};

// �� Point ��ü�� ���Ͽ� ���ο� Point ��ü�� ��ȯ�ϴ� �Լ�
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
    opcnt++; // ���� Ƚ�� ����
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y); // �� ���� x ��ǥ�� y ��ǥ�� ���Ͽ� ���ο� Point ��ü ��ȯ
}

// �� Point ��ü�� ���� ���ο� Point ��ü�� ��ȯ�ϴ� �Լ�
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
    opcnt++; // ���� Ƚ�� ����
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y); // �� ���� x ��ǥ�� y ��ǥ�� ���� ���ο� Point ��ü ��ȯ
}

// ��ǥ�� ����ϴ� �Լ�
void ShowPointPos(const Point& pos) {
    cout << "x : " << pos.x << ", "; // x ��ǥ ���
    cout << "y : " << pos.y << endl; // y ��ǥ ���
}

// ���� �Լ�
int main(void) {
    Point pos1(1, 2); // ù ��° Point ��ü ����
    Point pos2(2, 4); // �� ��° Point ��ü ����
    PointOP op; // PointOP ��ü ����

    // �� Point ��ü�� ���� ����� ���
    ShowPointPos(op.PointAdd(pos1, pos2));

    // �� Point ��ü�� �� ����� ���
    ShowPointPos(op.PointSub(pos2, pos1));

    return 0;
}
/*
1. Point Ŭ������ x ��ǥ�� y ��ǥ�� ������,
    -> �����ڸ� ���� �ʱ�ȭ ��.

2. PointOP Ŭ������ �� ���� ���ϰų� ���� ������ �����ϰ�,
    -> �̷��� ������ Ƚ���� ������.

3. ShowPointPos �Լ��� Point ��ü�� ��ǥ�� �����.

4. main �Լ������� �� ���� �ʱ�ȭ�ϰ�, PointOP ��ü�� ������ �� �� ���� ���ϰ� ����,
    -> �� ����� �����
*/