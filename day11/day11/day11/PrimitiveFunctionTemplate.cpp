#include <iostream>
using namespace std;

template < class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << "," << (T2)num << endl;
}

int main(void)
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}
/*
템플릿 함수:
ShowData 함수는 템플릿 함수로, 두 개의 템플릿 매개변수를 가지고 있습니다.

타입 변환:
ShowData 함수는 입력된 num을 T1과 T2 타입으로 각각 변환하여 출력합니다.
타입 변환은 C++의 형 변환 연산자를 사용하여 이루어집니다.

템플릿 인수 명시:
ShowData 함수를 호출할 때, <T1, T2>와 같이 템플릿 인수를 명시합니다.
이는 컴파일러에게 함수를 특정한 타입으로 인스턴스화하도록 지시하는 역할을 합니다.

템플릿 함수의 유연성:
ShowData 함수는 다양한 타입의 인수를 받아들일 수 있으며, 컴파일 시점에서 타입 변환을 수행합니다.
*/