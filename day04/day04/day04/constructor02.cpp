#include <iostream>
using namespace std;

// SimpleClass 클래스 정의
class SimpleClass {
private:
    int num1; // 첫 번째 정수 멤버 변수
    int num2; // 두 번째 정수 멤버 변수

public:
    // 기본 생성자: 모든 멤버 변수를 0으로 초기화
    SimpleClass()
    {
        num1 = 0;
        num2 = 0;
    }

    // 하나의 정수를 받는 생성자: num1을 받은 정수로 초기화하고, num2는 0으로 초기화
    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }

    // 두 개의 정수를 받는 생성자: 각각 num1과 num2를 받은 정수로 초기화
    SimpleClass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }

    /*
    // 두 개의 정수를 받는 생성자입니다.
    // 매개변수로 받은 값으로 객체의 멤버 변수들을 초기화합니다.
    // 매개변수가 생략될 경우에는 각각 0으로 초기화됩니다.
    SimpleClass(int n1 = 0, int n2 = 0)
        {
            num1 = n1; // 첫 번째 매개변수로 받은 값을 num1에 할당합니다.
            num2 = n2; // 두 번째 매개변수로 받은 값을 num2에 할당합니다.
        }

    */

    // 멤버 변수들을 출력하는 함수
    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void) {
    // 객체 생성 및 초기화 후 출력
    SimpleClass sc1; // 기본 생성자 호출
    sc1.ShowData();

    SimpleClass sc2; // 기본 생성자 호출
    sc2.ShowData();

    SimpleClass sc3(100, 200); // 두 개의 정수를 받는 생성자 호출
    sc3.ShowData();
    return 0;
}