#include <iostream>
using namespace std;

class Base {
public:
    Base() {} // 기본 생성자
    virtual ~Base() {} // 가상 소멸자: 파생 클래스의 객체가 파괴될 때 해당 파생 클래스의 소멸자를 호출하기 위해 가상 소멸자로 선언
    virtual void func1() { cout << "Base::func1()" << endl; } // 가상 함수 func1(): 파생 클래스에서 재정의 가능한 함수
    virtual void func2() { cout << "Base::func2()" << endl; } // 가상 함수 func2(): 파생 클래스에서 재정의 가능한 함수
    virtual void func3() { cout << "Base::func3()" << endl; } // 가상 함수 func3(): 파생 클래스에서 재정의 가능한 함수
};

class Derived : public Base {
public:
    void func1() override { cout << "Derived::func1()" << endl; } // func1()을 오버라이딩하여 새로운 구현 제공
    void func3() override { cout << "Derived::func3()" << endl; } // func3()을 오버라이딩하여 새로운 구현 제공
    void func4() { cout << "Derived::func4()" << endl; } // Derived 클래스에만 존재하는 새로운 멤버 함수

    Derived() = default; // 기본 생성자를 사용하는 경우
};

int main() {
    Base b; // Base 클래스의 객체 생성
    Derived d; // Derived 클래스의 객체 생성
    Base* pb = new Derived(); // Base 클래스의 포인터로 Derived 클래스의 객체를 가리킴

    pb->func1(); // Derived::func1() - 가상 함수 호출은 실제 객체의 형에 따라 실행됨
    pb->func2(); // Base::func2()
    pb->func3(); // Derived::func3()

    cout << endl;

    Derived* pd = &d; // Derived 클래스의 포인터로 Derived 객체를 가리킴
    pd->func1(); // Derived::func1()
    pd->func2(); // Base::func2()
    pd->func3(); // Derived::func3()
    pd->func4(); // Derived::func4() - Derived 클래스의 멤버 함수 호출

    delete pb; // 동적으로 할당된 메모리 해제

    return 0;
}

/*
가상 함수와 다형성:

Base 클래스의 멤버 함수들(func1(), func2(), func3())은 모두 가상 함수로 선언되어 있습니다.
Derived 클래스에서 func1()과 func3()을 오버라이딩하여 새로운 구현을 제공했습니다.
가상 함수는 객체의 실제 형태에 따라 호출됩니다. 따라서 pb->func1()은 Derived 클래스의 func1()이 호출됩니다.

동적 할당 및 메모리 해제:

Base* pb = new Derived();와 같이 동적으로 Derived 객체를 생성하여 Base 클래스의 포인터로 가리킬 수 있습니다.
동적으로 할당된 메모리는 delete pb;를 통해 해제되어야 합니다.

다형성의 예:

pb가 Base 클래스의 포인터이지만 실제로 Derived 객체를 가리키고 있습니다. 이것은 다형성의 한 예입니다.
가상 함수는 객체의 실제 형태를 기반으로 호출되므로 Derived 클래스에서 오버라이딩한 함수가 호출됩니다.
*/