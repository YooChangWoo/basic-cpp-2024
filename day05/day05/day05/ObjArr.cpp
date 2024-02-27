#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(char* myname, int myage)   // 생성자 오버로딩
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()      //디폴트 생성자
    {
        name = NULL;
        age = 0;
        cout << "Called Person" << endl;
    }
    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << ",";
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[]name;
        cout << "called destrutor!" << endl;
    }
};

int main(void)
{
    Person parr[3];      // 객체배열 3개의 Person 타입의 개체 선언

    char namestr[100];   // 문자배열 
    char* strptr;       // 문자타입의 포인터 변수, char 타입의 문자의 주소값을 저장하는 포인터변수 
    int age;
    int len;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;

        len = strlen(namestr) + 1;
        strptr = new char[len];   // 힙 영역에 메모리 동적 할당
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();
    return 0;

}
/*
 포인트 배열 : 배열(포인트를 저장하고 있는 배열)
 배열 포인트 : 포인트 (배열을 가르키고 있는 포인트)
*/