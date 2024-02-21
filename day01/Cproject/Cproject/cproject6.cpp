#include <iostream>

using namespace std; // std 네임스페이스의 모든 것을 사용

/*
반복제어문:while
*/
int main() {

    int inKey;
    cout << "put Int > " << endl;
    cin >> inKey;

    while (true) {
        cout << "Enter a number: ";
        cin >> inKey;

        switch (inKey) {
        case 5:
            cout << "Bingo" << endl;
            break; // 반복문을 빠져 나올때

            // 5보다 큰 경우
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            cout << "This is " << inKey << ", Number Down" << endl;
            break;

            // 5보다 작은 경우
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            cout << "This is " << inKey << ", Number Up" << endl;
            break;

        default:


            return 0;

        }
    }
}