#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // private 멤버 변수 num

public:
    SoSimple(int n) : num(n) // 생성자: 멤버 변수 num을 초기화합니다.
    { }

    SoSimple(const SoSimple& copy) : num(copy.num) // 복사 생성자: 다른 객체로부터 객체를 복사합니다.
    {
        cout << " Called SoSimple(const SoSimple& copy)" << endl; // 복사 생성자 호출 시 메시지 출력
    }

    SoSimple& AddNum(int n) // 멤버 함수: num에 n을 더하고 객체 자신의 참조를 반환합니다.
    {
        num += n; // num에 n을 더합니다.
        return *this; // 객체 자신의 참조를 반환합니다.
    }

    void ShowData() // 멤버 함수: 객체의 데이터를 출력합니다.
    {
        cout << "num: " << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob) // 전역 함수: SoSimple 객체를 인자로 받아 출력합니다.
{
    cout << "return 이전" << endl; // 함수 호출 시 메시지 출력
    return ob; // 받은 객체를 반환합니다.
}

int main(void)
{
    SoSimple obj(7); // SoSimple 클래스의 객체 obj를 생성하고 초기화합니다.

    // SimpleFuncObj 함수를 호출하고, 반환된 객체에 AddNum 함수를 호출한 후 ShowData를 호출하여 결과를 출력합니다.
    SimpleFuncObj(obj).AddNum(30).ShowData();
    // obj의 ShowData를 호출하여 결과를 출력합니다.
    obj.ShowData();

    return 0;
}

/*
SoSimple 클래스:

SoSimple 클래스는 하나의 private 멤버 변수 num을 가지고 있습니다.
생성자는 객체를 초기화하고 멤버 변수 num을 인자로 받은 값으로 설정합니다.
복사 생성자는 다른 객체로부터 객체를 복사할 때 호출되며, 복사하는 객체의 num 값을 복사하여 현재 객체의 num에 설정합니다.
AddNum 멤버 함수는 num에 인자로 받은 값을 더한 후 객체의 참조를 반환합니다.
ShowData 멤버 함수는 객체의 num을 출력합니다.

전역 함수 SimpleFuncObj:

SimpleFuncObj 함수는 SoSimple 객체를 인자로 받아 출력합니다.
함수 내에서 "return 이전" 메시지를 출력한 후 받은 객체를 반환합니다.

main 함수:

main 함수에서 SoSimple 객체 obj를 생성하고 초기화합니다.
SimpleFuncObj 함수를 호출하고, 반환된 객체에 AddNum 함수를 호출한 후 ShowData를 호출하여 결과를 출력합니다.
마지막으로 obj의 ShowData를 호출하여 결과를 출력합니다.
프로그램을 실행하면, 함수 호출 시점에 따라 메시지가 출력되고, num에 대한 연산 결과가 출력됩니다.
*/