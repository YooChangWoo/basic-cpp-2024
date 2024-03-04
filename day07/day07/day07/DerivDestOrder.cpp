#include <iostream>
using namespace std;

// ��� Ŭ���� ����
class SoBase
{
private:
	int baseNum; // ��� Ŭ������ ������ ��� ����

public:
	// ��� Ŭ������ ������: baseNum�� �ʱ�ȭ�ϰ� �޽��� ���
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}

	// ��� Ŭ������ �Ҹ���: �޽��� ���
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

// �Ļ� Ŭ���� ����
class SoDerived : public SoBase
{
private:
	int derivNum; // �Ļ� Ŭ������ ������ ��� ����

public:
	// �Ļ� Ŭ������ ������: ��� Ŭ������ �����ڸ� ȣ���ϰ� derivNum �ʱ�ȭ �� �޽��� ���
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}

	// �Ļ� Ŭ������ �Ҹ���: �޽��� ���
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	// �Ļ� Ŭ���� ��ü ������ ���ÿ� ������ ȣ��
	SoDerived drv1(15);
	SoDerived drv2(27);

	return 0;
}

/*
SoBase(int n): ��� Ŭ������ SoBase�� �������Դϴ�.
�� �����ڴ� ������ ���ڸ� �޾Ƽ� baseNum ��� ������ �ʱ�ȭ�ϰ�, ��ü�� ������ �� �ش� ���� ����մϴ�.

~SoBase(): ��� Ŭ������ SoBase�� �Ҹ����Դϴ�.
�� �Ҹ��ڴ� ��ü�� �Ҹ�� �� baseNum ��� ������ ���� ����մϴ�.

SoDerived(int n): �Ļ� Ŭ������ SoDerived�� �������Դϴ�.
�� �����ڴ� ���� ��� Ŭ������ SoBase�� �����ڸ� ȣ���ϰ�,
�� �Ŀ� �Ļ� Ŭ������ derivNum ��� ������ �ʱ�ȭ�ϰ�, ������ ���� ����մϴ�.

~SoDerived(): �Ļ� Ŭ������ SoDerived�� �Ҹ����Դϴ�.
�� �Ҹ��ڴ� ��ü�� �Ҹ�� �� derivNum ��� ������ ���� ����մϴ�.

main() �Լ������� SoDerived Ŭ������ �� ��ü�� �����ϰ�,
�����ڿ� �Ҹ��ڰ� ȣ��Ǵ� ������ Ȯ���� �� �ֽ��ϴ�.
��ü�� ������ ���� �����ڰ� ȣ��Ǹ�, ��ü�� �Ҹ�� ���� �Ҹ��ڰ� ȣ��˴ϴ�.
���� ��� ����� ���� ��ü�� ������ �Ҹ� ������ ������ �� �ֽ��ϴ�.
*/