#include <iostream>
using namespace std;

// 전역변수 - 프로그램 전체에서 사용가능
int global = 100; 
int global1 = 200;

int main() {
	int val = 100;

	// 지역 변수 - 선언된 범위에서만 사용가능
	global = 200; 

	int global1 = 300;

	cout << "전역변수 Global >  " << global << endl;
	cout << "지역변수 > " << val << endl;

	// 지역변수와 이름이 동일한 경우 전역변수는 가려짐
	cout << "전역변수 Global1 >" << global1 << endl;

	return 0;
}

void func() {
	int val = 0;
	global = 10;
	global1 = 10;
	val = 10;
}