#include <iostream>
using namespace std;

// T 타입의 템플릿 매개변수를 갖는 Point 클래스 템플릿 선언
template <typename T>
class Point
{
private:
    T xpos, ypos; // T 타입의 xpos(가로 좌표), ypos(세로 좌표) 멤버 변수

public:
    // 생성자: xpos와 ypos를 초기화. 기본값으로 0을 사용
    Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}

    // 멤버 함수: xpos와 ypos의 값을 출력
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

int main(void)
{
    // int 타입을 사용하는 Point 객체 생성 및 출력
    Point<int> pos1(3, 4);
    pos1.ShowPosition();

    // double 타입을 사용하는 Point 객체 생성 및 출력
    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    // char 타입을 사용하는 Point 객체 생성 및 출력
    // 'P'와 'F'는 문자로, 좌표의 개념에서는 비표준적이지만, 이 클래스는 어떤 타입의 좌표도 처리할 수 있음을 보여줌
    Point<char> pos3('P', 'F');
    pos3.ShowPosition();

    return 0;
}
/*
1. 핵심 포인트는 템플릿을 사용해 Point 클래스를 구현함으로써, 다양한 데이터 타입에 대해 좌표를 표현할 수 있다는 것. 

2. 예를 들어, Point<int>는 정수 좌표, Point<double>는 소수점 좌표, Point<char>는 문자로 표현되는 좌표를 의미함. 

3. 이처럼 템플릿을 사용하면 같은 클래스 또는 함수의 구조를 유지하면서도 다양한 데이터 타입에 대해 유연하게 코드를 재사용할 수 있음
*/