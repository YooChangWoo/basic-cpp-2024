#include <iostream>
using namespace std;

// ���� �Ǹ��� Ŭ���� ����
class FruitSeller
{
private:
	int APPLE_PRICE;    // ��� �� ���� ����
	int numofApples;    // ���� ������ ����� ����
	int myMoney;        // �� �����

public:
	// ������: �ʱ�ȭ ����Ʈ�� ����Ͽ� ��� ���� �ʱ�ȭ
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numofApples(num), myMoney(money)
	{
	}

	// ����� �Ǹ��ϰ� ������ ����ϴ� �Լ�
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;    // ������ ����� ���� ���
		numofApples -= num;               // ���� ��� ���� ������Ʈ
		myMoney += money;                 // ����� ������Ʈ
		return num;                       // ������ ����� ���� ��ȯ
	}

	// ���� ���� �Ǹ����� ���¸� ����ϴ� �Լ�
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numofApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

// ���� ������ Ŭ���� ����
class FruitBuyer
{
private:
	int myMoney;         // ���� �������� ������
	int numofApples;     // ���� �����ڰ� ������ ����� ����

public:
	// ������: �ʱ�ȭ ����Ʈ�� ����Ͽ� ��� ���� �ʱ�ȭ
	FruitBuyer(int money)
		: myMoney(money), numofApples(0)
	{
	}

	// ������ �����ϴ� �Լ�
	void BuyApples(FruitSeller& seller, int money)
	{
		numofApples += seller.SaleApples(money);    // �Ǹ��ڷκ��� ����� �����ϰ� ������ ����� ������ ������Ʈ
		myMoney -= money;                           // �����ݿ��� ������ ������ ����
	}

	// ���� ���� �������� ���¸� ����ϴ� �Լ�
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numofApples << endl << endl;
	}
};

int main(void)
{
	// ���� �Ǹ��� ��ü ���� �� �ʱ�ȭ
	FruitSeller seller(1000, 20, 0);
	// ���� ������ ��ü ���� �� �ʱ�ȭ
	FruitBuyer buyer(5000);
	// ���� �����ڰ� ���� �Ǹ��ڷκ��� ����� ����
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	// ���� �Ǹ����� ���� ���� ���
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	// ���� �������� ���� ���� ���
	buyer.ShowBuyResult();
	return 0;
}

/*
1. FruitSeller Ŭ����:

	-> Apple_Price, numOfApples, myMoney��� �� ���� ��� ������ ������ ����.
		=> ������ ����� ����, ���� ����� ����, �Ǹ����� ���� �ݾ��� ��Ÿ��.

	->	InitMember �Լ��� ��� �������� �ʱ�ȭ.
		=> �� �Լ��� ����, ��� ����, ���� �ݾ��� �Ű������� �޾ƿͼ� ��� ������ �Ҵ�.

		-> SaleApples �Լ��� ����� �Ǹ��ϴ� �޼���.
			=> �����ڷκ��� ���� ���� ������� �Ǹ��ϰ�, �Ǹŵ� ����� ������ �Ǹ� ������ ��ȯ.

		-> ShowSalesResult �Լ� = ���� ����� ������ �Ǹ� ������ ���.

2. FruitBuyer Ŭ����:

	-> numOfApples, myMoney��� �� ���� ��� ������ ������ ����.
		=> ������ ������ ����� ����, �������� ���� �ݾ��� ��Ÿ��.

	-> InitMember �Լ��� ��� �������� �ʱ�ȭ.
		=> �ʱ⿡�� ����� �ϳ��� �������� �ʾ����Ƿ� numOfApples�� 0.

	-> BuyApples �Լ��� ���� �Ǹ��ڷκ��� ����� �����ϴ� �޼���.
		=>�Ǹ��ڿ��� ���� �ְ�, �Ǹŵ� ����� ������ ������Ű��, �������� �ܾ��� ���ҽ�Ŵ.

	->ShowBuyResult �Լ��� ���� ���� �ݾװ� ������ ����� ������ ���.


3. ���� �Լ�:
	-> main �Լ������� ���� ���� �Ǹ��ڿ� ���� ������ ��ü�� ���� �� -> �ʱ�ȭ.
	-> �����ڰ� �Ǹ��ڷκ��� ����� �����ϰ�, �ŷ� ������ ����� ���.

*/