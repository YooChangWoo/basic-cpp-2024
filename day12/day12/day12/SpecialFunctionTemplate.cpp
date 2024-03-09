#include <iostream>
#include <cstring> // strlen과 strcmp 함수를 사용하기 위해 포함
using namespace std;

// 일반 템플릿 함수: 두 개의 매개변수를 비교하여 더 큰 값을 반환합니다.
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b; // a가 b보다 크면 a를, 그렇지 않으면 b를 반환
}

// 템플릿 특수화: char* 타입에 대한 Max 함수
template <>
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b; // 문자열의 길이를 비교하여 더 긴 문자열을 반환
}

// 템플릿 특수화: const char* 타입에 대한 Max 함수
template <>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b; // 문자열을 사전 순으로 비교하여 사전 순으로 더 뒤에 오는 문자열을 반환
}

int main(void)
{
	cout << Max(11, 15) << endl; // 일반 타입(int)에 대한 Max 호출
	cout << Max('T', 'Q') << endl; // 일반 타입(char)에 대한 Max 호출
	cout << Max(3.5, 7.5) << endl; // 일반 타입(double)에 대한 Max 호출
	cout << Max("Simple", "Best") << endl; // const char* 특수화에 대한 Max 호출

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl; // char* 특수화에 대한 Max 호출
	return 0;
}
/*
1. 첫 번째 Max(11, 15)는 일반 템플릿 함수를 사용하여 두 정수를 비교하고 더 큰 값을 반환함.

2. 두 번째 Max('T', 'Q')는 char 타입에 대해 일반 템플릿 함수를 사용하여 두 문자를 비교하고 ASCII 값이 더 큰 문자를 반환함.

3. 세 번째 Max(3.5, 7.5)는 일반 템플릿 함수를 사용하여 두 부동 소수점 숫자를 비교하고 더 큰 값을 반환함.

4. 네 번째 Max("Simple", "Best")는 const char*에 대한 특수화된 함수를 호출하여 문자열을 사전 순으로 비교하고, 사전 순으로 뒤에 오는 문자열을 반환함.

5. 마지막으로, 두 char 배열에 대한 Max(str1, str2) 호출은 char* 타입에 대한 특수화된 함수를 사용하여 두 문자열의 길이를 비교하고 더 긴 문자열을 반환함.
*/