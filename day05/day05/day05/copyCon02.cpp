#include <iostream>
#include <iostream>
using namespace std;

class AA {
    int a;
    int b;

public:
    // ������: ��� ���� a�� b�� ���ڷ� �޾� �ʱ�ȭ�մϴ�.
    AA(int a, int b) {
        this->a = a; // this �����͸� ����Ͽ� ��� ������ �����մϴ�.
        this->b = b;
    }

    // ��ü ������ ����ϴ� �޼���
    void AAInfo() {
        cout << a << " " << b << endl;
    }
};

int main() {
    AA obj1(10, 20); // AA Ŭ������ ��ü obj1�� �����ϰ� (10, 20)���� �ʱ�ȭ�մϴ�.
    obj1.AAInfo(); // obj1�� ������ ����մϴ�.

    // obj1�� �����Ͽ� obj2�� �����մϴ�.
    // ���� �����ڸ� �������� �ʾ�����, �����Ϸ��� �ڵ����� �������ݴϴ�.
    AA obj2(obj1);
    obj2.AAInfo(); // obj2�� ������ ����մϴ�.

    return 0;
}
