#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA = 1707540; // 러시아의 면적을 나타내는 상수 멤버 변수
    const static int CANADA = 998467;  // 캐나다의 면적을 나타내는 상수 멤버 변수
    const static int CHINA = 957290;   // 중국의 면적을 나타내는 상수 멤버 변수
    const static int SOUTH_KOREA = 9922; // 한국의 면적을 나타내는 상수 멤버 변수
};

int main(void)
{
    cout << "러시아 면적: " << CountryArea::RUSSIA << "㎢" << endl;  // 클래스 이름을 통해 멤버 변수에 접근하여 출력
    cout << "캐나다 면적: " << CountryArea::CANADA << "㎢" << endl;  // 클래스 이름을 통해 멤버 변수에 접근하여 출력
    cout << "중국 면적: " << CountryArea::CHINA << "㎢" << endl;   // 클래스 이름을 통해 멤버 변수에 접근하여 출력
    cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "㎢" << endl; // 클래스 이름을 통해 멤버 변수에 접근하여 출력
    return 0;
}

/*
이 코드에서는 CountryArea 클래스 내에 각 나라의 면적을 나타내는 상수(static constant) 멤버 변수들을 정의합니다
. 이러한 멤버 변수들은 객체 생성 없이 클래스 이름을 통해 직접 접근할 수 있습니다.

main() 함수에서는 클래스 이름을 통해 각 나라의 면적을 출력합니다.
이러한 상수 멤버 변수는 객체가 생성되지 않아도 사용할 수 있으며,
코드를 읽고 이해하기 쉽게 만들어 줍니다.
*/