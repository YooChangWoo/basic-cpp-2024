/*
#include <iostream>

int gloval = 100; //

void func() {
	int a;
	a = 100;
	gloval = 200;
}

int main()
{
	int a;
	int val;       // 메모리공간(RAM)에 int크기로 저장공간을 할당받고 val이름으로 사용한다.
	std::cout << "숫자입력: ";
	std::cin >> val;

	std::cout << "입력한 숫자는" << val << "입니다." << std::endl;
	a = 10;
	val = 100;
	gloval = 300;
	return 0;
}


int main()
{
	int val1, val2;
	int result = 0;  // 변수 선언과 동시에 값을 대입 : 변수 초기화
	// int val1;
	// int val2;
}/*
/*
  지역변수 = 로컬변수 : 선언되어진 범위 안에서만 사용이 가능(static 영역에 저장)
  전형변수 = 소속이 되어있지 않기 때문에 어디서든 사용 가능
*/
/*
#include <iostream>

int main(void)
{
	int val1, val2;
	int result = 0;
	std::cout << "두 개의 숫자입력: ";
	std::cin >> val1 >> va12;

	if (val1 < val2)
	{
		for (int i = val1 + 1; i < val2; i++)
			result += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			result + i;
	}

	std::cout << "두 수 사이의 정수 합: " << result << std::endl;
	return 0;
}
*/

/*
  제어문
    1. 선택제어문
	    if, switch
	2. 반복제어문
	    for, while

	*for(초기식; 조건식 : 증감식)  {
	    1. 초기식을 가지고 조건식을 따진다.
		2. 참이면 for문의 실행문을 실행하고
		3. 증감식을 실행한다.
		4. 조건식을 따지고
		5. 반복한다
	* }
*/