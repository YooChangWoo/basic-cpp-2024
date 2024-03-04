#include <iostream>
#include <cstring> // strlen �� strcpy �Լ��� ����ϱ� ���� ��� ���� �߰�
using namespace std;

class First
{
private:
    char* strOne; // ���ڿ��� �����ϱ� ���� ������

public:
    // ������: ���ڿ��� �����Ͽ� ����
    First(const char* str)
    {
        strOne = new char[strlen(str) + 1]; // ���ڿ��� ���� + �� ���� ����('\0') ���� �Ҵ�
        strcpy(strOne, str); // ���ڿ� ����
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~First()
    {
        cout << "~First()" << endl;
        delete[] strOne; // �������� �Ҵ�� �޸� ����
    }
};

class Second : public First
{
private:
    char* strTwo; // ���ڿ��� �����ϱ� ���� ������

public:
    // ������: ���ڿ��� �����Ͽ� ����
    Second(const char* str1, const char* str2) : First(str1)
    {
        strTwo = new char[strlen(str2) + 1]; // ���ڿ��� ���� + �� ���� ����('\0') ���� �Ҵ�
        strcpy(strTwo, str2); // ���ڿ� ����
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~Second()
    {
        cout << "~Second()" << endl;
        delete[] strTwo; // �������� �Ҵ�� �޸� ����
    }
};

int main(void)
{
 /*
    ��� ���迡 �־ ��ü�����ʹ� �����ؾ� �Ѵ�.
    �θ�Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����Ű�� ���(������) ���� ���� �� �����ؾ� �Ѵ�.
 */
    // Second Ŭ������ ��ü�� ���� �����Ͽ� �޸� ������ �����մϴ�.
    Second* ptr = new Second("simple", "complex");

    // �������� �Ҵ�� �޸𸮸� �����մϴ�.
    delete ptr;

    return 0;
}



