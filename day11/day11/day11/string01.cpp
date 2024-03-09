#include <iostream>
#include <string>
using namespace std;
/*
	C-Style 문자열
	문자열은 마지막에 널문자가 붙는다.
*/
/*
int main()
{
	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;
	cout << "====================" << endl;
	char ary[6] = {'a', 'b', 'c', 'd', 'e' };       // 문자열 타입의 배열 선언
	cout << ary << endl;
	printf("==============================\n");
	char ary1[6] = { 'a', 'b', 'c', '\0', 'e' };    // 널 문자 - 문자열의 끝을 알린다.
	cout << ary1 << endl;
	cout << sizeof(ary1) << endl;                   // 전체 문자 크기
	cout << strlen(ary1) << endl;                   // 널 문자 앞까지의 크기
	printf("==============================\n");
	char str[] = "string";                          // 자동으로 널문자가 붙는다.
	cout << str << endl;
	cout << sizeof(str) << endl;                    // 널문자가 포함된 크기다 리턴된다.
	cout << strlen(str) << endl;                    
	printf("===============================\n");
	const char* pstr = "STRING";
	cout << pstr << endl;
	cout << sizeof(str) << endl;                    // 널 문자가 포함된 크기가 리턴된다.
	cout << strlen(str) << endl;
	// pstr[ 0 ] = 's';                             // 문자열을 포인터로 사용하는 경우는 변경이 불가능

	printf("==================================\n");
	printf("==================================\n");
	*/
/*
  c++ -style : head 영역에 저장한다.
*/
int main()
{
	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl;
	// cout << strlen(s) << endl;
	cout << s.size() << endl;

	string s1 = "Hongkildon";
	cout << s1 << endl;
	cout << sizeof(s1) << endl;
	cout << s1.size() << endl;
	
	return 0;
}