#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Human {
    char name[30]; // �̸��� �����ϴ� ���ڿ� �迭
    int age; // ���̸� �����ϴ� ���� ����

public:
    Human(char* pname, int age) // ������: �̸��� ���̸� �޾� ��ü�� �ʱ�ȭ
    {
        cout << "������ ȣ��: " << endl; // ������ ȣ���� ���
        strcpy(name, pname); // �̸� ����
        this->age = age; // ���� ����  // ���޹��� �ŰԺ��� ����
    }
    void HumanInfo() // ��ü ���� ���
    {
        cout << "�̸�: " << name << " "; // �̸� ���
        cout << "����: " << age << endl; // ���� ���
    }
    ~Human() // �Ҹ���: ��ü�� �Ҹ�� �� ȣ��Ǹ�, �޸� ���� ���� ���� �۾��� ����
    {
        cout << "�Ҹ��� ȣ��" << endl; // �Ҹ��� ȣ���� ���
    }
};

int main()
{
    // Human Ŭ������ ��ü �迭 ���� �� �ʱ�ȭ
    Human h[3] = { Human("ȫ�浿", 50), Human("������", 60), Human("���Ժ�", 60) };

    // ��ü �迭�� ��ȸ�ϸ鼭 ��ü ���� ���
    for (int i = 0; i < 3; i++) {
        h[i].HumanInfo();
    }

    Human* h1 = new Human("ȫ�浿", 50);  // �� ������ ��ü ����, ������ ���� h1���� �ּҰ� ���޹���
    h1->HumanInfo();               // h1�� ������ ��ü �̹Ƿ� ���� ���� -> �� ���� �����Ϳ� ���� 
    // ��ü�����Ͱ� ����Ű�� ����� ����
    Human h1("������", 60);
    h2.HumanInfo();                     // �Ϲ� ��ü �̹Ƿ� ���� ���� . �� ���� �����Ϳ� ����, �����Ͱ� �ƴ� �������� ��ü�� ����
    return 0;