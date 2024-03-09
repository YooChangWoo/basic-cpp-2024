#include <iostream>
#include "ArrayTemplate.h" // BoundCheckArray 템플릿 클래스의 선언을 포함하는 헤더 파일을 포함함.
#include "Point.h" // Point 클래스의 선언을 포함하는 헤더 파일을 포함함.

using namespace std;

int main(void)
{
    /*** int형 정수 저장 ***/
    BoundCheckArray<int> iarr(5); // int 타입의 배열 객체 iarr을 생성함. 크기는 5.

    // 배열에 값을 할당한다.
    for (int i = 0; i < 5; i++)
        iarr[i] = (i + 1) * 11;

    // 배열에 저장된 값을 출력한다.
    for (int i = 0; i < 5; i++)
        cout << iarr[i] << endl;


    /*** Point 객체 저장 ***/
    BoundCheckArray<Point> oarr(3); // Point 객체를 저장하는 배열 객체 oarr을 생성함. 크기는 3.

    // 배열에 Point 객체를 할당함.
    oarr[0] = Point(3, 4);
    oarr[1] = Point(5, 6);
    oarr[2] = Point(7, 8);

    // 배열에 저장된 Point 객체의 좌표를 출력함.
    for (int i = 0; i < oarr.GetArrLen(); i++)
        cout << oarr[i];

    /*** Point 객체의 주소 값 저장 ***/
    typedef Point* POINT_PTR; // Point 포인터를 POINT_PTR이라는 별칭으로 정의함.
    BoundCheckArray<POINT_PTR> parr(3); // Point 포인터를 저장하는 배열 객체 parr을 생성함. 크기는 3이다.

    // 배열에 Point 객체의 주소 값을 할당함.
    parr[0] = new Point(3, 4);
    parr[1] = new Point(5, 6);
    parr[2] = new Point(7, 8);

    // 배열에 저장된 Point 객체의 좌표를 출력함.
    for (int i = 0; i < parr.GetArrLen(); i++)
        cout << *(parr[i]);

    // 동적으로 할당된 메모리를 해제함.
    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0; // 프로그램 종료
}
/*
1. #include <iostream>: 표준 입력과 출력을 위한 헤더 파일을 포함함.

2. "ArrayTemplate.h": BoundCheckArray 템플릿 클래스의 선언이 포함된 헤더 파일을 포함함.

3. "Point.h": Point 클래스의 선언이 포함된 헤더 파일을 포함함.

4. using namespace std;: 표준 라이브러리의 std 네임스페이스를 사용함.
*/