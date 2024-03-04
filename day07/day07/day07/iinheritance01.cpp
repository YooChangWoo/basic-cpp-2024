#define _CRT_SECURE_NO_
#include <iostream>
using namespace std;

// Person Ŭ���� ����
class Person
{
private:
    char name[50]; // �̸��� �����ϴ� ���ڿ� �迭
    int age;       // ���̸� �����ϴ� ���� ����

public:
    // ������: �̸��� ���̸� �޾� ��� ������ �ʱ�ȭ
    Person(const char* myname, int myage)
    {
        age = myage;
        strcpy(name, myname);
    }

    // �̸��� ����ϴ� ��� �Լ�
    void whatYouName() const {
        cout << "My name is " << name << endl;
    }

    // ���̸� ����ϴ� ��� �Լ�
    void howOldArtYou() const {
        cout << "I'm " << age << " years old" << endl;
    }
};

// UnivStudent Ŭ���� ����, Person Ŭ������ ���
class UnivStudent : public Person {
    string major; // ������ �����ϴ� ���ڿ� ����

public:
    // ������: �̸�, ����, ������ �޾� �ʱ�ȭ, �θ� Ŭ������ ������ ȣ��
    UnivStudent(char* myname, int myage, string major) : Person(myname, myage) {
        cout << "�ڽ� ������ ȣ��" << endl;
        this->major = major;
    }

    // �ڽ��� �̸��� ���̸� ����ϴ� �Լ��� ȣ���ϴ� �Լ�
    void WhoAreYour() const {
        whatYouName(); // �θ� Ŭ������ �̸� ��� �Լ� ȣ��
        howOldArtYou(); // �θ� Ŭ������ ���� ��� �Լ� ȣ��
    }
};

int main()
{
    // UnivStudent ��ü ���� �� �ʱ�ȭ
    UnivStudent s("ȫ�浿", 50, "���");

    // ��ü�� �̸��� ���̸� ����ϴ� �Լ� ȣ��
    s.WhoAreYour();

    return 0;
}

/*
Person Ŭ����:

�̸��� ���̸� �����ϴ� ��� ������ ������ �ֽ��ϴ�.
�����ڸ� ���� �̸��� ���̸� �޾� ��� ������ �ʱ�ȭ�մϴ�.
�̸��� ���̸� ����ϴ� ��� �Լ��� �����մϴ�.

UnivStudent Ŭ����:

Person Ŭ������ ��ӹ޽��ϴ�.
������ �߰������� �����ϴ� ��� ������ ������ �ֽ��ϴ�.
�����ڸ� ���� �̸�, ����, ������ �޾� �ʱ�ȭ�մϴ�.
�̶�, �θ� Ŭ������ �����ڸ� ȣ���մϴ�.
�θ� Ŭ�������� ��ӹ��� ��� �Լ��� ȣ���Ͽ� �̸��� ���̸� ����ϴ� �Լ��� �����մϴ�.

main() �Լ�:

UnivStudent Ŭ������ ��ü�� �����ϰ� �ʱ�ȭ�մϴ�.
��ü�� �̸��� ���̸� ����ϴ� �Լ��� ȣ���մϴ�.
�̶�, �θ� Ŭ������ Person Ŭ������ ��� �Լ��� ȣ��˴ϴ�.
�� ���������� Ŭ������ ����� ���� ��ü ���� ���α׷����� �⺻ ������ �����ݴϴ�.
Ŭ������ ����� ���� �ڵ��� ���뼺�� �������� ��������,
��ü�� ���踦 ��Ȯ�ϰ� ǥ���� �� �ֽ��ϴ�.
*/