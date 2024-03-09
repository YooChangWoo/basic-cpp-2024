#pragma once
#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template <typename T>
class Point
{
private:
    T xpos, ypos; // T 타입의 xpos와 ypos 멤버 변수

public:
    // 생성자: T 타입의 x와 y 값을 받아 xpos와 ypos를 초기화함.
    // 디폴트 인자를 사용하여, 인자가 전달되지 않을 경우 0으로 초기화함.
    Point(T x = 0, T y = 0);

    // 멤버 함수: xpos와 ypos를 출력함.
    void ShowPosition() const;
};


#endif

/*
1. template <typename T>: 클래스 정의 이전에 선언되어, Point 클래스가 템플릿 클래스임을 나타냄. 이로써 Point 클래스는 다양한 타입을 다룰 수 있다.

2. private 섹션에서는 xpos와 ypos라는 이름의 두 멤버 변수를 선언함. 
    -> 이 변수들의 타입은 템플릿 매개변수 T로, Point 객체 생성 시 결정됨.

3. public 섹션에서는 생성자와 ShowPosition이라는 멤버 함수를 선언함. 생성자는 객체가 생성될 때 xpos와 ypos를 초기화하고, 
    -> ShowPosition 함수는 객체의 좌표를 표시함.
*/