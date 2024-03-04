#include <iostream>
using namespace std;

// Person Ŭ���� ����
class Person
{
public:
    void Sleep() { cout << "sleep" << endl; }
};

// Student Ŭ���� ����, Person Ŭ������ �����
class Student : public Person
{
public:
    void Study() { cout << "Study" << endl; }
};

// PartTimeStudent Ŭ���� ����, Student Ŭ������ �����
class PartTimeStudent : public Student
{
public:
    void Work() { cout << "Work" << endl; }
};

// main �Լ�
int main(void)
{
    //Student * ptr0 = new Student();    // ������ Ÿ������ ����ϴ� ���� ��Ģ�̴�.
    /*
     �θ�Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����ų �� �ִ�.
     ������ �ڽ�Ÿ���� ��ü �����ͷ� �θ� ��ü�� ����ų �� ����.
     �׸��� ������ ��ü �������� Ÿ���� ������.
    */
    // Person Ÿ���� �����ͷ� Student ��ü�� ����Ű�� ����
    Person* prt1 = new Student();

    // Person Ÿ���� �����ͷ� PartTimeStudent ��ü�� ����Ű�� ����
    Person* ptr2 = new PartTimeStudent();

    // Student Ÿ���� �����ͷ� PartTimeStudent ��ü�� ����Ű�� ����
    Student* ptr3 = new PartTimeStudent();

    // ������ �����͸� ���� �޼��� ȣ��
    prt1->Sleep(); // Person Ÿ���� �������̹Ƿ� Person Ŭ������ Sleep �޼��� ȣ��
    ptr2->Sleep(); // Person Ÿ���� �������̹Ƿ� Person Ŭ������ Sleep �޼��� ȣ��
    ptr3->Study(); // Student Ÿ���� �������̹Ƿ� Student Ŭ������ Study �޼��� ȣ��

    // ���� �Ҵ�� �޸𸮸� ����
    delete prt1;
    delete ptr2;
    delete ptr3;

    return 0;
}
/*
Ŭ������ ��� ���� : Person Ŭ������ Student Ŭ������ �θ��̰�,
Student Ŭ������ PartTimeStudent Ŭ������ �θ��Դϴ�.
�̷��� ��� ���踦 ���� Ŭ���� ������ ���� ������ �����˴ϴ�.

�����Ϳ� ������ : �����͸� ���� �پ��� ��ü�� ����ų �� �ֽ��ϴ�.
���� ���, Person* prt1�� Student ��ü�� ����ų �� �ֽ��ϴ�.�̴� �������� �����Դϴ�.

���ٰ� �������� Ÿ�� : �������� Ÿ���� �ش� �����Ͱ� ����Ű�� ��ü�� Ÿ���� �ƴ϶�
������ ��ü�� Ÿ���� �����ϴ�.�̴� �޼��� ȣ�� �ÿ��� ����˴ϴ�.

�޸� ���� : �������� �Ҵ�� �޸𸮴� ������ ������ delete �����ڸ� ����Ͽ� �����Ǿ�� �մϴ�.

�̷��� ������� ��ü ���� ���α׷��ֿ��� �߿��� ��������, �ڵ带 ���� �� �����ϰ� Ȱ���� �� �־�� �մϴ�.
*/
