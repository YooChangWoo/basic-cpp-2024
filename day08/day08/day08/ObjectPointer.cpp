#include <iostream>
using namespace std;

// Person 클래스 정의
class Person
{
public:
    void Sleep() { cout << "sleep" << endl; }
};

// Student 클래스 정의, Person 클래스를 상속함
class Student : public Person
{
public:
    void Study() { cout << "Study" << endl; }
};

// PartTimeStudent 클래스 정의, Student 클래스를 상속함
class PartTimeStudent : public Student
{
public:
    void Work() { cout << "Work" << endl; }
};

// main 함수
int main(void)
{
    //Student * ptr0 = new Student();    // 동일한 타입으로 사용하는 것이 원칙이다.
    /*
     부모타입의 객체 포인터로 자식 객체를 가리킬 수 있다.
     하지만 자식타입의 객체 포인터로 부모 객체를 가리킬 수 없다.
     그리고 접근은 객체 포인터의 타입을 따른다.
    */
    // Person 타입의 포인터로 Student 객체를 가리키는 예제
    Person* prt1 = new Student();

    // Person 타입의 포인터로 PartTimeStudent 객체를 가리키는 예제
    Person* ptr2 = new PartTimeStudent();

    // Student 타입의 포인터로 PartTimeStudent 객체를 가리키는 예제
    Student* ptr3 = new PartTimeStudent();

    // 각각의 포인터를 통해 메서드 호출
    prt1->Sleep(); // Person 타입의 포인터이므로 Person 클래스의 Sleep 메서드 호출
    ptr2->Sleep(); // Person 타입의 포인터이므로 Person 클래스의 Sleep 메서드 호출
    ptr3->Study(); // Student 타입의 포인터이므로 Student 클래스의 Study 메서드 호출

    // 동적 할당된 메모리를 해제
    delete prt1;
    delete ptr2;
    delete ptr3;

    return 0;
}
/*
클래스의 상속 관계 : Person 클래스는 Student 클래스의 부모이고,
Student 클래스는 PartTimeStudent 클래스의 부모입니다.
이러한 상속 관계를 통해 클래스 간에는 계층 구조가 형성됩니다.

포인터와 다형성 : 포인터를 통해 다양한 객체를 가리킬 수 있습니다.
예를 들어, Person* prt1은 Student 객체를 가리킬 수 있습니다.이는 다형성의 개념입니다.

접근과 포인터의 타입 : 포인터의 타입은 해당 포인터가 가리키는 객체의 타입이 아니라
포인터 자체의 타입을 따릅니다.이는 메서드 호출 시에도 적용됩니다.

메모리 관리 : 동적으로 할당된 메모리는 적절한 시점에 delete 연산자를 사용하여 해제되어야 합니다.

이러한 개념들은 객체 지향 프로그래밍에서 중요한 개념으로, 코드를 통해 잘 이해하고 활용할 수 있어야 합니다.
*/
