#include <iostream>
#include <cstring> // strlen 및 strcpy 함수를 사용하기 위해 헤더 파일 추가
using namespace std;

class First
{
private:
    char* strOne; // 문자열을 저장하기 위한 포인터

public:
    // 생성자: 문자열을 복사하여 저장
    First(const char* str)
    {
        strOne = new char[strlen(str) + 1]; // 문자열의 길이 + 널 종료 문자('\0') 공간 할당
        strcpy(strOne, str); // 문자열 복사
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~First()
    {
        cout << "~First()" << endl;
        delete[] strOne; // 동적으로 할당된 메모리 해제
    }
};

class Second : public First
{
private:
    char* strTwo; // 문자열을 저장하기 위한 포인터

public:
    // 생성자: 문자열을 복사하여 저장
    Second(const char* str1, const char* str2) : First(str1)
    {
        strTwo = new char[strlen(str2) + 1]; // 문자열의 길이 + 널 종료 문자('\0') 공간 할당
        strcpy(strTwo, str2); // 문자열 복사
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Second()
    {
        cout << "~Second()" << endl;
        delete[] strTwo; // 동적으로 할당된 메모리 해제
    }
};

int main(void)
{
 /*
    상속 관계에 있어서 객체포인터는 조심해야 한다.
    부모타입의 객체 포인터로 자식 객체를 가리키는 경우(다형성) 조심 조심 또 조심해야 한다.
 */
    // Second 클래스의 객체를 직접 생성하여 메모리 누수를 방지합니다.
    Second* ptr = new Second("simple", "complex");

    // 동적으로 할당된 메모리를 해제합니다.
    delete ptr;

    return 0;
}



