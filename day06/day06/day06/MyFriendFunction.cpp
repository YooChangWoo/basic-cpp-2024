#include <iostream>
#include <cstring>
using namespace std;

// 전방 선언: PointOP 클래스가 Point 클래스를 friend로 선언하기 위해 필요함.
class Point;

// PointOP 클래스 선언
class PointOP
{
private:
    int opcnt; // 연산 횟수를 저장하는 private 변수

public:
    PointOP() : opcnt(0) // 생성자: opcnt를 초기화
    { }

    // 두 Point 객체를 더하여 새로운 Point 객체를 반환하는 함수
    Point PointAdd(const Point&, const Point&);

    // 두 Point 객체를 빼서 새로운 Point 객체를 반환하는 함수
    Point PointSub(const Point&, const Point&);

    // 소멸자: 연산 횟수를 출력하는 역할
    ~PointOP()
    {
        cout << "Operation times: " << opcnt << endl;
    }
};

// Point 클래스 선언
class Point {
private:
    int x; // x 좌표를 저장하는 private 변수
    int y; // y 좌표를 저장하는 private 변수

public:
    // 생성자: x 좌표와 y 좌표를 초기화
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos)
    {}

    // PointOP 클래스의 PointAdd 함수와 PointSub 함수를 friend로 선언하여 이들 함수가 Point의 private 멤버에 접근할 수 있도록 함
    friend Point PointOP::PointAdd(const Point&, const Point&);
    friend Point PointOP::PointSub(const Point&, const Point&);

    // 좌표를 출력하는 함수
    friend void ShowPointPos(const Point&);
};

// 두 Point 객체를 더하여 새로운 Point 객체를 반환하는 함수
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
    opcnt++; // 연산 횟수 증가
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y); // 두 점의 x 좌표와 y 좌표를 더하여 새로운 Point 객체 반환
}

// 두 Point 객체를 빼서 새로운 Point 객체를 반환하는 함수
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
    opcnt++; // 연산 횟수 증가
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y); // 두 점의 x 좌표와 y 좌표를 빼서 새로운 Point 객체 반환
}

// 좌표를 출력하는 함수
void ShowPointPos(const Point& pos) {
    cout << "x : " << pos.x << ", "; // x 좌표 출력
    cout << "y : " << pos.y << endl; // y 좌표 출력
}

// 메인 함수
int main(void) {
    Point pos1(1, 2); // 첫 번째 Point 객체 생성
    Point pos2(2, 4); // 두 번째 Point 객체 생성
    PointOP op; // PointOP 객체 생성

    // 두 Point 객체를 더한 결과를 출력
    ShowPointPos(op.PointAdd(pos1, pos2));

    // 두 Point 객체를 뺀 결과를 출력
    ShowPointPos(op.PointSub(pos2, pos1));

    return 0;
}
/*
1. Point 클래스는 x 좌표와 y 좌표를 가지며,
    -> 생성자를 통해 초기화 됨.

2. PointOP 클래스는 두 점을 더하거나 빼는 연산을 수행하고,
    -> 이러한 연산의 횟수를 추적함.

3. ShowPointPos 함수는 Point 객체의 좌표를 출력함.

4. main 함수에서는 두 점을 초기화하고, PointOP 객체를 생성한 후 두 점을 더하고 빼며,
    -> 그 결과를 출력함
*/