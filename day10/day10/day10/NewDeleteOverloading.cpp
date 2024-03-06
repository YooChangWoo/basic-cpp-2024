#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // ��ǥ���� ��Ÿ���� ��� ����
public:
    // ������: ��ǥ�� �ʱ�ȭ
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }

    // << ������ �����ε� �Լ��� ������� ����
    friend ostream& operator<<(ostream& os, const Point& pos);

    // ���ο� �޸� �Ҵ� �����ڸ� �����ε��Ͽ� �޸� �Ҵ� �� �α׸� ���
    void* operator new (size_t size)
    {
        cout << "operator new : " << size << endl;
        void* adr = new char[size]; // size ũ���� char �迭 ���� �Ҵ�
        return adr;
    }

    // ���� �����ڸ� �����ε��Ͽ� �޸� ���� �� �α׸� ���
    void operator delete (void* adr)
    {
        cout << "operator delete()" << endl;
        delete[] adr; // �������� �Ҵ�� �޸𸮸� ����
    }
};

// << ������ �����ε� �Լ��� ����
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl; // ��ǥ���� ���
    return os;
}

int main(void)
{
    // Point ��ü�� �������� �Ҵ��ϰ�, << �����ڸ� ����Ͽ� ��ǥ�� ���
    Point* ptr = new Point(3, 4);
    cout << *ptr; // << �����ڸ� ����Ͽ� ��ǥ�� ���
    delete ptr; // �������� �Ҵ�� �޸� ����
    return 0;
}
/*
Point Ŭ������ operator new�� operator delete �Լ��� �����ε��Ͽ� ���� �޸� �Ҵ�� ������ Ŀ���͸���¡�մϴ�.
�̷��� �ϸ� �޸� �Ҵ� �� ���� �� ����ڰ� ���ϴ� �۾��� �߰��� �� �ֽ��ϴ�.

operator<< �Լ��� ostream ��ü�� Point ��ü�� �޾Ƽ� ��ǥ���� ����մϴ�.
�� �Լ��� Point Ŭ������ ������ �Լ��� ����Ǿ� �־ Point Ŭ������ private ����� ������ �� �ֽ��ϴ�.

main �Լ������� new Ű���带 ����Ͽ� Point ��ü�� �������� �Ҵ��ϰ�,
��� ������ <<�� ����Ͽ� ��ǥ���� ����մϴ�.
���������� delete Ű���带 ����Ͽ� �������� �Ҵ�� �޸𸮸� �����մϴ�.
*/