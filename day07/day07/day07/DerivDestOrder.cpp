#include <iostream>
using namespace std;

// 기반 클래스 정의
class SoBase
{
private:
	int baseNum; // 기반 클래스의 정수형 멤버 변수

public:
	// 기반 클래스의 생성자: baseNum을 초기화하고 메시지 출력
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}

	// 기반 클래스의 소멸자: 메시지 출력
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

// 파생 클래스 정의
class SoDerived : public SoBase
{
private:
	int derivNum; // 파생 클래스의 정수형 멤버 변수

public:
	// 파생 클래스의 생성자: 기반 클래스의 생성자를 호출하고 derivNum 초기화 및 메시지 출력
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}

	// 파생 클래스의 소멸자: 메시지 출력
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	// 파생 클래스 객체 생성과 동시에 생성자 호출
	SoDerived drv1(15);
	SoDerived drv2(27);

	return 0;
}

/*
SoBase(int n): 기반 클래스인 SoBase의 생성자입니다.
이 생성자는 정수형 인자를 받아서 baseNum 멤버 변수를 초기화하고, 객체가 생성될 때 해당 값을 출력합니다.

~SoBase(): 기반 클래스인 SoBase의 소멸자입니다.
이 소멸자는 객체가 소멸될 때 baseNum 멤버 변수의 값을 출력합니다.

SoDerived(int n): 파생 클래스인 SoDerived의 생성자입니다.
이 생성자는 먼저 기반 클래스인 SoBase의 생성자를 호출하고,
그 후에 파생 클래스의 derivNum 멤버 변수를 초기화하고, 생성된 값을 출력합니다.

~SoDerived(): 파생 클래스인 SoDerived의 소멸자입니다.
이 소멸자는 객체가 소멸될 때 derivNum 멤버 변수의 값을 출력합니다.

main() 함수에서는 SoDerived 클래스의 두 객체를 생성하고,
생성자와 소멸자가 호출되는 순서를 확인할 수 있습니다.
객체가 생성될 때는 생성자가 호출되며, 객체가 소멸될 때는 소멸자가 호출됩니다.
따라서 출력 결과를 통해 객체의 생성과 소멸 과정을 추적할 수 있습니다.
*/