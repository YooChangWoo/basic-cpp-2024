#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
    Point pos1;
    // pos1의 좌표를 초기화하고, 초기화가 실패하면 실패 메시지 출력
    if (!pos1.InitMembers(-2, 4))
        cout << "초기화 실패" << endl;
    // pos1의 좌표를 초기화하고, 초기화가 실패하면 실패 메시지 출력
    if (!pos1.InitMembers(2, 4))
        cout << "초기화 실패" << endl;

    Point pos2;
    // pos2의 좌표를 초기화하고, 초기화가 실패하면 실패 메시지 출력
    if (!pos1.InitMembers(5, 9))
        cout << "초기화 실패" << endl;

    Rectangle rec;
    // 직사각형의 상단 좌표와 우하단 좌표를 초기화하고, 초기화가 실패하면 실패 메시지 출력
    if (!rec.InitMembers(pos2, pos1))
        cout << "직사각형 초기화 실패" << endl;

    // 직사각형의 상단 좌표와 우하단 좌표를 초기화하고, 초기화가 실패하면 실패 메시지 출력
    if (!rec.InitMembers(pos1, pos2))
        cout << "직사각형 초기화 실패" << endl;

    // 직사각형 정보 출력
    rec.ShowRecInfo();
    return 0;
}
/*
객체의 초기화 과정에서 발생하는 실패를 처리하는 방법이 중요함.
객체 간의 관계와 정보 교환에 대한 이해가 필요하고,
각 클래스의 초기화 메소드(InitMembers())가 호출되는데,
이 메소드들이 객체의 멤버 변수를 적절히 초기화하는지 확인할 필요가 있음
*/