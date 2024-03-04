#include <iostream>
using namespace std;

class Base {
public:
    Base() {} // �⺻ ������
    virtual ~Base() {} // ���� �Ҹ���: �Ļ� Ŭ������ ��ü�� �ı��� �� �ش� �Ļ� Ŭ������ �Ҹ��ڸ� ȣ���ϱ� ���� ���� �Ҹ��ڷ� ����
    virtual void func1() { cout << "Base::func1()" << endl; } // ���� �Լ� func1(): �Ļ� Ŭ�������� ������ ������ �Լ�
    virtual void func2() { cout << "Base::func2()" << endl; } // ���� �Լ� func2(): �Ļ� Ŭ�������� ������ ������ �Լ�
    virtual void func3() { cout << "Base::func3()" << endl; } // ���� �Լ� func3(): �Ļ� Ŭ�������� ������ ������ �Լ�
};

class Derived : public Base {
public:
    void func1() override { cout << "Derived::func1()" << endl; } // func1()�� �������̵��Ͽ� ���ο� ���� ����
    void func3() override { cout << "Derived::func3()" << endl; } // func3()�� �������̵��Ͽ� ���ο� ���� ����
    void func4() { cout << "Derived::func4()" << endl; } // Derived Ŭ�������� �����ϴ� ���ο� ��� �Լ�

    Derived() = default; // �⺻ �����ڸ� ����ϴ� ���
};

int main() {
    Base b; // Base Ŭ������ ��ü ����
    Derived d; // Derived Ŭ������ ��ü ����
    Base* pb = new Derived(); // Base Ŭ������ �����ͷ� Derived Ŭ������ ��ü�� ����Ŵ

    pb->func1(); // Derived::func1() - ���� �Լ� ȣ���� ���� ��ü�� ���� ���� �����
    pb->func2(); // Base::func2()
    pb->func3(); // Derived::func3()

    cout << endl;

    Derived* pd = &d; // Derived Ŭ������ �����ͷ� Derived ��ü�� ����Ŵ
    pd->func1(); // Derived::func1()
    pd->func2(); // Base::func2()
    pd->func3(); // Derived::func3()
    pd->func4(); // Derived::func4() - Derived Ŭ������ ��� �Լ� ȣ��

    delete pb; // �������� �Ҵ�� �޸� ����

    return 0;
}

/*
���� �Լ��� ������:

Base Ŭ������ ��� �Լ���(func1(), func2(), func3())�� ��� ���� �Լ��� ����Ǿ� �ֽ��ϴ�.
Derived Ŭ�������� func1()�� func3()�� �������̵��Ͽ� ���ο� ������ �����߽��ϴ�.
���� �Լ��� ��ü�� ���� ���¿� ���� ȣ��˴ϴ�. ���� pb->func1()�� Derived Ŭ������ func1()�� ȣ��˴ϴ�.

���� �Ҵ� �� �޸� ����:

Base* pb = new Derived();�� ���� �������� Derived ��ü�� �����Ͽ� Base Ŭ������ �����ͷ� ����ų �� �ֽ��ϴ�.
�������� �Ҵ�� �޸𸮴� delete pb;�� ���� �����Ǿ�� �մϴ�.

�������� ��:

pb�� Base Ŭ������ ������������ ������ Derived ��ü�� ����Ű�� �ֽ��ϴ�. �̰��� �������� �� ���Դϴ�.
���� �Լ��� ��ü�� ���� ���¸� ������� ȣ��ǹǷ� Derived Ŭ�������� �������̵��� �Լ��� ȣ��˴ϴ�.
*/