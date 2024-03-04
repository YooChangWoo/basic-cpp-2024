#include <iostream>
#include <cstring> // strcpy 함수를 사용하기 위해 include

using namespace std;

// 직원 정보를 표현하는 PermanentWorker 클래스 정의
class PermanentWorker
{
private:
    char name[100]; // 직원 이름을 저장하는 문자열 배열
    int salary;     // 직원 월급을 저장하는 정수 변수

public:
    // 생성자: 직원 이름과 월급을 받아 초기화
    PermanentWorker(const char* name, int money)
        : salary(money)
    {
        strcpy(this->name, name); // 이름을 복사하여 멤버 변수에 저장
    }

    // 직원의 월급을 반환하는 함수
    int GetPay() const
    {
        return salary;
    }

    // 직원의 이름과 월급 정보를 출력하는 함수
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 직원 정보를 관리하는 EmployeeHandler 클래스 정의
class EmployeeHandler
{
private:
    PermanentWorker* empList[50]; // PermanentWorker 객체 포인트 저장하는 배열
    int empNum;                    // 등록된 직원 수를 저장하는 변수

public:
    // 생성자: 직원 수 초기화
    EmployeeHandler() : empNum(0)
    { }

    // 직원을 배열에 등록하는 함수
    void AddEmployee(PermanentWorker* emp)  // 정규직 객체의 포인트를 받아서 empList 배열에 집어넣는다.
    {
        empList[empNum++] = emp;
    }

    // 등록된 모든 직원의 정보를 출력하는 함수
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();   // empList 배열의 요소값(객체주소)을 통해서 멤버함수에 접근
    }

    // 등록된 모든 직원의 월급 총합을 출력하는 함수
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // 소멸자: 등록된 직원 객체 메모리 해제
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("Son", 1000));
    handler.AddEmployee(new PermanentWorker("Hwang", 1500));
    handler.AddEmployee(new PermanentWorker("Kim", 2000));

    // 이번 달에 지불해야 할 급여의 정보 출력
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합 출력
    handler.ShowTotalSalary();

    return 0; // 프로그램 종료
}