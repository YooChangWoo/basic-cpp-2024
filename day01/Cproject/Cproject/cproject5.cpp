#include <iostream>

using namespace std; // std 네임스페이스의 모든 것을 사용

int main()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum = sum + i;
	}
	std::cout << sum << std::endl;

	return 0;

}