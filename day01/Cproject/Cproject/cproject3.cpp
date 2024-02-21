#include <iostream>

using namespace std; // std 네임스페이스의 모든 것을 사용

/*
	선택제어문: Switch
	
*/
int main()
{
	int inKey;
	cout << "put Int > " << endl;
	cin >> inKey;

    switch (inKey) {
    case 5:
        cout << "Bingo" << endl;
        break;

    // 5보다 큰 경우
    case 6:
        cout << "This is 6, Number Down" << endl; 
        break;
    case 7:
        cout << "This is 7, Number Down" << endl;
        break;
    case 8:
        cout << "This is 8, Number Down" << endl;
        break;
    case 9:
        cout << "This is 9, Number Down" << endl;
        break;
    case 10:
        cout << "This is 10, Number Down" << endl;
        break;

    // 5보다 작은 경우
    
    case 4: 
        cout << "This is 4, Number Up" << endl;
        break;
    case 3:
        cout << "This is 3, Number Up" << endl;
        break;
    case 2:
        cout << "This is 2, Number Up" << endl;
        break;
    case 1:
        cout << "This is 1, Number Up" << endl;
        break;
    case 0:
        cout << "This is 0, Number Up" << endl;
        break;
    default:
        cout << "Invalid input" << endl; // 기본적으로 다른 입력 값
    }


	return 0;
}

// break 문 
// -> case에 break 문 꼭 사용!! break 없어지면, 다음 case 출력값도 나옴

// default 문 
// -> 만약 위에 있는 숫자 이외에 숫자 적을 시 Invaild input 출력