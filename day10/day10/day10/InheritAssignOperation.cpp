#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2; // ������ ��� ���� ����
public:
    // ������: ��� ���� �ʱ�ȭ
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    {  }
    // ������ ��� �Լ�
    void ShowData() { cout << num1 << ", " << num2 << endl; }

    // ���� ������ �����ε�
    First& operator=(const First& ref)
    {
        cout << "First& operator=()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First
{
private:
    int num3, num4; // �߰����� ������ ��� ���� ����
public:
    // ������: �θ� Ŭ������ ������ ȣ���Ͽ� �ʱ�ȭ, �߰� ��� ���� �ʱ�ȭ
    Second(int n1, int n2, int n3, int n4)
        : First(n1, n2), num3(n3), num4(n4)
    {  }

    // ������ ��� �Լ�
    void ShowData()
    {
        First::ShowData(); // �θ� Ŭ������ ShowData() �Լ� ȣ��
        cout << num3 << ", " << num4 << endl; // �ڽ��� ��� ���� ���
    }

    // ���� ������ �����ε�
    /*
    Second& operator=(const Second &ref)
    {
        cout << "Second& operator=()" << endl;
        // �θ� Ŭ������ ���� ������ ȣ�� (������)
        // First::operator=(ref);
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
    */
};


int main(void)
{
    Second ssrc(111, 222, 333, 444); // Second Ŭ������ ��ü ���� �� �ʱ�ȭ
    Second scpy(0, 0, 0, 0); // Second Ŭ������ ��ü ���� �� �ʱ�ȭ

    scpy = ssrc; // ���� ������ ȣ��
    scpy.ShowData(); // ��ü�� ������ ���
    return 0;
}
/*
First Ŭ������ �� ���� ������ ��� ������ ������ ������,
���� �����ڸ� �����ε��Ͽ� ��ü�� ��� ������ ������ �� �ֽ��ϴ�.

Second Ŭ������ First Ŭ������ ��ӹް� ������,
�� ���� �߰����� ������ ��� ������ ������ �ֽ��ϴ�.

Second Ŭ������ �����ڿ����� �θ� Ŭ������ First Ŭ������ �����ڸ� ȣ���Ͽ�
��ӵ� ��� ������ �ʱ�ȭ�ϰ�, �ڽ��� ��� ������ �ʱ�ȭ�մϴ�.

Second Ŭ������ ShowData() �Լ������� �θ� Ŭ������ First Ŭ������ ShowData() �Լ��� ȣ���� ��,
�ڽ��� ��� ������ ����մϴ�.

Second Ŭ�������� ���� �����ڸ� �����ε��ϴ� ���� ���û����Դϴ�.
�θ� Ŭ������ First Ŭ������ ���� �����ڸ� ȣ���� ���� �ְ�,
�ڽ��� ��� ������ ������ ���� �ֽ��ϴ�.
*/