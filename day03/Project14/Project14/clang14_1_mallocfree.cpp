#include <iostream>
#include <string.h>
#include <cstdlib> // <stdlib.h> 대신 <cstdlib> 헤더를 사


#define _CRT_SECURE_NO_WARNINGS


using namespace std;

char* MakeStrAdr(int len)
{
    char* str = (char*)malloc(sizeof(char) * len); // C: HEAP영역에 메모리 할당 => 20byte 크기
    printf("char size : %llu\n", sizeof(char));
    return str;
}
/* 
1. MakeStrAdr 함수 => 정수 len을 매개변수로 받아서 길이가 len인 문자열을 동적으로 할당.
2. malloc 함수 => 사용하여 len만큼의 메모리를 동적으로 할당하고, 
               => 그 메모리의 시작 주소를 가리키는 포인터 str을 반환.
*/


int main(void) {
    char* str = MakeStrAdr(20);
    strcpy(str, "I am So Happy~");
    cout << str << endl;
    free(str);

    return 0;
}


	/* 
    1. main 함수 => 먼저 MakeStrAdr 함수를 호출하여 길이가 20인 문자열을 할당하고 이에 대한 포인터를 str에 저장.
	2. strcpy 함수를 사용하여 "I am So Happy~"라는 문자열을 str이 가리키는 메모리에 복사.
	3. cout을 사용하여 str이 가리키는 문자열을 출력.
    4. 마지막으로 free 함수를 사용하여 str이 가리키는 메모리를 해제.*/
