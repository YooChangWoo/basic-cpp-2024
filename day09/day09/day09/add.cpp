/*
  객체를 더하는 add 멤버함수
*/
#include <iostream>
using namespace std;

class Point {
    int x, y; // private 멤버 변수 x와 y 선언
public:
    // 생성자 정의, 기본값은 각각 0
    Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
        cout << "Operator" << endl; // 생성자 호출 시 출력문
    }
    // 두 Point 객체를 더하는 연산자 오버로딩
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y); // 두 객체의 x와 y를 더한 객체 반환
    }
    // Point 객체 정보를 출력하는 함수
    void showPoint() {
        cout << '[' << x << ']' << endl; // 객체의 x 값을 출력
    }
};

int main()
{
    Point pos1(3, 4); // Point 객체 pos1 생성 및 초기화
    Point pos2(10, 20); // Point 객체 pos2 생성 및 초기화
    Point pos3 = pos1, add(pos2); // Point 객체 pos3를 pos1과 add를 초기화
    pos3.showPoint(); // pos3의 정보 출력

    return 0;
}

/*
객체 생성 및 초기화:

객체들이 생성되고 초기화됩니다. 생성자에서는 초기화 리스트를 사용하여 초기화합니다.
연산자 오버로딩:

+ 연산자가 오버로딩되어 두 개의 Point 객체를 더할 수 있도록 합니다.
operator+() 함수 내에서는 두 객체의 x와 y 값을 더하여 새로운 객체를 생성하여 반환합니다.

연산 및 출력:

생성한 객체들 간의 연산과 정보 출력이 이루어집니다.
*/