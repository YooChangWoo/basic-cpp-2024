#include <iostream> 


//출력, 입력
int main(void) {
	// 메모리 값 = 할당 받아야 할 사이즈 = int 값... 
	// 여기 코드 작성 할 때에는 c++ 코드 = int 자료형 사이즈 = 10을 입출력 받아서 씀!
	int a = 10; //int => type, 자료형(크기)** 이거만 외우자, 컴파일 크기 다름, 고정적이지 않음


	// 문자, 문자열 = 문자 1개, 2개이상의 문자 = 문자열
	// 문자 = ' ', 문자열 = " " => 무조건 중요 잘 확인...
	// << => "Hello World"  -> std::count에 출력, std::endl 도 std::count -> 출력
	std::cout << "Hello World!" << std::endl; //std = 안에 들어가서 std::endl -> 대행 시키는것, 이번줄 끝내는 것
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << a << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	return 0;
}


// 헤더파일 선언문 = #include <iostream>
// c언어에서는 <stdio.h> 사용
// std::cout + << => 이용하여 출력
// std::endl => 끝