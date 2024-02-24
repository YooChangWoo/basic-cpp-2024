#include <iostream>


// 인라인 함수를 사용하여,
// 제곱을 계산하는 매크로 함수 정의
inline int SQUARE(int x)
{
	return x * x;
}


// SQUARE 매크로 함수 호출 
// 결과 출력 하는 main
int main(void) {

	// 5의 제곱인 25 출력
	std::cout << SQUARE(5) << std::endl;   

	// 12의 제곱인 144 출력
	std::cout << SQUARE(12) << std::endl;  
	return 0;
}