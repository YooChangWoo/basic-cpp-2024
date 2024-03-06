#include <iostream>
using namespace std;

class Point {
private:
	int x;

public:

};

int main()
{
	Point a(10, 20);
	Point b(20, 30);
	Point c = a + b; 
	Point d = a + 100;
	Point e = 100 + a;

	d.viewPoint();
	e.viewPoint();

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
		
}