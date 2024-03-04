#include <iostream>
#include <cstring>
using namespace std;

// ��� ������ ǥ���ϴ� Person Ŭ���� ����
class Person {
private:
    char* name; // �̸��� �����ϴ� ���ڿ� ������

public:
    // ������: �̸��� �޾Ƽ� �������� �޸� �Ҵ��Ͽ� ����
    Person(char* myname)
    {
        name = new char[strlen(myname) + 1]; // ���ڿ� ���� + �� ����('\0') ���� �Ҵ�
        strcpy(name, myname); // ���� �̸��� �����Ͽ� ����
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~Person()
    {
        delete[] name; // �������� �Ҵ�� �޸� ����
    }

    // �̸��� ����ϴ� �Լ�
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
};

// ���л� ������ ǥ���ϴ� UnivStudent Ŭ���� ����, Person Ŭ������ ���
class UnivStudent : public Person {
private:
    char* major; // ������ �����ϴ� ���ڿ� ������

public:
    // ������: �̸��� ������ �޾� �ʱ�ȭ, Person Ŭ������ ������ ȣ��
    UnivStudent(char* myname, char* mymajor)
        : Person(myname) // Person Ŭ������ ������ ȣ��
    {
        major = new char[strlen(mymajor) + 1]; // ���ڿ� ���� + �� ����('\0') ���� �Ҵ�
        strcpy(major, mymajor); // ���� ������ �����Ͽ� ����
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~UnivStudent()
    {
        delete[] major; // �������� �Ҵ�� �޸� ����
    }

    // �ڽ��� �̸��� ������ ����ϴ� �Լ�
    void WhoAreYou() const
    {
        WhatYourName(); // ��ӹ��� Person Ŭ������ �Լ� ȣ��
        cout << "My major is " << major << endl << endl;
    }
};

// ���� �Լ�
int main(void)
{
    // ���л� ��ü ���� �� �ʱ�ȭ
    UnivStudent st1("Kim", "Mathematics");
    st1.WhoAreYou(); // ��ü�� �̸��� ���� ���

    // �ٸ� ���л� ��ü ���� �� �ʱ�ȭ
    UnivStudent st2("Hong", "Physics:)");
    st2.WhoAreYou(); // ��ü�� �̸��� ���� ���

    return 0;
}

/*
Person Ŭ����:

�̸��� �������� �Ҵ�޾� �����ϴ� Ŭ�����Դϴ�.
�����ڿ��� �̸��� �޾� �������� �޸𸮸� �Ҵ��ϰ� �����Ͽ� �����ϸ�,
�Ҹ��ڿ��� �������� �Ҵ�� �޸𸮸� �����մϴ�.

UnivStudent Ŭ����:

���л� ������ ǥ���ϴ� Ŭ������, Person Ŭ������ ����մϴ�.
�����ڿ��� �̸��� ������ �޾� �ʱ�ȭ�ϰ�,
�Ҹ��ڿ��� �������� �Ҵ�� �޸𸮸� �����մϴ�.

WhoAreYou() �Լ��� ���� ��ü�� �̸��� ������ ����մϴ�.
�� �ڵ�� �������� �Ҵ�� ���ڿ��� �ٷ�� ������,
��ü�� ������ �� �Ҵ�� �޸𸮸� �����ϰ� �����ϴ� ���� �߿��մϴ�.
Ŭ������ �Ҹ��ڸ� ����Ͽ� �޸� ������ �����մϴ�.
*/