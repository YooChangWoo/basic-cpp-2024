// 5명의 이름과 국,영,수 3과목을 입력받아 학생별 총점과 평균 그리고 과목별 총점과 평균을 구하시오

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
    // 생성자: 이름과 각 과목 점수 초기화
    Grade(const string& n, int k, int m, int e) : name(n), kr(k), math(m), english(e) {}

    // 학생의 총점 계산
    int getTotal() const {
        return kr + math + english;
    }

    // 학생의 평균 계산
    double getAverage() const {
        return static_cast<double>(getTotal()) / 3.0;
    }

    // 학생의 이름 반환
    const string& getName() const {
        return name;
    }

    // 과목별 점수 반환
    int getKorean() const { return kr; }
    int getMath() const { return math; }
    int getEnglish() const { return english; }
};

int main() {
    // 학생 객체를 담는 vector 선언
    vector<Grade> students(5);

    // 각 과목 점수 입력 받기
    int korean, math, english;
    cout << "국어, 수학, 영어 점수를 입력하세요: ";
    cin >> korean >> math >> english;

    // 학생 정보 입력 받기
    for (int i = 0; i < 5; ++i) {
        string studentName;
        cout << "학생 " << i + 1 << "의 이름을 입력하세요: ";
        cin >> studentName;

        // 학생 객체 생성 및 배열에 저장
        students[i] = Grade(studentName, korean, math, english);
    }

    // 학생별 총점과 평균 출력
    cout << "\n--- 학생별 정보 ---" << endl;
    for (const auto& student : students) {
        cout << "이름: " << student.getName() << ", 총점: " << student.getTotal() << ", 평균: " << student.getAverage() << endl;
    }

    // 과목별 총점과 평균 계산
    int totalKorean = 0, totalMath = 0, totalEnglish = 0;
    for (const auto& student : students) {
        totalKorean += student.getKorean();
        totalMath += student.getMath();
        totalEnglish += student.getEnglish();
    }

    double averageKorean = static_cast<double>(totalKorean) / 5;
    double averageMath = static_cast<double>(totalMath) / 5;
    double averageEnglish = static_cast<double>(totalEnglish) / 5;

    // 과목별 총점과 평균 출력
    cout << "\n--- 과목별 정보 ---" << endl;
    cout << "국어 총점: " << totalKorean << ", 평균: " << averageKorean << endl;
    cout << "수학 총점: " << totalMath << ", 평균: " << averageMath << endl;
    cout << "영어 총점: " << totalEnglish << ", 평균: " << averageEnglish << endl;

    return 0;
}
