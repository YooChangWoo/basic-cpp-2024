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

    friend Point operator+(const Point& pos1, const Point& pos2); // operator+ 함수를 friend로 선언하여 클래스 외부에서 접근 가능하게 함
};

// 두 Point 객체를 더하는 연산자 오버로딩 함수
Point operator+(const Point& pos1, const Point& pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos); // 두 Point 객체의 좌표값을 더하여 새로운 Point 객체 생성
    return pos; // 새로운 Point 객체 반환
}

int main(void)
{
    Point pos1(3, 4); // 첫 번째 Point 객체 생성 (좌표: 3, 4)
    Point pos2(10, 20); // 두 번째 Point 객체 생성 (좌표: 10, 20)

    Point pos3 = pos1 + pos2; // 두 Point 객체를 더한 결과를 pos3에 할당

    pos1.ShowPosition(); // pos1의 좌표 출력
    pos2.ShowPosition(); // pos2의 좌표 출력
    pos3.ShowPosition(); // pos3의 좌표 출력

    return 0;
}

/*
연산자 오버로딩 (operator+):
이 예제에서는 + 연산자를 오버로딩하여 두 Point 객체를 더합니다.
operator+ 함수는 friend 함수로 선언되어 클래스 내의 private 멤버에 접근할 수 있도록 합니다.

friend 함수:
operator+ 함수가 Point 클래스 내부의 private 멤버에 접근할 수 있도록 하기 위해 friend로 선언되었습니다.

operator+ 함수 구현:
operator+ 함수는 두 개의 Point 객체를 인자로 받아서 각 좌표를 더한 후, 새로운 Point 객체를 반환합니다.

사용법:
main 함수에서는 두 Point 객체를 생성하고, 이를 더하여 새로운 Point 객체에 할당합니다.
*/
