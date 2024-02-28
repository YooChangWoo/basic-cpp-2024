#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name; // �̸��� �����ϴ� ���ڿ� ������
    int age;    // ���̸� �����ϴ� ����

public:
    // ������
    Person(const char* myname, int myage) : age(myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy_s(name, len, myname);
    }

    // ���� ������
    Person(const Person& other) : age(other.age) {
        int len = strlen(other.name) + 1;
        name = new char[len];
        strcpy_s(name, len, other.name);
    }

    // �Ҹ���
    ~Person() {
        delete[] name;
        cout << "�Ҹ��� ȣ���!!" << endl;
    }

    // ���� ���� ���
    void ShowPersonInfo() const {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
        cout << endl;
    }
};

int main() {
    Person man1("Hong", 29);
    Person man2 = man1; // ���� ������ ȣ��
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}

    /* �߰� ����
    1. ������ (Constructor):
        - Person Ŭ������ �����ڴ� �̸��� ���̸� �Ű������� ����.
        -���� �Էµ� �̸��� ���̿� 1�� ���� ��ŭ �������� �޸𸮸� �Ҵ���.
            --> �̴� ���ڿ��� ���� ǥ���ϴ� �� ����('\0')�� ����� ��.
        - �� ��, strcpy_s �Լ��� ����Ͽ� �Էµ� �̸��� �������� �Ҵ�� �޸𸮿� ����.


    2. �Ҹ��� (Destructor):
        - Person Ŭ������ �Ҹ��ڴ� �������� �Ҵ�� �޸𸮸� ������.
            --> delete[]�� ����Ͽ� name�� ����Ű�� �޸𸮸� ������.

    3. ���� ������ (Copy Constructor):
        - ���� �����ڴ� ��ü�� �ٸ� ��ü�� �ʱ�ȭ�� �� ȣ���.
        - Person Ŭ������ ���� �����ڴ� �ٸ� ��ü�� �̸��� ���̸� �����ͼ� ���ο� �޸𸮸� �Ҵ��ϰ�, �ش� ������ ������.

    4. ���� ���� ��� (ShowPersonInfo):
        - ShowPersonInfo �Լ��� ��ü�� �̸��� ���̸� �����.

    5. �ֿ� ����Ʈ:
        - �������� �Ҵ�� �޸𸮸� ����ϴ� ���, �ݵ�� �޸𸮸� �����ؾ� ��.
            --> �̸� ���� �Ҹ��ڸ� �����.
        - ���� �����ڸ� ������ ���� ���� ����(shallow copy)�� �ƴ� ���� ����(deep copy)�� �ؾ���.
            --> �� ���������� �������� �Ҵ�� ���ڿ��� �ٷ�� �����Ƿ�, ���� ���縦 ������.

    */