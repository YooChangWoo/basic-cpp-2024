#include <iostream>

using namespace std;

int main() {
	int num = 10; // 지역변수 선언과 초기화 
	cout << "num: " << num << endl;

	int *pnum = &num;	//주소로 num변수에 접근
	int& rnum = num;	//참조로 num변수에 접근
	num = 20;

	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;

	*pnum = 30;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;

	rnum = 40;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;
	return 0;
}