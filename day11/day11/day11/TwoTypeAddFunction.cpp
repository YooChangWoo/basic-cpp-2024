#include <iostream>
using namespace std;

// 템플릿 함수 선언
template <typename T>
T Add(T num1, T num2)
{
    // T 타입을 사용하는 템플릿 함수
    cout << "T Add(T num1, T num2)" << endl;
    return num1 + num2;
}

// 정수형 매개변수를 받는 함수
int Add(int num1, int num2)
{
    cout << "Add(int num1, int num2)" << endl;
    return num1 + num2;
}

// 실수형 매개변수를 받는 함수
double Add(double num1, double num2)
{
    cout << "Add(double num1, double num2)" << endl;
    return num1 + num2;
}

int main(void)
{
    // 함수 호출 및 결과 출력
    cout << Add(5, 7) << endl;                     // 정수형 함수 호출
    cout << Add(3.7, 7.5) << endl;                 // 실수형 함수 호출
    cout << Add<int>(5, 7) << endl;                // 템플릿 함수에 int 타입으로 호출
    cout << Add<double>(3.7, 7.5) << endl;         // 템플릿 함수에 double 타입으로 호출
    return 0;
}
/*
템플릿 함수와 오버로딩:
Add 함수는 템플릿 함수와 오버로딩을 모두 사용합니다
. 템플릿 함수는 함수의 다양한 타입을 처리하고,
오버로딩된 함수는 특정 타입에 대한 동작을 정의합니다.

함수 호출과 다형성:
Add 함수는 함수 호출 시 전달되는 인자의 타입에 따라 적절한 버전의 함수를 호출합니다.
이는 다형성(polymorphism)의 한 형태입니다.

템플릿 함수와 오버로딩의 우선순위:
템플릿 함수와 오버로딩된 함수 중에서 호출할 함수를 선택할 때,
호출 문맥에서 가장 적합한 것이 선택됩니다.

함수 호출 시 타입 지정:
함수 호출 시 <타입>을 사용하여 특정 타입의 함수를 호출할 수 있습니다.
이것은 템플릿 함수가 아닌 특정한 버전의 함수를 호출하는 방법입니다
*/