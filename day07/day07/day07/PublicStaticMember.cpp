#include <iostream>
using namespace std;

class SoSimple
{
public:                   //접근제한이 public
    static int simObjCnt; // static 멤버변수 선언(클래스 멤버)
public:
    SoSimple()
    {
        simObjCnt++; // 객체가 생성될 때마다 정적 멤버 변수를 증가시킴
    }
};
int SoSimple::simObjCnt = 0; // static 멤버변수의 초기화

int main(void)
{
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl; // 클래스 이름으로 정적 멤버 변수에 접근하여 출력
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl; // 클래스이름으로 static 멤버에 변수에 접근하여 출력
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl; // 객체를 통한 정적 멤버 변수에 접근하여 출력 (권장되지 않는 방법)
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl; // 객체를 통한 정적 멤버 변수에 접근하여 출력 (권장되지 않는 방법)
    return 0;
}
/*
이 코드에서는 SoSimple 클래스에 정적 멤버 변수 simObjCnt를 선언하고,
클래스 외부에서 초기화합니다.SoSimple의 생성자에서 객체가 생성될 때마다 simObjCnt를 증가시킵니다.

main() 함수에서는 다양한 방법으로 simObjCnt에 접근합니다.
클래스 이름을 통해 접근하는 것이 가장 바람직하며,
객체를 통해서도 접근이 가능하지만 권장되는 방법은 아닙니다.

정적(static) 멤버 변수는 클래스의 모든 객체가 공유하는 변수이므로,
클래스 이름을 통해 접근하는 것이 가장 명확하고 일반적인 방법입니다.
*/