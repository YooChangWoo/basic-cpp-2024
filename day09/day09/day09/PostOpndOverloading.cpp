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

    // ���� ���� ������ �����ε� (++pos)
    Point& operator++()        // ���� - �°��ϰ� �����ش�.   a = i++
    {
        xpos += 1; // x��ǥ ����
        ypos += 1; // y��ǥ ����

        return *this; // ���� ��ü ��ȯ
    }

    // ���� ���� ������ �����ε� (pos++)
    const Point operator++(int)      // ���� - �����ְ� ����. a = i++
    {   // ������ ��ü�� �����Ͽ� ������ �Ӽ����� ������Ų��.
        const Point retobj(xpos, ypos); // ���� ��ǥ�� �����ϱ� ���� �ӽ� Point ��ü ����  // const Point ret
        // ���� ��ü�� �Ӽ����� 1�� ������Ų��.
        xpos += 1; // x��ǥ ����
        ypos += 1; // y��ǥ ����
        // ���� ������ ������ ��ü�� �����Ѵ�.
        return retobj; // ���� ������ ��ǥ�� ������ �ӽ� ��ü ��ȯ
    }

    friend Point& operator--(Point& ref); // ���� ���� ������ �Լ��� friend�� ����
    friend const Point operator--(Point& ref, int); // ���� ���� ������ �Լ��� friend�� ����
};

// ���� ���� ������ �����ε� (--pos)
Point& operator--(Point& ref)
{
    ref.xpos -= 1; // x��ǥ ����
    ref.ypos -= 1; // y��ǥ ����
    return ref; // ����� ��ü ��ȯ
}

// ���� ���� ������ �����ε� (pos--)
const Point operator--(Point& ref, int)
{
    const Point retobj(ref.xpos, ref.ypos); // ���� ��ǥ�� �����ϱ� ���� �ӽ� Point ��ü ����
    ref.xpos -= 1; // x��ǥ ����
    ref.ypos -= 1; // y��ǥ ����
    return retobj; // ���� ������ ��ǥ�� ������ �ӽ� ��ü ��ȯ
}

int main(void)
{
    Point pos(3, 5); // Point ��ü ���� (��ǥ: 3, 5)
    Point cpy; // ������ Point ��ü ����

    cpy = pos--; // ���� ���� ������ ���
    cpy.ShowPosition(); // ����� ��ü�� ��ǥ ���
    pos.ShowPosition(); // ���ҵ� ��ü�� ��ǥ ���

    cpy = pos++; // ���� ���� ������ ���
    cpy.ShowPosition(); // ����� ��ü�� ��ǥ ���
    pos.ShowPosition(); // ������ ��ü�� ��ǥ ���

    return 0;
}

/*
���� ���� ������ �����ε� (++pos):
++pos �����ڸ� �����ε��Ͽ� ��ǥ���� 1�� ������ŵ�ϴ�.
�Լ��� ���� ��ü�� ������ ��ȯ�մϴ�.

���� ���� ������ �����ε� (pos++):
pos++ �����ڸ� �����ε��Ͽ�, ���� ������ ��ǥ�� �ӽ� ��ü�� �����ϰ�, ��ǥ�� 1�� ������ŵ�ϴ�.
�Լ��� ���� ������ ��ǥ�� ������ �ӽ� ��ü�� ��ȯ�մϴ�.

���� �� ���� ���� ������ �����ε�:
���� �� ���� ���� �����ڸ� �����ε��Ͽ�, ��ǥ���� 1�� ���ҽ�ŵ�ϴ�.
���� �����ڴ� int ������ ���� �Ű������� ������, ������ �����ε��� ���� ������ �����մϴ�.
*/