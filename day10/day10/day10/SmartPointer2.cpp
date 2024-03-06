#include <iostream>
using namespace std;

// Point 클래스 선언
class Point
{
private:
    int xpos, ypos; // x, y 좌표를 저장하는 멤버 변수
public:
    // 생성자: 초기화 리스트를 사용하여 멤버 변수 초기화
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        cout << "Point 객체 생성" << endl;
    }

    // 소멸자: 객체가 소멸될 때 호출되는 함수
    ~Point()
    {
        cout << "Point 객체 소멸" << endl;
    }

    // 좌표 설정 함수
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    // 스트림 출력 연산자 오버로딩 함수
    friend ostream& operator<<(ostream& os, const Point& pos);
};

// 스트림 출력 연산자 오버로딩 함수 정의
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

// SmartPtr 클래스 선언
class SmartPtr
{
private:
    Point* posptr; // Point 클래스의 포인터 멤버 변수
public:
    // 생성자: Point 객체를 가리키는 포인터를 받아 초기화
    SmartPtr(Point* ptr) : posptr(ptr)
    {  }

    // 참조 연산자(*) 오버로딩: 포인터가 가리키는 Point 객체를 반환
    Point& operator*() const
    {
        return *posptr;
    }

    // 화살표 연산자(->) 오버로딩: 포인터가 가리키는 Point 객체에 접근
    Point* operator->() const
    {
        return posptr;
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~SmartPtr()
    {
        delete posptr;
    }
};

// main 함수
int main(void)
{
    // SmartPtr 객체 생성 및 초기화
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(2, 3));
    SmartPtr sptr3(new Point(4, 5));

    // 객체 출력
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    // 객체의 좌표 설정
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);

    // 변경된 좌표 출력
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    return 0;
}
/*
Point 클래스: 정수형 x, y 좌표를 가지는 클래스로,
스트림 출력 연산자(<<)를 오버로딩하여 좌표를 출력할 수 있습니다.

SmartPtr 클래스: 포인터 멤버를 가지고 있으며,
포인터가 가리키는 Point 객체를 참조하거나 접근할 수 있는 연산자(*, ->)를 오버로딩하고 있습니다.
또한, 객체가 소멸될 때 동적으로 할당된 메모리를 해제하는 역할을 합니다.

main 함수: SmartPtr 객체를 생성하고 Point 객체를 동적으로 할당하여 초기화합니다.
이후 포인터 연산자를 사용하여 객체에 접근하고, 좌표를 설정한 후 변경된 좌표를 출력합니다.
*/