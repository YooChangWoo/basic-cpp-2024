template <typename T>
class Point
{
private:
	T xpos, ypos; // T 타입의 xpos와 ypos 멤버 변수

public:
	// 생성자: T 타입의 x와 y 값을 받아 xpos와 ypos를 초기화함.
	// 디폴트 인자를 사용하여, 인자가 전달되지 않을 경우 0으로 초기화함.
	Point(T x = 0, T y = 0);

	// 멤버 함수: xpos와 ypos를 출력한다.
	void ShowPosition() const;
};


template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{
	// 초기화 리스트를 사용하여 xpos와 ypos를 초기화함.
}

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}



int main(void)
{
	Point<int> pos1(3, 4); // int 타입 좌표로 Point 객체 생성
	pos1.ShowPosition(); // 객체의 좌표 출력

	Point<double> pos2(2.4, 3.6); // double 타입 좌표로 Point 객체 생성
	pos2.ShowPosition(); // 객체의 좌표 출력

	Point<char> pos3('P', 'F'); // char 타입 좌표로 Point 객체 생성
	pos3.ShowPosition(); // 객체의 좌표 출력
	return 0;
}

/*
1. template <typename T>: 클래스 정의 이전에 선언되어, Point 클래스가 템플릿 클래스임을 나타냄. 
	-> 이로써 Point 클래스는 다양한 타입을 다룰 수 있음.

2. private 섹션에서는 xpos와 ypos라는 이름의 두 멤버 변수를 선언함. 
	-> 이 변수들의 타입은 템플릿 매개변수 T로, Point 객체 생성 시 결정됨.

3. public 섹션에서는 생성자와 ShowPosition이라는 멤버 함수를 선언함. 
	-> 생성자는 객체가 생성될 때 xpos와 ypos를 초기화하고, ShowPosition 함수는 객체의 좌표를 표시함.

4. 생성자와 ShowPosition 멤버 함수는 클래스 외부에서 구현되며, 
	-> 각각 객체의 좌표를 초기화하고 출력함.

5. main 함수에서는 int, double, char 타입의 좌표를 가지는 Point 객체를 생성하고 각각의 좌표를 출력함. 
	-> 이를 통해, 클래스 템플릿이 어떻게 다양한 타입에 대해 유연하게 사용될 수 있는지를 보여줌
*/