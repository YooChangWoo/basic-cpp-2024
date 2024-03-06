#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos; // 좌표값을 나타내는 멤버 변수
public:
    // 생성자: 좌표값 초기화
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }

    // << 연산자 오버로딩 함수를 프렌드로 선언
    friend ostream& operator<<(ostream& os, const Point& pos);

    // 새로운 메모리 할당 연산자를 오버로딩하여 메모리 할당 시 로그를 출력
    void* operator new (size_t size)
    {
        cout << "operator new : " << size << endl;
        void* adr = new char[size]; // size 크기의 char 배열 동적 할당
        return adr;
    }

    // 삭제 연산자를 오버로딩하여 메모리 해제 시 로그를 출력
    void operator delete (void* adr)
    {
        cout << "operator delete()" << endl;
        delete[] adr; // 동적으로 할당된 메모리를 해제
    }
};

// << 연산자 오버로딩 함수의 정의
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl; // 좌표값을 출력
    return os;
}

int main(void)
{
    // Point 객체를 동적으로 할당하고, << 연산자를 사용하여 좌표값 출력
    Point* ptr = new Point(3, 4);
    cout << *ptr; // << 연산자를 사용하여 좌표값 출력
    delete ptr; // 동적으로 할당된 메모리 해제
    return 0;
}
/*
Point 클래스에 operator new와 operator delete 함수를 오버로딩하여 동적 메모리 할당과 해제를 커스터마이징합니다.
이렇게 하면 메모리 할당 및 해제 시 사용자가 원하는 작업을 추가할 수 있습니다.

operator<< 함수는 ostream 객체와 Point 객체를 받아서 좌표값을 출력합니다.
이 함수는 Point 클래스의 프렌드 함수로 선언되어 있어서 Point 클래스의 private 멤버에 접근할 수 있습니다.

main 함수에서는 new 키워드를 사용하여 Point 객체를 동적으로 할당하고,
출력 연산자 <<를 사용하여 좌표값을 출력합니다.
마지막으로 delete 키워드를 사용하여 동적으로 할당된 메모리를 해제합니다.
*/