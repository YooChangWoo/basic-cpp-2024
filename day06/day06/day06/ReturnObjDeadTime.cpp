#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    // 생성자: 객체가 생성될 때 호출되며, 멤버 변수를 초기화합니다.
    SoSimple(int n) : num(n)
    {
        cout << "New Object: " << this << endl; // 객체가 생성될 때 주소 출력
    }

    // 복사 생성자: 다른 객체로부터 객체를 복사할 때 호출되며, 멤버 변수를 복사합니다.
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "New Copy obj: " << this << endl; // 복사된 객체가 생성될 때 주소 출력
    }

    // 소멸자: 객체가 소멸될 때 호출되며, 메모리 등의 자원을 정리합니다.
    ~SoSimple()
    {
        cout << "Destroy obj: " << this << endl; // 객체가 소멸될 때 주소 출력
    }
};

// 함수 정의: SoSimple 객체를 인자로 받아서 처리한 후 다시 반환합니다.
SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR: " << &ob << endl; // 함수 내에서 받은 객체의 주소 출력
    return ob; // 받은 객체를 그대로 반환
}

int main(void)
{
    // 객체 생성
    SoSimple obj(7);

    // 함수 호출: 객체를 인자로 전달하고, 반환된 객체를 새로운 객체에 할당합니다.
    SimpleFuncObj(obj);

    cout << endl;

    // 함수 호출: 객체를 인자로 전달하고, 반환된 객체를 새로운 객체에 할당합니다.
    SoSimple tempRef = SimpleFuncObj(obj);
    cout << "Return Obj" << &tempRef << endl; // 반환된 객체의 주소 출력

    return 0;

/*

New Object: 000000485915F884        객체 obj 주소
New Copy obj: 000000485915F984      객체 ob 주소
Parm ADR: 000000485915F984          객체 ob 주소
New Copy obj: 000000485915F9C4      임시 객체 주소
Destroy obj: 000000485915F984       객체 ob 소멸
Destroy obj: 000000485915F9C4       임시 객체 소멸

New Copy obj: 000000485915F9E4      객체 ob 주소
Parm ADR: 000000485915F9E4          객체 ob 주소
New Copy obj: 000000485915F8A4      임시 객체 주소
Destroy obj: 000000485915F9E4       객체 ob 소멸
Return Obj000000485915F8A4          임시 객체 주소
Destroy obj: 000000485915F8A4       임시객체 소멸
Destroy obj: 000000485915F884       객체 obj 소멸

*/

/* 추가 설명
1. SoSimple 클래스는 하나의 정수형 멤버 변수 num을 가지고 있음.

2. 생성자 SoSimple(int n)은 객체가 생성될 때 호출되며,
-> 멤버 변수 num을 인자 n으로 초기화함.

3. AddNum(int n) 함수는 매개변수로 받은 정수 n을 현재 객체의 num에 더한 후,
-> 자신의 객체를 반환함. 이 함수는 객체의 내부 상태를 변경하는 역할.

4. ShowData() 함수는 현재 객체의 num 값을 출력함.
-> 이 함수는 객체의 내부 상태를 읽어오는 역할.

5. main() 함수에서는 상수 객체 obj를 생성하고, 이 객체의 num 값을 출력함.
-> 상수 객체는 한 번 생성되면 수정할 수 없기 때문에 AddNum() 함수를 호출하려고 하면 컴파일 오류가 발생함.
*/