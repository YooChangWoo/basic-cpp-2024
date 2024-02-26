#include <iostream>
#include "Rectangle.h"
using namespace std;

// Rectangle 클래스 멤버 함수 정의

// 직사각형 멤버 변수 초기화 함수
bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
    // 상단 좌표의 x값이 우하단 좌표의 x값보다 크거나, 상단 좌표의 y값이 0보다 클 경우
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        cout << "잘못된 위치정보 전달" << endl;
        return false; // 초기화 실패를 반환합니다.
    }
    // 상단 좌표와 우하단 좌표를 멤버 변수에 설정합니다.
    upLeft = ul;
    lowRight = lr;
    return true; // 초기화 성공을 반환합니다.
}

// 직사각형 정보 출력 함수
void Rectangle::ShowRecInfo() const
{
    // 직사각형의 상단 좌표와 우하단 좌표를 출력합니다.
    cout << "상단 좌표: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;
    cout << "우 하단 좌표: " << '[' << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << ']' << endl << endl;
}