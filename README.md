# Basic-cpp-2024
IoT 시스템개발자 심화 프로그래밍 언어 학습리포지토리

## 1일차
- 개발환경 설치
	- Visual Studio 2022 Community 설치
	- C, C++ 소스코드 실행
	- C++에 대해 설명

- 제어문
	1. 선택제어문 
		- if, switch
		- if, else 문(C언어종류) / elif = Python
		- 반복문 For
		- 반복문 While
		- Overloading(재정의), Overriding
		
	2. 반복제어문 
		- for,while
		- for(초기식; 조건식; 증감식){
			1. 초기식을 가지고 조건식을 따진다.
			2. 참이면 for문의 실행문 실행
			3. 증감식을 실행
			4. 조건식을 따지고
			2.
			3.
			4.
			2.
			3.
			4.
			.
			.
			.
		}

	
- 지역변수 = 로컬변수
	1. 선언되어진 범위 안에서만 사용이 가능(static 영역에 저장)

- 자료형
	1. 문자 : 문자(char),문자열
	2. 숫자 : 정수(int),실수
	
- 정수로 계산하기
	



## 2일차
// class 안에 들어 가는 함수 = Method

- Default Value
- Reference 함수
	- 반환형 Reference Type
- Name Space
- 전역,지역변수
- C에서 메모리
	- 스택 : 지역변수, 매개변수
	- HEAP : 사용자에게 할당된 영역
		= Malloc() -> free()반환 = 사용을 할려면 Malloc으로 할당을 받는다
	- data: 함수, 전역변수, 상수, 문자 리터럴
	
	- // A & B = 비트 And 연산자
	- // A && B = 논리 And 연산자 = 논리 곱
		
-------------- clang04_test--------------

## 3일차
- Reference 함수(변수) = 계속
- MALLOC & FREE => NEW & DELETE(대신)
	= Malloc() -> free()반환 = 사용을 할려면 Malloc으로 할당을 받는다
	-> HEAP : 사용자에게 할당된 영역
	=> 사용을 할려면 Malloc()(C++: NEW)으로 할당을 받는다 => FREE(C++: DELETE로 반환)

- 접근제어 지시자
	- Public
	- Protected
	- Private
	
- C++ 파일분할 (C++ 와 Head 파일로 분할하는 것 배움)
	
## 4일차
- Class = 멤버변수와 멤버함수로 구성된다. = 클래스 내부에는 멤버들의 선언을 작성 = 멤버함수의 정의를 외부로 뺌(Scope 연산자 사용) = 일반적으로 멤버변수 = Private, 멤버함수= Public의 접근제한을 사용 = 생성자(기능:객체를 생성하고, 초기화)

- 클래스(Class) 와 객채(Object)

- 객체지향 프로그래밍의 이해

- 정보은닉

- 생성자와 소멸자 a. SimpleClass sc(20);
=> 주어진 코드는 SimpleClass라는 클래스의 객체 sc를 생성. => 이 객체는 생성자에 정수 값 20을 전달하여 초기화

- b. SimpleClass *ptr = new SimpleClass(); => SimpleClass 클래스의 포인터를 생성하고, 동적으로 메모리를 할당하여 객체를 초기화. => 여기서 new 연산자는 힙(heap) 메모리에서 동적으로 객체를 생성하고, 해당 객체에 대한 포인터를 반환. => SimpleClass *ptr은 SimpleClass 타입을 가리키는 포인터를 선언. => new SimpleClass()는 SimpleClass의 기본 생성자를 호출하여 객체를 생성. 이후 반환된 포인터는 ptr에 할당. => 따라서 ptr은 힙 메모리에 동적으로 생성된 SimpleClass 객체를 가리키는 포인터

- strcpy, Private, Public
## 5일차
- 멤버 이니셜라이즈
	- 객체 생성 전, 선언과 동시에 초기화가 필요한 경우에 사용
	- const 변수와 참조 변수의 초기화에 사용
	
- 생성자(클래스 이름과 같은 멤버 함수로 출력x)
	- 객체 생성시 자동으로 호출되는 멤버함수
	- 모든 클래스는 디폴트 생성자를 가지고 있음
	- 만약 명시적으로 생성자를 작성하면 디폴트 생성자의 호출 불가 -> 디폴트 생성자가 필요한 경우 명시적으로 작성
	- 멤버변수를 초기화를 담당
	
- 생성자 불일치
	- 매개변수가 void형으로 선언되는 디폴트 생성자
	- 생성자가 하나도 정의되어 있지 않을때에만 삽입이 됨!
	
- Private 생성자
	- 생성자들은 모두 Public으로 선언
	- 객체의 생성이 클래스의 외부에서 진행도기 때문에 생성자는 Public으로 선언
	
- 소멸자 => 객체 생성시 반드시 호출되는 것이 생성자 -> 객체 소멸시 반드시 호출 되는 것은 소멸자

- 메모리 동적할당 : new 연산자 사용
	- 프로그램 실행 중 = 메모리 할당
	
- 객체 배열
```c++ 
SoSimple arr[10];
```

```c++ 동적으로 할당할 경우
SoSimple *ptrArr = new SoSimple[10]

```
- 포인터배열 : 포인터를 저장하는 배열
- 배열 포인터 : 배열을 가리키는 포인터
- 복사 생성자, 디폴트 생성자
## 6일차
- 깊은 복사와 얕은 복사
- 복사 생성자의 호출 시점
	1. 기존에 생성된 객체 => 새로운 객체를 초기화
	2. Call-By-Value 방식의 함수호출 과정에서 객체를 인자로 전달
	3. 객체를 반환 -> 참조형으로는 반환 X
	
- Return Object Dead Time

- friend

- static

- const
	1. 객체와 객체의 특성들
	2. 함수 오버 로딩
	3. 함수의 Friend 선언

- C++ 에서의 Static
## 7일차
```c++
Person class
	char *name; // 이름을 저장하는 동적 할당된 문자열 포인터
	int age; // 나이를 저장하는 정수

int main()
{
    Person p("Hong", 30); // "Hong" 문자열을 가지고 30이라는 나이로 Person 객체 생성
    p.personInfo(); // Person 객체의 정보 출력

    Person copyp(p); // p 객체를 복사하여 새로운 객체 copyp 생성
    copyp.personInfo(); // 복사된 객체 copyp의 정보 출력

    return 0;
}
	```
	
		- name 필드는 힙영역에 메모리를 할당하여 저장
		- 자기 객체를 생성하고 객체 복사를 하시오

- 상속(INHERITANCE)
	- 문법적 이해
	- 유도클래스의 객체생성 과정

- Protected 선언과 세가지 형태의 상속
	
## 8일차
- 다형성
	- 오버로딩 = 다중 정의
	- 오버라이딩 = 재정의, 상속관계에서 사용

- 참조자의 참조 가능성
- 가상 소멸자와 참조자의 참조 가능성
- 순수 가상 함수와 추상 클래스
- 멤버함수와 가상함수의 동작원리
- 가상함수

(오후 점심시간)
=> remotecontrol 클래스, samsungTv클래스, lgTv클래스를 설계하고 
	-> remote->on() 호출하면 연결된 tv에 따라서 삼성TV on 또는 엘지Tv on 출력 되도록 프로그램 완성

- 순수 가상 함수
- 가상 소멸자와 참조자의 참조 가능성
- 가상(Virtual)의 원리와 다중상속
- 다중상속에 대한 이해
## 9일차 

## 10일차