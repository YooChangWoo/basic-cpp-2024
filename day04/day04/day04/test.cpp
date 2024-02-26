#include <iostream>
using namespace std;

class StudentClass {
	const int ID;              // const를 이용하여 상수화 시킴
	char name[20];             // 문자열배열을 선언하고 바로 초기화하지 않는 경우는 strcpy()를 통하여 초기화 한다.
	char major[20];
	int age;

public:
	// 문자열은 주소기 때문에 포인트 변수에 넣어서 사용한다.  -문자열의 첫번째 문자 주소가 저장된다-
	// 멤버이니셜라이즈는 객체 생성시 초기화되지 않는 멤버들을 초기화 할때 사용한다. 즉 객체 생성과 상관없이 미리 초기화가 되는 멤버들에 초기화
	StudentClass(int aID,const char* aname,const char* amajor, int aage) : ID(aID) // 멤버 이니셜라이즈
	{
		//ID = aID;
		strcpy(name, aname);     // 문자열배열을 선언하고 바로 초기화하지 않는 경우는 strcpy()를 통하여 초기화 한다.
		strcpy(major, amajor);   
		age = aage
	}
	
	void ShowInfo() const {
		cout << "학번 ->" << ID << endl;
		cout << "이름 ->" << name << endl;
		cout << "전공 ->" << major << endl;
		cout << "나이 ->" << age << endl;
	}
};


int main()
{
	StudentClass student1(100, "유창우", "스포츠과학", 31);   // 객체를 생성하면 생성자를 호출해야한다.
	
	student1.ShowInfo();

	return 0;
}

// 추가 설명:
   // strcpy => string copy의 줄임말, 함수는 어떤 변수(메모리) or 
   //문자열 상수에 저장 되어있는 문자열을 다른 변수(메모리) 복사할 때 사용
   // strcpy_s => strcpy함수의 단점을 보완하기 위해서 만들어진 함수
   // -> 유사하지만, dest변수와 src변수 사이에 dest가 가리키는 메모리의 크기를 적는 매개 변수가 추가.

/*
1. private:
-> private으로 선언된 멤버는 클래스 외부에서 접근할 수 없으며, 오직 클래스 내부의 멤버 함수에서만 접근할 수 있음.
--> 즉, 해당 멤버는 클래스의 구현에만 영향을 미치며 외부에서는 숨겨져 있음.

2. public:
-> public으로 선언된 멤버는 클래스 외부에서도 접근할 수 있음.
--> 따라서 클래스를 사용하는 코드에서 해당 멤버에 직접 접근하여 값을 읽거나 변경할 수 있음.
*/