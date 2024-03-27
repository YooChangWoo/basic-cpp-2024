/*#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "정수 2개 입력 : "; // 사용자에게 두 개의 숫자를 입력할 것을 요청하는 메시지 출력
    cin >> num1 >> num2; // 두 개의 숫자를 한 번에 입력 받음

    try {
        if (num1 == 0 && num2 == 0) { // 두 숫자가 모두 0이면 예외 발생
            throw string("두 숫자 다 0으로 나눌 수 없다."); // 예외 던지기
        }
        else if (num2 == 0) { // 두 번째 숫자가 0이면 예외 발생
            throw string("숫자를 0으로 나눌 수 없다."); // 예외 던지기
        }
        else { // 예외가 발생하지 않을 경우에만 사칙연산 수행
            cout << "더하기: " << num1 + num2 << endl;
            cout << "빼기: " << num1 - num2 << endl;
            cout << "곱하기: " << num1 * num2 << endl;
            cout << "나누기: " << num1 / num2 << endl;
        }
    }
    catch (string& errorMessage) { // 예외 처리
        cout << "ERROR : " << errorMessage << endl;
    }

    return 0;
}  이거를 예외처리 함수 만들기 */


#include <iostream>
using namespace std;

// 예외 처리를 포함한 사칙연산을 수행하는 함수
void calculate(double num1, double num2) {
    try {
        // 예외 처리: 두 숫자가 모두 0이면 나눗셈이 불가능한 경우
        if ( num1 == 0 && num2 == 0 ) {
            throw string("두 숫자 다 0으로 나눌 수 없습니다."); // 오류 메시지를 던짐
        }
        // 예외 처리: 두 번째 숫자가 0이면 나눗셈이 불가능한 경우
        else if ( num2 == 0 ) {
            throw string("숫자를 0으로 나눌 수 없습니다."); // 오류 메시지를 던짐
        }
        // 예외가 발생하지 않으면 사칙연산을 수행하여 결과 출력
        else {
            cout << "더하기: " << num1 + num2 << endl; // 덧셈 결과 출력
            cout << "빼기: " << num1 - num2 << endl;   // 뺄셈 결과 출력
            cout << "곱하기: " << num1 * num2 << endl; // 곱셈 결과 출력
            cout << "나누기: " << num1 / num2 << endl; // 나눗셈 결과 출력
        }
    }
    // 예외 처리: string 타입의 오류 메시지를 받아서 출력
    catch ( string& errorMessage ) {
        cout << "ERROR: " << errorMessage << endl; // 오류 메시지 출력
    }
}

int main() {
    double num1, num2;

    // 사용자로부터 두 개의 숫자를 입력 받음
    cout << "정수 2개 입력: ";
    cin >> num1 >> num2;

    // calculate 함수를 호출하여 입력받은 숫자로 사칙연산 수행
    calculate(num1, num2);

    return 0;
}

/*
int main(int argc, char *argv[])
{
    int n1, n2;
    cout << "정수 2개를 입력 하시오";
    cin >> n1 >> n2;
    try {
        cal(n1, n2);
    }
    catch (int exception){
        cout<< "0으로 나눌수 없습니다" << endl;
    }
}
*/