#include <iostream>	

namespace mystd
{
    using namespace std;

    // ����� ���� ostream Ŭ���� ����
    class ostream
    {
    public:
        // ���ڿ� ��� ������ �����ε�
        void operator<< (char* str)
        {
            printf("%s", str); // ���ڿ��� ���
        }

        // ���� ��� ������ �����ε�
        void operator<< (char str)
        {
            printf("%c", str); // ���ڸ� ���
        }

        // ���� ��� ������ �����ε�
        void operator<< (int num)
        {
            printf("%d", num); // ������ ���
        }

        // �Ǽ� ��� ������ �����ε�
        void operator<< (double e)
        {
            printf("%g", e); // �Ǽ��� ���
        }

        // �Լ� �����͸� ���� ������ �����ε�
        void operator<< (ostream& (*fp)(ostream& ostm))
        {
            fp(*this); // �Լ� �����͸� ���� ���ǵ� �Լ��� ȣ���Ͽ� ����
        }
    };

    // ����� ���� endl �Լ�
    ostream& endl(ostream& ostm)
    {
        ostm << '\n'; // ���� ���� ���
        fflush(stdout); // ��� ���� ����
        return ostm; // ostream ��ü ��ȯ
    }

    ostream cout; // ����� ���� ostream ��ü
}

int main(void)
{
    using mystd::cout; // mystd ���ӽ����̽��� cout ���
    using mystd::endl; // mystd ���ӽ����̽��� endl ���

    cout << "Simple String"; // ���ڿ� ���
    cout << endl; // ���� ���
    cout << 3.14; // �Ǽ� ���
    cout << endl; // ���� ���
    cout << 123; // ���� ���
    endl(cout); // ���� ���

    return 0;
}

/*
����� ���� ostream Ŭ������ endl �Լ�:

mystd ���ӽ����̽� ���� ostream Ŭ������ endl �Լ��� ���ǵǾ� �ֽ��ϴ�.
ostream Ŭ������ ����ڰ� ������ ��� ��Ŀ� ���� �پ��� ������ ������ ����� �� �ֵ��� �����ڸ� �����ε��մϴ�.
endl �Լ��� ��� ��Ʈ���� ���� ���ڸ� �߰��ϰ� ��� ���۸� ���� ������ �մϴ�.

������ �����ε��� ��ȯ��:

������ �����ε� �Լ����� ��ȯ���� void�� �Ǿ� �ֽ��ϴ�.
�̴� ������ �����ε��� �������� ��뿡 ���� ȣ��Ǵ� ��쿡�� �� �۵��ϵ��� �մϴ�.

���� �Լ� �����͸� ���� ������ �����ε�:
�Լ� �����͸� ���� ostream Ŭ������ ����� ���� ��� �Լ��� �߰��մϴ�.
�̴� cout << endl�� ���� ���·� ���˴ϴ�.

����� ���� ��� ���:
����ڴ� mystd::cout�� mystd::endl�� ����Ͽ� �����͸� ����� �� �ֽ��ϴ�.
*/