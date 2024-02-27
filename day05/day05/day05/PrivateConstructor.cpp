#include <iostream>
using namespace std;

class AAA
{
private:
    int num; // ������ ��� ���� num
public:          
    AAA() : num(0) {} // �⺻ ������, num�� 0���� �ʱ�ȭ
    AAA& CreateInitObj(int n) const // n�� �޾Ƽ� AAA ��ü�� �����ϴ� �Լ�
    {          // ~AAA() []; : �Ҹ���
        AAA* ptr = new AAA(n); // n ���� �޾� ��ü�� ���� �Ҵ��Ͽ� ������ ptr�� ����
        return *ptr; // ��ü�� ���۷����� ��ȯ
    }
    void showNum() const { cout << num << endl; } // num�� ����ϴ� �Լ�
private:  // �̱����� ���� �� ����ϱ�
    AAA(int n) : num(n) {} // num�� n���� �ʱ�ȭ�ϴ� ������
    
};

int main(void)
{
    AAA base; // AAA Ŭ������ ��ü base ����, num�� 0���� �ʱ�ȭ��
    base.showNum(); // base ��ü�� num�� ���

    AAA& obj1 = base.CreateInitObj(3); // base�� �̿��Ͽ� AAA ��ü�� �����ϰ�, obj1�� ������ ����
    obj1.showNum(); // obj1 ��ü�� num�� ���

    AAA& obj2 = base.CreateInitObj(12); // base�� �̿��Ͽ� AAA ��ü�� �����ϰ�, obj2�� ������ ����
    obj2.showNum(); // obj2 ��ü�� num�� ���

    delete& obj1; // obj1�� �����ϴ� ��ü�� ����
    delete& obj2; // obj2�� �����ϴ� ��ü�� ����
    return 0;
}