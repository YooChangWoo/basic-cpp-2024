#include <iostream>
using namespace std;

class AAA
{
public:
    AAA()
    {
        cout << "empty object" << endl; // AAA Ŭ������ ��ü�� ������ �� "empty object"�� ���
    }
    void ShowYourName()
    {
        cout << "I'm class AAA" << endl; // AAA Ŭ������ �̸��� ����ϴ� �Լ�
    }
};

class BBB
{
private:
    AAA& ref; // AAA Ŭ������ ������ ����Ű�� ��� ���� ref
    const int& num; // int�� ��� ������ ����Ű�� ��� ���� num

public:
    BBB(AAA& r, const int& n)
        : ref(r), num(n)
    {
        // BBB Ŭ������ ������, ref�� num�� �Ű������� �ʱ�ȭ
        // empty constructor body: ����ִ� ������ ����
    }
    void ShowYourName()
    {
        ref.ShowYourName(); // AAA Ŭ������ ShowYourName �Լ� ȣ��
        cout << "and" << endl; // "and" ���
        cout << "I ref num: " << num << endl; // num�� ���� ���
    }
};

int main(void)
{
    AAA obj1; // AAA Ŭ������ ��ü obj1 ����, "empty object" ���
    BBB obj2(obj1, 20); // BBB Ŭ������ ��ü obj2�� obj1�� 20���� ����
    obj2.ShowYourName(); // obj2�� ShowYourName �Լ� ȣ��
    return 0;
}

/*
* ������(Ŭ���� �̸��� ���� ����Լ��� ����� ����.)
	- ��ü ������ �ڵ����� ȣ�߷ε�� ����Լ�
	- ��� Ŭ������ ����Ʈ �����ڸ� ������ �ִ�.
	- ���� ��������� �����ڸ� �ۼ��ϸ� ����Ʈ �������� ȣ���� �Ұ��ϸ�
		����Ʈ �����ڰ� �ʿ��� ���� ��������� �ۼ��Ѵ�.
	- ����������� �ʱ�ȭ�� ����Ѵ�.

* ��� �̴ϼ� ������
	- ��ü �������� ����� ���ÿ� �ʱ�ȭ�� �ʿ��� ��쿡 ����Ѵ�.
	- const ������ ���������� �ʱ�ȭ�� ���
*/