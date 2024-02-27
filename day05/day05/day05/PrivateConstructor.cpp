#include <iostream>
using namespace std;

class AAA
{
private:
    int num; // 정수형 멤버 변수 num
public:          
    AAA() : num(0) {} // 기본 생성자, num을 0으로 초기화
    AAA& CreateInitObj(int n) const // n을 받아서 AAA 객체를 생성하는 함수
    {          // ~AAA() []; : 소멸자
        AAA* ptr = new AAA(n); // n 값을 받아 객체를 동적 할당하여 포인터 ptr에 저장
        return *ptr; // 객체의 레퍼런스를 반환
    }
    void showNum() const { cout << num << endl; } // num을 출력하는 함수
private:  // 싱글톤을 만들 때 사용하기
    AAA(int n) : num(n) {} // num을 n으로 초기화하는 생성자
    
};

int main(void)
{
    AAA base; // AAA 클래스의 객체 base 생성, num은 0으로 초기화됨
    base.showNum(); // base 객체의 num을 출력

    AAA& obj1 = base.CreateInitObj(3); // base를 이용하여 AAA 객체를 생성하고, obj1에 참조로 저장
    obj1.showNum(); // obj1 객체의 num을 출력

    AAA& obj2 = base.CreateInitObj(12); // base를 이용하여 AAA 객체를 생성하고, obj2에 참조로 저장
    obj2.showNum(); // obj2 객체의 num을 출력

    delete& obj1; // obj1이 참조하는 객체를 삭제
    delete& obj2; // obj2이 참조하는 객체를 삭제
    return 0;
}