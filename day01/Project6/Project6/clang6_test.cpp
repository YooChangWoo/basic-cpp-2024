#include <iostream>

int main(void) {

	
	char name[100];
	char lang[200];



	std::cout << "What is your name? => ";
	std::cin >> name;

	std::cout << "좋아하는 Program => ";
	std::cin >> lang;

	std::cout << "My name is " <<name<<"입니다 \n";
	std::cout << "좋아하는 Program is " << lang << "입니다"<< std::endl;
	return 0; // 프로그램의 정상 종료를 나타냄.
}

// 자료형
// 문자 : 문자(char),문자열
// 숫자 : 정수(int),실수

// 1.char부분:
// -> 크기가 각각 100, 200인 문자 배열 name과 lang을 선언. 
// --> 이 배열들은 사용자로부터 입력을 받을 때 사용.

// 2. std  cout << name 부분: 
// -> 사용자에게 이름을 묻는 프롬프트를 출력

// 2 - 1. std cin << name 부분: 
// -> 사용자가 입력한 이름을 name 배열에 저장

// 3. std  cout << program 부분:
// -> 사용자에게 어떤 프로그래밍 언어를 좋아하는지 묻는 프롬프트를 출력

// 3 - 1. std cin << lang 부분:
// -> 사용자가 입력한 좋아하는 프로그래밍 언어를 lang 배열에 저장 

// 4. std::cout << "My name is " <<name<<"입니다 \n" : 
// -> 사용자가 입력한 이름을 출력 

// 5. std::cout << "좋아하는 Program is " << lang << "입니다" << std::endl : 
// -> 사용자가 입력한 좋아하는 프로그래밍 언어를 출력

