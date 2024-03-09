#include <iostream>
#include "ArrayTemplate.h" // BoundCheckArray 템플릿 클래스가 정의된 헤더 파일을 포함함.
#include "PointTemplate.h" // Point 템플릿 클래스가 정의된 헤더 파일을 포함함.
using namespace std;

int main(void)
{
    // BoundCheckArray를 사용하여 Point<int> 객체를 저장하는 배열 생성
    BoundCheckArray<Point<int>> oarr1(3);
    oarr1[0] = Point<int>(3, 4); // 배열의 첫 번째 요소에 Point<int> 객체를 할당함.
    oarr1[1] = Point<int>(5, 6); // 배열의 두 번째 요소에 Point<int> 객체를 할당함.
    oarr1[2] = Point<int>(7, 8); // 배열의 세 번째 요소에 Point<int> 객체를 할당함.

    // 배열에 저장된 Point<int> 객체의 좌표를 출력합니다.
    for (int i = 0; i < oarr1.GetArrLen(); i++)
        oarr1[i].ShowPosition();

    // BoundCheckArray를 사용하여 Point<double> 객체를 저장하는 배열 생성
    BoundCheckArray<Point<double>> oarr2(3);
    oarr2[0] = Point<double>(3.14, 4.31); // 배열의 첫 번째 요소에 Point<double> 객체를 할당함.
    oarr2[1] = Point<double>(5.09, 6.07); // 배열의 두 번째 요소에 Point<double> 객체를 할당함.
    oarr2[2] = Point<double>(7.82, 8.54); // 배열의 세 번째 요소에 Point<double> 객체를 할당함.

    // 배열에 저장된 Point<double> 객체의 좌표를 출력함.
    for (int i = 0; i < oarr2.GetArrLen(); i++)
        oarr2[i].ShowPosition();

    // Point<int> 객체의 포인터를 저장하는 배열 생성
    typedef Point<int>* POINT_PTR; // Point<int> 객체의 포인터 타입 정의
    BoundCheckArray<POINT_PTR> oparr(3); // BoundCheckArray를 사용하여 POINT_PTR 타입의 배열 생성
    oparr[0] = new Point<int>(11, 12); // 배열의 첫 번째 요소에 Point<int> 객체의 동적 할당된 포인터를 할당함.
    oparr[1] = new Point<int>(13, 14); // 배열의 두 번째 요소에 Point<int> 객체의 동적 할당된 포인터를 할당함.
    oparr[2] = new Point<int>(15, 16); // 배열의 세 번째 요소에 Point<int> 객체의 동적 할당된 포인터를 할당함.

    // 배열에 저장된 Point<int> 객체의 좌표를 출력함.
    for (int i = 0; i < oparr.GetArrLen(); i++)
        oparr[i]->ShowPosition(); // 객체의 포인터를 통해 ShowPosition() 함수 호출

    // 동적으로 할당된 Point<int> 객체의 메모리를 해제함.
    delete oparr[0]; delete oparr[1]; delete oparr[2];

    return 0;
}

/*
1.  먼저 BoundCheckArray 템플릿 클래스를 사용하여 Point<int>와 Point<double> 객체를 저장하는 배열을 생성하고, 이를 출력함. 

2. 그리고 Point<int> 객체의 포인터를 저장하는 배열을 생성하여 동적으로 할당된 객체들을 생성하고 출력한 후, 메모리를 해제함.
*/