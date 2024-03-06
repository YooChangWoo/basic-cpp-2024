#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
private:
	int xpos, ypos; // x와 y 좌표
public:
	// 생성자: x와 y 좌표를 초기화
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }

	// 두 Point 객체를 더하는 연산자 오버로딩
	Point operator+(const Point& pos) const
	{
		// 현재 객체의 x 좌표와 다른 객체의 x 좌표를 더하고,
		// 현재 객체의 y 좌표와 다른 객체의 y 좌표를 더하여 새로운 Point 객체를 생성하여 반환
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	// ostream 연산자 오버로딩: Point 객체를 출력
	friend ostream& operator<<(ostream& os, const Point& pos);
};

// ostream 연산자 오버로딩 정의
ostream& operator<<(ostream& os, const Point& pos)
{
	// Point 객체의 좌표를 [x, y] 형태로 출력
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// Adder 클래스 정의
class Adder
{
public:
	// 정수형 두 수를 더하는 함수 호출 연산자 오버로딩
	int operator()(const int& n1, const int& n2)
	{
		// 두 정수를 더하여 결과 반환
		return n1 + n2;
	}

	// 실수형 두 수를 더하는 함수 호출 연산자 오버로딩
	double operator()(const double& e1, const double& e2)
	{
		// 두 실수를 더하여 결과 반환
		return e1 + e2;
	}

	// Point 객체 두 개를 더하는 함수 호출 연산자 오버로딩
	Point operator()(const Point& pos1, const Point& pos2)
	{
		// Point 클래스에서 정의한 operator+를 사용하여 두 Point 객체를 더함
		return pos1 + pos2;
	}
};

int main(void)
{
	// Adder 객체 생성
	Adder adder;

	// 정수형 덧셈 연산 결과 출력
	cout << adder(1, 3) << endl;

	// 실수형 덧셈 연산 결과 출력
	cout << adder(1.5, 3.7) << endl;

	// Point 객체를 더한 결과 출력
	cout << adder(Point(3, 4), Point(7, 9));

	return 0;
}
/*
연산자 오버로딩 (Operator Overloading):

클래스 내부의 연산자를 새로운 의미로 재정의하는 기법이며,
코드의 가독성을 높이고 사용자 정의 타입에 대한 표준 연산 지원을 가능하게 합니다.
Point 클래스에서 operator+를 오버로딩하여 두 점을 더할 수 있도록 하였습니다.
Adder 클래스에서는 함수 호출 연산자 ()를 여러 형태로 오버로딩하여 정수, 실수, 그리고 Point 객체에 대한 덧셈을 지원합니다.

함수 객체 (Function Object):

Adder 클래스는 함수처럼 동작하는 객체입니다.
Adder 클래스의 객체를 함수처럼 호출할 수 있으며,
이를 통해 다양한 타입의 데이터에 대한 연산을 수행할 수 있습니다.

스트림 출력 연산자의 오버로딩 (Overloading Stream Output Operator):

ostream& operator<<를 사용하여 사용자 정의 타입인 Point 객체를 출력할 수 있습니다.
이를 통해 사용자는 cout을 사용하여 Point 객체를 직접 출력할 수 있습니다.
*/