#include <iostream>
using namespace std;

class Myclass {
private:
	char name[30];
	int age;
public:
	Myclass(const char myname, int myage)
	{
		myage = age;
		strcpy(name, myname);
	}
	void whatYouName() const {
		cout << "My name is" << name << endl;
	}
	void howOldArtYou() const {
		cout << "my age is" << age << endl;
	}
};

class MyInfo : public Myclass {
private:
	char pNumber[20];
public:
	void printMyInfo() { const char * pNumber
		: pNumber
		:"���� �̸��� xxx �̰� ���̴� xx ���̸� ��ȭ��ȣ�� xxx �Դϴ�.";
	}
};

/*

*/