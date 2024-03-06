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
        cout << '[' << xpos << "," << ypos << ']' << endl;
    }

    Point operator+(const Point& ref) // + 연산자 오버로딩  //operator+라는 이름의 함수
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos); // 두 Point 객체의 좌표값을 더한 새로운 Point 객체 생성
        return pos; // 새로운 Point 객체 반환
    }
};

int main(void)
{
    Point pos1(3, 4); // 첫 번째 Point 객체 생성 (좌표: 3, 4)
    Point pos2(10, 20); // 두 번째 Point 객체 생성 (좌표: 10, 20)
        // pos1과 pos2를 더한 결과를 pos3에 할당
    Point pos3 = pos1.operator+(pos2); // operator+ 함수를 직접 호출하여 두 Point 객체를 더한 결과를 얻음
    Point pos3 = pos2.operator+(pos3);

    pos1.ShowPosition(); // pos1의 좌표 출력
    pos2.ShowPosition(); // pos2의 좌표 출력
    pos3.ShowPosition(); // pos3의 좌표 출력
    
    return 0;
}
/*
연산자 오버로딩 :

클래스 내에서 + 연산자가 오버로딩되어 있으며, 이를 통해 두 Point 객체를 더할 수 있습니다.
operator+ 함수는 두 개의 Point 객체를 받아서 더한 후, 새로운 Point 객체를 반환합니다.

operator+ 호출 :

main 함수에서 pos1과 pos2를 더하기 위해 operator+ 함수를 호출합니다.
이는 pos1.operator+(pos2)와 동일한 역할을 합니다.
새로운 Point 객체가 생성되어 pos3에 할당됩니다.
    
ShowPosition 함수 :

ShowPosition 함수는 각 Point 객체의 좌표를 출력합니다.
*/