#include <iostream>
#include <cstring>
using namespace std;

class Grade {
private:
    char* name;
    int kor;
    int math;
    int eng;
    int total;
    double average;

public:
    // 생성자: 학생의 이름과 세 과목의 점수를 받아 초기화
    Grade(const char* name, int kor, int math, int eng) {
        // 이름 복사
        size_t len = strlen(name) + 1;
        this->name = new char[ len ];
        strcpy_s(this->name, len, name);


        this->kor = kor;
        this->math = math;
        this->eng = eng;

        // 총점과 평균 계산
        Total();
        Average();
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Grade() {
        delete[] name;
    }

    // 총점 계산 함수
    void Total() {
        total = kor + math + eng;
    }

    // 평균 계산 함수
    void Average() {
        average = total / 3.0;
    }

    // 이름 반환 함수
    const char* getName() const {
        return name;
    }

    // 국어 점수 반환 함수
    int getKor() const {
        return kor;
    }

    // 수학 점수 반환 함수
    int getMath() const {
        return math;
    }

    // 영어 점수 반환 함수
    int getEng() const {
        return eng;
    }

    // 총점 반환 함수
    int getTotal() const {
        return total;
    }

    // 평균 반환 함수
    double getAverage() const {
        return average;
    }
};

int main() {
    const int STUDENTS = 5;
    Grade* gradeAry[ STUDENTS ];    // 학생 객체를 포인터 배열


    for ( int i = 0; i < STUDENTS; i++ ) {
        char name[ 20 ];
        int inko, inEng, inmath;

        cout << "이름: ";
        cin >> name;
        cout << "국어: ";
        cin >> inko;
        cout << "수학: ";
        cin >> inmath;
        cout << "영어: ";
        cin >> inEng;
        cout << endl;


        gradeAry[ i ] = new Grade(name, inko, inmath, inEng);
    }

    for ( int i = 0; i < STUDENTS; i++ ) {
        cout << "이름: " << gradeAry[ i ]->getName() << endl;
        cout << "국어: " << gradeAry[ i ]->getKor() << ", 수학: " << gradeAry[ i ]->getMath() << ", 영어: " << gradeAry[ i ]->getEng() << endl;
        cout << "총점: " << gradeAry[ i ]->getTotal() << ", 평균: " << gradeAry[ i ]->getAverage() << endl;  // 각 총점과 평균 출력
        cout << endl;
    }

    for ( int i = 0; i < STUDENTS; i++ ) {
        delete gradeAry[ i ];

    }

    return 0;
}