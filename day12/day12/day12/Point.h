#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // 2차원 좌표를 나타내는 두 개의 private 멤버 변수
public:
    Point(int x = 0, int y = 0); // 생성자 선언
    friend ostream& operator<<(ostream& os, const Point& pos); // operator<< 함수를 friend로 선언하여 접근 권한을 부여함.
};

#endif

/*
1. Point 클래스를 선언함. 이 클래스는 2차원 좌표를 나타냄.

2. int xpos, ypos;: 두 개의 private 멤버 변수로, 각각 x축과 y축 좌표를 나타냄.

3. Point(int x = 0, int y = 0);: 생성자를 선언함. 
    -> 기본값을 설정하여 인자 없이 객체를 생성할 때 0, 0 좌표로 초기화할 수 있도록 함.

4. friend ostream& operator<<(ostream& os, const Point& pos);: operator<< 함수를 friend로 선언하여 클래스 외부에서 해당 함수에 접근할 수 있도록 함. 
    -> 이 함수는 스트림 출력을 위해 좌표를 출력할 것임.
*/