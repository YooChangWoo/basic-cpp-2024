// 5���� �̸��� ��,��,�� 3������ �Է¹޾� �л��� ������ ��� �׸��� ���� ������ ����� ���Ͻÿ�

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Grade {
private:
    string name;
    int kr;
    int math;
    int english;

public:
    // ������: �̸��� �� ���� ���� �ʱ�ȭ
    Grade(const string& n, int k, int m, int e) : name(n), kr(k), math(m), english(e) {}

    // �л��� ���� ���
    int getTotal() const {
        return kr + math + english;
    }

    // �л��� ��� ���
    double getAverage() const {
        return static_cast<double>(getTotal()) / 3.0;
    }

    // �л��� �̸� ��ȯ
    const string& getName() const {
        return name;
    }

    // ���� ���� ��ȯ
    int getKorean() const { return kr; }
    int getMath() const { return math; }
    int getEnglish() const { return english; }
};

int main() {
    // �л� ��ü�� ��� vector ����
    vector<Grade> students(5);

    // �� ���� ���� �Է� �ޱ�
    int korean, math, english;
    cout << "����, ����, ���� ������ �Է��ϼ���: ";
    cin >> korean >> math >> english;

    // �л� ���� �Է� �ޱ�
    for (int i = 0; i < 5; ++i) {
        string studentName;
        cout << "�л� " << i + 1 << "�� �̸��� �Է��ϼ���: ";
        cin >> studentName;

        // �л� ��ü ���� �� �迭�� ����
        students[i] = Grade(studentName, korean, math, english);
    }

    // �л��� ������ ��� ���
    cout << "\n--- �л��� ���� ---" << endl;
    for (const auto& student : students) {
        cout << "�̸�: " << student.getName() << ", ����: " << student.getTotal() << ", ���: " << student.getAverage() << endl;
    }

    // ���� ������ ��� ���
    int totalKorean = 0, totalMath = 0, totalEnglish = 0;
    for (const auto& student : students) {
        totalKorean += student.getKorean();
        totalMath += student.getMath();
        totalEnglish += student.getEnglish();
    }

    double averageKorean = static_cast<double>(totalKorean) / 5;
    double averageMath = static_cast<double>(totalMath) / 5;
    double averageEnglish = static_cast<double>(totalEnglish) / 5;

    // ���� ������ ��� ���
    cout << "\n--- ���� ���� ---" << endl;
    cout << "���� ����: " << totalKorean << ", ���: " << averageKorean << endl;
    cout << "���� ����: " << totalMath << ", ���: " << averageMath << endl;
    cout << "���� ����: " << totalEnglish << ", ���: " << averageEnglish << endl;

    return 0;
}
