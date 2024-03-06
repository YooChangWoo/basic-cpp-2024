#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name; // ���ڿ��� ������ ���� �޸𸮸� ����Ű�� ������
    int age; // ���̸� �����ϴ� ����
public:
    // ������ ����
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1; // ���ڿ� ���� ���
        name = new char[len]; // ���� �޸� �Ҵ�
        strcpy(name, myname); // ���ڿ� ����
        age = myage; // ���� ����
    }

    Person& operator=(const Person& ref)
    {
        delete[]name;

        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }

    // ���� ���� ��� �Լ� (��� ��� �Լ��� ����)
    void ShowPersonInfo() const
    {
        cout << "�̸� :" << name << endl;
        cout << "���� :" << age << endl;
    }
    // �Ҹ��� ����
    ~Person()
    {
        delete[] name; // �������� �Ҵ�� �޸� ����
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong Woo", 29); // Person Ŭ������ ��ü man1 ���� �� �ʱ�ȭ
    Person man2("Yoon ji yul", 22); // Person Ŭ������ ��ü man2 ���� �� �ʱ�ȭ
    man2 = man1; // ��ü man1�� ��ü man2�� ����

    man1.ShowPersonInfo(); // man1�� ���� ���
    man2.ShowPersonInfo(); // man2�� ���� ���
    return 0;
}

/*
���� ����(Depth Copy):

Person Ŭ������ �������� �Ҵ�� ���ڿ��� �����ͷ� ������ �ֽ��ϴ�.
���� ���� �����ڿ� �Ҵ� �����ڰ� ������ ���� ���簡 �̷�����ϴ�.
man2 = man1;�� ���� ���� ���꿡���� ��ü�� �ּҰ� ����˴ϴ�.
�̰��� �� ��ü�� ������ �޸� ������ ����Ű�� �Ǵ� ���� ����� �̾����ϴ�.

�Ҹ���(Destructor):

Ŭ������ ���� �Ҵ�� �޸𸮰� ������ �Ҹ��ڸ� �����Ͽ� �޸� ������ �����ؾ� �մϴ�.
Person Ŭ������ �Ҹ��ڿ����� �������� �Ҵ�� name �迭�� �����մϴ�.
�� ���α׷������� man1�� man2�� �������� ��� �� �Ҹ��ڰ� ȣ��Ǿ� �޸� ������ �����մϴ�.

���ڿ� ó��:

strcpy �Լ��� ����Ͽ� ���ڿ��� �����մϴ�. �� �Լ��� �� ���� ���ڱ��� �����մϴ�.
���ڿ��� �ٷ� �� �޸� �Ҵ�� ������ �����ؾ� �մϴ�.

���� �������� ����:

Ŭ������ ���� �����ڰ� ���ǵ��� �ʾ����Ƿ� �⺻ ���� �����ڰ� ���˴ϴ�.
�� ��� ���� ���簡 ����Ǿ� name �����͸� ����ǹǷ� �� ��ü�� ������ �޸𸮸� ����Ű�� �˴ϴ�.
*/