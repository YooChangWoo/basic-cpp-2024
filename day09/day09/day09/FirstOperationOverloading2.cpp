#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2; // �� ���� ������ private ��� ���� ����
public:
    // ������ ����, �⺻���� ���� 0
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    {  }
    // ��� ���� ��� �Լ�
    void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
    int num3, num4; // �� ���� ������ private ��� ���� ����
public:
    // ������ ����, �⺻���� ���� 0
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    {  }
    // ��� ���� ��� �Լ�
    void ShowData() { cout << num3 << ", " << num4 << endl; }

    // ���� ������ �����ε�
    Second& operator=(const Second& ref)
    {
        cout << "Second& operator=()" << endl; // ����Ʈ ���� ������ ȣ���� Ȯ���ϱ� ���� ��¹�
        num3 = ref.num3; // num3 �� ����
        num4 = ref.num4; // num4 �� ����
        return *this; // ���� ��ü�� ���� ��ȯ
    }
};

int main(void)
{
    First fsrc(111, 222); // First Ŭ������ ��ü fsrc ���� �� �ʱ�ȭ
    First fcpy; // First Ŭ������ ��ü fcpy ����
    Second ssrc(333, 444); // Second Ŭ������ ��ü ssrc ���� �� �ʱ�ȭ
    Second scpy; // Second Ŭ������ ��ü scpy ����

    fcpy = fsrc; // ����Ʈ ���� �����ڸ� �̿��� ��ü fcpy�� ��ü fsrc ����
    scpy = ssrc; // ��������� �ۼ��� ���� �����ڸ� �̿��� ��ü scpy�� ��ü ssrc ����

    fcpy.ShowData(); // fcpy ��ü�� ������ ���
    scpy.ShowData(); // scpy ��ü�� ������ ���

    First fob1, fob2; // First Ŭ������ ��ü fob1, fob2 ����
    Second sob1, sob2; // Second Ŭ������ ��ü sob1, sob2 ����

    // �������� ���� �������� ���� Ȯ��
    fob1 = fob2 = fsrc; // fsrc ��ü�� fob1�� �����ϰ�, fob1�� fob2�� ����
    sob1 = sob2 = ssrc; // ssrc ��ü�� sob1�� �����ϰ�, sob1�� sob2�� ����

    // ��ü���� ������ ���
    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
    return 0;
}

/*
���� ������ �����ε�:

Second Ŭ�������� operator= �Լ��� �����ε��߽��ϴ�. �� �Լ��� ��ü ���� ���� ������ �����մϴ�.
���� �����ڸ� �����ε��ϸ� ��ü�� �ٸ� ��ü�� ����� �� ������ �߻��ϴ����� ������ �� �ֽ��ϴ�.
���⼭�� ��ü�� ��� ������ �ٸ� ��ü�� ��� ������ �����ϰ� �ֽ��ϴ�.

��ü ���� �� ���� ����:

First�� Second Ŭ������ ��ü���� �����ϰ� ���� �����ϰ� �ֽ��ϴ�.
fcpy = fsrc;�� ���� ��ü�� �ٸ� ��ü�� �����ϸ�, ���� ������ �����ε� �Լ��� ȣ��˴ϴ�.
�̸� ���� ��ü�� ���°� ����ǰ�, ��ü ���� �����Ͱ� �����˴ϴ�.

�������� ���� �������� ����:

fob1 = fob2 = fsrc;�� ���� �������� ���� ������ ����� ��, ���� �����ڴ� �����ʿ��� �������� �򰡵˴ϴ�.
���� fsrc�� �����Ͱ� ���� fob2�� ����ǰ�, �� ������ fob2�� �����Ͱ� fob1�� ����˴ϴ�.
*/