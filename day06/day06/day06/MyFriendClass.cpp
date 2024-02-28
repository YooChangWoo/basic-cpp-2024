#include <iostream>
#include <cstring>
using namespace std;

class Girl; // Girl이라는 이름이 클래스의 이름임을 알리고 선언

class Boy
{
private:
    int height; // 남자의 키를 저장하는 private 멤버 변수
    friend class Girl; // Girl 클래스를 friend로 선언하여 Girl 클래스의 멤버 함수가 Boy 클래스의 private 멤버에 접근할 수 있도록 함

public:
    // 생성자: 키를 입력받아 초기화함
    Boy(int len) : height(len) {}

    // ShowYourFriendInfo 함수: Girl 객체를 받아와서 그의 전화번호를 출력함
    void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
    char phNum[20]; // 여자의 전화번호를 저장하는 private 멤버 변수

public:
    // 생성자: 전화번호를 입력받아 초기화함
    Girl(const char* num)
    {
        strcpy_s(phNum, num);
    }

    // ShowYourFriendInfo 함수: Boy 객체를 받아와서 그의 키를 출력함
    void ShowYourFriendInfo(Boy& frn);

    // Boy 클래스를 friend로 선언하여 Boy 클래스의 멤버 함수가 Girl 클래스의 private 멤버에 접근할 수 있도록 함
    friend class Boy;
};

// Boy 클래스의 ShowYourFriendInfo 함수 정의
void Boy::ShowYourFriendInfo(Girl& frn)
{
    // Girl 클래스의 private 멤버인 전화번호를 출력
    cout << "Her phone Number : " << frn.phNum << endl;
}

// Girl 클래스의 ShowYourFriendInfo 함수 정의
void Girl::ShowYourFriendInfo(Boy& frn)
{
    // Boy 클래스의 private 멤버인 키를 출력
    cout << "His height : " << frn.height << endl;
}

// 메인 함수
int main(void)
{
    // Boy 객체 생성 및 초기화
    Boy boy(170);

    // Girl 객체 생성 및 초기화
    Girl gir("010-1234-5678");

    // Boy 객체의 ShowYourFriendInfo 함수 호출하여 Girl 객체의 전화번호 출력
    boy.ShowYourFriendInfo(gir);

    // Girl 객체의 ShowYourFriendInfo 함수 호출하여 Boy 객체의 키 출력
    gir.ShowYourFriendInfo(boy);

    return 0;
}

/*
Boy 클래스:

Boy 클래스는 하나의 private 멤버 변수 height를 가지고 있습니다.
height 변수에 대한 접근을 허용하기 위해 Girl 클래스를 friend로 선언합니다.
ShowYourFriendInfo() 함수는 Girl 객체의 전화번호를 출력합니다.

Girl 클래스:

Girl 클래스는 하나의 private 멤버 변수 phNum을 가지고 있습니다.
phNum 변수에 대한 접근을 허용하기 위해 Boy 클래스를 friend로 선언합니다.
ShowYourFriendInfo() 함수는 Boy 객체의 키를 출력합니다.

main 함수:

main 함수에서는 Boy 클래스와 Girl 클래스의 객체를 생성합니다.
두 객체 간의 정보를 서로 출력할 수 있도록 friend로 선언된 멤버 함수를 호출합니다.
프로그램을 실행하면, 두 클래스의 객체 간에 정보를 주고받는 것을 확인할 수 있습니다. 이는 friend 선언을 통해 두 클래스 간의 멤버 변수 및 함수에 접근할 수 있게 됩니다.
*/