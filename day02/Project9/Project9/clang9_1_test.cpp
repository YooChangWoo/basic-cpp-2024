#include <iostream>

// adder 함수의 선언: 두 개의 정수를 매개변수로 받고, 기본값으로 각각 num1 = 1과 num2 = 2를 가짐
int adder(int num1 = 1, int num2 = 2);

int main(void)
{
    // adder 함수 호출 및 결과 출력
    std::cout << adder() << std::endl;     // 1 + 2 = 3
    std::cout << adder(5) << std::endl;    // 5 + 2 = 7
    std::cout << adder(3, 5) << std::endl; // 3 + 5 = 8

    return 0;
}

// adder 함수의 정의: 두 개의 정수를 매개변수로 받아서 합을 반환
int adder(int num1, int num2) {
    return num1 + num2;
}