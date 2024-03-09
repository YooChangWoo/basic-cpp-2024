#include <iostream>
using namespace std;

class Number
{
private:
    int num; // 정수 값을 저장하는 멤버 변수
public:
    // 기본 생성자, 매개변수가 주어지지 않으면 0으로 초기화
    Number(int n = 0) : num(n)
    {
        cout << "Number(int n=0)" << endl;
    }
    // 대입 연산자 오버로딩
    Number& operator=(const Number& ref)
    {
        cout << "operator=()" << endl;
        num = ref.num;
        return *this;
    }
    // 현재 객체의 정수 값을 출력하는 함수
    void ShowNumber() { cout << num << endl; }
};

int main(void)
{
    Number num; // 기본 생성자 호출하여 num 객체 생성
    num = 30;   // int를 Number 객체에 대입, 대입 연산자가 호출됨
    num.ShowNumber(); // num의 값을 출력
    return 0;
}
/*
클래스 Number 정의:
Number 클래스는 하나의 정수 값을 갖는 간단한 클래스입니다.
private 섹션에는 int형 멤버 변수 num이 있습니다.

생성자:
클래스에는 기본 생성자가 정의되어 있습니다.
매개변수가 주어지지 않으면 0으로 초기화됩니다.

대입 연산자 오버로딩:
대입 연산자 operator=가 클래스 내부에 오버로딩되어 있습니다.
이 연산자는 다른 Number 객체의 값을 현재 객체에 할당합니다.

Main 함수:
main 함수에서는 먼저 기본 생성자를 이용하여 num 객체를 생성합니다.
그런 다음, 정수 30을 num 객체에 대입합니다. 대입 연산자가 호출되며,
해당 연산자가 객체에 값을 할당하게 됩니다.
마지막으로 ShowNumber() 함수를 호출하여 num 객체의 값을 출력합니다.
*/