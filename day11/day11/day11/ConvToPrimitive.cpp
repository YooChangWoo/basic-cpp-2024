#include <iostream>
using namespace std;

class Number
{
private:
    int num; // 정수를 저장하는 멤버 변수
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
    // 형 변환 연산자 오버로딩, Number 객체를 int로 변환
    operator int()
    {
        return num;
    }
    // 현재 객체의 정수 값을 출력하는 함수
    void ShowNumber() { cout << num << endl; }
};

int main(void)
{
    Number num1; // 기본 생성자 호출하여 num1 객체 생성
    num1 = 30;   // 30을 num1에 대입

    Number num2 = num1 + 20; // num1에 20을 더한 값을 가지는 num2 객체 생성
    num2.ShowNumber();        // num2의 값을 출력
    return 0;
}
/*
클래스 Number 정의:
Number 클래스는 하나의 정수를 나타내는 간단한 클래스입니다. private 섹션에는 int 형 멤버 변수 num이 있습니다.

생성자와 대입 연산자 오버로딩:
Number 클래스에는 기본 생성자와 대입 연산자(operator=)가 오버로딩되어 있습니다.
생성자는 기본값을 가지며, 대입 연산자는 다른 Number 객체를 받아들여 현재 객체에 값을 복사합니다.

형 변환 연산자 오버로딩:
Number 클래스에는 operator int() 형 변환 연산자가 오버로딩되어 있습니다.
이것은 Number 객체를 int 형으로 변환할 때 호출됩니다.
이는 Number 객체를 int로 사용할 수 있게 해줍니다.

Main 함수:
main 함수에서는 먼저 기본 생성자를 이용하여 num1 객체를 생성한 후, 이 객체에 30을 대입합니다.
그 다음에는 num2 객체를 생성하는데, 이는 num1에 20을 더한 값을 가지게 됩니다.
마지막으로 num2의 값을 출력합니다.
*/