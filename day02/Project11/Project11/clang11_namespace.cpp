#include <iostream>


// namespace BestComImpl { ... } 
// -> BestComImpl이라는 네임스페이스를 정의. 
// --> 네임스페이스는 변수, 함수, 클래스 등을 그룹화하여, 
// --->전역 범위에서의 이름 충돌을 방지.

// void SimpleFunc(void) { ... }
// -> BestComImpl 네임스페이스 내에 정의된 SimpleFunc 함수.
// --> 이 함수는 "BestCom이 정의한 함수"를 출력
namespace BestComImpl {
    void SimpleFunc(void) {
        std::cout << "BestCom이 정의한 함수 " << std::endl;
    }
}


// namespace ProgComImpl { ... }
// -> ProgComImpl이라는 네임스페이스를 정의.

// void SimpleFunc(void) { ... } 
// -> ProgComImpl 네임스페이스 내에 정의된 SimpleFunc 함수.
// --> 이 함수는 "ProgCom이 정의한 함수"를 출력합니다.
namespace ProgComImpl {
    void SimpleFunc(void) {
        std::cout << "ProgCom이 정의한 함수 " << std::endl;
    }
}
int main(void) {
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}

// BestComImpl 네임스페이스 
// -> SimpleFunc 함수가 정의.
// -->이 함수는 "BestCom이 정의한 함수" 출력.

// ProgComImpl 네임스페이스
// -> SimpleFunc 함수가 정의.
// --> 이 함수는 "ProgCom이 정의한 함수"를 출력.