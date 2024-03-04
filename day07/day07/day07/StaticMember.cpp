#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt; // 정적 멤버 변수로 선언된 SoSimple 객체의 수를 추적하는 변수
public:
    SoSimple()
    {
        simObjCnt++; // 객체가 생성될 때마다 카운트를 증가시킴
        cout << simObjCnt << "번째 SoSimple 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
};
int SoSimple::simObjCnt = 0; // 정적 멤버 변수의 초기화

class SoComplex
{
private:
    static int cmxObjCnt; // 정적 멤버 변수로 선언된 SoComplex 객체의 수를 추적하는 변수
public:
    SoComplex()
    {
        cmxObjCnt++; // 객체가 생성될 때마다 카운트를 증가시킴
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
    SoComplex(SoComplex& copy)
    {
        cmxObjCnt++; // 복사 생성자가 호출될 때마다 카운트를 증가시킴
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
};
int SoComplex::cmxObjCnt = 0; // 정적 멤버 변수의 초기화

int main(void)
{
    SoSimple sim1; // SoSimple 객체 생성
    SoSimple sim2; // SoSimple 객체 생성

    SoComplex cmx1; // SoComplex 객체 생성
    SoComplex cmx2 = cmx1; // SoComplex 객체의 복사 생성자 호출을 통한 객체 생성
    SoComplex cmx3; // SoComplex 객체 생성

    return 0;
}

/*
해당 코드는 두 개의 클래스를 정의하고, 각 클래스에서 정적 멤버 변수를 사용하여 객체의 수를 추적합니다.
SoSimple 클래스와 SoComplex 클래스 모두 내부에 정적 멤버 변수가 선언되어 있습니다.
이들 변수는 객체가 생성될 때마다 증가되며, 객체 생성 시 번호가 출력됩니다.

main() 함수에서는 각 클래스의 객체를 생성하고, 복사 생성자를 호출하여 객체를 생성하며,
마지막으로 새로운 SoComplex 객체를 생성합니다.
*/