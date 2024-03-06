#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos; // 2차원 좌표를 저장하는 private 멤버 변수
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) // 생성자, 기본값으로 (0,0)으로 초기화
	{  }

	void ShowPosition() const // 현재 좌표를 출력하는 멤버 함수
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times) // * 연산자를 오버로딩하여 좌표에 상수를 곱한 결과를 반환하는 멤버 함수
	{
		Point pos(xpos * times, ypos * times); // 현재 좌표에 상수를 곱한 새로운 Point 객체 생성
		return pos; // 새로운 Point 객체 반환
	}

	friend Point operator*(int times, Point& ref); // friend 선언을 통해 전역 함수로 연산자 오버로딩을 가능하게 함
};

Point operator*(int times, Point& ref)
{
	return ref * times; // 전역 함수에서는 멤버 함수로 연산을 위임하여 다시 연산 결과를 반환함
}

int main(void)
{
	Point pos(1, 2); // 초기 좌표 (1, 2)를 가진 Point 객체 생성
	Point cpy; // 복사할 Point 객체 생성

	cpy = 3 * pos; // 전역 함수를 통해 정수와 객체의 곱을 계산하여 cpy에 할당
	cpy.ShowPosition(); // cpy의 좌표 출력: [3, 6]

	cpy = 2 * pos * 3; // 전역 함수를 통해 계산되는 값과 객체의 곱을 연산하고, 그 결과에 다시 정수를 곱하여 cpy에 할당
	cpy.ShowPosition(); // cpy의 좌표 출력: [6, 12]

	return 0;
}

/*
전역 함수를 이용한 연산자 오버로딩:

전역 함수로 연산자 * 을 오버로딩하여, 정수와 Point 객체의 곱셈을 구현합니다.
전역 함수에서는 Point 클래스의 멤버 함수를 호출하여 연산 결과를 반환합니다.

연산자 우선순위와 연산 순서:

곱셈 연산자는 왼쪽에서 오른쪽으로 계산됩니다. 따라서 2 * pos * 3는 ((2 * pos) * 3)로 계산됩니다.
먼저 전역 함수를 통해 2와 pos를 곱한 결과를 계산하고, 그 결과에 다시 3을 곱하여 최종적으로 새로운 Point 객체가 생성됩니다.
*/