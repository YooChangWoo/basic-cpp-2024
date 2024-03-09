#pragma once
#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray
{
private:
    T* arr; // 동적 배열을 가리키는 포인터
    int arrlen; // 배열의 길이

    // 복사 생성자와 대입 연산자를 private으로 선언하여 복사를 금지함.
    BoundCheckArray(const BoundCheckArray& arr) { }
    BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
    // 생성자: 배열의 길이를 받아 동적 배열을 할당함.
    BoundCheckArray(int len);

    // 배열 요소에 대한 접근을 제공하는 연산자 오버로딩 함수들
    T& operator[] (int idx); // 배열 요소에 대한 읽고 쓰기
    T operator[] (int idx) const; // 배열 요소에 대한 읽기 전용

    // 배열의 길이를 반환하는 함수
    int GetArrLen() const;

    // 소멸자: 동적 배열을 삭제함.
    ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len)
{
    arr = new T[len]; // 배열의 길이에 맞게 동적 배열을 할당함.
}


template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
    // 인덱스가 유효한 범위인지 확인함.
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1); // 프로그램을 종료함.
    }
    return arr[idx]; // 배열 요소에 대한 레퍼런스를 반환함.
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
    // 인덱스가 유효한 범위인지 확인함.
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1); // 프로그램을 종료함.
    }
    return arr[idx]; // 배열 요소의 값 복사본을 반환함.
}


template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
    return arrlen; // 배열의 길이를 반환함.
}


template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete[]arr; // 동적으로 할당된 배열을 삭제함.
}


#endif

/*
1. #pragma once: 중복 포함을 방지하기 위해 사용되는 전처리기 지시문.

2. #ifndef __ARRAY_TEMPLATE_H__, #define __ARRAY_TEMPLATE_H__, #endif: 헤더 가드임. 
    -> 헤더 파일이 중복해서 포함되는 것을 방지함. 
        -> __ARRAY_TEMPLATE_H__는 임의의 심볼로, 이 헤더 파일이 다른 헤더 파일과 중복 포함되지 않도록 보장함.

3. <iostream>과 <cstdlib> 헤더 파일을 포함하여 입력 및 출력 기능과 exit() 함수를 사용할 수 있게 함.

4. BoundCheckArray 클래스 템플릿을 정의함. 
    -> 이 클래스는 동적 배열의 길이와 배열 요소에 대한 접근을 제공함.

5. private 섹션에는 복사 생성자와 대입 연산자가 private으로 선언되어 있어서, 
    -> 복사를 금지하고 객체의 얕은 복사를 방지함.

6. public 섹션에는 생성자, 연산자 오버로딩 함수들, 배열의 길이를 반환하는 함수, 소멸자가 선언되어 있음.

7. 생성자는 배열의 길이를 받아와서 동적으로 배열을 할당함. 
    -> 인자 len으로 받은 배열의 길이를 arrlen에 저장함.

8. operator[] 함수를 오버로딩하여 배열 요소에 접근함. 
    -> 이 함수는 배열 요소에 대한 읽기/쓰기 및 읽기 전용 연산을 수행함. 
        -> 인덱스가 유효한 범위인지 확인하고, 유효하지 않으면 오류 메시지를 출력하고 프로그램을 종료함.

9. GetArrLen 함수는 배열의 길이를 반환함.

10 .소멸자는 동적으로 할당된 배열을 해제함.
*/