// ���� �����

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
	cout << "ù��° ���� �Է�> ";
	cin >> n1;

	//cout << "n1:" << n1 << endl;

	cout << "������ �Է� (+, -, *, /) > ";
	cin >> op;

	cout << "�ι�° ���� �Է�> ";
	cin >> n2;
	

		if (op == ' +') {
			cout<< "���: "<< add(n1, n2)<< endl;
		}
		else if (op == '-') {
			cout << "���: " << minu(n1, n2) << endl;
		}
		else if (op == '*') {
			cout << "���: " << multi(n1, n2) << endl;
		}
		else if (op == '/') {
			cout << "���: " << divid(n1, n2) << endl;
		}
	return 0;
}
