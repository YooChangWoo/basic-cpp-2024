#include <iostream>

using namespace std; // std 네임스페이스의 모든 것을 사용

int main()
{
	int inKey;
	cout << "숫자 하나를 입력 > " << endl;
	cin >> inKey;

    for (int i = 0; i <= 10; ++i) {

        // 입력 값이 5를 입력 받으면 'Bingo'출력
        if (inKey == 5) { 
            cout << "Bingo" << endl;
            break;
        }

        // 입력 값이 5를 넘어버리면, 내리라고 'Down' 출력
        else if (inKey > 5) {
            cout << "Down" << endl;
            break;
        }

        // 입력 값이 5보다 작으면, 올리라고 'Up' 출력
        else if (inKey < 5) {
            cout << "Up" << endl;
            break;
        }
    }

	return 0;

}