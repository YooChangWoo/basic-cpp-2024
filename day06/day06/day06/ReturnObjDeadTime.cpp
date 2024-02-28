#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    // ������: ��ü�� ������ �� ȣ��Ǹ�, ��� ������ �ʱ�ȭ�մϴ�.
    SoSimple(int n) : num(n)
    {
        cout << "New Object: " << this << endl; // ��ü�� ������ �� �ּ� ���
    }

    // ���� ������: �ٸ� ��ü�κ��� ��ü�� ������ �� ȣ��Ǹ�, ��� ������ �����մϴ�.
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "New Copy obj: " << this << endl; // ����� ��ü�� ������ �� �ּ� ���
    }

    // �Ҹ���: ��ü�� �Ҹ�� �� ȣ��Ǹ�, �޸� ���� �ڿ��� �����մϴ�.
    ~SoSimple()
    {
        cout << "Destroy obj: " << this << endl; // ��ü�� �Ҹ�� �� �ּ� ���
    }
};

// �Լ� ����: SoSimple ��ü�� ���ڷ� �޾Ƽ� ó���� �� �ٽ� ��ȯ�մϴ�.
SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR: " << &ob << endl; // �Լ� ������ ���� ��ü�� �ּ� ���
    return ob; // ���� ��ü�� �״�� ��ȯ
}

int main(void)
{
    // ��ü ����
    SoSimple obj(7);

    // �Լ� ȣ��: ��ü�� ���ڷ� �����ϰ�, ��ȯ�� ��ü�� ���ο� ��ü�� �Ҵ��մϴ�.
    SimpleFuncObj(obj);

    cout << endl;

    // �Լ� ȣ��: ��ü�� ���ڷ� �����ϰ�, ��ȯ�� ��ü�� ���ο� ��ü�� �Ҵ��մϴ�.
    SoSimple tempRef = SimpleFuncObj(obj);
    cout << "Return Obj" << &tempRef << endl; // ��ȯ�� ��ü�� �ּ� ���

    return 0;

/*

New Object: 000000485915F884        ��ü obj �ּ�
New Copy obj: 000000485915F984      ��ü ob �ּ�
Parm ADR: 000000485915F984          ��ü ob �ּ�
New Copy obj: 000000485915F9C4      �ӽ� ��ü �ּ�
Destroy obj: 000000485915F984       ��ü ob �Ҹ�
Destroy obj: 000000485915F9C4       �ӽ� ��ü �Ҹ�

New Copy obj: 000000485915F9E4      ��ü ob �ּ�
Parm ADR: 000000485915F9E4          ��ü ob �ּ�
New Copy obj: 000000485915F8A4      �ӽ� ��ü �ּ�
Destroy obj: 000000485915F9E4       ��ü ob �Ҹ�
Return Obj000000485915F8A4          �ӽ� ��ü �ּ�
Destroy obj: 000000485915F8A4       �ӽð�ü �Ҹ�
Destroy obj: 000000485915F884       ��ü obj �Ҹ�

*/

/* �߰� ����
1. SoSimple Ŭ������ �ϳ��� ������ ��� ���� num�� ������ ����.

2. ������ SoSimple(int n)�� ��ü�� ������ �� ȣ��Ǹ�,
-> ��� ���� num�� ���� n���� �ʱ�ȭ��.

3. AddNum(int n) �Լ��� �Ű������� ���� ���� n�� ���� ��ü�� num�� ���� ��,
-> �ڽ��� ��ü�� ��ȯ��. �� �Լ��� ��ü�� ���� ���¸� �����ϴ� ����.

4. ShowData() �Լ��� ���� ��ü�� num ���� �����.
-> �� �Լ��� ��ü�� ���� ���¸� �о���� ����.

5. main() �Լ������� ��� ��ü obj�� �����ϰ�, �� ��ü�� num ���� �����.
-> ��� ��ü�� �� �� �����Ǹ� ������ �� ���� ������ AddNum() �Լ��� ȣ���Ϸ��� �ϸ� ������ ������ �߻���.
*/