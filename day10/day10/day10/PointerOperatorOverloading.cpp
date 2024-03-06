#include <iostream>
using namespace std;

class Number
{
private:
    int num; // 정수형 멤버 변수
public:
    // 생성자: 멤버 변수 초기화
    Number(int n) : num(n) { }

    // 데이터 출력 함수
    void ShowData() { cout << num << endl; }

    // 화살표 연산자(*) 오버로딩
    Number* operator ->()
    {
        return this; // 현재 객체의 포인터 반환
    }

    // 참조 연산자(*) 오버로딩
    Number& operator*()
    {
        return *this; // 현재 객체의 참조 반환
    }
};

int main(void)
{
    Number num(20); // Number 클래스의 객체 생성
    num.ShowData(); // 객체의 데이터 출력

    // 화살표 연산자(*)를 사용하여 멤버 함수 호출
    (*num) = 30; // 참조 연산자(*)로 객체에 접근하여 데이터 변경
    num->ShowData(); // 화살표 연산자(*)를 사용하여 객체의 멤버 함수 호출
    (*num).ShowData(); // 참조 연산자(*)를 사용하여 객체의 멤버 함수 호출
    return 0;
}
/*
Number 클래스에서 화살표 연산자(->)와 참조 연산자(*)를 오버로딩하였습니다.

operator->() 함수는 객체의 주소를 반환합니다.
따라서 num->ShowData()는 사실상 num.ShowData()와 동일한 작업을 수행합니다.

operator*() 함수는 객체의 참조를 반환합니다
. 따라서 (*num)은 객체 자체를 가리키게 됩니다.

main 함수에서는 객체의 데이터를 출력한 후,
화살표 연산자와 참조 연산자를 사용하여 객체의 멤버 함수를 호출하거나 데이터를 변경합니다.
*/