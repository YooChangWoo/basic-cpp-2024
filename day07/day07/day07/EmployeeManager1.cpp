#include <iostream>
#include <cstring> // strcpy �Լ��� ����ϱ� ���� include

using namespace std;

// ���� ������ ǥ���ϴ� PermanentWorker Ŭ���� ����
class PermanentWorker
{
private:
    char name[100]; // ���� �̸��� �����ϴ� ���ڿ� �迭
    int salary;     // ���� ������ �����ϴ� ���� ����

public:
    // ������: ���� �̸��� ������ �޾� �ʱ�ȭ
    PermanentWorker(const char* name, int money)
        : salary(money)
    {
        strcpy(this->name, name); // �̸��� �����Ͽ� ��� ������ ����
    }

    // ������ ������ ��ȯ�ϴ� �Լ�
    int GetPay() const
    {
        return salary;
    }

    // ������ �̸��� ���� ������ ����ϴ� �Լ�
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// ���� ������ �����ϴ� EmployeeHandler Ŭ���� ����
class EmployeeHandler
{
private:
    PermanentWorker* empList[50]; // PermanentWorker ��ü ����Ʈ �����ϴ� �迭
    int empNum;                    // ��ϵ� ���� ���� �����ϴ� ����

public:
    // ������: ���� �� �ʱ�ȭ
    EmployeeHandler() : empNum(0)
    { }

    // ������ �迭�� ����ϴ� �Լ�
    void AddEmployee(PermanentWorker* emp)  // ������ ��ü�� ����Ʈ�� �޾Ƽ� empList �迭�� ����ִ´�.
    {
        empList[empNum++] = emp;
    }

    // ��ϵ� ��� ������ ������ ����ϴ� �Լ�
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();   // empList �迭�� ��Ұ�(��ü�ּ�)�� ���ؼ� ����Լ��� ����
    }

    // ��ϵ� ��� ������ ���� ������ ����ϴ� �Լ�
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // �Ҹ���: ��ϵ� ���� ��ü �޸� ����
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // ���� ������ �������� ����� ��Ʈ�� Ŭ������ ��ü ����
    EmployeeHandler handler;

    // ���� ���
    handler.AddEmployee(new PermanentWorker("Son", 1000));
    handler.AddEmployee(new PermanentWorker("Hwang", 1500));
    handler.AddEmployee(new PermanentWorker("Kim", 2000));

    // �̹� �޿� �����ؾ� �� �޿��� ���� ���
    handler.ShowAllSalaryInfo();

    // �̹� �޿� �����ؾ� �� �޿��� ���� ���
    handler.ShowTotalSalary();

    return 0; // ���α׷� ����
}