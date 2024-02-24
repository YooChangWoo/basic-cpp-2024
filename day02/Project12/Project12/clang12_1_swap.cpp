#include <iostream>
using namespace std;

/*
    swap 함수 구현하기
*/
void swap(int *aa, int *bb) { // 주소받을수 있는 포인터 변수를 선언
    int temp = *aa;
    *aa = *bb; // 주소의 데이터를 참조
    *bb = temp;

    // swap 함수를 정의. 이 함수는 두 개의 참조 매개변수 a와 b를 받아서, 이들의 값을 교환.
    // int temp = x; -> 임시 변수 temp를 선언하고, x의 값을 저장.
    // x = y; ->  x에 y의 값을 대입.
    // y = temp; -> y에 임시 변수 temp의 값을 대입하여 교환합니다.

    
    
    

}


int main() {
    int a = 10;
    int b = 20;

    cout << "before" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(a, b);

    cout << "after" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
int& num2 = num1; // num2 -> num1의 참조
int& num2 = 100; // c++의 리터럴 값

int num = 10;   // 일반적인 변수 선언
int* ptr = &num1; // ptr -> num1 포인터
int& num2 = num1; //이미 위에서 num2 -> num1의 참조로 선언


