#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // 정수를 저장하는 멤버 변수

public:
    // 생성자
    SoSimple(int n) : num(n)
    { }

    // 복사 생성자
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }

    // 데이터를 출력하는 멤버 함수
    void ShowData()                 // 멤버 함수 --> 객체생성 후 사용 가능
    {
        cout << "Num: " << num << endl;
    }
};

// 객체를 매개변수로 받는 함수
void SimpleFuncObj(SoSimple ob)     // 전역함수 --> 개나 소나 바로 접근가능
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7); // 객체 생성 및 초기화
    cout << "호출 전!! : " << endl;
    SimpleFuncObj(obj); // 함수 호출 시 객체 전달
    cout << "함수 호출 후!! :" << endl;
    return 0;
}

/* 추가 설명
1. SoSimple 클래스는 하나의 int 멤버 변수를 갖음
2. SoSimple(int n) 생성자는 정수를 매개변수로 받아 멤버 변수를 초기화
3. SoSimple(const SoSimple& copy) 복사 생성자는 다른 객체를 받아 그 객체의 멤버 변수를 복사하여 초기화
    -> 이때 복사 생성자가 호출되었다는 메시지를 출력

4. ShowData() 함수는 객체의 멤버 변수를 출력
5. SimpleFuncObj(SoSimple ob) 함수는 SoSimple 클래스의 객체를 매개변수로 받아 해당 객체의 데이터를 출력
6. main 함수에서는 obj 객체를 생성하고, SimpleFuncObj 함수를 호출하여 obj 객체를 전달
    -> 함수가 호출될 때 객체를 복사하게 되므로 복사 생성자가 호출
*/
