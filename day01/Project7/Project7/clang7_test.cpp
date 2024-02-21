#include <iostream>

using namespace std;

void MyFunc(void)
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
	std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main() 
{
	// 매개변수가 없는 MyFunc(void) 함수를 호출.
	// 이는 void MyFunc(void)가 호출.
	MyFunc();

	// 문자 'A'를 매개변수로 갖는 MyFunc(char c) 함수를 호출. 
	// -> 이는 void MyFunc(char c)가 호출.
	MyFunc('A');

	// 두 개의 정수 12와 13을 매개변수로 갖는 MyFunc(int a, int b) 함수를 호출.
	// 이는 void MyFunc(int a, int b)가 호출.
	MyFunc(12,13);
	return 0;
}