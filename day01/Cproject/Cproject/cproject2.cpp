#include <iostream>

using namespace std; // std 네임스페이스의 모든 것을 사용

/*
if, else 문
*/
int main() {

	int inKey;
	cout << "put Int > " << endl;
	cin >> inKey;


	// inKey가 5이면, inKey 수 빙고 출력
	if (inKey == 5) { // if (조건식) {... 실행문}
		cout << "Bingo" << endl;
	}

	// inKey가 5다 크면, inKey 수 내려가라는 말
	else if (inKey > 5) {
		cout << "Down" << endl;
	}

	// inKey가 5보다 작으면, inKey 수 올라가라는 말
	else if (inKey < 5) {
		cout << "Up" << endl;
	}

	else cout << "Put Wrong Number > ";

	//Python elif = C/C++ else if
	return 0;
}