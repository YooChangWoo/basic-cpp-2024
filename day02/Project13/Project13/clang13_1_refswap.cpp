#include <iostream>
using namespace std;

/*
    reference swap 함수 구현하기
*/

// swap 함수는 두 개의 정수형 참조 매개변수 x와 y를 받음.
// 함수 내부에서는 임시 변수 temp를 사용하여 x의 값을 저장 후 
// x에 y의 값을 대입한 후에 y에 temp의 값을 대입하여 두 변수의 값을 교환함.

void swap(int &ref1, int &ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}



int main() 
{
    int val1 = 10;
    int val2 = 20;

    swap(val1, val2);
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

    

    return 0;
}
