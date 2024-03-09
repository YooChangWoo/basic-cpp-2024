#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}
/*
int main(void)
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;
	return 0;
}
*/

int main(void)
{
	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;
	return 0;
}
/*
템플릿 함수:
Add 함수는 템플릿 함수입니다.
템플릿 함수는 특정한 자료형에 의존하지 않고 일반화된 함수를 작성할 수 있도록 합니다.
이 경우, T라는 템플릿 매개변수를 사용하여 함수를 정의했습니다.

타입 추론:
함수 호출 시, 컴파일러는 인자의 자료형을 통해 어떤 타입의 Add 함수를 호출할지 결정합니다.
이를 타입 추론(Type Inference)이라고 합니다.

템플릿 인스턴스화:
컴파일러는 함수 호출 시 인자의 자료형에 맞게 템플릿을 인스턴스화합니다.
예를 들어, Add(15, 20)의 경우, 컴파일러는 T를 int로 추론하고 Add<int>(15, 20)으로 인스턴스화합니다.

템플릿 함수의 일반성:
Add 함수는 정수형이나 실수형 등 다양한 자료형에 대해 동작합니다.
이는 템플릿 함수의 일반성을 나타내는 것입니다.

템플릿의 장점:
템플릿은 코드의 재사용성을 높여주고, 일반화된 코드를 작성하여 코드의 유연성을 증가시킵니다.
*/