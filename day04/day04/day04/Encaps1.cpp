#include <iostream>
using namespace std;

// 재체기를 막는 약 클래스
class Sneezcap
{
public:
    void Take() const { cout << "재체기가 멎습니다" << endl; }
};

// 콧물을 멈추는 약 클래스
class SinivelCap
{
public:
    void Take() const { cout << "콧물이 멈춥니다" << endl; }
};

// 재채기를 멈추는 약 클래스
class Snufflecap
{
public:
    void Take() const { cout << "재채기가 멈춥니다" << endl; }
};

// Contac600 약 클래스
class Contac600
{
public:
    void Take() const { cout << "Contac600을 복용합니다." << endl; }
};

// 감기 환자 클래스
class ColdPatient
{
public:
    // 콧물 약을 복용하는 함수
    void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }

    // 재채기 약을 복용하는 함수
    void TakeSneezcap(const Sneezcap& cap) const { cap.Take(); }

    // 재채기 약을 복용하는 함수
    void TakeSnufflecap(const Snufflecap& cap) const { cap.Take(); }

    // Contac600 약을 복용하는 함수
    void TakeContac600(const Contac600& cap) const { cap.Take(); }
};

int main(void)
{
    // 약 객체 생성
    SinivelCap scap;        // 콧물 약
    Sneezcap zcap;          // 재채기 약
    Snufflecap ncap;        // 재채기 약
    Contac600 contac600;    // Contac600 약

    // 감기 환자 객체 생성
    ColdPatient sufferer;

    // 환자가 약을 복용
    sufferer.TakeSinivelCap(scap);     // 콧물 약 복용
    sufferer.TakeSneezcap(zcap);       // 재채기 약 복용
    sufferer.TakeSnufflecap(ncap);     // 재채기 약 복용
    sufferer.TakeContac600(contac600); // Contac600 약 복용

    return 0;
}
