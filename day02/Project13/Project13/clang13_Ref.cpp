#include <iostream>

using namespace std;

int main() {

	// 크기가 3인 정수형 배열 arr을 선언하고 초기화. 
	// 배열의 각 요소에는 1, 3, 5가 순서대로 저장
	int arr[] = { 1, 3, 5, 7, 9 }; // 배열선언

	for (int i = 0; i < 5; i++) // 배열출력
	{
		cout << i << "번째 방에 들어있는 요소값!" << arr[i] << endl; //배열의 각 원소에 접근

	}

	arr[3] = 10;
	cout << "arr[3]" << arr[3] << endl;
	// 배열 arr의 각 요소에 대한 참조를 생성
	// 이를 각각 ref1, ref2, ref3에 저장
	// 따라서 이제 ref1, ref2, ref3 => 각각 arr의 첫 번째, 두 번째, 세 번째 요소를 가리키는 참조
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	ref1 = 100;
	cout << "arr[0] = " << arr[0] << endl;
	return 0;
}