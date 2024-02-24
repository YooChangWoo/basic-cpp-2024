#include <iostream>

using namespace std;

int Adder(int num1 = 1, int num2 = 2);   // 함수 선언

void func() {
    cout << "Hi" << endl;
}

int main(void)
{
    cout << Adder() << endl;      // 함수 호출 :  Adder(), 3
    cout << Adder(5) << endl;      // 7
    cout << Adder(3, 5) << endl;   // 8
    func(); // func() 호출: 반환값이 없으므로 출력하지 않음
    return 0;
}

int Adder(int num1, int num2)   // 함수 정의
{
    return num1 + num2;
}
#include <iostream>

using namespace std;

int Adder(int num1 = 1, int num2 = 2);   // 함수 선언

void func() {
    cout << "Hi" << endl;
}

int main(void)
{
    cout << Adder() << endl;      // 함수 호출 :  Adder(), 3
    cout << Adder(5) << endl;      // 7
    cout << Adder(3, 5) << endl;   // 8
    func(); // func() 호출: 반환값이 없으므로 출력하지 않음
    return 0;
}

int Adder(int num1, int num2)   // 함수 정의
{
    return num1 + num2;
}

/*
매개변수에 디폴트 값이 설정되어 있으면, 선언된 매개변수의 수보다 적은 수의 인자전달이 가능하다.
그리고 전달되는 인자는 왼쪽에서부터 채워져 나가고, 부족분은 디폴트 값으로 채워진다.
*/

//클래스 안에 들어가는 함수 : 메서드 틀린부분 찾아줘
