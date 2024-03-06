#include <iostream>	

namespace mystd
{
    using namespace std;

    // 사용자 정의 ostream 클래스 선언
    class ostream
    {
    public:
        // 문자열 출력 연산자 오버로딩
        ostream& operator<< (char* str)
        {
            printf("%s", str); // 문자열을 출력
            return *this; // 자기 자신을 반환하여 연쇄적으로 연산자 사용 가능하도록 함
        }

        // 문자 출력 연산자 오버로딩
        ostream& operator<< (char str)
        {
            printf("%c", str); // 문자를 출력
            return *this; // 자기 자신을 반환하여 연쇄적으로 연산자 사용 가능하도록 함
        }

        // 정수 출력 연산자 오버로딩
        ostream& operator<< (int num)
        {
            printf("%d", num); // 정수를 출력
            return *this; // 자기 자신을 반환하여 연쇄적으로 연산자 사용 가능하도록 함
        }

        // 실수 출력 연산자 오버로딩
        ostream& operator<< (double e)
        {
            printf("%g", e); // 실수를 출력
            return *this; // 자기 자신을 반환하여 연쇄적으로 연산자 사용 가능하도록 함
        }

        // 함수 포인터를 통한 연산자 오버로딩
        ostream& operator<< (ostream& (*fp)(ostream& ostm))
        {
            return fp(*this); // 함수 포인터를 통해 정의된 함수를 호출하여 반환
        }
    };

    // 사용자 정의 endl 함수
    ostream& endl(ostream& ostm)
    {
        ostm << '\n'; // 개행 문자 출력
        fflush(stdout); // 출력 버퍼를 비움
        return ostm; // ostream 객체 반환
    }

    ostream cout; // 사용자 정의 ostream 객체
}

int main(void)
{
    using mystd::cout; // mystd 네임스페이스의 cout 사용
    using mystd::endl; // mystd 네임스페이스의 endl 사용
    cout << 3.14 << endl << 123 << endl; // 실수, 정수 출력 후 각각 개행
    return 0;
}

/*
사용자 정의 ostream 클래스와 endl 함수:
mystd 네임스페이스 내에 ostream 클래스와 endl 함수가 정의되어 있습니다.
ostream 클래스는 사용자가 지정한 출력 방식에 따라 다양한 데이터 유형을 출력할 수 있도록 연산자를 오버로딩합니다.
endl 함수는 출력 스트림에 개행 문자를 추가하고 출력 버퍼를 비우는 역할을 합니다.

전역 함수 포인터를 통한 연산자 오버로딩:
함수 포인터를 통해 ostream 클래스에 사용자 정의 출력 함수를 추가합니다. 이는 cout << endl과 같은 형태로 사용됩니다.

사용자 정의 출력 방식:
사용자는 mystd::cout과 mystd::endl을 사용하여 데이터를 출력할 수 있습니다.
*/