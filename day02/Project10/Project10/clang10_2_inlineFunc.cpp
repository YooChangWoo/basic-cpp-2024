#include <iostream>

// 인라인 함수를 사용하여 제곱을 계산하는 함수 정의
inline int SQUARE(int x)
{
    return x * x;
}

// main 함수
int main(void) {
    // SQUARE 함수 호출 및 결과 출력
    std::cout << "5의 제곱: " << SQUARE(5) << std::endl;   // 5의 제곱인 25 출력
    std::cout << "12의 제곱: " << SQUARE(12) << std::endl;  // 12의 제곱인 144 출력
    return 0;
}
