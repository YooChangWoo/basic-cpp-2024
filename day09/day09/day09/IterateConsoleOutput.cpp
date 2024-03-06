#include <iostream>	

namespace mystd
{
    using namespace std;

    // ����� ���� ostream Ŭ���� ����
    class ostream
    {
    public:
        // ���ڿ� ��� ������ �����ε�
        ostream& operator<< (char* str)
        {
            printf("%s", str); // ���ڿ��� ���
            return *this; // �ڱ� �ڽ��� ��ȯ�Ͽ� ���������� ������ ��� �����ϵ��� ��
        }

        // ���� ��� ������ �����ε�
        ostream& operator<< (char str)
        {
            printf("%c", str); // ���ڸ� ���
            return *this; // �ڱ� �ڽ��� ��ȯ�Ͽ� ���������� ������ ��� �����ϵ��� ��
        }

        // ���� ��� ������ �����ε�
        ostream& operator<< (int num)
        {
            printf("%d", num); // ������ ���
            return *this; // �ڱ� �ڽ��� ��ȯ�Ͽ� ���������� ������ ��� �����ϵ��� ��
        }

        // �Ǽ� ��� ������ �����ε�
        ostream& operator<< (double e)
        {
            printf("%g", e); // �Ǽ��� ���
            return *this; // �ڱ� �ڽ��� ��ȯ�Ͽ� ���������� ������ ��� �����ϵ��� ��
        }

        // �Լ� �����͸� ���� ������ �����ε�
        ostream& operator<< (ostream& (*fp)(ostream& ostm))
        {
            return fp(*this); // �Լ� �����͸� ���� ���ǵ� �Լ��� ȣ���Ͽ� ��ȯ
        }
    };

    // ����� ���� endl �Լ�
    ostream& endl(ostream& ostm)
    {
        ostm << '\n'; // ���� ���� ���
        fflush(stdout); // ��� ���۸� ���
        return ostm; // ostream ��ü ��ȯ
    }

    ostream cout; // ����� ���� ostream ��ü
}

int main(void)
{
    using mystd::cout; // mystd ���ӽ����̽��� cout ���
    using mystd::endl; // mystd ���ӽ����̽��� endl ���
    cout << 3.14 << endl << 123 << endl; // �Ǽ�, ���� ��� �� ���� ����
    return 0;
}

/*
����� ���� ostream Ŭ������ endl �Լ�:
mystd ���ӽ����̽� ���� ostream Ŭ������ endl �Լ��� ���ǵǾ� �ֽ��ϴ�.
ostream Ŭ������ ����ڰ� ������ ��� ��Ŀ� ���� �پ��� ������ ������ ����� �� �ֵ��� �����ڸ� �����ε��մϴ�.
endl �Լ��� ��� ��Ʈ���� ���� ���ڸ� �߰��ϰ� ��� ���۸� ���� ������ �մϴ�.

���� �Լ� �����͸� ���� ������ �����ε�:
�Լ� �����͸� ���� ostream Ŭ������ ����� ���� ��� �Լ��� �߰��մϴ�. �̴� cout << endl�� ���� ���·� ���˴ϴ�.

����� ���� ��� ���:
����ڴ� mystd::cout�� mystd::endl�� ����Ͽ� �����͸� ����� �� �ֽ��ϴ�.
*/