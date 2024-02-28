#include <iostream>
using namespace std;

// counter 함수 선언
void counter()
{
    // 정적 지역 변수 cnt 선언 및 초기화
    static int cnt;

    // int cnt = 0; -> 밑에 설명 있음
    // cnt 변수 증가
    cnt++;
    // cnt 값 출력
    cout << "Current cnt: " << cnt << endl;
}

// 메인 함수
int main(void)
{
    // 10번 반복하는 for 루프
    for (int i = 0; i < 10; i++)
        counter(); // counter 함수 호출
    return 0;
}

/* 추가 설명
1. counter() 함수 내에 정의된 정적 지역 변수 cnt는 해당 함수가 처음 호출될 때 초기화됨.
    -> 그 후에는 함수가 종료되더라도 cnt 변수의 값은 유지됨.

2. 각 counter() 함수 호출마다 cnt 변수가 증가하며, 호출 횟수가 증가 됨.

3. main() 함수에서는 for 루프를 통해 counter() 함수를 10번 호출됨.
    -> 각 호출마다 cnt 변수가 증가되고, 그 값이 출력됨.

4. 따라서 출력 결과는 호출 횟수에 따라 1부터 10까지 증가하는 숫자들이 됩
*/

/* static int cnt; 가 없어지고, int cnt=0; 에 대해 설명
1. int cnt = 0;: counter() 함수 내에 cnt를 지역 변수로 선언하고 초기화.
    -> 이제 cnt는 함수가 호출될 때마다 새로운 변수가 생성됨.

2. 각 counter() 함수 호출마다 cnt 변수가 1로 초기화되고, 1이 출력됨.
    -> 함수가 종료되면서 변수 cnt는 사라지며,
    --> 다음 호출 시에는 다시 1로 초기화됨.

3. 따라서 모든 출력은 1로 나타나게 됨.
    -> 호출 횟수를 추적하려는 목적에는 적합하지 않음.
    --> 변수 cnt가 항상 1로 초기화되기 때문에 호출 횟수를 추적할 수 없음
*/