#include <iostream>

/*int gloval -> 전역 변수(프로그램의 어디에서든지 접근할 수 있는 변수) */
int gloval = 100;


/* a = func() 함수 내에서만 접근할 수 있음, 다른 함수 -> 외부에서는 사용할 수 없음 */
void func() {
	int a = 100; // a  = 지역변수 -> 특정 범위(scope) 내에서만 접근할 수 있는 변수
}

int main(void)
{
	int a;
	int val1;
	std::cout << "첫번째 숫자 입력:";
	std::cin >> val1;

	int val2;
	std::cout << "두번째 숫자 입력:";
	std::cin >> val2;

	val1 = 100; // 여기서 지정해놓고, 추후에 cmd 틀었을때, 다른 값 넣어도 val1 = 100 으로 출력
	a = 10;
	gloval = 300;

	int result = val1 + val2;
	std::cout << "Add Result: " << result << std::endl;
	std::cout << a <<'+' << gloval << std::endl;
	return 0;
}

// 0. val1+ val2 = 두 개의 정수형 변수를 선언.
// -> val1+ val2 = 사용자로 <- 입력을 받을 숫자 = 저장할 변수
// => 메모리 공간(Ram) -> int 크기로 저장공간을 할당 => val 이름 사용

// 1. std::cout = 객체를 사용 -> 텍스트를 표준 출력 스트림 => 출력

// 2. std::cin 객체 = 사용하여 사용자로부터 입력을 받음. 
// 사용자가 키보드로 숫자를 입력 -> 해당 숫자가 각각 val1과 val2 변수에 저장

// 3. std::cout << "Add Result: " << result << std::endl;
// => 계산된 결과를 표준 출력 스트림으로 출력. 
// =>"Add Result: "와 result 변수의 값을 출력.
// std::endl은 새 줄을 생성하는 역할을 합니다.

// 4. return 0; 
// -> main 함수의 종료를 나타냄. 
// => 반환 값 0은 프로그램이 성공적으로 종료되었음을 나타냄.

// 5. 출력창
// cmd 출력후 숫자 입력 받고
// -> 숫자나 문자 받고, 다쓰면 무조건 엔터 치기

// 6. C++ 
// <<, >> => 화살표 방향 잘 확인
// 데이터의 입력, 출력 마찬가지로 별도의 포맷지정 -> 필요 x

/*
지역변수 = 로컬변수 => 선언되어진 범위 안에서만 사용 O
*/