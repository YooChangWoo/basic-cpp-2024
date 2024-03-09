#include <iostream>
#include "Point.h" // Point 클래스의 선언이 들어있는 헤더 파일을 포함함.

using namespace std;

// Point 클래스의 생성자 정의
Point::Point(int x, int y) : xpos(x), ypos(y) { }


// operator<< 함수 정의
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}
/*
1. #include <iostream>: 표준 입력과 출력을 위한 헤더 파일을 포함함.

2. "Point.h": Point 클래스의 선언이 들어있는 헤더 파일을 포함함.

3. using namespace std;: 표준 라이브러리의 std 네임스페이스를 사용함.

4. Point::Point(int x, int y) : xpos(x), ypos(y) { }: Point 클래스의 생성자를 정의함. 
    -> 인자 x와 y를 받아 xpos와 ypos를 초기화함.

5. ostream& operator<<(ostream& os, const Point& pos): operator<< 함수를 정의함. 
    -> 이 함수는 ostream 객체와 Point 객체를 인자로 받음. 
        -> const 한정자를 사용하여 Point 객체 pos를 변경하지 않고 읽기만 함.

6. os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;: os 스트림에 Point 객체의 좌표를 출력함. 
    -> xpos와 ypos는 Point 객체의 private 멤버 변수로서 직접 접근할 수 없으므로 클래스의 멤버 함수를 통해 간접적으로 접근함.

7. return os;: 출력된 스트림을 반환함.

*/