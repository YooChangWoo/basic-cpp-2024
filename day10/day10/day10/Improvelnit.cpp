#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    // 정수 하나를 입력으로 받는 생성자
    AAA(int n = 0) : num(n)
    {
        cout << "AAA(int n=0)" << endl;
    }
    // 객체 하나를 입력으로 받는 생성자
    AAA(const AAA& ref) : num(ref.num)
    {
        cout << "AAA(const AAA & ref)" << endl;
    }
    // 대입 연산자 오버로딩
    AAA& operator=(const AAA& ref)
    {
        num = ref.num;
        cout << "operator=(const AAA &ref)" << endl;
        return *this;
    }
};

class BBB
{
private:
    AAA mem; // AAA 타입의 멤버 변수
public:
    // AAA 타입의 객체를 입력으로 받는 생성자
    BBB(const AAA& ref) : mem(ref)
    {  }
};

class CCC
{
private:
    AAA mem;
public:
    // AAA 타입의 객체를 입력으로 받는 생성자
    CCC(const AAA& ref)
    {
        mem = ref; // 대입 연산을 통해 초기화
    }
};

int main(void)
{
    AAA obj1(12); // AAA 클래스의 객체 생성
    cout << "*********************" << endl;
    BBB obj2(obj1); // BBB 클래스의 객체 생성, 멤버 이니셜라이저를 통해 초기화
    cout << "*********************" << endl;
    CCC obj3(obj1); // CCC 클래스의 객체 생성, 대입 연산자를 통해 초기화
    return 0;
}
/*
클래스 AAA는 정수 하나를 받는 생성자, 객체 하나를 받는 생성자,
그리고 대입 연산자를 오버로딩하고 있습니다.

클래스 BBB는 AAA 클래스를 멤버로 갖고 있으며,
멤버 이니셜라이저를 사용하여 AAA 객체를 초기화합니다.

클래스 CCC는 AAA 클래스를 멤버로 갖고 있으며,
대입 연산자를 사용하여 AAA 객체를 초기화합니다.

main 함수에서는 객체를 생성하고 초기화하는 과정을 보여줍니다.
BBB 클래스는 멤버 이니셜라이저를 사용하여 멤버 객체를 초기화하고,
CCC 클래스는 대입 연산자를 통해 멤버 객체를 초기화합니다.
*/