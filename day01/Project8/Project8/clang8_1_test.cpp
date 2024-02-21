#include <iostream>

using namespace std;

// 두 숫자의 합을 계산하는 함수
int add(int a, int b) {
    return a + b;
}

// 두 숫자의 차를 계산하는 함수
int subtract(int a, int b) {
    return a - b;
}

// 두 숫자의 곱을 계산하는 함수
int multiply(int a, int b) {
    return a * b;
}

// 두 숫자의 나눗셈을 계산하는 함수
// 주의: 나눗셈에서 두 번째 숫자가 0인 경우에는 오류가 발생할 수 있으므로 이에 대한 처리가 필요합니다.
// 이 예제에서는 오류 처리를 하지 않았습니다.
int divide(int a, int b) {
    return a / b;
}

int main() {
    int num1, num2;

    // 사용자로부터 두 개의 숫자 입력 받기
    cout << "첫 번째 숫자를 입력하세요: ";
    cin >> num1; // cin에 num1 저장

    cout << "두 번째 숫자를 입력하세요: ";
    cin >> num2; // cin에 num2 저장

    // 결과 출력
    cout << "두 숫자의 합: " << add(num1, num2) << endl;
    cout << "두 숫자의 빼기: " << subtract(num1, num2) << endl;
    cout << "두 숫자의 곱: " << multiply(num1, num2) << endl;
    cout << "두 숫자의 나누기: " << divide(num1, num2) << endl;

    return 0;
}
