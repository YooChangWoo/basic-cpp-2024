#include <iostream>
using namespace std;

// 과일 판매자 클래스 정의
class FruitSeller
{
private:
	int APPLE_PRICE;    // 사과 한 개의 가격
	int numofApples;    // 현재 보유한 사과의 개수
	int myMoney;        // 총 매출액

public:
	// 생성자: 초기화 리스트를 사용하여 멤버 변수 초기화
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numofApples(num), myMoney(money)
	{
	}

	// 사과를 판매하고 수익을 계산하는 함수
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;    // 구매한 사과의 개수 계산
		numofApples -= num;               // 남은 사과 개수 업데이트
		myMoney += money;                 // 매출액 업데이트
		return num;                       // 구매한 사과의 개수 반환
	}

	// 현재 과일 판매자의 상태를 출력하는 함수
	void ShowSalesResult() const
	{
		cout << "남은 사과: " << numofApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

// 과일 구매자 클래스 정의
class FruitBuyer
{
private:
	int myMoney;         // 과일 구매자의 소지금
	int numofApples;     // 과일 구매자가 보유한 사과의 개수

public:
	// 생성자: 초기화 리스트를 사용하여 멤버 변수 초기화
	FruitBuyer(int money)
		: myMoney(money), numofApples(0)
	{
	}

	// 과일을 구매하는 함수
	void BuyApples(FruitSeller& seller, int money)
	{
		numofApples += seller.SaleApples(money);    // 판매자로부터 사과를 구매하고 보유한 사과의 개수를 업데이트
		myMoney -= money;                           // 소지금에서 구매한 가격을 차감
	}

	// 현재 과일 구매자의 상태를 출력하는 함수
	void ShowBuyResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numofApples << endl << endl;
	}
};

int main(void)
{
	// 과일 판매자 객체 생성 및 초기화
	FruitSeller seller(1000, 20, 0);
	// 과일 구매자 객체 생성 및 초기화
	FruitBuyer buyer(5000);
	// 과일 구매자가 과일 판매자로부터 사과를 구매
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	// 과일 판매자의 현재 상태 출력
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	// 과일 구매자의 현재 상태 출력
	buyer.ShowBuyResult();
	return 0;
}

/*
1. FruitSeller 클래스:

	-> Apple_Price, numOfApples, myMoney라는 세 가지 멤버 변수를 가지고 있음.
		=> 각각은 사과의 가격, 남은 사과의 개수, 판매자의 보유 금액을 나타냄.

	->	InitMember 함수는 멤버 변수들을 초기화.
		=> 이 함수는 가격, 사과 개수, 보유 금액을 매개변수로 받아와서 멤버 변수에 할당.

		-> SaleApples 함수는 사과를 판매하는 메서드.
			=> 구매자로부터 받은 돈을 기반으로 판매하고, 판매된 사과의 개수와 판매 수익을 반환.

		-> ShowSalesResult 함수 = 남은 사과의 개수와 판매 수익을 출력.

2. FruitBuyer 클래스:

	-> numOfApples, myMoney라는 두 가지 멤버 변수를 가지고 있음.
		=> 각각은 구매한 사과의 개수, 구매자의 보유 금액을 나타냄.

	-> InitMember 함수는 멤버 변수들을 초기화.
		=> 초기에는 사과를 하나도 구매하지 않았으므로 numOfApples은 0.

	-> BuyApples 함수는 과일 판매자로부터 사과를 구매하는 메서드.
		=>판매자에게 돈을 주고, 판매된 사과의 개수를 증가시키고, 구매자의 잔액을 감소시킴.

	->ShowBuyResult 함수는 현재 보유 금액과 구매한 사과의 개수를 출력.


3. 메인 함수:
	-> main 함수에서는 먼저 과일 판매자와 과일 구매자 객체를 생성 후 -> 초기화.
	-> 구매자가 판매자로부터 사과를 구매하고, 거래 과정의 결과를 출력.

*/