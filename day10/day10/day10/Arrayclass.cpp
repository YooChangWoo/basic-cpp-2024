#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr;       // 동적으로 할당된 배열을 가리키는 포인터
    int arrlen;     // 배열의 길이를 저장하는 변수
public:
    // 생성자: 배열의 길이를 받아서 동적으로 배열을 할당함
    BoundCheckIntArray(int len) : arrlen(len)
    {
        printf("생성자 호출\n");
        arr = new int[len]; // len 길이의 int 배열을 동적으로 할당
    }

    // [] 연산자 오버로딩: 배열 요소에 접근할 때 사용됨
    int& operator[] (int idx)
    {
        printf("[]연산자 호출\n");
        // 인덱스가 유효한지 확인
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl; // 유효하지 않으면 예외 출력
            exit(1); // 프로그램 종료
        }

        return arr[idx]; // 해당 인덱스의 요소에 대한 레퍼런스 반환
    }

    // 소멸자: 동적으로 할당된 배열 메모리를 해제함
    ~BoundCheckIntArray()
    {
        printf("소멸자 호출\n");
        delete[] arr; // 동적으로 할당된 배열 메모리를 해제
    }
};

int main(void)
{
    BoundCheckIntArray arr(5); // 길이가 5인 BoundCheckIntArray 객체 생성

    // 배열에 값을 할당
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;

    // 배열의 값을 출력 (인덱스 오버플로우가 발생할 수 있음)
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;

    return 0;
}

/*
동적 배열과 인덱스 오버로딩: BoundCheckIntArray 클래스는 동적으로 할당된 배열을 사용합니다.
이 클래스는 배열에 접근할 때 인덱스 오버로딩을 사용하여 각 요소에 접근합니다.

인덱스 검사: 배열의 인덱스를 검사하여 접근이 유효한지 확인합니다.
operator[] 함수 내에서 인덱스가 배열의 범위를 벗어나면
"Array index out of bound exception"을 출력하고 프로그램을 종료합니다.

메모리 해제: 클래스의 소멸자에서는 동적으로 할당된 배열 메모리를 해제합니다.
이는 메모리 누수를 방지하고 프로그램의 메모리 사용량을 관리하는 데 중요합니다.

사용 예시: main 함수에서는 BoundCheckIntArray 객체를 생성하고 배열에 값을 할당한 후,
배열의 값을 출력합니다.
인덱스 오버플로우가 발생하는 경우, 예외 처리 메시지가 출력됩니다.
*/