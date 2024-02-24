#include <iostream>

// 매크로 함수를 사용하여 
// 제곱을 계산하는 매크로 함수 정의
#define SQUARE(x) ((x)*(x))

int main(void) {
    // SQUARE 매크로 함수 호출 -> 결과 출력

    // 5의 제곱인 25 출력
    std::cout << "5의 제곱: " << 5 * 5 << std::endl; 

    // 12의 제곱인 144 출력
    std::cout << "12의 제곱: " << 12 * 12 << std::endl;  
    return 0;
}
