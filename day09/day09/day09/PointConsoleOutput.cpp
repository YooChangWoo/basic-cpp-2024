#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {  }

    // 좌표를 출력하는 멤버 함수
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    // << 연산자를 통해 Point 객체를 출력하기 위해 ostream의 friend로 선언된 함수
    friend ostream& operator<<(ostream&, const Point&);
};

// << 연산자를 오버로딩하여 Point 객체를 출력하기 위한 함수 정의
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main(void)
{
    Point pos1(1, 3);
    cout << pos1; // pos1 객체 출력
    Point pos2(101, 303);
    cout << pos2; // pos2 객체 출력
    return 0;
}

/*
연산자 오버로딩:

operator<< 함수는 출력 스트림에 Point 객체를 출력하기 위해 오버로딩됩니다.
이 함수는 ostream 클래스의 객체(os)와 Point 객체(pos)를 매개변수로 받고, Point 객체의 좌표를 적절한 형식으로 출력합니다.

friend 함수:

operator<< 함수가 Point 클래스의 friend로 선언되어 있으므로, Point 클래스의 private 멤버에 접근할 수 있습니다.
이를 통해 operator<< 함수에서 Point 객체의 xpos와 ypos 멤버에 접근하여 출력할 수 있습니다.

사용 예시:

main() 함수에서는 cout << pos1;과 cout << pos2;와 같이 Point 객체를 출력하는 것을 볼 수 있습니다.
이러한 구문은 operator<< 함수의 오버로딩을 통해 가능해집니다.
*/

