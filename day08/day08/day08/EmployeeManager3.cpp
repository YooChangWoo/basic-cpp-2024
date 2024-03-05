// date : 2024-03-04
// file : test03_EmplMana2.cpp
// desc : p.336

#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    char name[100];

public:
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }

    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary;

public:
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }

    void  AddworkTime(int Time)
    {
        workTime += Time;
    }

    int GetPay() const
    {
        return workTime * payPerHour;
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(const char* name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }

    void AddSalesResult(int value)
    {
        salesResult += value;
    }

    int GetPay() const
    {
        cout << "SalesWorker" << endl;      // 오버라이딩된 멤버 함수는 자식 것이 실행된다
        return PermanentWorker::GetPay()   // 따라서 재정의된 부모것을 호출하려면 PermanentWorker(부모)의 GetPay 함수 호출
            + (int)(salesResult * bonusRatio);
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;      // SalesWorker의 GetPay 함수가 호출됨
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];         // 객체 포인터 배열
    int empNum;

public:
    EmployeeHandler() : empNum(0)         // empList() - nullptr 초기화 == empList{}
    { }

    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllsalaryInfo() const
    {

        /*
        for (int i=0; i < empNum; i++)
           empList[i] -> ShowSalaryInfo();
        */
    }

    void ShowTotalSalary() const
    {
        int sum = 0;

        /*
        for (int i = 0; i < empNum; i++)
           sum += empList[i]->GetPay();
        */

        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("SON", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker* alba = new TemporaryWorker("KIM", 700);
    alba->AddworkTime(5);         // 5시간 일한결과 등록
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker* seller = new SalesWorker("Hwang", 1000, 0.1);
    seller->AddSalesResult(7000);         // 영업실적 7000
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllsalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();

    SalesWorker s("Hong", 1000, 0.1);
    cout << s.GetPay() << endl;
    s.ShowSalaryInfo();
    return 0;
}

/*
상속 및 다형성 활용:

Employee, PermanentWorker, TemporaryWorker, SalesWorker 클래스는 상속을 통해 계층 구조를 형성합니다.
Employee 클래스를 기반으로 하위 클래스에서 각자의 특성을 구현합니다.
다형성을 이용하여 Employee 포인터로 다양한 종류의 직원을 다룰 수 있습니다.

가상 함수 및 순수 가상 함수:

Employee 클래스에는 순수 가상 함수(GetPay(), ShowSalaryInfo())가 있습니다.
순수 가상 함수는 하위 클래스에서 반드시 재정의되어야 합니다.
이를 통해 직원 클래스의 행동이 다형적으로 구현되고,
Employee 포인터를 통해 실제 객체의 타입에 따라 적절한 동작이 수행됩니다.

동적 메모리 할당 및 해제:

EmployeeHandler 클래스는 포인터 배열을 사용하여 직원 객체를 동적으로 할당하고 관리합니다.
객체의 생명주기가 관리 클래스(EmployeeHandler)보다 길기 때문에,
소멸자를 통해 메모리 누수를 방지하기 위해 동적으로 할당된 메모리를 해제합니다.

객체지향 설계 원칙:

코드는 객체지향적인 설계 원칙에 따라 각 클래스가 하나의 목적을 갖도록 작성되었습니다.
이러한 설계는 코드의 재사용성을 높이고, 유지 보수를 용이하게 합니다.

클래스의 책임 분리:

각 클래스는 한 가지 주요 책임에 집중합니다.
예를 들어, Employee 클래스는 직원의 기본 정보를 다루고,
PermanentWorker, TemporaryWorker, SalesWorker는 각각의 급여 계산 방식을 다룹니다.
이러한 포인트들은 코드의 유연성과 확장성을 높이며, 객체지향적인 원칙을 따라 코드를 구성합니다.
*/