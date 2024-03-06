#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr;       // �������� �Ҵ�� �迭�� ����Ű�� ������
    int arrlen;     // �迭�� ���̸� �����ϴ� ����
public:
    // ������: �迭�� ���̸� �޾Ƽ� �������� �迭�� �Ҵ���
    BoundCheckIntArray(int len) : arrlen(len)
    {
        printf("������ ȣ��\n");
        arr = new int[len]; // len ������ int �迭�� �������� �Ҵ�
    }

    // [] ������ �����ε�: �迭 ��ҿ� ������ �� ����
    int& operator[] (int idx)
    {
        printf("[]������ ȣ��\n");
        // �ε����� ��ȿ���� Ȯ��
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl; // ��ȿ���� ������ ���� ���
            exit(1); // ���α׷� ����
        }

        return arr[idx]; // �ش� �ε����� ��ҿ� ���� ���۷��� ��ȯ
    }

    // �Ҹ���: �������� �Ҵ�� �迭 �޸𸮸� ������
    ~BoundCheckIntArray()
    {
        printf("�Ҹ��� ȣ��\n");
        delete[] arr; // �������� �Ҵ�� �迭 �޸𸮸� ����
    }
};

int main(void)
{
    BoundCheckIntArray arr(5); // ���̰� 5�� BoundCheckIntArray ��ü ����

    // �迭�� ���� �Ҵ�
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;

    // �迭�� ���� ��� (�ε��� �����÷ο찡 �߻��� �� ����)
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;

    return 0;
}

/*
���� �迭�� �ε��� �����ε�: BoundCheckIntArray Ŭ������ �������� �Ҵ�� �迭�� ����մϴ�.
�� Ŭ������ �迭�� ������ �� �ε��� �����ε��� ����Ͽ� �� ��ҿ� �����մϴ�.

�ε��� �˻�: �迭�� �ε����� �˻��Ͽ� ������ ��ȿ���� Ȯ���մϴ�.
operator[] �Լ� ������ �ε����� �迭�� ������ �����
"Array index out of bound exception"�� ����ϰ� ���α׷��� �����մϴ�.

�޸� ����: Ŭ������ �Ҹ��ڿ����� �������� �Ҵ�� �迭 �޸𸮸� �����մϴ�.
�̴� �޸� ������ �����ϰ� ���α׷��� �޸� ��뷮�� �����ϴ� �� �߿��մϴ�.

��� ����: main �Լ������� BoundCheckIntArray ��ü�� �����ϰ� �迭�� ���� �Ҵ��� ��,
�迭�� ���� ����մϴ�.
�ε��� �����÷ο찡 �߻��ϴ� ���, ���� ó�� �޽����� ��µ˴ϴ�.
*/