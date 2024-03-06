#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2; // 정수형 멤버 변수 선언
public:
    // 생성자: 멤버 변수 초기화
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    {  }
    // 데이터 출력 함수
    void ShowData() { cout << num1 << ", " << num2 << endl; }

    // 대입 연산자 오버로딩
    First& operator=(const First& ref)
    {
        cout << "First& operator=()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First
{
private:
    int num3, num4; // 추가적인 정수형 멤버 변수 선언
public:
    // 생성자: 부모 클래스의 생성자 호출하여 초기화, 추가 멤버 변수 초기화
    Second(int n1, int n2, int n3, int n4)
        : First(n1, n2), num3(n3), num4(n4)
    {  }

    // 데이터 출력 함수
    void ShowData()
    {
        First::ShowData(); // 부모 클래스의 ShowData() 함수 호출
        cout << num3 << ", " << num4 << endl; // 자신의 멤버 변수 출력
    }

    // 대입 연산자 오버로딩
    /*
    Second& operator=(const Second &ref)
    {
        cout << "Second& operator=()" << endl;
        // 부모 클래스의 대입 연산자 호출 (선택적)
        // First::operator=(ref);
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
    */
};


int main(void)
{
    Second ssrc(111, 222, 333, 444); // Second 클래스의 객체 생성 및 초기화
    Second scpy(0, 0, 0, 0); // Second 클래스의 객체 생성 및 초기화

    scpy = ssrc; // 대입 연산자 호출
    scpy.ShowData(); // 객체의 데이터 출력
    return 0;
}
/*
First 클래스는 두 개의 정수형 멤버 변수를 가지고 있으며,
대입 연산자를 오버로딩하여 객체의 멤버 변수를 복사할 수 있습니다.

Second 클래스는 First 클래스를 상속받고 있으며,
두 개의 추가적인 정수형 멤버 변수를 가지고 있습니다.

Second 클래스의 생성자에서는 부모 클래스인 First 클래스의 생성자를 호출하여
상속된 멤버 변수를 초기화하고, 자신의 멤버 변수를 초기화합니다.

Second 클래스의 ShowData() 함수에서는 부모 클래스인 First 클래스의 ShowData() 함수를 호출한 후,
자신의 멤버 변수를 출력합니다.

Second 클래스에서 대입 연산자를 오버로딩하는 것은 선택사항입니다.
부모 클래스인 First 클래스의 대입 연산자를 호출할 수도 있고,
자신의 멤버 변수만 복사할 수도 있습니다.
*/