
#include <iostream>

using namespace std;

class MyClass {
private:
   int* ptr;

public:
   MyClass(int p) : ptr(new int[100])
   {
      printf("������ ȣ��\n");
   }
   ~MyClass()
   {
      printf("�Ҹ��� ȣ��\n");
      delete[]ptr;
   }
};

int main()
{
   MyClass *m1 = new MyClass(10);
   cout <<"======================================"  << endl;

   unique_ptr<MyClass> m2(new MyClass(20));         // unique_ptr<MyClass> �� ����Ʈ ������

   return 0;
}
