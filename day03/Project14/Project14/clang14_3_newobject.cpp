#include <iostream>
#include <string.h>
#include <cstdlib> // <stdlib.h> 대신 <cstdlib> 헤더를 사용
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 또다른 타입
class Simple {
public:
    Simple()
    {
        cout <<  "I am Computer !" << endl;
    }
};

/*
1. Simple 클래스에 소멸자가 추가.
 => 동적으로 할당된 메모리를 해제하기 위해 소멸자에서 delete 연산이 수행

 => 소멸자를 추가한 이유는 동적으로 할당된 객체가 더 이상 필요하지 않을 때 해당 객체의 메모리를 해제하기 위해서.

C++에서 객체가 동적으로 할당되면 메모리는 프로그램의 힙(heap)에 할당. 
-> 객체가 더 이상 필요하지 않을 때에는 해당 메모리를 해제. 
-> 소멸자는 객체가 소멸될 때 호출되는 특별한 멤버 함수로서, 주로 객체가 더 이상 필요하지 않을 때 할당된 리소스를 해제하기 위해 사용됨.

위 코드에서는 Simple 클래스가 동적으로 할당된 두 개의 객체를 생성. 
-> 이들 객체는 각각 new 연산자와 malloc 함수를 사용하여 동적으로 할당. 
-> 그러나 이들 객체가 더 이상 필요하지 않을 때에는 해당 메모리를 해제. 
-> 소멸자를 추가함으로써 객체가 소멸될 때 할당된 메모리를 해제가능. 
-> 이는 프로그램이 메모리를 효율적으로 관리하고 메모리 누수를 방지하는 데 도움이 됨.
*/


int main(void) {
    
    cout << " case 1: ";
    Simple* sp1 = new Simple; // 동적 => new 연산자를 통해 Simple 객체 생성
    //Aaa *ap = new Aaa;


    cout << " case 2: ";
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc 함수로 메모리 할당

    cout << endl << "end of main !" << endl;
    delete sp1; // 동적으로 할당된 객체 삭제, 객체를 반환
    free(sp2); // malloc으로 할당된 메모리 해제
    return 0;
}

/*
1. delete 연산은 동적으로 할당된 객체를 삭제하고 해당 객체의 소멸자를 호출.
2. malloc 함수로 할당된 메모리에 대해 -> free 함수를 호출하여 메모리를 해제해야 함.
*/