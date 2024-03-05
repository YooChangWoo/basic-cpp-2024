#include <iostream>
using namespace std;

// 클래스 Data를 흉내낸 영역
typedef struct Data
{
    int data; // 데이터 멤버

    // 함수 포인터 멤버
    void (*ShowData)(Data*);      // ShowData 멤버함수 선언 // 매개변수 생략가능
    void (*Add)(Data*, int);      // Add 멤버함수 선언
} Data;

// 데이터를 출력하는 함수
void ShowData(Data* THIS)         //ShowData 멤버함수 정의
{
    cout << "Data: " << THIS->data << endl;
}

// 데이터에 값을 더하는 함수
void Add(Data* THIS, int num)       //Add 멤버함수 정의
{
    THIS->data += num;
}

// 적절히 변경된 main 함수
int main(void)
{
    // Data 구조체변수 obj1, obj2 객체를 생성하고 초기화
    Data obj1 = { 15, ShowData, Add };
    Data obj2 = { 7, ShowData, Add };

    // 각 객체에 값을 더하고, 데이터를 출력한다.
    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    return 0;
};
/*
함수 포인터 멤버 :
구조체 Data 안에는 함수 포인터 멤버가 있다.이러한 함수 포인터들은 객체의 메서드를 가리킨다.

구조체로 클래스 모방 :
C 언어는 클래스 개념이 없지만, 구조체와 함수 포인터를 사용하여 클래스와 유사한 개념을 모방할 수 있다.
이 예제에서는 Data 구조체를 사용하여 클래스를 흉내냈다.

포인터를 통한 객체의 메서드 호출 :
함수 포인터 멤버를 통해 객체의 메서드를 호출한다.
예를 들어, obj1.Add(&obj1, 17); 은 obj1 객체의 Add 메서드를 호출한다.

데이터 은닉과 캡슐화의 부족 :
C 언어에서는 구조체의 멤버가 모두 공개적으로 접근된다.
따라서 데이터 은닉과 캡슐화가 부족하다.모든 멤버에 대한 접근이 허용되므로,
사용자가 의도하지 않은 변경이 발생할 수 있다.

코드의 이식성 :
이러한 방식은 C 언어로 작성된 코드를 C++로 쉽게 이식할 수 있도록 해준다.
이는 C++로 이식 가능한 코드를 작성할 때 유용할 수 있다.

이러한 접근 방식은 C 언어에서 객체지향 프로그래밍 개념을 구현하려는 경우에 유용하게 사용된다.
하지만 C++의 클래스와 객체 지향 기능에 비해 제약이 있으므로,
보다 복잡한 프로그램을 작성할 때는 클래스와 객체를 사용하는 것이 더 효율적이다.
*/