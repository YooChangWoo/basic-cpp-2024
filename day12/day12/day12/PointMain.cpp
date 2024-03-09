#include <iostream>
#include "PointTemplate.h" // Point 클래스 템플릿의 선언을 포함하는 헤더 파일을 포함함.
#include "PointTemplate.cpp" // Point 클래스 템플릿의 멤버 함수 정의를 포함하는 소스 파일을 포함함.

using namespace std;

int main(void)
{
    // int 타입을 사용하여 Point 객체 생성
    Point<int> pos1(3, 4);
    pos1.ShowPosition(); // 생성된 Point 객체의 좌표를 출력함.

    // double 타입을 사용하여 Point 객체 생성
    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition(); // 생성된 Point 객체의 좌표를 출력함.

    // char 타입을 사용하여 Point 객체 생성
    Point<char> pos3('P', 'F');
    pos3.ShowPosition(); // 생성된 Point 객체의 좌표를 출력함.

    return 0; // 프로그램 종료
}

/*
1. #include <iostream>: 입력과 출력을 위해 사용되는 표준 입출력 스트림을 사용하기 위한 헤더 파일을 포함함.

2. "PointTemplate.h": Point 클래스 템플릿의 선언이 포함된 헤더 파일을 포함함. 
    -> 이 헤더 파일에는 클래스 템플릿의 선언이 포함되어 있으며, 
        -> 클래스 템플릿의 정의는 따로 분리되어 있음.

3. "PointTemplate.cpp": Point 클래스 템플릿의 멤버 함수 정의가 포함된 소스 파일을 포함함. 
    -> 이 파일에는 Point 클래스 템플릿의 멤버 함수 정의가 포함되어 있습니다.

4.using namespace std;: 표준 라이브러리의 std 네임스페이스를 사용한다.

5. Point<int> pos1(3, 4);: int 타입을 사용하여 pos1 객체를 생성하고 초기화함. 
    -> x 좌표는 3, y 좌표는 4이다.

6. pos1.ShowPosition();: pos1 객체의 좌표를 출력함.

7. 이하 동일한 방식으로 Point<double>과 Point<char> 객체를 생성하고, 
    -> 각 객체의 좌표를 출력함.

8. return 0;: 프로그램이 성공적으로 종료되었음을 나타내는 메인 함수의 반환 값.
*/