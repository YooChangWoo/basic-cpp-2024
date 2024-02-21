#include <iostream>

using namespace std;

int main() {
    int num1, num2;

    // 사용자로부터 두 개의 숫자 입력 받기
    cout << "첫 번째 숫자를 입력하세요: ";
    cin >> num1; // cin에 num1 저장

    cout << "두 번째 숫자를 입력하세요: ";
    cin >> num2; // cin에 num2 저장

    // 입력받은 두 숫자의(num1, num2) 합 계산
    int sum = num1 + num2;
    int sub = num1 - num2;
    int multi = num1 * num2;
    int div = num1 / num2;

    // 결과 출력
    cout << "두 숫자의 합: " << sum << endl;
    cout << "두 숫자의 빼기: " << sub << endl;
    cout << "두 숫자의 곱: " << multi << endl;
    cout << "두 숫자의 곱: " << div << endl;

    return 0;
}
