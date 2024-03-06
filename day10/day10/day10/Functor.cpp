#include <iostream>
using namespace std;

// Point Ŭ���� ����
class Point
{
private:
	int xpos, ypos; // x�� y ��ǥ
public:
	// ������: x�� y ��ǥ�� �ʱ�ȭ
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }

	// �� Point ��ü�� ���ϴ� ������ �����ε�
	Point operator+(const Point& pos) const
	{
		// ���� ��ü�� x ��ǥ�� �ٸ� ��ü�� x ��ǥ�� ���ϰ�,
		// ���� ��ü�� y ��ǥ�� �ٸ� ��ü�� y ��ǥ�� ���Ͽ� ���ο� Point ��ü�� �����Ͽ� ��ȯ
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	// ostream ������ �����ε�: Point ��ü�� ���
	friend ostream& operator<<(ostream& os, const Point& pos);
};

// ostream ������ �����ε� ����
ostream& operator<<(ostream& os, const Point& pos)
{
	// Point ��ü�� ��ǥ�� [x, y] ���·� ���
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// Adder Ŭ���� ����
class Adder
{
public:
	// ������ �� ���� ���ϴ� �Լ� ȣ�� ������ �����ε�
	int operator()(const int& n1, const int& n2)
	{
		// �� ������ ���Ͽ� ��� ��ȯ
		return n1 + n2;
	}

	// �Ǽ��� �� ���� ���ϴ� �Լ� ȣ�� ������ �����ε�
	double operator()(const double& e1, const double& e2)
	{
		// �� �Ǽ��� ���Ͽ� ��� ��ȯ
		return e1 + e2;
	}

	// Point ��ü �� ���� ���ϴ� �Լ� ȣ�� ������ �����ε�
	Point operator()(const Point& pos1, const Point& pos2)
	{
		// Point Ŭ�������� ������ operator+�� ����Ͽ� �� Point ��ü�� ����
		return pos1 + pos2;
	}
};

int main(void)
{
	// Adder ��ü ����
	Adder adder;

	// ������ ���� ���� ��� ���
	cout << adder(1, 3) << endl;

	// �Ǽ��� ���� ���� ��� ���
	cout << adder(1.5, 3.7) << endl;

	// Point ��ü�� ���� ��� ���
	cout << adder(Point(3, 4), Point(7, 9));

	return 0;
}
/*
������ �����ε� (Operator Overloading):

Ŭ���� ������ �����ڸ� ���ο� �ǹ̷� �������ϴ� ����̸�,
�ڵ��� �������� ���̰� ����� ���� Ÿ�Կ� ���� ǥ�� ���� ������ �����ϰ� �մϴ�.
Point Ŭ�������� operator+�� �����ε��Ͽ� �� ���� ���� �� �ֵ��� �Ͽ����ϴ�.
Adder Ŭ���������� �Լ� ȣ�� ������ ()�� ���� ���·� �����ε��Ͽ� ����, �Ǽ�, �׸��� Point ��ü�� ���� ������ �����մϴ�.

�Լ� ��ü (Function Object):

Adder Ŭ������ �Լ�ó�� �����ϴ� ��ü�Դϴ�.
Adder Ŭ������ ��ü�� �Լ�ó�� ȣ���� �� ������,
�̸� ���� �پ��� Ÿ���� �����Ϳ� ���� ������ ������ �� �ֽ��ϴ�.

��Ʈ�� ��� �������� �����ε� (Overloading Stream Output Operator):

ostream& operator<<�� ����Ͽ� ����� ���� Ÿ���� Point ��ü�� ����� �� �ֽ��ϴ�.
�̸� ���� ����ڴ� cout�� ����Ͽ� Point ��ü�� ���� ����� �� �ֽ��ϴ�.
*/