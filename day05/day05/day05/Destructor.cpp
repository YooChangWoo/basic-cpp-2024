#include <iostream>
#include <cstring>
using namespace std;

class person
{
private:
	char* name; // 문자열을 저장하는 포인터
	int age; // 나이를 저장하는 변수

public:
	person(const char* myname, int myage) // 이름과 나이를 입력받는 생성자
	{   // strlen()문자의 길이를 나타내는 함수 //+1 : 문자열을 나타내는 것 nell 대신해서 들어감
		int len = strlen(myname) + 1; // 입력된 이름의 길이를 구하고 널 문자를 고려하여 1을 더합니다.
		name = new char[len]; // 동적 할당을 통해 이름을 저장할 메모리를 할당합니다.
		cout << "char 크기 : " << sizeof(char) << endl; // char의 크기를 출력합니다.
		strcpy(name, myname); // 입력된 이름을 할당된 메모리에 복사합니다.
		age = myage; // 나이를 할당합니다.
	}
	void ShowPersonInfo() const // 정보를 출력하는 함수
	{
		cout << "이름:" << name << endl; // 이름을 출력합니다.
		cout << "나이:" << age << endl; // 나이를 출력합니다.
	}
	~person() // 소멸자
	{
		delete[]name; // 동적으로 할당된 메모리를 해제합니다.
		cout << "called destructor!" << endl; // 소멸자가 호출되었음을 알립니다.
	}
};

int main(void)
{
	person man1("Yoo Chang Woo", 30); // person 클래스의 객체 man1을 생성하고 이름과 나이를 전달합니다.
	person man2("Lee dong WOO", 40); // person 클래스의 객체 man2을 생성하고 이름과 나이를 전달합니다.
	man1.ShowPersonInfo(); // man1의 정보를 출력합니다.
	man2.ShowPersonInfo(); // man2의 정보를 출력합니다.
	return 0;
}