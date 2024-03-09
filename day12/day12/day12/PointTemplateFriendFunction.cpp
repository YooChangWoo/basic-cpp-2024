#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    // 생성자: 기본값으로 0을 갖는 x와 y 좌표로 초기화함.
    Point(T x = 0, T y = 0) : xpos(x), ypos(y)
    {  }

    // 좌표를 출력하는 멤버 함수
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // operator+ 함수를 Point<int> 클래스의 friend 함수로 선언
    friend Point<int> operator+(const Point<int>&, const Point<int>&);

    // operator<< 함수를 ostream 클래스의 friend 함수로 선언
    friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

// operator+ 함수 정의: 두 Point<int> 객체를 받아 좌표를 더한 Point<int> 객체를 반환함.
Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
    return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

// operator<< 함수 정의: Point<int> 객체를 출력함.
ostream& operator<<(ostream& os, const Point<int>& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main(void)
{
    // Point<int> 객체 생성
    Point<int> pos1(2, 4);
    Point<int> pos2(4, 8);

    // 두 Point<int> 객체를 더하여 새로운 Point<int> 객체 생성
    Point<int> pos3 = pos1 + pos2;

    // 좌표 출력
    cout << pos1 << pos2 << pos3;

    return 0;
}

/*
템플릿 클래스 Point를 정의하고, 이를 이용하여 정수형 좌표를 처리하는 예시를 보여줌...
*/