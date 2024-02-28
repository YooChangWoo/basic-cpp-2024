#include <iostream>
#include <cstring>
using namespace std;

class Girl; // Girl�̶�� �̸��� Ŭ������ �̸����� �˸��� ����

class Boy
{
private:
    int height; // ������ Ű�� �����ϴ� private ��� ����
    friend class Girl; // Girl Ŭ������ friend�� �����Ͽ� Girl Ŭ������ ��� �Լ��� Boy Ŭ������ private ����� ������ �� �ֵ��� ��

public:
    // ������: Ű�� �Է¹޾� �ʱ�ȭ��
    Boy(int len) : height(len) {}

    // ShowYourFriendInfo �Լ�: Girl ��ü�� �޾ƿͼ� ���� ��ȭ��ȣ�� �����
    void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
    char phNum[20]; // ������ ��ȭ��ȣ�� �����ϴ� private ��� ����

public:
    // ������: ��ȭ��ȣ�� �Է¹޾� �ʱ�ȭ��
    Girl(const char* num)
    {
        strcpy_s(phNum, num);
    }

    // ShowYourFriendInfo �Լ�: Boy ��ü�� �޾ƿͼ� ���� Ű�� �����
    void ShowYourFriendInfo(Boy& frn);

    // Boy Ŭ������ friend�� �����Ͽ� Boy Ŭ������ ��� �Լ��� Girl Ŭ������ private ����� ������ �� �ֵ��� ��
    friend class Boy;
};

// Boy Ŭ������ ShowYourFriendInfo �Լ� ����
void Boy::ShowYourFriendInfo(Girl& frn)
{
    // Girl Ŭ������ private ����� ��ȭ��ȣ�� ���
    cout << "Her phone Number : " << frn.phNum << endl;
}

// Girl Ŭ������ ShowYourFriendInfo �Լ� ����
void Girl::ShowYourFriendInfo(Boy& frn)
{
    // Boy Ŭ������ private ����� Ű�� ���
    cout << "His height : " << frn.height << endl;
}

// ���� �Լ�
int main(void)
{
    // Boy ��ü ���� �� �ʱ�ȭ
    Boy boy(170);

    // Girl ��ü ���� �� �ʱ�ȭ
    Girl gir("010-1234-5678");

    // Boy ��ü�� ShowYourFriendInfo �Լ� ȣ���Ͽ� Girl ��ü�� ��ȭ��ȣ ���
    boy.ShowYourFriendInfo(gir);

    // Girl ��ü�� ShowYourFriendInfo �Լ� ȣ���Ͽ� Boy ��ü�� Ű ���
    gir.ShowYourFriendInfo(boy);

    return 0;
}

/*
Boy Ŭ����:

Boy Ŭ������ �ϳ��� private ��� ���� height�� ������ �ֽ��ϴ�.
height ������ ���� ������ ����ϱ� ���� Girl Ŭ������ friend�� �����մϴ�.
ShowYourFriendInfo() �Լ��� Girl ��ü�� ��ȭ��ȣ�� ����մϴ�.

Girl Ŭ����:

Girl Ŭ������ �ϳ��� private ��� ���� phNum�� ������ �ֽ��ϴ�.
phNum ������ ���� ������ ����ϱ� ���� Boy Ŭ������ friend�� �����մϴ�.
ShowYourFriendInfo() �Լ��� Boy ��ü�� Ű�� ����մϴ�.

main �Լ�:

main �Լ������� Boy Ŭ������ Girl Ŭ������ ��ü�� �����մϴ�.
�� ��ü ���� ������ ���� ����� �� �ֵ��� friend�� ����� ��� �Լ��� ȣ���մϴ�.
���α׷��� �����ϸ�, �� Ŭ������ ��ü ���� ������ �ְ�޴� ���� Ȯ���� �� �ֽ��ϴ�. �̴� friend ������ ���� �� Ŭ���� ���� ��� ���� �� �Լ��� ������ �� �ְ� �˴ϴ�.
*/