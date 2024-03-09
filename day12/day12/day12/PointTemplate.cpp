#include <iostream>
#include "PointTemplate.h" // "PointTemplate.h" 헤더 파일을 포함함.
using namespace std;

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{  }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

/*
1. <iostream> 헤더 파일을 포함하여 입출력 기능을 사용할 수 있음.

2. "PointTemplate.h" 헤더 파일을 포함하여 Point 클래스 템플릿의 선언을 가져옴.

3. 생성자는 Point 클래스의 멤버 함수이며, 
	-> Point 템플릿의 멤버 함수임을 나타내기 위해 template <typename T>로 시작함.

4. Point<T>::Point(T x, T y)는 Point 클래스 템플릿의 생성자를 정의함. 
	-> 생성자는 xpos와 ypos 멤버 변수를 인자 x와 y로 초기화함.

5. 초기화 리스트를 사용하여 xpos(x)와 ypos(y)를 초기화함.

6. void Point<T>::ShowPosition() const는 Point 클래스 템플릿의 ShowPosition 멤버 함수를 정의함. 
	-> 이 함수는 좌표를 출력함.

7. const 한정자가 있는데, 
	-> 이는 멤버 함수가 객체의 내부 상태를 변경하지 않음을 나타냄.

8. cout << '[' << xpos << ", " << ypos << ']' << endl;은 xpos와 ypos를 출력하여 좌표를 표시함.

*/