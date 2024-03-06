#include <iostream>

using namespace std;

class Myclass {
private:
    int x; // private ��� ���� x ����

public:
    // ������ ����, �⺻���� 0
    Myclass(int y = 0) : x(y)
    { }
    // ��� ���� x ����ϴ� �Լ�, const �Լ��� ����
    void print() const
    {
        cout << "value: " << x << endl;
    }

    // �� Myclass ��ü�� ���ϴ� ������ �����ε�
    Myclass operator+(const Myclass& ref)
    {
        Myclass z(x + ref.x); // ���� ��ü�� x�� ref ��ü�� x�� ���� ���� ������ ��ü z ����
        return z; // z ��ü ��ȯ
    }
};

int main()
{
    Myclass a(10); // Myclass ��ü a ���� �� �ʱ�ȭ
    a.print();                        // value: 10 ���

    Myclass b(a); // Myclass ��ü b�� a�� �����Ͽ� ����
    b.print();                        // value: 10 ���

    Myclass c(b); // Myclass ��ü c�� b�� �����Ͽ� ����
    c.print();                        // value: 10 ���

    Myclass d = a + b + c; // Myclass ��ü d�� a, b, c�� ���� ���� ����
    d.print();                        // value: 30 ���
    return 0;
}

/*
���� �Լ� (main):

main() �Լ������� Myclass ��ü���� �����ϰ� �ʱ�ȭ�մϴ�.
������ ��ü���� print() �Լ��� ȣ���Ͽ� x ���� ����մϴ�.
Myclass ��ü���� ���� ����� ���ο� ��ü�� �����ϰ�, �̸� ����մϴ�.

������ �����ε�:

+ �����ڰ� �����ε��Ǿ� �� ���� Myclass ��ü�� ���� �� �ֵ��� �մϴ�.
operator+() �Լ� ������ �� ��ü�� x ���� ���Ͽ� ���ο� ��ü�� �����Ͽ� ��ȯ�մϴ�.

��ü ���� �� ����:

��ü���� �����ǰ� ���� �����ڰ� ȣ��Ǿ� ��ü�� �����մϴ�.
�̷��� ���� ���������� ��ü�� ��� �������� ������ ����˴ϴ�.

���� �� ���:

��ü�� ���� ����� �̿� ���� ����� �ùٸ��� ��µ˴ϴ�.
��ü�� ���¸� �������� �ʴ� �Լ��� const�� �����Ͽ� �������� ���Դϴ�.
*/