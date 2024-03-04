#include <iostream>
#include <cstring>
using namespace std;

// 직원 클래스 정의
class Employee
{
private:
    char name[100]; // 직원의 이름을 저장하는 문자열 배열
public:
    // 직원의 이름을 받아 초기화하는 생성자
    Employee(const char* name) 
    {
        strcpy(this->name, name);
    }
    // 직원의 이름을 출력하는 메서드
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

// 정규직 직원 클래스, 직원 클래스를 상속함
class PermanentWorker : public Employee
{
private:
    int salary; // 정규직 직원의 급여
public:
    // 직원의 이름과 급여를 받아 초기화하는 생성자
    PermanentWorker(const char* name, int money) // 수정: char* -> const char* (안정성 및 권장사항)
        : Employee(name), salary(money)
    {  }
    // 직원의 급여를 반환하는 메서드
    int GetPay() const
    {
        return salary;
    }
    // 직원의 이름과 급여 정보를 출력하는 메서드
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 직원을 관리하는 핸들러 클래스
class EmployeeHandler
{
private:
    Employee* empList[50]; // 직원 객체의 포인터 배열
    int empNum; // 등록된 직원 수
public:
    // 생성자: 직원 수 초기화
    EmployeeHandler() : empNum(0)
    { }
    // 직원을 추가하는 메서드
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    // 모든 직원의 급여 정보를 출력하는 메서드
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // 모든 직원의 급여 총합을 출력하는 메서드
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += dynamic_cast<PermanentWorker*>(empList[i])->GetPay(); // 수정: dynamic_cast 추가
        cout << "salary sum: " << sum << endl;
    }
    // 소멸자: 동적으로 할당된 메모리 해제
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

// main 함수
int main(void)
{
    // 직원을 관리하는 핸들러 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보 출력
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합 출력
    handler.ShowTotalSalary();

    return 0;
}

/*
주요 포인트:

상속과 생성자 초기화 리스트:

PermanentWorker 클래스는 Employee 클래스를 상속받습니다.
속을 받으면서 Employee 클래스의 생성자를 호출하여 초기화합니다.

직원 등록과 메모리 관리:

EmployeeHandler 클래스는 최대 50명의 직원을 관리할 수 있는 배열을 가집니다.
AddEmployee() 메서드를 통해 직원을 등록하고,
동적으로 할당된 메모리를 EmployeeHandler의 소멸자에서 해제합니다.

급여 정보 출력:

ShowAllSalaryInfo() 메서드는 등록된 모든 직원의 급여 정보를 출력합니다.
ShowTotalSalary() 메서드는 모든 직원의 급여 총합을 출력합니다.
이 코드는 객체 지향 프로그래밍의 기본 개념을 활용하여 직원 관리 시스템을 구현한 예제입니다.
클래스와 객체를 효과적으로 활용하여 코드를 모듈화하고, 메모리 관리를 올바르게 수행하는 것이 주요 목표입니다.
*/