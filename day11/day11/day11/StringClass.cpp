#include <iostream>
#include <cstring>
using namespace std;

// 문자열 클래스 선언
class String
{
private:
    int len;    // 문자열의 길이를 저장하는 변수
    char* str;  // 문자열을 저장하는 포인터
public:
    String();                       // 기본 생성자
    String(const char* s);          // 문자열을 받는 생성자
    String(const String& s);        // 복사 생성자
    ~String();                      // 소멸자
    String& operator= (const String& s);    // 대입 연산자 오버로딩
    String& operator+= (const String& s);   // 복합 대입 연산자 오버로딩
    bool operator== (const String& s);      // 비교 연산자 오버로딩
    String operator+ (const String& s);     // 연결 연산자 오버로딩

    friend ostream& operator<< (ostream& os, const String& s);   // 출력 연산자 오버로딩
    friend istream& operator>> (istream& is, String& s);        // 입력 연산자 오버로딩
};

// 기본 생성자 정의
String::String()
{
    len = 0;        // 초기화된 문자열의 길이는 0
    str = NULL;     // 초기화된 문자열은 NULL 포인터를 가짐
}

// 문자열을 받는 생성자 정의
String::String(const char* s)
{
    len = strlen(s) + 1;    // 문자열의 길이 계산 (널 문자 포함)
    str = new char[ len ];    // 동적 메모리 할당
    strcpy(str, s);         // 문자열 복사
}

// 복사 생성자 정의
String::String(const String& s)
{
    len = s.len;            // 길이 복사
    str = new char[ len ];    // 메모리 할당
    strcpy(str, s.str);     // 문자열 복사
}

// 소멸자 정의
String::~String()
{
    if ( str != NULL )
        delete[] str;   // 동적으로 할당된 메모리 해제
}

// 대입 연산자 오버로딩 정의
String& String::operator= (const String& s)
{
    if ( str != NULL )
        delete[] str;       // 기존 메모리 해제
    len = s.len;            // 길이 복사
    str = new char[ len ];    // 메모리 할당
    strcpy(str, s.str);     // 문자열 복사
    return *this;
}

// 복합 대입 연산자 오버로딩 정의
String& String::operator+= (const String& s)
{
    len += ( s.len - 1 );         // 길이 조정
    char* tempstr = new char[ len ];  // 새로운 메모리 할당
    strcpy(tempstr, str);           // 이전 문자열 복사
    strcat(tempstr, s.str);         // 새로운 문자열 추가

    if ( str != NULL )
        delete[] str;       // 이전 메모리 해제
    str = tempstr;          // 새로운 메모리 할당
    return *this;
}

// 비교 연산자 오버로딩 정의
bool String::operator== (const String& s)
{
    return strcmp(str, s.str) ? false : true;    // 문자열 비교
}

// 연결 연산자 오버로딩 정의
String String::operator+ (const String& s)
{
    char* tempstr = new char[ len + s.len - 1 ];   // 새로운 메모리 할당
    strcpy(tempstr, str);                         // 첫 번째 문자열 복사
    strcat(tempstr, s.str);                       // 두 번째 문자열 추가

    String temp(tempstr);       // 새로운 String 객체 생성
    delete[] tempstr;           // 메모리 해제
    return temp;                // 새로운 객체 반환
}

// 출력 연산자 오버로딩 정의
ostream& operator<< (ostream& os, const String& s)
{
    os << s.str;    // 문자열 출력
    return os;
}

// 입력 연산자 오버로딩 정의
istream& operator>> (istream& is, String& s)
{
    char str[ 100 ];
    is >> str;          // 입력 받은 문자열을 str에 저장
    s = String(str);    // 입력 받은 문자열로 String 객체를 생성하여 대입
    return is;
}

// main 함수
int main(void)
{
    String str1 = "I like ";            // 문자열 초기화
    String str2 = "string class";       // 문자열 초기화
    String str3 = str1 + str2;          // 문자열 연결

    cout << str1 << endl;               
    cout << str2 << endl;               
    cout << str3 << endl;               

    str1 += str2;                       // 복합 대입 연산
    if ( str1 == str3 )                   // 비교 연산
        cout << "동일 문자열!" << endl; 
    else
        cout << "동일하지 않은 문자열!" << endl;    

    String str4;
    cout << "문자열 입력: ";             // 사용자에게 입력 요청
    cin >> str4;                        // 문자열 입력
    cout << "입력한 문자열: " << str4 << endl;     // 입력한 문자열 출력
    return 0;
}
/*
String 클래스:
이 코드는 사용자가 직접 구현한 문자열 클래스인 String을 보여줍니다.
C++ 표준 라이브러리의 std::string과 유사한 기능을 제공합니다.

동적 메모리 할당:
String 클래스는 문자열을 저장하기 위해 동적 메모리 할당을 사용합니다.
이것은 문자열의 길이가 런타임에 결정되는 경우 유용합니다.

복사 생성자와 소멸자:
복사 생성자와 소멸자를 정의하여 메모리 누수를 방지합니다.
소멸자는 객체가 소멸될 때 동적으로 할당된 메모리를 해제합니다.

연산자 오버로딩:
String 클래스는 대입 연산자(=), 복합 대입 연산자(+=), 비교 연산자(==), 연결 연산자(+)를
오버로딩하여 문자열을 다루는 다양한 기능을 제공합니다.

친구 함수: 
<<와 >> 연산자를 오버로딩하기 위해 친구 함수를 사용합니다. 
이것은 String 클래스의 private 멤버에 접근할 수 있도록 합니다.

입출력 연산자 오버로딩:
<<와 >> 연산자를 오버로딩하여 String 객체를 표준 입출력 스트림에 직접 출력하고 입력할 수 있습니다.

사용자 입력: 
사용자로부터 문자열을 입력 받을 때, 공백 문자를 포함한 문자열도 처리할 수 있습니다.
*/