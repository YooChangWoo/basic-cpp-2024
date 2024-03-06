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
    Point& operator++()
    {
        xpos += 1; // x좌표 증가
        ypos += 1; // y좌표 증가
        return *this; // 현재 객체 반환
    }

    friend Point& operator--(Point& ref); // friend로 선언하여 전위 감소 연산자에 대한 함수를 선언
};

// 전위 감소 연산자 오버로딩 (--pos)
Point& operator--(Point& ref)
{
    ref.xpos -= 1; // x좌표 감소
    ref.ypos -= 1; // y좌표 감소
    return ref; // 변경된 객체 반환
}

int main(void)
{
    Point pos(1, 2); // Point 객체 생성 (좌표: 1, 2)

    ++pos; // 전위 증가 연산자 사용
    pos.ShowPosition(); // 증가된 좌표 출력

    --pos; // 전위 감소 연산자 사용
    pos.ShowPosition(); // 감소된 좌표 출력

    ++(++pos); // 연속으로 전위 증가 연산자 두 번 호출
    pos.ShowPosition(); // 증가된 좌표 출력

    --(--pos); // 연속으로 전위 감소 연산자 두 번 호출
    pos.ShowPosition(); // 감소된 좌표 출력

    return 0;
}

/*
전위 증가 연산자 오버로딩 (++pos):
클래스 내에서 전위 증가 연산자를 오버로딩하여, 좌표값을 1씩 증가시킵니다.
함수는 현재 객체를 참조로 반환합니다.

friend 함수:
전위 감소 연산자 함수가 Point 클래스의 멤버에 직접 접근할 수 있도록 friend로 선언되었습니다.

전위 감소 연산자 오버로딩 (--pos):
전위 감소 연산자를 오버로딩하여, 좌표값을 1씩 감소시킵니다.
함수는 참조로 변경된 객체를 반환합니다.

연산자 사용:
main 함수에서 전위 증가와 감소 연산자를 사용하여 좌표값을 변경하고, ShowPosition 함수를 통해 변경된 좌표를 출력합니다.
*/