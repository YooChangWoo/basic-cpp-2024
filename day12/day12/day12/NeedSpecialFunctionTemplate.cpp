#include <iostream>
using namespace std;

// 템플릿 함수 정의
template <typename T>
T Max(T a, T b)
{
    // a와 b를 비교하여 더 큰 값을 반환
    return a > b ? a : b;
}

int main(void)
{
    // 정수형 두 수를 비교하여 더 큰 값을 출력
    cout << Max(11, 15) << endl;    // 15 출력

    // 문자형 두 문자를 비교하여 ASCII 값이 큰 문자를 출력
    cout << Max('T', 'Q') << endl;  // 'T' 출력

    // 실수형 두 수를 비교하여 더 큰 값을 출력
    cout << Max(3.5, 7.5) << endl;  // 7.5 출력

    // 문자열 두 개를 비교하여 사전순으로 더 뒤에 있는 문자열을 출력
    cout << Max("Simple", "Best") << endl;  // "Simple" 출력
    // 주의: 문자열의 비교는 주소값으로 비교되어 사전순으로 더 뒤에 있는 문자열이 출력됨

    return 0;
}

/*
1. template <typename T> T Max(T a, T b): 
    -> 템플릿 함수 Max의 정의부. 두 개의 값 a와 b를 비교하여 더 큰 값을 반환함.

2. cout << Max(11, 15) << endl;: 
    -> 정수형 두 수를 비교하여 더 큰 값을 출력함. => 15가 출력됨.

3. cout << Max('T', 'Q') << endl;: 
    -> 문자형 두 문자를 비교하여 ASCII 값이 큰 문자를 출력함. => 'T'가 출력됨.

4. cout << Max(3.5, 7.5) << endl;: 
    -> 실수형 두 수를 비교하여 더 큰 값을 출력함. => 7.5가 출력됨.

5. cout << Max("Simple", "Best") << endl;: 
    - 문자열 두 개를 비교하여 사전순으로 더 뒤에 있는 문자열을 출력함. 
        -> 주의해야 할 점은 문자열의 비교는 주소값으로 비교되어 사전순으로 더 뒤에 있는 문자열이 출력됨
            => 여기서는 "Simple"이 출력됩니다.
*/