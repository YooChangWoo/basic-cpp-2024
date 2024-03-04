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
        cout << "SalesWorker" << endl;      // �������̵��� ��� �Լ��� �ڽ� ���� ����ȴ�
        return PermanentWorker::GetPay()   // ���� �����ǵ� �θ���� ȣ���Ϸ��� PermanentWorker(�θ�)�� GetPay �Լ� ȣ��
            + (int)(salesResult * bonusRatio);
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;      // SalesWorker�� GetPay �Լ��� ȣ���
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];         // ��ü ������ �迭
    int empNum;

public:
    EmployeeHandler() : empNum(0)         // empList() - nullptr �ʱ�ȭ == empList{}
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
    // ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
    EmployeeHandler handler;

    // ������ ���
    handler.AddEmployee(new PermanentWorker("SON", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // �ӽ��� ���
    TemporaryWorker* alba = new TemporaryWorker("KIM", 700);
    alba->AddworkTime(5);         // 5�ð� ���Ѱ�� ���
    handler.AddEmployee(alba);

    // ������ ���
    SalesWorker* seller = new SalesWorker("Hwang", 1000, 0.1);
    seller->AddSalesResult(7000);         // �������� 7000
    handler.AddEmployee(seller);

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowAllsalaryInfo();

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowTotalSalary();

    SalesWorker s("Hong", 1000, 0.1);
    cout << s.GetPay() << endl;
    s.ShowSalaryInfo();
    return 0;
}

/*
��� �� ������ Ȱ��:

Employee, PermanentWorker, TemporaryWorker, SalesWorker Ŭ������ ����� ���� ���� ������ �����մϴ�.
Employee Ŭ������ ������� ���� Ŭ�������� ������ Ư���� �����մϴ�.
�������� �̿��Ͽ� Employee �����ͷ� �پ��� ������ ������ �ٷ� �� �ֽ��ϴ�.

���� �Լ� �� ���� ���� �Լ�:

Employee Ŭ�������� ���� ���� �Լ�(GetPay(), ShowSalaryInfo())�� �ֽ��ϴ�.
���� ���� �Լ��� ���� Ŭ�������� �ݵ�� �����ǵǾ�� �մϴ�.
�̸� ���� ���� Ŭ������ �ൿ�� ���������� �����ǰ�,
Employee �����͸� ���� ���� ��ü�� Ÿ�Կ� ���� ������ ������ ����˴ϴ�.

���� �޸� �Ҵ� �� ����:

EmployeeHandler Ŭ������ ������ �迭�� ����Ͽ� ���� ��ü�� �������� �Ҵ��ϰ� �����մϴ�.
��ü�� �����ֱⰡ ���� Ŭ����(EmployeeHandler)���� ��� ������,
�Ҹ��ڸ� ���� �޸� ������ �����ϱ� ���� �������� �Ҵ�� �޸𸮸� �����մϴ�.

��ü���� ���� ��Ģ:

�ڵ�� ��ü�������� ���� ��Ģ�� ���� �� Ŭ������ �ϳ��� ������ ������ �ۼ��Ǿ����ϴ�.
�̷��� ����� �ڵ��� ���뼺�� ���̰�, ���� ������ �����ϰ� �մϴ�.

Ŭ������ å�� �и�:

�� Ŭ������ �� ���� �ֿ� å�ӿ� �����մϴ�.
���� ���, Employee Ŭ������ ������ �⺻ ������ �ٷ��,
PermanentWorker, TemporaryWorker, SalesWorker�� ������ �޿� ��� ����� �ٷ�ϴ�.
�̷��� ����Ʈ���� �ڵ��� �������� Ȯ�强�� ���̸�, ��ü�������� ��Ģ�� ���� �ڵ带 �����մϴ�.
*/