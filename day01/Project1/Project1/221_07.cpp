// 계산기 만들기

#include <iostream>

using namespace std;

int add(int a, int b) {
	int result = 0;
	result = a + b;
	return result;
}

int minu(int a, int b) {
	int result = 0;
	result = a - b;
	return result;
}

int multi(int a, int b) {
	int result = 0;
	result = a * b;
	return result;
}

int divid(int a, int b) {
	int result = 0;
	result = a / b;
	return result;
}

int main()
{
	int n1, n2 = 0;
	char op;
	cout << "첫번째 정수 입력> ";
	cin >> n1;

	//cout << "n1:" << n1 << endl;

	cout << "연산자 입력 (+, -, *, /) > ";
	cin >> op;

	cout << "두번째 정수 입력> ";
	cin >> n2;
	

		if (op == ' +') {
			cout<< "결과: "<< add(n1, n2)<< endl;
		}
		else if (op == '-') {
			cout << "결과: " << minu(n1, n2) << endl;
		}
		else if (op == '*') {
			cout << "결과: " << multi(n1, n2) << endl;
		}
		else if (op == '/') {
			cout << "결과: " << divid(n1, n2) << endl;
		}
	return 0;
}
