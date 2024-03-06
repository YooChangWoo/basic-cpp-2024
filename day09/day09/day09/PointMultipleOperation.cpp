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
};

int main(void)
{
	Point pos(1, 2); // 초기 좌표 (1, 2)를 가진 Point 객체 생성
	Point cpy; // 복사할 Point 객체 생성

	cpy = pos * 3; // pos의 좌표에 3을 곱하여 cpy에 할당
	cpy.ShowPosition(); // cpy의 좌표 출력: [3, 6]

	cpy = pos * 3 * 2; // pos의 좌표에 3을 곱하고 그 결과에 2를 곱하여 cpy에 할당
	cpy.ShowPosition(); // cpy의 좌표 출력: [6, 12]

	return 0;
}

/*
연산자 오버로딩:

Point 클래스에서 * 연산자를 오버로딩하여 정수를 받아서
현재 좌표에 곱한 값을 가지는 새로운 Point 객체를 반환합니다.

연산자 우선순위:

곱셈 연산자는 왼쪽에서 오른쪽으로 계산됩니다.
따라서 pos * 3 * 2는 ((pos * 3) * 2)로 계산됩니다.
먼저 pos * 3을 계산하여 새로운 Point 객체를 생성하고,
그 결과에 2를 곱하여 최종적으로 새로운 Point 객체가 생성됩니다.

*/