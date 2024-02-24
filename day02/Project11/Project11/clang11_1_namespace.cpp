#include <iostream>


namespace BestComImpl {
    void SimpleFunc(void);
}


namespace ProgComImpl {
    void SimpleFunc(void);
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




// BestComImpl 네임스페이스에 정의된 SimpleFunc 함수를 구현. 
// --> 이 함수는 "BestCom이 정의한 함수"를 출력.
void BestComImpl::SimpleFunc(void){
    std::cout << "BestCom이 정의한 함수" << std::endl;;
}


// ProgComImpl 네임스페이스에 정의된 SimpleFunc 함수를 구현. 
// --> 이 함수는 "BestCom이 정의한 함수"를 출력.
void ProgComImpl::SimpleFunc(void) {
    std::cout << "BestCom이 정의한 함수" << std::endl;;
}