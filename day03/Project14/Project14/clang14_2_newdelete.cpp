#include <iostream>
#include <string.h>
#include <cstdlib> // <stdlib.h> 대신 <cstdlib> 헤더를 사


#define _CRT_SECURE_NO_WARNINGS


using namespace std;

char* MakeStrAdr(int len)
{
    // char* str = (char*)malloc(sizeof(char) * len); // C: HEAP영역에 메모리 할당 => 20byte 크기
    char* str = new char[len];
    printf("char size : %llu\n", sizeof(char));
    return str;
}
/*
1. MakeStrAdr 함수는 정수 len을 매개변수로 받아서 길이가 len인 문자열을 동적으로 할당.
2. new 연산자를 사용하여 길이가 len인 문자열을 위한 메모리를 동적으로 할당하고, 그 메모리의 시작 주소를 가리키는 포인터 str을 반환.
3. printf("char size : %llu\n", sizeof(char));는 char 데이터 타입의 크기를 출력하는 코드.
*/


int main(void) {
    char* str = MakeStrAdr(20);
    strcpy(str, "I am So Happy~");
    cout << str << endl;
    //free(str);
    delete []str; // C++ => 할당 받은 메모리를 반환 하는 부분
    return 0;
}


/*
1. main 함수 => 먼저 MakeStrAdr 함수를 호출하여 길이가 20인 문자열을 동적으로 할당하고 이에 대한 포인터를 str에 저장.
2. strcpy 함수 => 사용하여 "I am So Happy~"라는 문자열을 str이 가리키는 메모리에 복사.
3. cout을 사용하여 -> str이 가리키는 문자열을 출력.
4. delete []str; => new 연산자를 사용하여 할당된 배열 형태의 메모리를 해제하는 코드. 
    -> delete와 []를 함께 사용하여 배열 형태의 메모리를 해제.
    
    객체지향 = 클래스
    new 라는 연산자 사용해서 만듬
    생성되는 곳 => Heap
    포인터 
    */