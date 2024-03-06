#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2; // 두 개의 정수형 private 멤버 변수 선언
public:
    // 생성자 정의, 기본값은 각각 0
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    {  }
    // 멤버 변수 출력 함수
    void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
    int num3, num4; // 두 개의 정수형 private 멤버 변수 선언
public:
    // 생성자 정의, 기본값은 각각 0
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    {  }
    // 멤버 변수 출력 함수
    void ShowData() { cout << num3 << ", " << num4 << endl; }

    // 대입 연산자 오버로딩
    Second& operator=(const Second& ref)
    {
        cout << "Second& operator=()" << endl; // 디폴트 대입 연산자 호출을 확인하기 위한 출력문
        num3 = ref.num3; // num3 값 복사
        num4 = ref.num4; // num4 값 복사
        return *this; // 현재 객체의 참조 반환
    }
};

int main(void)
{
    First fsrc(111, 222); // First 클래스의 객체 fsrc 생성 및 초기화
    First fcpy; // First 클래스의 객체 fcpy 생성
    Second ssrc(333, 444); // Second 클래스의 객체 ssrc 생성 및 초기화
    Second scpy; // Second 클래스의 객체 scpy 생성

    fcpy = fsrc; // 디폴트 대입 연산자를 이용한 객체 fcpy에 객체 fsrc 복사
    scpy = ssrc; // 명시적으로 작성한 대입 연산자를 이용한 객체 scpy에 객체 ssrc 복사

    fcpy.ShowData(); // fcpy 객체의 데이터 출력
    scpy.ShowData(); // scpy 객체의 데이터 출력

    First fob1, fob2; // First 클래스의 객체 fob1, fob2 생성
    Second sob1, sob2; // Second 클래스의 객체 sob1, sob2 생성

    // 연속적인 대입 연산자의 동작 확인
    fob1 = fob2 = fsrc; // fsrc 객체를 fob1에 대입하고, fob1을 fob2에 대입
    sob1 = sob2 = ssrc; // ssrc 객체를 sob1에 대입하고, sob1을 sob2에 대입

    // 객체들의 데이터 출력
    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
    return 0;
}

/*
대입 연산자 오버로딩:

Second 클래스에서 operator= 함수를 오버로딩했습니다. 이 함수는 객체 간의 대입 연산을 정의합니다.
대입 연산자를 오버로딩하면 객체가 다른 객체로 복사될 때 무엇이 발생하는지를 정의할 수 있습니다.
여기서는 객체의 멤버 변수를 다른 객체의 멤버 변수로 복사하고 있습니다.

객체 복사 및 대입 연산:

First와 Second 클래스의 객체들을 생성하고 서로 복사하고 있습니다.
fcpy = fsrc;와 같이 객체를 다른 객체에 대입하면, 대입 연산자 오버로딩 함수가 호출됩니다.
이를 통해 객체의 상태가 복사되고, 객체 간의 데이터가 공유됩니다.

연속적인 대입 연산자의 동작:

fob1 = fob2 = fsrc;와 같이 연속적인 대입 연산이 수행될 때, 대입 연산자는 오른쪽에서 왼쪽으로 평가됩니다.
따라서 fsrc의 데이터가 먼저 fob2에 복사되고, 그 다음에 fob2의 데이터가 fob1에 복사됩니다.
*/