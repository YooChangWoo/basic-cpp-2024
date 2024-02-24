#include <iostream>
int adder(int num1 = 1, int num2 = 2) { //함수 정의
        return num1 + num2;
    }

int main(void)
{
    int count = 0; // 반복 횟수를 제어하는 변수

    while (count < 3) // count가 3보다 작을 때까지 반복
    {
        // adder() 호출: 기본 매개변수를 사용하여 1 + 2 = 3을 반환
        if (count == 0) {
            std::cout << "adder() 호출: 기본 매개변수를 사용하여 ";
            std::cout << adder() << "을 반환" << std::endl;
        }
        // adder(5) 호출: 첫 번째 매개변수는 5, 두 번째 매개변수는 기본값 2를 사용하여 5 + 2 = 7을 반환
        else if (count == 1) {
            std::cout << "adder(5) 호출: 첫 번째 매개변수는 5, ";
            std::cout << "두 번째 매개변수는 기본값 2를 사용하여 ";
            std::cout << adder(5) << "을 반환" << std::endl;
        }
        // adder(3, 5) 호출: 첫 번째 매개변수는 3, 두 번째 매개변수는 5로 주어져 3 + 5 = 8을 반환
        else if (count == 2) {
            std::cout << "adder(3, 5) 호출: 첫 번째 매개변수는 3, ";
            std::cout << "두 번째 매개변수는 5로 주어져 ";
            std::cout << adder(3, 5) << "을 반환" << std::endl;
        }

        count++; // 반복 횟수 증가
    }

    return 0;
}

// class 안에 들어 가는 함수 = Method