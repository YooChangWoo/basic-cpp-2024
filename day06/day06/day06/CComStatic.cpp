#include <iostream>
using namespace std;

// counter �Լ� ����
void counter()
{
    // ���� ���� ���� cnt ���� �� �ʱ�ȭ
    static int cnt;

    // int cnt = 0; -> �ؿ� ���� ����
    // cnt ���� ����
    cnt++;
    // cnt �� ���
    cout << "Current cnt: " << cnt << endl;
}

// ���� �Լ�
int main(void)
{
    // 10�� �ݺ��ϴ� for ����
    for (int i = 0; i < 10; i++)
        counter(); // counter �Լ� ȣ��
    return 0;
}

/* �߰� ����
1. counter() �Լ� ���� ���ǵ� ���� ���� ���� cnt�� �ش� �Լ��� ó�� ȣ��� �� �ʱ�ȭ��.
    -> �� �Ŀ��� �Լ��� ����Ǵ��� cnt ������ ���� ������.

2. �� counter() �Լ� ȣ�⸶�� cnt ������ �����ϸ�, ȣ�� Ƚ���� ���� ��.

3. main() �Լ������� for ������ ���� counter() �Լ��� 10�� ȣ���.
    -> �� ȣ�⸶�� cnt ������ �����ǰ�, �� ���� ��µ�.

4. ���� ��� ����� ȣ�� Ƚ���� ���� 1���� 10���� �����ϴ� ���ڵ��� ��
*/

/* static int cnt; �� ��������, int cnt=0; �� ���� ����
1. int cnt = 0;: counter() �Լ� ���� cnt�� ���� ������ �����ϰ� �ʱ�ȭ.
    -> ���� cnt�� �Լ��� ȣ��� ������ ���ο� ������ ������.

2. �� counter() �Լ� ȣ�⸶�� cnt ������ 1�� �ʱ�ȭ�ǰ�, 1�� ��µ�.
    -> �Լ��� ����Ǹ鼭 ���� cnt�� �������,
    --> ���� ȣ�� �ÿ��� �ٽ� 1�� �ʱ�ȭ��.

3. ���� ��� ����� 1�� ��Ÿ���� ��.
    -> ȣ�� Ƚ���� �����Ϸ��� �������� �������� ����.
    --> ���� cnt�� �׻� 1�� �ʱ�ȭ�Ǳ� ������ ȣ�� Ƚ���� ������ �� ����
*/