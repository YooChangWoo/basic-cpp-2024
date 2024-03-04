class SoSimple
{
private:
    int num1;
    mutable int num2; // const 멤버 함수 내에서도 변경할 수 있는 mutable 변수로 선언
public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    { }
    void ShowSimpleData() const
    {
        cout << num1 << "," << num2 << endl; // num1과 num2 출력
    }
    void CopyToNum2() const
    {
        num2 = num1; // const 함수 내에서도 mutable 변수인 num2를 변경할 수 있음(값의 변경을 허락한다)
    }
};

int main(void)
{
    SoSimple sm(1, 2);
    sm.ShowSimpleData(); // num1과 num2 출력
    sm.CopyToNum2(); // num1을 num2로 복사
    sm.ShowSimpleData(); // 변경된 num2 출력
    return 0;
}

/*
mutable int num2;: num2를 mutable로 선언하여,
const 멤버 함수 내에서도 수정할 수 있도록 허용합니다.
ShowSimpleData() 함수에서 num을 출력하는 부분을 num1로 수정합니다.
CopyToNum2() 함수 내에서 num2를 num1의 값으로 복사합니다.
이러한 수정으로 인해 코드는 num1과 num2의 값을 출력하고,
CopyToNum2() 함수를 통해 num2를 num1의 값으로 변경할 수 있게 됩니다.
*/