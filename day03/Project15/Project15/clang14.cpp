#include <iostream>
using namespace std;

// Simple 클래스 정의
class Simple {
public:
    // 생성자: 객체가 생성될 때 호출됨
    Simple() {
        cout << "I am Computer!" << endl;
    }

    // 소멸자: 객체가 소멸될 때 호출됨
    ~Simple() {
        cout << "Destructor called!" << endl;
    }
};

int main(void) {
    cout << "Case 1: ";
    // 동적으로 Simple 객체 생성
    Simple* sp1 = new Simple;

    cout << "Case 2: ";
    // malloc 함수로 메모리 할당
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

    cout << endl << "End of main!" << endl;

    // 동적으로 할당된 객체 삭제
    delete sp1;
    // malloc으로 할당된 메모리 해제
    free(sp2);

    return 0;
}

/*
1. Simple 클래스:

- Simple 클래스는 단순한 생성자와 소멸자를 가지고 있는 클래스.
- 생성자는 객체가 생성될 때 호출되어 "I am Computer!"를 출력.
- 소멸자는 객체가 소멸될 때 호출되어 "Destructor called!"를 출력.


main 함수:

- "Case 1:" 출력 후, new 연산자를 사용하여 동적으로 Simple 객체를 생성. 생성자가 호출되어 "I am Computer!"가 출력.

- "Case 2:" 출력 후, malloc 함수를 사용하여 메모리를 할당하고, 이를 Simple 객체의 포인터에 할당. 
 -> 하지만 생성자가 호출되지 않으므로 "I am Computer!"가 출력되지 않습니다.

 - "End of main!" 출력 후, 프로그램이 종료.
- 마지막으로, delete 연산자를 사용하여 동적으로 할당된 객체를 삭제하고, free 함수를 사용하여 malloc 함수로 할당된 메모리를 해제. 
==> 두 경우 모두 소멸자가 호출되어 "Destructor called!"가 출력.
===> 이렇게 동적으로 생성된 객체는 필요 없어질 때 적절하게 삭제되어 메모리 누수를 방지
*/