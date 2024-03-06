#include <iostream>
using namespace std;

// Point Ŭ���� ����
class Point
{
private:
    int xpos, ypos; // x, y ��ǥ�� �����ϴ� ��� ����
public:
    // ������: �ʱ�ȭ ����Ʈ�� ����Ͽ� ��� ���� �ʱ�ȭ
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        cout << "Point ��ü ����" << endl;
    }

    // �Ҹ���: ��ü�� �Ҹ�� �� ȣ��Ǵ� �Լ�
    ~Point()
    {
        cout << "Point ��ü �Ҹ�" << endl;
    }

    // ��ǥ ���� �Լ�
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    // ��Ʈ�� ��� ������ �����ε� �Լ�
    friend ostream& operator<<(ostream& os, const Point& pos);
};

// ��Ʈ�� ��� ������ �����ε� �Լ� ����
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

// SmartPtr Ŭ���� ����
class SmartPtr
{
private:
    Point* posptr; // Point Ŭ������ ������ ��� ����
public:
    // ������: Point ��ü�� ����Ű�� �����͸� �޾� �ʱ�ȭ
    SmartPtr(Point* ptr) : posptr(ptr)
    {  }

    // ���� ������(*) �����ε�: �����Ͱ� ����Ű�� Point ��ü�� ��ȯ
    Point& operator*() const
    {
        return *posptr;
    }

    // ȭ��ǥ ������(->) �����ε�: �����Ͱ� ����Ű�� Point ��ü�� ����
    Point* operator->() const
    {
        return posptr;
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~SmartPtr()
    {
        delete posptr;
    }
};

// main �Լ�
int main(void)
{
    // SmartPtr ��ü ���� �� �ʱ�ȭ
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(2, 3));
    SmartPtr sptr3(new Point(4, 5));

    // ��ü ���
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    // ��ü�� ��ǥ ����
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);

    // ����� ��ǥ ���
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    return 0;
}
/*
Point Ŭ����: ������ x, y ��ǥ�� ������ Ŭ������,
��Ʈ�� ��� ������(<<)�� �����ε��Ͽ� ��ǥ�� ����� �� �ֽ��ϴ�.

SmartPtr Ŭ����: ������ ����� ������ ������,
�����Ͱ� ����Ű�� Point ��ü�� �����ϰų� ������ �� �ִ� ������(*, ->)�� �����ε��ϰ� �ֽ��ϴ�.
����, ��ü�� �Ҹ�� �� �������� �Ҵ�� �޸𸮸� �����ϴ� ������ �մϴ�.

main �Լ�: SmartPtr ��ü�� �����ϰ� Point ��ü�� �������� �Ҵ��Ͽ� �ʱ�ȭ�մϴ�.
���� ������ �����ڸ� ����Ͽ� ��ü�� �����ϰ�, ��ǥ�� ������ �� ����� ��ǥ�� ����մϴ�.
*/