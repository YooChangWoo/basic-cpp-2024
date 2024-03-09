#pragma once
#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template <typename T>
class Point
{
private:
    T xpos, ypos; // 2차원 좌표를 나타내는 두 개의 private 멤버 변수
public:
    Point(T x = 0, T y = 0); // 생성자 선언
    void ShowPosition() const; // 좌표를 출력하는 함수 선언
};


template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{  }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

#endif

/*
1. Point 클래스 템플릿을 정의합니다. 이 클래스는 템플릿을 사용하여 다양한 데이터 타입을 처리할 수 있는 2차원 좌표를 나타냅니다.

2. T xpos, ypos;: 두 개의 private 멤버 변수로, 각각 x축과 y축 좌표를 나타냅니다.

3. Point(T x = 0, T y = 0);: 생성자를 선언합니다. 기본값을 설정하여 인자 없이 객체를 생성할 때 0, 0 좌표로 초기화할 수 있도록 합니다.

4. void ShowPosition() const;: 좌표를 출력하는 함수를 선언합니다. 이 함수는 객체의 좌표를 출력합니다. const 한정자를 사용하여 멤버 변수를 변경하지 않는다는 것을 나타냅니다.

5. 생성자와 ShowPosition 함수의 정의를 헤더 파일 내에 함께 포함합니다. 이렇게 함으로써 함수 템플릿을 구현합니다.

6. Point<T>::Point(T x, T y) : xpos(x), ypos(y) { }: 생성자를 정의합니다. 인자로 받은 좌표를 멤버 변수에 초기화합니다.

7. void Point<T>::ShowPosition() const: 좌표를 출력하는 함수를 정의합니다. const 한정자를 사용하여 멤버 변수를 변경하지 않는다는 것을 나타냅니다. 좌표를 출력할 때는 xpos와 ypos 값을 이용합니다.
*/