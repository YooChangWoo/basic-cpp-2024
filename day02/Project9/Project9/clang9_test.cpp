#include <iostream>

// 두 정수를 입력받아 더한 값을 반환하는 함수.
// 매개변수가 주어지지 않으면 num1은 기본적으로 1, num2는 기본적으로 2로 설정됨.
int adder(int num1 = 1, int num2 = 2)
{
	return num1 + num2;
}

int main(void)
{
	// 각각의 호출에 대한 결과를 출력
	// adder() 호출: 기본 매개변수를 사용하여 1 + 2 = 3을 반환
	std::cout << adder() << std::endl;   

	// adder(5) 호출: 첫 번째 매개변수는 5, 두 번째 매개변수는 기본값 2를 사용하여 5 + 2 = 7을 반환
	std::cout << adder(5) << std::endl;

	// adder(3, 5) 호출: 첫 번째 매개변수는 3, 두 번째 매개변수는 5로 주어져 3 + 5 = 8을 반환
	std::cout << adder(3, 5) << std::endl; 

	return 0;
}