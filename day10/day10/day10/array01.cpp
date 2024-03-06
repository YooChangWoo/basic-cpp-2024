#include <iostream>

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };  // int형 배열선언, 크기가 5인 배열 생성
    int* parr = arr;                  // 배열의 이름은 해당 배열의 첫 번째 요소를 가리키는 포인터이다.

    // 배열의 주소와 크기 출력
    printf("arr 주소: %p\n", arr);
    printf("arr 크기: %u\n", sizeof(arr));    // int의 크기 4 * 배열 요소의 수 5 = 20 바이트

    // 각 배열 요소의 주소 출력
    printf("arr[0] 주소: %p\n", &arr[0]);     // 첫 번째 요소의 주소
    printf("arr[1] 주소: %p\n", &arr[1]);     // 두 번째 요소의 주소
    printf("arr + 1: %p\n", arr + 1);         // 첫 번째 요소의 주소에서 sizeof(int)만큼 증가하므로 두 번째 요소의 주소를 가리킴

    // 포인터 변수 parr의 주소와 값 출력
    printf("parr 주소: %p\n", &parr);
    printf("Parr 데이터: %p\n", parr);       // 배열 arr의 주소를 가리킴
    printf("parr + 1: %p\n", parr + 1);      // 배열의 주소에서 sizeof(int)만큼 증가하므로 다음 요소의 주소를 가리킴

    // parr[0]은 parr이 가리키는 곳에서의 값이므로 arr[0]과 동일하다.
    // *parr은 parr이 가리키는 곳의 값을 의미하며, 이는 arr의 첫 번째 요소를 가리킨다.
    printf("parr[0]: %d *parr: %d  arr[0]: %d\n", parr[0], *parr, arr[0]);

    return 0;
}
/*
배열의 인덱스 연산자 오버로딩:
사용자가 정의한 클래스에서 배열처럼 동작하도록 [] 연산자를 오버로딩할 수 있습니다.
이를 통해 객체를 배열처럼 사용할 수 있고, 객체의 내부 데이터에 직접 접근할 수 있습니다.

배열의 표현 방법:
배열은 메모리에 연속적으로 저장된 데이터 요소의 모음입니다.
C++에서는 배열을 선언할 때 [] 안에 요소의 개수를 지정하여 표현합니다.
예를 들어, int arr[5]는 5개의 정수 요소를 가진 배열을 선언하는 것을 의미합니다.
배열은 인덱스를 사용하여 요소에 접근할 수 있습니다.
배열의 인덱스는 0부터 시작하며, arr[0], arr[1], arr[2], ...와 같은 방식으로 요소에 접근할 수 있습니다.
*/