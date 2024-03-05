#include <iostream>
using namespace std;

class Data
{
private:
    int data; // private 데이터 멤버

public:
    // 생성자: 객체를 초기화하는 역할을 한다.
    Data(int num) : data(num)
    {
    }

    // 데이터를 출력하는 멤버 함수
    void ShowData()
    {
        cout << "Data: " << data << endl;
    }

    // 데이터에 값을 더하는 멤버 함수
    void Add(int num)
    {
        data += num;
    }
};

int main(void)
{
    // Data 클래스의 객체 obj를 생성하고, 초기값으로 15를 전달한다.
    Data obj(15);

    // obj에 17을 더한다.
    obj.Add(17);

    // obj의 데이터를 출력한다.
    obj.ShowData();

    return 0;
}

/*
클래스와 객체:
클래스는 데이터와 그 데이터에 대한 작업을 정의한 사용자 정의 데이터 형식이다.
객체는 클래스의 인스턴스이며, 클래스의 멤버 변수와 멤버 함수에 접근할 수 있다.

접근 제어 지시자(private):
private 키워드로 선언된 멤버는 클래스 외부에서 접근할 수 없다.
이는 데이터 은닉(data hiding)을 통해 클래스 내부의 데이터를 보호하는 데 사용된다.

생성자(Constructor):
클래스의 객체가 생성될 때 호출되는 특별한 멤버 함수이다.
이 예제에서는 Data 클래스에 인자를 받는 생성자를 정의하여 객체를 초기화한다.

멤버 함수(Methods):
클래스 내에 정의된 함수로, 해당 클래스의 객체에 작동한다.
ShowData()와 Add() 함수는 Data 클래스의 멤버 함수이며, 객체의 데이터를 출력하거나 데이터를 변경한다.

클래스의 인스턴스화(Instantiation):
Data obj(15);는 Data 클래스의 객체 obj를 생성하고, 이를 초기화하는 코드이다.

멤버 함수 호출:
obj.Add(17);는 obj의 Add() 멤버 함수를 호출하여 data 멤버에 17을 더한다.

캡슐화(Encapsulation):
클래스는 데이터와 그 데이터에 대한 작업을 하나로 묶는 캡슐화를 제공한다.
이 예제에서는 Data 클래스가 데이터와 해당 데이터에 대한 작업을 캡슐화한다.

정보 은닉(Information Hiding):
data 멤버 변수가 private로 선언되었으므로, 외부에서 직접 접근할 수 없다.
대신에 ShowData()와 Add() 같은 공개된 인터페이스를 통해 데이터에 접근한다.
*/