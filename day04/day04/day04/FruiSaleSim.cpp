#include <iostream>
using namespace std;

class FruitSeller                   // 과일 판매자 클래스 정의
{
private:
	int APPLE_PRICE;    // 사과 한 개의 가격
	int numofApples;    // 현재 보유한 사과의 개수
	int myMoney;        // 총 매출액

public:
	// 과일 판매자의 속성을 초기화하는 함수
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numofApples = num;
		myMoney = money;
	}

	// 사과를 판매하고 수익을 계산하는 함수
	int saleApples(int money)
	{
		int num = money / APPLE_PRICE;    // 구매한 사과의 개수 계산
		numofApples -= num;               // 남은 사과 개수 업데이트
		myMoney += money;                 // 매출액 업데이트
		return num;                       // 구매한 사과의 개수 반환
	}

	// 현재 과일 판매자의 상태를 출력하는 함수
	void showSalesResult()
	{
		cout << "남은 사과: " << numofApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer          // 과일 구매자 클래스 정의
{
	int myMoney;         // 과일 구매자의 소지금
	int numofApples;     // 과일 구매자가 보유한 사과의 개수

public:
	// 과일 구매자의 속성을 초기화하는 함수
	void InitMembers(int money)
	{
		myMoney = money;
		numofApples = 0;
	}

	// 과일을 구매하는 함수
	void BuyApples(FruitSeller& refseller, int money)
	{
		numofApples += refseller.saleApples(money);    // 판매자로부터 사과를 구매하고 보유한 사과의 개수를 업데이트
		myMoney -= money;                              // 소지금에서 구매한 가격을 차감
	}

	// 현재 과일 구매자의 상태를 출력하는 함수
	void showBuyResult()
	{
		cout << "현재 잔액:" << myMoney << endl;
		cout << "사과 개수:" << numofApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);   // 과일 판매자 객체 초기화

	FruitBuyer buyer;
	buyer.InitMembers(5000);           // 과일 구매자 객체 초기화

	buyer.BuyApples(seller, 2000);     // 과일 구매자가 과일 판매자로부터 사과를 구매

	cout << "과일 판매자의 현황" << endl;
	seller.showSalesResult();           // 과일 판매자의 현황 출력

	cout << "과일 구매자의 현황" << endl;
	buyer.showBuyResult();              // 과일 구매자의 현황 출력

	return 0;
}
