#include <iostream>
using namespace std;

int& refRetFuncOne(int& ref) { //refreturn1.cpp의 refRetFuncone과 동일
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = refRetFuncOne(num1); // num2 = 2

	num1+=1;// num1 = 3
	num2+=100;// num2 = 102
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}