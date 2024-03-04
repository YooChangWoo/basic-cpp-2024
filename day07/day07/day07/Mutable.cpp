class SoSimple
{
private:
    int num1;
    mutable int num2; // const ��� �Լ� �������� ������ �� �ִ� mutable ������ ����
public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    { }
    void ShowSimpleData() const
    {
        cout << num1 << "," << num2 << endl; // num1�� num2 ���
    }
    void CopyToNum2() const
    {
        num2 = num1; // const �Լ� �������� mutable ������ num2�� ������ �� ����(���� ������ ����Ѵ�)
    }
};

int main(void)
{
    SoSimple sm(1, 2);
    sm.ShowSimpleData(); // num1�� num2 ���
    sm.CopyToNum2(); // num1�� num2�� ����
    sm.ShowSimpleData(); // ����� num2 ���
    return 0;
}

/*
mutable int num2;: num2�� mutable�� �����Ͽ�,
const ��� �Լ� �������� ������ �� �ֵ��� ����մϴ�.
ShowSimpleData() �Լ����� num�� ����ϴ� �κ��� num1�� �����մϴ�.
CopyToNum2() �Լ� ������ num2�� num1�� ������ �����մϴ�.
�̷��� �������� ���� �ڵ�� num1�� num2�� ���� ����ϰ�,
CopyToNum2() �Լ��� ���� num2�� num1�� ������ ������ �� �ְ� �˴ϴ�.
*/