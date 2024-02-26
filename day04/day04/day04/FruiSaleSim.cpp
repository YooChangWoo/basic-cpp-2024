#include <iostream>
using namespace std;

class FruitSeller                   // ���� �Ǹ��� Ŭ���� ����
{
private:
	int APPLE_PRICE;    // ��� �� ���� ����
	int numofApples;    // ���� ������ ����� ����
	int myMoney;        // �� �����

public:
	// ���� �Ǹ����� �Ӽ��� �ʱ�ȭ�ϴ� �Լ�
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numofApples = num;
		myMoney = money;
	}

	// ����� �Ǹ��ϰ� ������ ����ϴ� �Լ�
	int saleApples(int money)
	{
		int num = money / APPLE_PRICE;    // ������ ����� ���� ���
		numofApples -= num;               // ���� ��� ���� ������Ʈ
		myMoney += money;                 // ����� ������Ʈ
		return num;                       // ������ ����� ���� ��ȯ
	}

	// ���� ���� �Ǹ����� ���¸� ����ϴ� �Լ�
	void showSalesResult()
	{
		cout << "���� ���: " << numofApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer          // ���� ������ Ŭ���� ����
{
	int myMoney;         // ���� �������� ������
	int numofApples;     // ���� �����ڰ� ������ ����� ����

public:
	// ���� �������� �Ӽ��� �ʱ�ȭ�ϴ� �Լ�
	void InitMembers(int money)
	{
		myMoney = money;
		numofApples = 0;
	}

	// ������ �����ϴ� �Լ�
	void BuyApples(FruitSeller& refseller, int money)
	{
		numofApples += refseller.saleApples(money);    // �Ǹ��ڷκ��� ����� �����ϰ� ������ ����� ������ ������Ʈ
		myMoney -= money;                              // �����ݿ��� ������ ������ ����
	}

	// ���� ���� �������� ���¸� ����ϴ� �Լ�
	void showBuyResult()
	{
		cout << "���� �ܾ�:" << myMoney << endl;
		cout << "��� ����:" << numofApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);   // ���� �Ǹ��� ��ü �ʱ�ȭ

	FruitBuyer buyer;
	buyer.InitMembers(5000);           // ���� ������ ��ü �ʱ�ȭ

	buyer.BuyApples(seller, 2000);     // ���� �����ڰ� ���� �Ǹ��ڷκ��� ����� ����

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.showSalesResult();           // ���� �Ǹ����� ��Ȳ ���

	cout << "���� �������� ��Ȳ" << endl;
	buyer.showBuyResult();              // ���� �������� ��Ȳ ���

	return 0;
}
