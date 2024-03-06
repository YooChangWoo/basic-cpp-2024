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
};

int main(void)
{
	Point pos(1, 2); // �ʱ� ��ǥ (1, 2)�� ���� Point ��ü ����
	Point cpy; // ������ Point ��ü ����

	cpy = pos * 3; // pos�� ��ǥ�� 3�� ���Ͽ� cpy�� �Ҵ�
	cpy.ShowPosition(); // cpy�� ��ǥ ���: [3, 6]

	cpy = pos * 3 * 2; // pos�� ��ǥ�� 3�� ���ϰ� �� ����� 2�� ���Ͽ� cpy�� �Ҵ�
	cpy.ShowPosition(); // cpy�� ��ǥ ���: [6, 12]

	return 0;
}

/*
������ �����ε�:

Point Ŭ�������� * �����ڸ� �����ε��Ͽ� ������ �޾Ƽ�
���� ��ǥ�� ���� ���� ������ ���ο� Point ��ü�� ��ȯ�մϴ�.

������ �켱����:

���� �����ڴ� ���ʿ��� ���������� ���˴ϴ�.
���� pos * 3 * 2�� ((pos * 3) * 2)�� ���˴ϴ�.
���� pos * 3�� ����Ͽ� ���ο� Point ��ü�� �����ϰ�,
�� ����� 2�� ���Ͽ� ���������� ���ο� Point ��ü�� �����˴ϴ�.

*/