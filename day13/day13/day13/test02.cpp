#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // int타입 vector 생성

    for ( int i = 0; i < 10; i++ )
    {
        v.push_back(i + 1);
        printf("v[%d] : %d\n", i, v[ i ]); // 각 원소의 값을 출력
        printf("v.size(): %||\n", v.size()); // 원소 갯수 출력
        printf("v.capcity(): %d\n", v.capacity()); // 메모리 공간 출력

    }
    cout << endl;

    v.push_back(20); // 정수 20을 벡터에 추가
    v.push_back(21); // 정수 21을 벡터에 추가

    for ( vector<int>::size_type i = 0; i < v.size(); i++ )
    {
        printf("v[%d]: %d\n", i, v[ i ]); // 인덱스와 해당하는 원소의 값을 출력
        printf("v.at(i): %d\n", v.at(i)); // 인덱스와 해당하는 원소의 값을 출력

        // 주의: v.at(i)는 벡터의 범위를 벗어나는 인덱스에 대해서 예외를 발생시킬 수 있음
    }
    cout << endl;

    cout << "iterator : 반복자" << endl;
    vector<int>::iterator iter;
    for ( iter = v.begin(); iter != v.end(); iter++ ) {
        cout << "* iter: " << *iter << endl; // 반복자를 통해 벡터의 모든 원소 출력
    }

    vector<string> vs;

    vs.push_back("Hi"); // 문자열 "Hi"를 벡터에 추가
    vs.push_back("Hello"); // 문자열 "Hello"를 벡터에 추가
    vs.push_back("Roy Lee"); // 문자열 "Roy Lee"를 벡터에 추가

    cout << "vs.Front() : " << vs.front() << endl; // 첫 번째 원소 출력
    cout << "vs.Back() : " << vs.back() << endl; // 마지막 원소 출력

    vector<string>::iterator it;
    for ( it = vs.begin(); it != vs.end(); it++ )
    {
        cout << *it << endl; // 벡터의 각 원소를 출력
    }

    vector<int> v1; // 크기가 0 인 백터가 생성
    vector<int> v2(5); // 크기가 5인 백터가 생성 (0으로 초기화)
    vector<int> v3 = { 10, 20 ,30 };
    vector<int> v4(10, 7); //크기가 10이고, 7초기화

    return 0;
}
/*
벡터(Vector):

벡터는 C++ 표준 라이브러리의 한 컨테이너로, 동적 배열을 구현합니다.
크기가 동적으로 조절되며, 배열과 유사하게 연속적인 메모리 공간에 원소들을 저장합니다.
<vector> 헤더 파일을 포함하여 사용합니다.

원소 추가와 삭제:

push_back() 함수를 사용하여 원소를 벡터의 끝에 추가할 수 있습니다.
벡터의 크기가 부족한 경우, 원소를 추가할 때마다 동적으로 메모리를 재할당하여 크기를 늘립니다.

원소 접근:

배열처럼 [] 연산자를 사용하여 인덱스를 통해 원소에 접근할 수 있습니다.
at() 함수를 사용하여 인덱스를 통해 원소에 접근할 수 있습니다.
범위를 벗어나는 인덱스에 대해서는 예외가 발생합니다.

반복자(Iterator):

벡터의 원소를 순회하고 접근하기 위해 반복자를 사용합니다.
begin() 함수는 첫 번째 원소를 가리키는 반복자를 반환합니다.
end() 함수는 마지막 원소의 다음 위치를 가리키는 반복자를 반환합니다.

front()와 back():

front() 함수는 첫 번째 원소를 반환합니다.
back() 함수는 마지막 원소를 반환합니다.

초기화:

다양한 방법으로 벡터를 초기화할 수 있습니다.
예를 들어, 크기를 지정하여 생성하거나 초기값을 지정하여 생성할 수 있습니다.
*/