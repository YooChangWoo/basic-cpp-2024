#include <iostream>

void func()
{
	//...
}

int main()
{
	func();
	return 0;

}

const int num = 10000;

ClassName objName;
ClassName* p = new ClassName; // => new �����ڴ� �� ������ �޸𸮿� �Ҵ� -> �� �ּҸ� ������

/*
ClassName* p = new ClassName; �̺κ� ����
��
1. new �����ڴ� �޸𸮸� �������� �Ҵ��ϰ�, �ش� �޸��� �ּҸ� ����Ű�� �����͸� ��ȯ.
=> ClassName*�� ClassName Ŭ������ �����͸� ����Ű�� ������ ������ �����ϴ� ���.

2. ���� ClassName* p�� ClassName Ŭ������ �����͸� ����Ű�� ������ ������ ������ ��.

3. new ClassName�� ClassName Ŭ������ ��ü�� �������� �Ҵ��ϴ� ����.
=> ���ο� ClassName ��ü�� �� �޸𸮿� �����ǰ�, �� ��ü�� �ּҸ� ��ȯ.

4. p = new ClassName�� ���ο� ClassName ��ü�� �����ϰ�, �� ��ü�� �ּҸ� ������ ���� p�� �Ҵ��ϴ� ��.

5. ���������, p�� ������ �޸𸮿� �������� ������ ClassName ��ü�� ����Ű�� �����Ͱ� ��.
=> �̷��� ������ ��ü�� ���α׷��� �ʿ��� ������ �޸𸮿� ���� �ְ� ��.
=> ��ü�� �� �̻� ������� ���� ���� delete p;�� ����Ͽ� �޸𸮸� ����
*/

ClassName objName;
int* p = new ClassName; // new ������ => ������ �޸� �Ҵ� -> �� �ּҸ� ���� ��

char a = 'a';
int* p = &a;