#include <iostream>
#include <cstring>
using namespace std;

namespace Car_CONST {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
    };
}

class Car {
private:
    char gamerID[Car_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Break();
    void Accel();
};

void Car::InitMembers(const char* ID, int fuel) {
    strcpy_s(gamerID, sizeof(gamerID), ID); // strcpy_s 사용
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState() {
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl;
}

void Car::Accel() {
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= Car_CONST::FUEL_STEP;
    if ((curSpeed + Car_CONST::ACC_STEP) >= Car_CONST::MAX_SPD) {
        curSpeed = Car_CONST::MAX_SPD;
        return;
    }
    curSpeed += Car_CONST::ACC_STEP;
}

void Car::Break() {
    if (curSpeed < Car_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= Car_CONST::BRK_STEP;
}

int main(void) {
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77;
    sped77.InitMembers("sped77", 100);
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}
