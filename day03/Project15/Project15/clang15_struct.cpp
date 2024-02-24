#include <iostream>
/*
C타입의 구조체
*/
typedef struct human { //human 구조체 => 내가 만든 사용자 정의 자료형
	char name[20]; // 속성 멤버변수(name, age, job)
	int age;
	char job[20];

} Human; // 앞으로 human 구조체를 Human으로 사용

void showHuman(Human h1) {
	printf("name: %s, age: %d, job: %s\n", h.name, h.age, h.job);
}

int main() {
	int a;
	human h1 = { "Hong", 50, "의적" }; //Human타입의 변수를 선언하고 초기화를 시킨다
	showHuman(h1);
	return 0;

}