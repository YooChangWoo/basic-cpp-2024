#include <iostream>

using namespace std;

class Myclass {
private:
    int x; // private 멤버 변수 x 선언

public:
    // 생성자 정의, 기본값은 0
    Myclass(int y = 0) : x(y)
    { }
    // 멤버 변수 x 출력하는 함수, const 함수로 선언
    void print() const
    {
        cout << "value: " << x << endl;
    }

    // 두 Myclass 객체를 더하는 연산자 오버로딩
    Myclass operator+(const Myclass& ref)
    {
        Myclass z(x + ref.x); // 현재 객체의 x와 ref 객체의 x를 더한 값을 가지는 객체 z 생성
        return z; // z 객체 반환
    }
};

int main()
{
    Myclass a(10); // Myclass 객체 a 생성 및 초기화
    a.print();                        // value: 10 출력

    Myclass b(a); // Myclass 객체 b를 a로 복사하여 생성
    b.print();                        // value: 10 출력

    Myclass c(b); // Myclass 객체 c를 b로 복사하여 생성
    c.print();                        // value: 10 출력

    Myclass d = a + b + c; // Myclass 객체 d에 a, b, c를 더한 값을 저장
    d.print();                        // value: 30 출력
    return 0;
}

/*
메인 함수 (main):

main() 함수에서는 Myclass 객체들을 생성하고 초기화합니다.
생성한 객체들의 print() 함수를 호출하여 x 값을 출력합니다.
Myclass 객체들을 더한 결과를 새로운 객체에 저장하고, 이를 출력합니다.

연산자 오버로딩:

+ 연산자가 오버로딩되어 두 개의 Myclass 객체를 더할 수 있도록 합니다.
operator+() 함수 내에서 두 객체의 x 값을 더하여 새로운 객체를 생성하여 반환합니다.

객체 생성 및 복사:

객체들이 생성되고 복사 생성자가 호출되어 객체를 복사합니다.
이러한 복사 과정에서는 객체의 멤버 변수들이 적절히 복사됩니다.

연산 및 출력:

객체들 간의 연산과 이에 따른 결과가 올바르게 출력됩니다.
객체의 상태를 변경하지 않는 함수는 const로 선언하여 안정성을 높입니다.
*/