#include <iostream>

void func()
{
	//...
}

int main()
{
	func();
	return 0;

}

const int num = 10000;

ClassName objName;
ClassName* p = new ClassName; // => new 연산자는 힙 영역에 메모리에 할당 -> 그 주소를 리턴함

/*
ClassName* p = new ClassName; 이부분 설명
ㄴ
1. new 연산자는 메모리를 동적으로 할당하고, 해당 메모리의 주소를 가리키는 포인터를 반환.
=> ClassName*은 ClassName 클래스의 포인터를 가리키는 포인터 변수를 선언하는 방식.

2. 따라서 ClassName* p는 ClassName 클래스의 포인터를 가리키는 포인터 변수를 선언한 것.

3. new ClassName은 ClassName 클래스의 객체를 동적으로 할당하는 구문.
=> 새로운 ClassName 객체가 힙 메모리에 생성되고, 이 객체의 주소를 반환.

4. p = new ClassName은 새로운 ClassName 객체를 생성하고, 이 객체의 주소를 포인터 변수 p에 할당하는 것.

5. 결과적으로, p는 힙영역 메모리에 동적으로 생성된 ClassName 객체를 가리키는 포인터가 됨.
=> 이렇게 생성된 객체는 프로그램이 필요할 때까지 메모리에 남아 있게 됨.
=> 객체를 더 이상 사용하지 않을 때는 delete p;를 사용하여 메모리를 해제
*/

ClassName objName;
int* p = new ClassName; // new 연산자 => 힙영역 메모리 할당 -> 그 주소를 리턴 중

char a = 'a';
int* p = &a;