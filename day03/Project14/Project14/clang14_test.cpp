#include <iostream>
using namespace std;


int main(void)
{
	// 상수를 선언 할때는 바로 초기화 해야만 함
	const int num = 10; 

	int& ref = num;  
	
	return 0;
}