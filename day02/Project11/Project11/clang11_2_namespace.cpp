#include <iostream>


// BestComImpl 네임스페이스 내에 SimpleFunc 함수의 선언.
// void PrettyFunc(void);
// -> BestComImpl 네임스페이스 내에 PrettyFunc 함수의 선언.
namespace BestComImpl {
    void SimpleFunc(void);
    void PrettyFunc(void); // PrettyFunc의 선언 추가
}

namespace ProgComImpl {
    void SimpleFunc(void);
}


// 이 코드는 BestComImpl 네임스페이스에 정의된 SimpleFunc 함수를 호출. 
int main(void) {
    BestComImpl::SimpleFunc();
    return 0;
}


// BestComImpl 네임스페이스에 정의된 SimpleFunc 함수를 구현. 
// -> 이 함수는 "BestCom이 정의한 함수"를 출력, 
// --> PrettyFunc() 함수를 호출, 
// ---> ProgComImpl::SimpleFunc() 함수를 호출.
void BestComImpl::SimpleFunc(void) {
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc(); // PrettyFunc 호출
    ProgComImpl::SimpleFunc();
}

// BestComImpl 네임스페이스에 정의된 PrettyFunc 함수를 구현.
// -> 이 함수는 "So Pretty."를 출력
void BestComImpl::PrettyFunc(void) {
    std::cout << "So Pretty" << std::endl;
}

// ProgComImpl 네임스페이스에 정의된 SimpleFunc 함수를 구현. 
// -> 이 함수는 "ProgCom이 정의한 함수"를 출력함.
void ProgComImpl::SimpleFunc(void) {
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}
