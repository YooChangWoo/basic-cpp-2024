#include <iostream>
#include <string> // C++ 표준 라이브러리에서 string 헤더 파일을 포함합니다.
using namespace std;

int main(void)
{
	// 문자열 변수들을 초기화합니다.
	string str1 = "I like ";
	string str2 = "string class";

	// 문자열 변수들을 연결하여 새로운 문자열을 생성합니다.
	string str3 = str1 + str2;

	// 문자열들을 출력합니다.
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	// 두 문자열을 복합 대입 연산자를 사용하여 연결합니다.
	str1 += str2;

	// 두 문자열이 동일한지 비교합니다.
	if ( str1 == str3 )
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열! " << endl;

	// 사용자로부터 문자열을 입력받습니다.
	string str4;
	cout << "문자열 입력: ";
	cin >> str4;

	// 입력한 문자열을 출력합니다.
	cout << "입력한 문자열 : " << str4 << endl;
	return 0;
}
/*
string 클래스:
C++ 표준 라이브러리에서 제공되는 string 클래스를 사용하여 문자열을 처리합니다.
이 클래스는 문자열을 동적으로 관리하므로 메모리 할당과 해제에 대한 작업을 신경 쓸 필요가 없습니다.

문자열 연산:
+ 연산자를 사용하여 문자열을 연결할 수 있습니다.
+= 연산자를 사용하여 문자열을 복합 대입할 수도 있습니다.

문자열 비교:
== 연산자를 사용하여 두 문자열이 동일한지 비교할 수 있습니다.

사용자 입력:
cin을 사용하여 사용자로부터 문자열을 입력받을 수 있습니다.
하지만 공백 문자를 포함하는 문자열은 제대로 처리되지 않을 수 있습니다
*/