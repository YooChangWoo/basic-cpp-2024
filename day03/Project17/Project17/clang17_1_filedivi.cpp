#include <iostream>

class AClass {
	int num;

public:					//접근제어 지시자
	AClass(int anum) { // 생성자: 초기화 담당자
		num = anum;
	}
	void AInfo() {
		std::cout << "A::num:" << num << std::endl;
	}
};

int main()
{
	AClass a(10);
	a.AInfo();

	return 0;

}