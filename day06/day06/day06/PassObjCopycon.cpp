#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // ������ �����ϴ� ��� ����

public:
    // ������
    SoSimple(int n) : num(n)
    { }

    // ���� ������
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }

    // �����͸� ����ϴ� ��� �Լ�
    void ShowData()                 // ��� �Լ� --> ��ü���� �� ��� ����
    {
        cout << "Num: " << num << endl;
    }
};

// ��ü�� �Ű������� �޴� �Լ�
void SimpleFuncObj(SoSimple ob)     // �����Լ� --> ���� �ҳ� �ٷ� ���ٰ���
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7); // ��ü ���� �� �ʱ�ȭ
    cout << "ȣ�� ��!! : " << endl;
    SimpleFuncObj(obj); // �Լ� ȣ�� �� ��ü ����
    cout << "�Լ� ȣ�� ��!! :" << endl;
    return 0;
}

/* �߰� ����
1. SoSimple Ŭ������ �ϳ��� int ��� ������ ����
2. SoSimple(int n) �����ڴ� ������ �Ű������� �޾� ��� ������ �ʱ�ȭ
3. SoSimple(const SoSimple& copy) ���� �����ڴ� �ٸ� ��ü�� �޾� �� ��ü�� ��� ������ �����Ͽ� �ʱ�ȭ
    -> �̶� ���� �����ڰ� ȣ��Ǿ��ٴ� �޽����� ���

4. ShowData() �Լ��� ��ü�� ��� ������ ���
5. SimpleFuncObj(SoSimple ob) �Լ��� SoSimple Ŭ������ ��ü�� �Ű������� �޾� �ش� ��ü�� �����͸� ���
6. main �Լ������� obj ��ü�� �����ϰ�, SimpleFuncObj �Լ��� ȣ���Ͽ� obj ��ü�� ����
    -> �Լ��� ȣ��� �� ��ü�� �����ϰ� �ǹǷ� ���� �����ڰ� ȣ��
*/
