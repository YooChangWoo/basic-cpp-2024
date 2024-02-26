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

## 6일차

## 7일차

## 8일차

## 9일차 

## 10일차