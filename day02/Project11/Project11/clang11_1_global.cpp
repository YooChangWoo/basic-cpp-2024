#include <iostream>
using namespace std;

int main() {

	// num변수를 상수화
	const int num = 10;

	// num이 상수이므로 변경 안됨
	// num = 100;

	int num1 = 10;
	int* pnum1;  // 포인터변수 pnum1 선언 => * : 그냥 아무런 의미 없는 기호
	pnum1 = &num1; // -> 변수 NUM1의 주소값을 포인터 변수 PNUM1에 저장함

	cout << "num에 저장된 값: " << num << endl;
	cout << "num1에 저장된 값: " << num1 << endl;
	cout << "num1의 주소값: " << &num << endl;
	cout << "pnum1에 저장된 값: " << pnum1 << endl;
	cout << "Pnum1에 저장된 놈의 데이터: " << *pnum1 << endl; //num의 값이랑 같음

	return 0;
}

