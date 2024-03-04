#include <iostream>
using namespace std;

int simObjCnt = 0; // SoSimple 클래스의 객체 수를 저장하는 변수
int cmxObjCnt = 0; // SoComplex 클래스의 객체 수를 저장하는 변수

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++; // SoSimple 객체가 생성될 때마다 객체 수를 증가시킴
        cout << simObjCnt << "번째 SoSimple 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++; // SoComplex 객체가 생성될 때마다 객체 수를 증가시킴
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
    SoComplex(SoComplex& copy)
    {
        cmxObjCnt++; // SoComplex 객체가 생성될 때마다 객체 수를 증가시킴
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl; // 객체가 생성될 때마다 번호를 출력
    }
};

int main(void)
{
    SoSimple sim1; // SoSimple 클래스의 객체 생성
    SoSimple sim2; // SoSimple 클래스의 객체 생성

    SoComplex com1; // SoComplex 클래스의 객체 생성
    SoComplex com2 = com1; // SoComplex 클래스의 복사 생성자 호출을 통한 객체 생성
    SoComplex(); // 익명의 SoComplex 객체를 생성하지만, 생성 후 아무 작업도 수행하지 않음

    return 0;
}

/*
이 코드는 두 가지 클래스를 정의합니다. 
SoSimple 클래스는 객체가 생성될 때마다 객체의 수를 증가시키고 생성 메시지를 출력합니다.
SoComplex 클래스도 비슷한 기능을 수행합니다.

그리고 main() 함수에서는 두 클래스의 객체를 생성하고, 
복사 생성자를 호출하며, 마지막으로 익명의 객체를 생성하는 등의 작업을 수행합니다.

따라서 이 코드는 객체의 생성과 관련된 간단한 동작을 보여주는 예제입니다.
*/