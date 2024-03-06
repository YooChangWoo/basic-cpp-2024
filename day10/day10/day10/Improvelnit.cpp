#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    // ���� �ϳ��� �Է����� �޴� ������
    AAA(int n = 0) : num(n)
    {
        cout << "AAA(int n=0)" << endl;
    }
    // ��ü �ϳ��� �Է����� �޴� ������
    AAA(const AAA& ref) : num(ref.num)
    {
        cout << "AAA(const AAA & ref)" << endl;
    }
    // ���� ������ �����ε�
    AAA& operator=(const AAA& ref)
    {
        num = ref.num;
        cout << "operator=(const AAA &ref)" << endl;
        return *this;
    }
};

class BBB
{
private:
    AAA mem; // AAA Ÿ���� ��� ����
public:
    // AAA Ÿ���� ��ü�� �Է����� �޴� ������
    BBB(const AAA& ref) : mem(ref)
    {  }
};

class CCC
{
private:
    AAA mem;
public:
    // AAA Ÿ���� ��ü�� �Է����� �޴� ������
    CCC(const AAA& ref)
    {
        mem = ref; // ���� ������ ���� �ʱ�ȭ
    }
};

int main(void)
{
    AAA obj1(12); // AAA Ŭ������ ��ü ����
    cout << "*********************" << endl;
    BBB obj2(obj1); // BBB Ŭ������ ��ü ����, ��� �̴ϼȶ������� ���� �ʱ�ȭ
    cout << "*********************" << endl;
    CCC obj3(obj1); // CCC Ŭ������ ��ü ����, ���� �����ڸ� ���� �ʱ�ȭ
    return 0;
}
/*
Ŭ���� AAA�� ���� �ϳ��� �޴� ������, ��ü �ϳ��� �޴� ������,
�׸��� ���� �����ڸ� �����ε��ϰ� �ֽ��ϴ�.

Ŭ���� BBB�� AAA Ŭ������ ����� ���� ������,
��� �̴ϼȶ������� ����Ͽ� AAA ��ü�� �ʱ�ȭ�մϴ�.

Ŭ���� CCC�� AAA Ŭ������ ����� ���� ������,
���� �����ڸ� ����Ͽ� AAA ��ü�� �ʱ�ȭ�մϴ�.

main �Լ������� ��ü�� �����ϰ� �ʱ�ȭ�ϴ� ������ �����ݴϴ�.
BBB Ŭ������ ��� �̴ϼȶ������� ����Ͽ� ��� ��ü�� �ʱ�ȭ�ϰ�,
CCC Ŭ������ ���� �����ڸ� ���� ��� ��ü�� �ʱ�ȭ�մϴ�.
*/