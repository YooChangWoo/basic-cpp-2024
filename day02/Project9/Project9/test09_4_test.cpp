#include <iostream>

// adder 함수의 선언: 두 개의 정수를 매개변수로 받고, 기본값으로 각각 num1 = 1과 num2 = 2를 가짐
int BoxVolume(int length, int width = 1, int height = 1);

int main(void)
{
    // adder 함수 호출 및 결과 출력
    std::cout << "[3, 3, 3] :" << BoxVolume(3,3,3) << std::endl;     // 1 + 2 = 3
    std::cout << "[5, 5, D] :" << BoxVolume(5,5) << std::endl;
    std::cout << "[7, D, D] :" << BoxVolume(7) << std::endl;
    std::cout << "[D, D, D] :" << BoxVolume(7) << std::endl;

    return 0;
}

// adder 함수의 정의: 두 개의 정수를 매개변수로 받아서 합을 반환
int adder(int num1, int num2) {
    return num1 + num2;
}