#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // 2���� ��ǥ�� x�� y ��ǥ���� �����ϱ� ���� private ��� ����
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) // ������, �⺻������ (0,0)���� �ʱ�ȭ
    { }

    void ShowPosition() const // ���� ��ǥ�� ����ϴ� �Լ�
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    friend Point operator+(const Point& pos1, const Point& pos2); // operator+ �Լ��� friend�� �����Ͽ� Ŭ���� �ܺο��� ���� �����ϰ� ��
};

// �� Point ��ü�� ���ϴ� ������ �����ε� �Լ�
Point operator+(const Point& pos1, const Point& pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos); // �� Point ��ü�� ��ǥ���� ���Ͽ� ���ο� Point ��ü ����
    return pos; // ���ο� Point ��ü ��ȯ
}

int main(void)
{
    Point pos1(3, 4); // ù ��° Point ��ü ���� (��ǥ: 3, 4)
    Point pos2(10, 20); // �� ��° Point ��ü ���� (��ǥ: 10, 20)

    Point pos3 = pos1 + pos2; // �� Point ��ü�� ���� ����� pos3�� �Ҵ�

    pos1.ShowPosition(); // pos1�� ��ǥ ���
    pos2.ShowPosition(); // pos2�� ��ǥ ���
    pos3.ShowPosition(); // pos3�� ��ǥ ���

    return 0;
}

/*
������ �����ε� (operator+):
�� ���������� + �����ڸ� �����ε��Ͽ� �� Point ��ü�� ���մϴ�.
operator+ �Լ��� friend �Լ��� ����Ǿ� Ŭ���� ���� private ����� ������ �� �ֵ��� �մϴ�.

friend �Լ�:
operator+ �Լ��� Point Ŭ���� ������ private ����� ������ �� �ֵ��� �ϱ� ���� friend�� ����Ǿ����ϴ�.

operator+ �Լ� ����:
operator+ �Լ��� �� ���� Point ��ü�� ���ڷ� �޾Ƽ� �� ��ǥ�� ���� ��, ���ο� Point ��ü�� ��ȯ�մϴ�.

����:
main �Լ������� �� Point ��ü�� �����ϰ�, �̸� ���Ͽ� ���ο� Point ��ü�� �Ҵ��մϴ�.
*/
