#include <iostream>
#include <string>

using namespace std;

// human 구조체 정의
// human 구조체 => 내가 만든 사용자 정의 자료형
// 속성 멤버변수(name, age, job)
struct Human {
    string name;
    int age;
    string job;
};

// Human 구조체를 매개변수로 받는 함수 정의, 멤버함수 기능
void showHuman(Human h1) { 
    cout << "name: " << h1.name << ", age: " << h1.age << ", job: " << h1.job << endl;
}

int main() {
    // human 구조체 변수 생성 및 초기화
    Human h1 = { "Hong", 50, "의적" };

    // showHuman 함수 호출하여 구조체 정보 출력
    showHuman(h1);

    return 0;
}
