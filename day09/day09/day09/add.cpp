/*
  ��ü�� ���ϴ� add ����Լ�
*/
#include <iostream>
using namespace std;

class Point {
    int x, y; // private ��� ���� x�� y ����
public:
    // ������ ����, �⺻���� ���� 0
    Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
        cout << "Operator" << endl; // ������ ȣ�� �� ��¹�
    }
    // �� Point ��ü�� ���ϴ� ������ �����ε�
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y); // �� ��ü�� x�� y�� ���� ��ü ��ȯ
    }
    // Point ��ü ������ ����ϴ� �Լ�
    void showPoint() {
        cout << '[' << x << ']' << endl; // ��ü�� x ���� ���
    }
};

int main()
{
    Point pos1(3, 4); // Point ��ü pos1 ���� �� �ʱ�ȭ
    Point pos2(10, 20); // Point ��ü pos2 ���� �� �ʱ�ȭ
    Point pos3 = pos1, add(pos2); // Point ��ü pos3�� pos1�� add�� �ʱ�ȭ
    pos3.showPoint(); // pos3�� ���� ���

    return 0;
}

/*
��ü ���� �� �ʱ�ȭ:

��ü���� �����ǰ� �ʱ�ȭ�˴ϴ�. �����ڿ����� �ʱ�ȭ ����Ʈ�� ����Ͽ� �ʱ�ȭ�մϴ�.
������ �����ε�:

+ �����ڰ� �����ε��Ǿ� �� ���� Point ��ü�� ���� �� �ֵ��� �մϴ�.
operator+() �Լ� �������� �� ��ü�� x�� y ���� ���Ͽ� ���ο� ��ü�� �����Ͽ� ��ȯ�մϴ�.

���� �� ���:

������ ��ü�� ���� ����� ���� ����� �̷�����ϴ�.
*/