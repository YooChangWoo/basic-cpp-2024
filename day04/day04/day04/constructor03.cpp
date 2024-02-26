#include <iostream>
using namespace std;

// SimpleClass 클래스 정의
class SimpleClass {
private:
    int num1; // 첫 번째 정수 멤버 변수
    int num2; // 두 번째 정수 멤버 변수

public:
    // 생성자 정의
    SimpleClass(int n1 = 0, int n2 = 0)
    {
        num1 = n1; // 첫 번째 매개변수로 받은 값을 num1에 할당합니다.
        num2 = n2; // 두 번째 매개변수로 받은 값을 num2에 할당합니다.
    }

    // 멤버 변수들을 출력하는 함수
    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void) {
    // 객체 생성 및 초기화 후 출력
    SimpleClass sc1; // 기본 생성자 호출 -> 함수의 선언
    SimpleClass mysc = sc1; // my객체 복사
    mysc.ShowData();
    return 0;
}


SimpleClass sc1() {
    SimpleClass sc(20, 30); // SimpleClass 타입의 객체를 생성하고 초기화합니다.
    return sc;
}