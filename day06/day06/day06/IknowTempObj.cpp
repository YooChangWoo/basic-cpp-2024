#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;

public:
    // 생성자: 객체가 생성될 때 호출되며, num을 인자로 초기화합니다.
    Temporary(int n) : num(n)
    {
        // 객체 생성 시 메시지 출력
        cout << "create obj: " << num << endl;
    }

    // 소멸자: 객체가 소멸될 때 호출되며, 메시지를 출력합니다.
    ~Temporary()
    {
        cout << "destroy obj: " << num << endl;
    }

    // 객체 정보를 출력하는 멤버 함수
    void ShowTempInfo()
    {
        cout << "My num is: " << num << endl;
    }
};

int main(void)
{
    // 임시 객체 생성 및 생성 메시지 출력
    Temporary temp1(100);
    cout << "********* after make!" << endl << endl;

    // 임시 객체 생성 및 생성 메시지 출력
    Temporary temp2(200);
    cout << "********* after make!" << endl << endl;

    // 객체 생성 후에 참조를 생성하여 임시 객체의 수명을 연장합니다.
    const Temporary& ref = Temporary(300);
    cout << "********* after make!" << endl << endl;

    return 0;
}

/*
Temperary 클래스:

Temperary 클래스는 하나의 private 멤버 변수 num을 가지고 있습니다.
생성자는 객체가 생성될 때 호출되어 멤버 변수를 초기화하고, 소멸자는 객체가 소멸될 때 호출되어 메시지를 출력합니다.
멤버 함수는 객체의 정보를 출력합니다.

main 함수:

main 함수에서는 임시 객체를 생성하고, 생성된 객체의 정보를 출력합니다.
첫 번째와 두 번째 임시 객체는 생성된 후에 바로 소멸됩니다. 이들은 생성 후에 사용되지 않았으므로 메모리에서 즉시 해제됩니다.
세 번째 임시 객체는 참조 변수 ref에 저장되어 있습니다. 그러나 ref는 상수 참조이므로 이후에 수정될 수 없습니다.
프로그램의 실행이 끝나면 main 함수의 실행이 종료되고, 이 때 ref에 저장된 임시 객체 또한 소멸됩니다.
프로그램을 실행하면, 임시 객체의 생성과 소멸이 발생하는 순서를 확인할 수 있습니다.
*/