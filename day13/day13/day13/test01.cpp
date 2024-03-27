#include <iostream>
using namespace std;

void cal(int _n1, int _n2)
{
	if ( !_n1 ) throw _n2;
	cout << "+: " << _n1 + _n2 << endl;
	cout << "-: " << _n1 - _n2 << endl;
	cout << "*: " << _n1 * _n2 << endl;
	cout << "/: " << _n1 / _n2 << endl;

}

int main(int argc, char* argv[])
{
	int n1, n2;
	cout << "정수 2개를 입력하세요:" << endl;
	cin >> n1 >> n2;
	try {
	cal(n1, n2);
	}
	catch ( int exception ) {
		cout << "0으로 나눌 수 없습니다. " << endl;
	}
	return 0;
}