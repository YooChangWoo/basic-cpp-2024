#include <iostream>
using namespace std;

class AAA
{
public:
    AAA()
    {
        cout << "empty object" << endl; // AAA 클래스의 객체가 생성될 때 "empty object"를 출력
    }
    void ShowYourName()
    {
        cout << "I'm class AAA" << endl; // AAA 클래스의 이름을 출력하는 함수
    }
};

class BBB
{
private:
    AAA& ref; // AAA 클래스의 참조를 가리키는 멤버 변수 ref
    const int& num; // int형 상수 참조를 가리키는 멤버 변수 num

public:
    BBB(AAA& r, const int& n)
        : ref(r), num(n)
    {
        // BBB 클래스의 생성자, ref와 num을 매개변수로 초기화
        // empty constructor body: 비어있는 생성자 본문
    }
    void ShowYourName()
    {
        ref.ShowYourName(); // AAA 클래스의 ShowYourName 함수 호출
        cout << "and" << endl; // "and" 출력
        cout << "I ref num: " << num << endl; // num의 값을 출력
    }
};

int main(void)
{
    AAA obj1; // AAA 클래스의 객체 obj1 생성, "empty object" 출력
    BBB obj2(obj1, 20); // BBB 클래스의 객체 obj2를 obj1과 20으로 생성
    obj2.ShowYourName(); // obj2의 ShowYourName 함수 호출
    return 0;
}

/*
* 생성자(클래스 이름과 같은 멤버함수로 출력은 없다.)
	- 객체 생성시 자동으로 호추로디는 멤버함수
	- 모든 클래스는 디폴트 생성자를 가지고 있다.
	- 만약 명시적으로 생성자를 작성하면 디폴트 생성자의 호출은 불가하며
		디폴트 생성자가 필요한 경우는 명시적으로 작성한다.
	- 멤버변수들의 초기화를 담당한다.

* 멤버 이니셜 라이즈
	- 객체 생성전에 선언과 동시에 초기화가 필요한 경우에 사용한다.
	- const 변수와 참조변수의 초기화에 사용
*/