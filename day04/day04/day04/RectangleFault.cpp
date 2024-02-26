#include <iostream>

using namespace std;

// 2차원 좌표를 표현하는 클래스
class Point
{
public:
    int x; // x 좌표
    int y; // y 좌표
};

// 직사각형을 표현하는 클래스
class Rectangle
{
public:
    Point upLeft;    // 좌 상단 꼭지점
    Point lowright;  // 우 하단 꼭지점

public:
    // 직사각형의 정보를 출력하는 함수
    void ShowRecInfo()
    {
        cout << "좌 상단: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "우 하단: " << '[' << lowright.x << ", ";
        cout << lowright.y << ']' << endl << endl;
    }
};

// 프로그램의 시작점
int main(void)
{
    Point pos1 = { -2, 4 };            // 첫 번째 점의 좌표
    Point pos2 = { 5, 9 };             // 두 번째 점의 좌표
    Rectangle rec = { pos2, pos1 };    // 직사각형 객체 생성 및 초기화
    rec.ShowRecInfo();                 // 직사각형 정보 출력
    return 0;                          // 프로그램 종료
}

/*
1. Point 클래스:
    -> Point 클래스는 2차원 평면상의 한 점을 나타내는 클래스.
    -> 멤버 변수로 x와 y를 가지고 있습니다. 이는 각각 x축과 y축의 좌표를 나타냄.

2. Rectangle 클래스:
    -> Rectangle 클래스는 직사각형을 나타내는 클래스.
    -> 멤버 변수로 upLeft와 lowRight를 가지고 있습니다.
        =>이는 직사각형의 좌상단과 우하단 점을 나타냄.
    -> ShowRecInfo 함수는 직사각형의 정보를 출력하는 메서드.

3. 메인 함수:

    -> main 함수에서는 두 개의 Point 객체를 생성하고, 이를 이용하여 Rectangle 객체를 생성.
    -> 첫 번째 Point 객체 pos1은 (-2, 4) 좌표.
    -> 두 번째 Point 객체 pos2은 (5, 9) 좌표.
    -> 이 두 개의 점으로 정의된 직사각형을 생성하여 Rectangle 객체 rec에 save.
    -> rec.ShowRecInfo()를 호출하여 직사각형의 정보를 출력.

*/
