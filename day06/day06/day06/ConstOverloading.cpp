#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    // ������: ��ü�� �ʱ�ȭ�մϴ�.
    SoSimple(int n) : num(n) {}

    // ��� �Լ�: num�� n�� ���� �� ��ü�� ������ ��ȯ�մϴ�.
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    // �Ϲ� ��� �Լ�: ��ü�� num�� ����մϴ�.
    void SimpleFunc()
    {
        cout << "SimpleFunc: " << num << endl;
    }

    // ��� ��� �Լ�: ��ü�� num�� ����մϴ�. ��ü�� �������� �����Ƿ� ��� �Լ��� ����˴ϴ�.
    void SimpleFunc() const
    {
        cout << "const SimpleFunc: " << num << endl;
    }
};

// ���� �Լ�: SoSimple ��ü�� ��� ������ ���ڷ� �޾� ��� ��� �Լ��� ȣ���մϴ�.
void YourFunc(const SoSimple& obj)
{
    obj.SimpleFunc();
}

int main(void)
{
    // ��ü ����
    SoSimple obj1(2);
    const SoSimple obj2(7);

    // ��ü�� �Ϲ� ��� �Լ� ȣ��
    obj1.SimpleFunc();
    obj2.SimpleFunc();

    // ���� �Լ� ȣ��: ��� ��ü�� ��� ��� �Լ��� ȣ��˴ϴ�.
    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}

/*
SoSimple Ŭ����:

SoSimple Ŭ������ �ϳ��� private ��� ���� num�� ������ �ֽ��ϴ�.
AddNum ��� �Լ��� num�� ���ڷ� ���� ���� ���� �� ��ü�� ������ ��ȯ�մϴ�.
SimpleFunc ��� �Լ��� ��ü�� num�� ����մϴ�.
const SimpleFunc ��� �Լ��� ��ü�� num�� ����ϸ�, ��ü�� �������� �����Ƿ� ��� ��� �Լ��� ����˴ϴ�.

YourFunc �Լ�:

YourFunc �Լ��� SoSimple Ŭ������ ��� ������ ���ڷ� �޾� ��� ��� �Լ��� ȣ���մϴ�.

main �Լ�:

main �Լ������� �Ϲ� ��ü obj1�� ��� ��ü obj2�� �����մϴ�.
��ü�� �Ϲ� ��� �Լ��� ��� ��� �Լ��� ȣ���Ͽ� ������ ����� Ȯ���մϴ�.
���� �Լ��� ȣ���Ͽ� ��� ��ü�� ��� ��� �Լ��� ȣ��Ǵ� ���� Ȯ���մϴ�.
���α׷��� �����ϸ�, �Ϲ� ��� �Լ��� ��� ��� �Լ��� ���� ȣ��Ǹ�, ��� ��ü�� ��� ��� �Լ��� ȣ���� �� ��ü�� �������� ������ Ȯ���� �� �ֽ��ϴ�.
*/