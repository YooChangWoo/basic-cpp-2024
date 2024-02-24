#include <iostream>
using namespace std;
/*
1. Car_CONST 네임스페이스: 
-> 이 네임스페이스에는 자동차에 대한 상수들이 열거형(enum)으로 정의
--> 이러한 상수들은 자동차의 속성 및 동작에 대한 정보를 정의. 
---> 예를 들어, 자동차의 ID 길이, 최대 속도, 연료 소모량, 가속 및 제동 속도 증가량이 포함
*/
namespace Car_CONST {
	enum {
		ID_LEN =20,
		MAX_SPD = 200,
		FUEL_STEP = 2, 
		ACC_STEP = 2,
		BRK_STEP = 2,
	};
}


/*
2. Car 구조체
-> 이 구조체에는 자동차의 속성 및 동작을 표현하는 멤버 변수와 멤버 함수가 정의
--> gamerID: 자동차의 소유자 ID를 저장.
--> fuelGauge: 자동차의 연료량을 저장.
--> curSpeed: 자동차의 현재 속도를 저장.
--> ShowCarState(): 자동차의 상태를 출력하는 함수로, 소유자 ID, 연료량 및 현재 속도를 출력.
--> Accel(): 자동차를 가속시키는 함수로, 연료 소모량과 속도를 조절.
--> Break(): 자동차를 감속시키는 함수로, 속도를 조절.
*/
struct Car
{
	char gamerID[Car_CONST::ID_LEN]; // char gameID[20];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {
		cout << "소유자 ID" << gamerID << endl;
		cout << "연료량" << fuelGauge << "%" << endl;
		cout << "현재속도" << curSpeed <<"km/s" << endl;

	}

	void Accel()
	{
		if (fuelGauge <= 0)
			return;
		else
		
			fuelGauge -= Car_CONST::FUEL_STEP;
		if ((curSpeed + Car_CONST::ACC_STEP) >= Car_CONST::MAX_SPD)
		{
			curSpeed = Car_CONST::MAX_SPD;
			return;

		}
		curSpeed += Car_CONST::ACC_STEP;

		
	}

	void Break()
	{
		if (curSpeed < Car_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		curSpeed -= Car_CONST::BRK_STEP;
	}
};


/*
3. main 함수: 
-> 이 함수에서는 두 대의 자동차 객체(run99와 sped77)를 생성하고, 
--> 각각의 객체에 대해 가속 및 감속 동작을 수행한 후에 자동차의 상태를 출력
*/
int main(void) {
	Car run99 = { "run99", 100, 0 };
	run99.Accel(); // 98,10
	run99.Accel(); // 96,20
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}