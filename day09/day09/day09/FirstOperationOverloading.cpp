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
        cout << '[' << xpos << "," << ypos << ']' << endl;
    }

    Point operator+(const Point& ref) // + ������ �����ε�  //operator+��� �̸��� �Լ�
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos); // �� Point ��ü�� ��ǥ���� ���� ���ο� Point ��ü ����
        return pos; // ���ο� Point ��ü ��ȯ
    }
};

int main(void)
{
    Point pos1(3, 4); // ù ��° Point ��ü ���� (��ǥ: 3, 4)
    Point pos2(10, 20); // �� ��° Point ��ü ���� (��ǥ: 10, 20)
        // pos1�� pos2�� ���� ����� pos3�� �Ҵ�
    Point pos3 = pos1.operator+(pos2); // operator+ �Լ��� ���� ȣ���Ͽ� �� Point ��ü�� ���� ����� ����
    Point pos3 = pos2.operator+(pos3);

    pos1.ShowPosition(); // pos1�� ��ǥ ���
    pos2.ShowPosition(); // pos2�� ��ǥ ���
    pos3.ShowPosition(); // pos3�� ��ǥ ���
    
    return 0;
}
/*
������ �����ε� :

Ŭ���� ������ + �����ڰ� �����ε��Ǿ� ������, �̸� ���� �� Point ��ü�� ���� �� �ֽ��ϴ�.
operator+ �Լ��� �� ���� Point ��ü�� �޾Ƽ� ���� ��, ���ο� Point ��ü�� ��ȯ�մϴ�.

operator+ ȣ�� :

main �Լ����� pos1�� pos2�� ���ϱ� ���� operator+ �Լ��� ȣ���մϴ�.
�̴� pos1.operator+(pos2)�� ������ ������ �մϴ�.
���ο� Point ��ü�� �����Ǿ� pos3�� �Ҵ�˴ϴ�.
    
ShowPosition �Լ� :

ShowPosition �Լ��� �� Point ��ü�� ��ǥ�� ����մϴ�.
*/