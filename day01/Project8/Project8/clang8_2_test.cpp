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
int divide(int a, int b) {
    if (a == 0 || b == 0) {
        cout << "0으로 나눌 수 없습니다." << endl;
        exit(1); // 프로그램 종료
        }
        return a / b;
}


int main() {
    int num1, num2;
    char op;

    // 사용자로부터 두 개의 숫자와 연산자 입력 받기
    cout << "첫 번째 숫자를 입력하세요: ";
    cin >> num1; // cin에 num1 저장

    cout << "연산자를 입력하세요 (+, -, *, /): ";
    cin >> op; // cin에 op 저장

    cout << "두 번째 숫자를 입력하세요: ";
    cin >> num2; // cin에 num2 저장

    // 연산에 따라 결과 출력
    switch (op) {
    case '+':
        cout << "결과: " << add(num1, num2) << endl;
        break;
    case '-':
        cout << "결과: " << subtract(num1, num2) << endl;
        break;
    case '*':
        cout << "결과: " << multiply(num1, num2) << endl;
        break;
    case '/':
        cout << "결과: " << divide(num1, num2) << endl;
        break;
    default:
        cout << "잘못된 연산자입니다." << endl;
    }

    return 0;
}