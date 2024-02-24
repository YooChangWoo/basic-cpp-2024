#include <iostream>

using namespace std;

namespace Car_CONST {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 2,
        BRK_STEP = 2,
    };
}

struct Car {
    //=========Member �Լ�=========
    char gamerID[Car_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    //=========Member �Լ�=========
    void ShowCarState(); // �������� ���
    void Accel(); // ����, �ӵ�����
    void Break(); // �극��ũ, �ӵ� ����
};

void Car :: ShowCarState() {
	cout << "������ ID" << gamerID << endl;
	cout << "���ᷮ" << fuelGauge << "%" << endl;
	cout << "����ӵ�" << curSpeed << "km/s" << endl;

}

void Car:: Accel()
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

void Car:: Break()
{
	if (curSpeed < Car_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= Car_CONST::BRK_STEP;
}
int main() {
    Car run99 = { "run99", 100, 0 };
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77 = { "sped77", 100, 0 };
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}