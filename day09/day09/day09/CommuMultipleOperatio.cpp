#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos; // 2���� ��ǥ�� �����ϴ� private ��� ����
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) // ������, �⺻������ (0,0)���� �ʱ�ȭ
	{  }

	void ShowPosition() const // ���� ��ǥ�� ����ϴ� ��� �Լ�
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times) // * �����ڸ� �����ε��Ͽ� ��ǥ�� ����� ���� ����� ��ȯ�ϴ� ��� �Լ�
	{
		Point pos(xpos * times, ypos * times); // ���� ��ǥ�� ����� ���� ���ο� Point ��ü ����
		return pos; // ���ο� Point ��ü ��ȯ
	}

	friend Point operator*(int times, Point& ref); // friend ������ ���� ���� �Լ��� ������ �����ε��� �����ϰ� ��
};

Point operator*(int times, Point& ref)
{
	return ref * times; // ���� �Լ������� ��� �Լ��� ������ �����Ͽ� �ٽ� ���� ����� ��ȯ��
}

int main(void)
{
	Point pos(1, 2); // �ʱ� ��ǥ (1, 2)�� ���� Point ��ü ����
	Point cpy; // ������ Point ��ü ����

	cpy = 3 * pos; // ���� �Լ��� ���� ������ ��ü�� ���� ����Ͽ� cpy�� �Ҵ�
	cpy.ShowPosition(); // cpy�� ��ǥ ���: [3, 6]

	cpy = 2 * pos * 3; // ���� �Լ��� ���� ���Ǵ� ���� ��ü�� ���� �����ϰ�, �� ����� �ٽ� ������ ���Ͽ� cpy�� �Ҵ�
	cpy.ShowPosition(); // cpy�� ��ǥ ���: [6, 12]

	return 0;
}

/*
���� �Լ��� �̿��� ������ �����ε�:

���� �Լ��� ������ * �� �����ε��Ͽ�, ������ Point ��ü�� ������ �����մϴ�.
���� �Լ������� Point Ŭ������ ��� �Լ��� ȣ���Ͽ� ���� ����� ��ȯ�մϴ�.

������ �켱������ ���� ����:

���� �����ڴ� ���ʿ��� ���������� ���˴ϴ�. ���� 2 * pos * 3�� ((2 * pos) * 3)�� ���˴ϴ�.
���� ���� �Լ��� ���� 2�� pos�� ���� ����� ����ϰ�, �� ����� �ٽ� 3�� ���Ͽ� ���������� ���ο� Point ��ü�� �����˴ϴ�.
*/