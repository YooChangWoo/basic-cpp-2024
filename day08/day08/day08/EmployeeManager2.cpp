#include <iostream>
#include <cstring>
using namespace std;

// ���� Ŭ���� ����
class Employee
{
private:
    char name[100]; // ������ �̸��� �����ϴ� ���ڿ� �迭
public:
    // ������ �̸��� �޾� �ʱ�ȭ�ϴ� ������
    Employee(const char* name) 
    {
        strcpy(this->name, name);
    }
    // ������ �̸��� ����ϴ� �޼���
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

// ������ ���� Ŭ����, ���� Ŭ������ �����
class PermanentWorker : public Employee
{
private:
    int salary; // ������ ������ �޿�
public:
    // ������ �̸��� �޿��� �޾� �ʱ�ȭ�ϴ� ������
    PermanentWorker(const char* name, int money) // ����: char* -> const char* (������ �� �������)
        : Employee(name), salary(money)
    {  }
    // ������ �޿��� ��ȯ�ϴ� �޼���
    int GetPay() const
    {
        return salary;
    }
    // ������ �̸��� �޿� ������ ����ϴ� �޼���
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// ������ �����ϴ� �ڵ鷯 Ŭ����
class EmployeeHandler
{
private:
    Employee* empList[50]; // ���� ��ü�� ������ �迭
    int empNum; // ��ϵ� ���� ��
public:
    // ������: ���� �� �ʱ�ȭ
    EmployeeHandler() : empNum(0)
    { }
    // ������ �߰��ϴ� �޼���
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    // ��� ������ �޿� ������ ����ϴ� �޼���
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // ��� ������ �޿� ������ ����ϴ� �޼���
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += dynamic_cast<PermanentWorker*>(empList[i])->GetPay(); // ����: dynamic_cast �߰�
        cout << "salary sum: " << sum << endl;
    }
    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

// main �Լ�
int main(void)
{
    // ������ �����ϴ� �ڵ鷯 ��ü ����
    EmployeeHandler handler;

    // ���� ���
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // �̹� �޿� �����ؾ� �� �޿��� ���� ���
    handler.ShowAllSalaryInfo();

    // �̹� �޿� �����ؾ� �� �޿��� ���� ���
    handler.ShowTotalSalary();

    return 0;
}

/*
�ֿ� ����Ʈ:

��Ӱ� ������ �ʱ�ȭ ����Ʈ:

PermanentWorker Ŭ������ Employee Ŭ������ ��ӹ޽��ϴ�.
���� �����鼭 Employee Ŭ������ �����ڸ� ȣ���Ͽ� �ʱ�ȭ�մϴ�.

���� ��ϰ� �޸� ����:

EmployeeHandler Ŭ������ �ִ� 50���� ������ ������ �� �ִ� �迭�� �����ϴ�.
AddEmployee() �޼��带 ���� ������ ����ϰ�,
�������� �Ҵ�� �޸𸮸� EmployeeHandler�� �Ҹ��ڿ��� �����մϴ�.

�޿� ���� ���:

ShowAllSalaryInfo() �޼���� ��ϵ� ��� ������ �޿� ������ ����մϴ�.
ShowTotalSalary() �޼���� ��� ������ �޿� ������ ����մϴ�.
�� �ڵ�� ��ü ���� ���α׷����� �⺻ ������ Ȱ���Ͽ� ���� ���� �ý����� ������ �����Դϴ�.
Ŭ������ ��ü�� ȿ�������� Ȱ���Ͽ� �ڵ带 ���ȭ�ϰ�, �޸� ������ �ùٸ��� �����ϴ� ���� �ֿ� ��ǥ�Դϴ�.
*/