#include <iostream>
#include <cstring>
using namespace std;

class person
{
private:
	char* name; // ���ڿ��� �����ϴ� ������
	int age; // ���̸� �����ϴ� ����

public:
	person(const char* myname, int myage) // �̸��� ���̸� �Է¹޴� ������
	{   // strlen()������ ���̸� ��Ÿ���� �Լ� //+1 : ���ڿ��� ��Ÿ���� �� nell ����ؼ� ��
		int len = strlen(myname) + 1; // �Էµ� �̸��� ���̸� ���ϰ� �� ���ڸ� ����Ͽ� 1�� ���մϴ�.
		name = new char[len]; // ���� �Ҵ��� ���� �̸��� ������ �޸𸮸� �Ҵ��մϴ�.
		cout << "char ũ�� : " << sizeof(char) << endl; // char�� ũ�⸦ ����մϴ�.
		strcpy(name, myname); // �Էµ� �̸��� �Ҵ�� �޸𸮿� �����մϴ�.
		age = myage; // ���̸� �Ҵ��մϴ�.
	}
	void ShowPersonInfo() const // ������ ����ϴ� �Լ�
	{
		cout << "�̸�:" << name << endl; // �̸��� ����մϴ�.
		cout << "����:" << age << endl; // ���̸� ����մϴ�.
	}
	~person() // �Ҹ���
	{
		delete[]name; // �������� �Ҵ�� �޸𸮸� �����մϴ�.
		cout << "called destructor!" << endl; // �Ҹ��ڰ� ȣ��Ǿ����� �˸��ϴ�.
	}
};

int main(void)
{
	person man1("Yoo Chang Woo", 30); // person Ŭ������ ��ü man1�� �����ϰ� �̸��� ���̸� �����մϴ�.
	person man2("Lee dong WOO", 40); // person Ŭ������ ��ü man2�� �����ϰ� �̸��� ���̸� �����մϴ�.
	man1.ShowPersonInfo(); // man1�� ������ ����մϴ�.
	man2.ShowPersonInfo(); // man2�� ������ ����մϴ�.
	return 0;
}