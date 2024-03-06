#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // 2차원 좌표의 x와 y 좌표값을 저장하기 위한 private 멤버 변수
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) // 생성자, 기본값으로 (0,0)으로 초기화
    { }

    void ShowPosition() const // 현재 좌표를 출력하는 함수
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // 전위 증가 연산자 오버로딩 (++pos)
    Point& operator++()        // 전위 - 승가하고 던져준다.   a = i++
    {
        xpos += 1; // x좌표 증가
        ypos += 1; // y좌표 증가

        return *this; // 현재 객체 반환
    }

    // 후위 증가 연산자 오버로딩 (pos++)
    const Point operator++(int)      // 후위 - 던져주고 증가. a = i++
    {   // 현재의 객체를 복사하여 현재의 속성값을 유지시킨다.
        const Point retobj(xpos, ypos); // 현재 좌표를 저장하기 위해 임시 Point 객체 생성  // const Point ret
        // 현재 객체의 속성갓을 1씩 증가시킨다.
        xpos += 1; // x좌표 증가
        ypos += 1; // y좌표 증가
        // 증가 이전에 복사한 객체를 전달한다.
        return retobj; // 증가 이전의 좌표를 저장한 임시 객체 반환
    }

    friend Point& operator--(Point& ref); // 전위 감소 연산자 함수를 friend로 선언
    friend const Point operator--(Point& ref, int); // 후위 감소 연산자 함수를 friend로 선언
};

// 전위 감소 연산자 오버로딩 (--pos)
Point& operator--(Point& ref)
{
    ref.xpos -= 1; // x좌표 감소
    ref.ypos -= 1; // y좌표 감소
    return ref; // 변경된 객체 반환
}

// 후위 감소 연산자 오버로딩 (pos--)
const Point operator--(Point& ref, int)
{
    const Point retobj(ref.xpos, ref.ypos); // 현재 좌표를 저장하기 위해 임시 Point 객체 생성
    ref.xpos -= 1; // x좌표 감소
    ref.ypos -= 1; // y좌표 감소
    return retobj; // 감소 이전의 좌표를 저장한 임시 객체 반환
}

int main(void)
{
    Point pos(3, 5); // Point 객체 생성 (좌표: 3, 5)
    Point cpy; // 복사할 Point 객체 생성

    cpy = pos--; // 후위 감소 연산자 사용
    cpy.ShowPosition(); // 복사된 객체의 좌표 출력
    pos.ShowPosition(); // 감소된 객체의 좌표 출력

    cpy = pos++; // 후위 증가 연산자 사용
    cpy.ShowPosition(); // 복사된 객체의 좌표 출력
    pos.ShowPosition(); // 증가된 객체의 좌표 출력

    return 0;
}

/*
전위 증가 연산자 오버로딩 (++pos):
++pos 연산자를 오버로딩하여 좌표값을 1씩 증가시킵니다.
함수는 현재 객체를 참조로 반환합니다.

후위 증가 연산자 오버로딩 (pos++):
pos++ 연산자를 오버로딩하여, 증가 이전의 좌표를 임시 객체에 저장하고, 좌표를 1씩 증가시킵니다.
함수는 증가 이전의 좌표를 저장한 임시 객체를 반환합니다.

전위 및 후위 감소 연산자 오버로딩:
전위 및 후위 감소 연산자를 오버로딩하여, 좌표값을 1씩 감소시킵니다.
후위 연산자는 int 형식의 더미 매개변수를 가지며, 연산자 오버로딩에 대한 구분을 제공합니다.
*/