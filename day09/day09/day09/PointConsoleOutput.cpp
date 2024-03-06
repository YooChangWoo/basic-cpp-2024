#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {  }

    // ��ǥ�� ����ϴ� ��� �Լ�
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // << �����ڸ� ���� Point ��ü�� ����ϱ� ���� ostream�� friend�� ����� �Լ�
    friend ostream& operator<<(ostream&, const Point&);
};

// << �����ڸ� �����ε��Ͽ� Point ��ü�� ����ϱ� ���� �Լ� ����
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main(void)
{
    Point pos1(1, 3);
    cout << pos1; // pos1 ��ü ���
    Point pos2(101, 303);
    cout << pos2; // pos2 ��ü ���
    return 0;
}

/*
������ �����ε�:

operator<< �Լ��� ��� ��Ʈ���� Point ��ü�� ����ϱ� ���� �����ε��˴ϴ�.
�� �Լ��� ostream Ŭ������ ��ü(os)�� Point ��ü(pos)�� �Ű������� �ް�, Point ��ü�� ��ǥ�� ������ �������� ����մϴ�.

friend �Լ�:

operator<< �Լ��� Point Ŭ������ friend�� ����Ǿ� �����Ƿ�, Point Ŭ������ private ����� ������ �� �ֽ��ϴ�.
�̸� ���� operator<< �Լ����� Point ��ü�� xpos�� ypos ����� �����Ͽ� ����� �� �ֽ��ϴ�.

��� ����:

main() �Լ������� cout << pos1;�� cout << pos2;�� ���� Point ��ü�� ����ϴ� ���� �� �� �ֽ��ϴ�.
�̷��� ������ operator<< �Լ��� �����ε��� ���� ���������ϴ�.
*/

