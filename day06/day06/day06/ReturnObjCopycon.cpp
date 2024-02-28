#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // private ��� ���� num

public:
    SoSimple(int n) : num(n) // ������: ��� ���� num�� �ʱ�ȭ�մϴ�.
    { }

    SoSimple(const SoSimple& copy) : num(copy.num) // ���� ������: �ٸ� ��ü�κ��� ��ü�� �����մϴ�.
    {
        cout << " Called SoSimple(const SoSimple& copy)" << endl; // ���� ������ ȣ�� �� �޽��� ���
    }

    SoSimple& AddNum(int n) // ��� �Լ�: num�� n�� ���ϰ� ��ü �ڽ��� ������ ��ȯ�մϴ�.
    {
        num += n; // num�� n�� ���մϴ�.
        return *this; // ��ü �ڽ��� ������ ��ȯ�մϴ�.
    }

    void ShowData() // ��� �Լ�: ��ü�� �����͸� ����մϴ�.
    {
        cout << "num: " << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob) // ���� �Լ�: SoSimple ��ü�� ���ڷ� �޾� ����մϴ�.
{
    cout << "return ����" << endl; // �Լ� ȣ�� �� �޽��� ���
    return ob; // ���� ��ü�� ��ȯ�մϴ�.
}

int main(void)
{
    SoSimple obj(7); // SoSimple Ŭ������ ��ü obj�� �����ϰ� �ʱ�ȭ�մϴ�.

    // SimpleFuncObj �Լ��� ȣ���ϰ�, ��ȯ�� ��ü�� AddNum �Լ��� ȣ���� �� ShowData�� ȣ���Ͽ� ����� ����մϴ�.
    SimpleFuncObj(obj).AddNum(30).ShowData();
    // obj�� ShowData�� ȣ���Ͽ� ����� ����մϴ�.
    obj.ShowData();

    return 0;
}

/*
SoSimple Ŭ����:

SoSimple Ŭ������ �ϳ��� private ��� ���� num�� ������ �ֽ��ϴ�.
�����ڴ� ��ü�� �ʱ�ȭ�ϰ� ��� ���� num�� ���ڷ� ���� ������ �����մϴ�.
���� �����ڴ� �ٸ� ��ü�κ��� ��ü�� ������ �� ȣ��Ǹ�, �����ϴ� ��ü�� num ���� �����Ͽ� ���� ��ü�� num�� �����մϴ�.
AddNum ��� �Լ��� num�� ���ڷ� ���� ���� ���� �� ��ü�� ������ ��ȯ�մϴ�.
ShowData ��� �Լ��� ��ü�� num�� ����մϴ�.

���� �Լ� SimpleFuncObj:

SimpleFuncObj �Լ��� SoSimple ��ü�� ���ڷ� �޾� ����մϴ�.
�Լ� ������ "return ����" �޽����� ����� �� ���� ��ü�� ��ȯ�մϴ�.

main �Լ�:

main �Լ����� SoSimple ��ü obj�� �����ϰ� �ʱ�ȭ�մϴ�.
SimpleFuncObj �Լ��� ȣ���ϰ�, ��ȯ�� ��ü�� AddNum �Լ��� ȣ���� �� ShowData�� ȣ���Ͽ� ����� ����մϴ�.
���������� obj�� ShowData�� ȣ���Ͽ� ����� ����մϴ�.
���α׷��� �����ϸ�, �Լ� ȣ�� ������ ���� �޽����� ��µǰ�, num�� ���� ���� ����� ��µ˴ϴ�.
*/