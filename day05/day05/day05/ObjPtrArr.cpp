#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(char* myname, int myage)   // ������ �����ε�
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()      //����Ʈ ������
    {
        name = NULL;
        age = 0;
        cout << "Called Person" << endl;
    }
    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "�̸�: " << name << ",";
        cout << "����: " << age << endl;
    }
    ~Person()
    {
        delete[]name;
        cout << "called destrutor!" << endl;
    }
};

int main(void)
{
	Person * parr[3];            // ��ü ����Ʈ �迭
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�:";
		cin >> namestr;
		cout << "����: ";
		cin >> age;

		parr[i] = new Person(namestr, age);    // �� ������ ��ü�� �����Ѵ�.
	}
    // -> ���ο� ������
	parr[0]->ShowPersonInfo();        // ��ü ����Ʈ�� ������ ����� �����Ѵ�.(->)
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}
