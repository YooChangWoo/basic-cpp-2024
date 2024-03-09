#include <iostream> // 표준 입출력을 위한 헤더 파일
#include <cstring> // 문자열 처리를 위한 헤더 파일
using namespace std; // 표준 네임스페이스를 사용

class Grade {
private:
    char* name; // 학생 이름을 저장하는 포인터
    int kor;    // 국어 점수
    int math;   // 수학 점수
    int eng;    // 영어 점수
    int total;  // 세 과목의 총점
    double average; // 세 과목의 평균 점수

public:
    // 기본 생성자
    Grade() : name(nullptr), kor(0), math(0), eng(0), total(0), average(0.0) {} // 초기화 리스트를 사용한 기본 생성자 정의

    // 생성자: 학생의 이름과 세 과목의 점수를 받아 초기화
    Grade(const char* name, int kor, int math, int eng) {
        // 이름 복사
        size_t len = strlen(name) + 1; // 이름의 길이 계산 (널 문자 포함)
        this->name = new char[ len ]; // 이름을 저장하기 위한 메모리 할당
        strcpy_s(this->name, len, name); // 이름 복사

        // 과목 점수 설정
        this->kor = kor; // 국어 점수 저장
        this->math = math; // 수학 점수 저장
        this->eng = eng; // 영어 점수 저장

        // 총점과 평균 계산
        calculateTotal(); // 총점 계산 함수 호출
        calculateAverage(); // 평균 계산 함수 호출
    }

    // 복사 생성자
    Grade(const Grade& other) {
        size_t len = strlen(other.name) + 1; // 다른 객체의 이름 길이 계산 (널 문자 포함)
        this->name = new char[ len ]; // 새로운 메모리 할당
        strcpy_s(this->name, len, other.name); // 이름 복사
        this->kor = other.kor; // 국어 점수 복사
        this->math = other.math; // 수학 점수 복사
        this->eng = other.eng; // 영어 점수 복사
        this->total = other.total; // 총점 복사
        this->average = other.average; // 평균 복사
    }

    // 대입 연산자 오버로딩
    Grade& operator=(const Grade& other) {
        if ( this != &other ) { // 자기 자신과의 대입이 아닌 경우에만 수행
            delete[] name; // 기존에 할당된 메모리 해제
            size_t len = strlen(other.name) + 1; // 다른 객체의 이름 길이 계산 (널 문자 포함)
            this->name = new char[ len ]; // 새로운 메모리 할당
            strcpy_s(this->name, len, other.name); // 이름 복사
            this->kor = other.kor; // 국어 점수 복사
            this->math = other.math; // 수학 점수 복사
            this->eng = other.eng; // 영어 점수 복사
            this->total = other.total; // 총점 복사
            this->average = other.average; // 평균 복사
        }
        return *this; // 대입된 객체 자체를 반환하여 연속적인 대입 가능
    }

    // 소멸자: 동적으로 할당된 메모리 해제
    ~Grade() {
        delete[] name;
    }

    // 총점 계산 함수
    void calculateTotal() {
        total = kor + math + eng;
    }

    // 평균 계산 함수
    void calculateAverage() {
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
    const int NUM_STUDENTS = 1; // 학생 수
    Grade grade[ NUM_STUDENTS ];    // 학생 객체 배열

    int korTotal = 0, mathTotal = 0, engTotal = 0; // 각 과목의 총점을 저장할 변수 초기화

    // 학생 정보 입력
    for ( int i = 0; i < NUM_STUDENTS; ++i ) {
        char name[ 20 ]; // 학생 이름을 저장할 배열
        int inko, inEng, inmath; // 국어, 수학, 영어 점수를 저장할 변수

        // 사용자로부터 학생 정보 입력 받음
        cout << "이름: "; // 학생의 이름을 입력 받는 프롬프트 출력
        cin >> name; // 사용자로부터 학생 이름 입력 받음
        cout << "국어: "; // 국어 점수를 입력 받는 프롬프트 출력
        cin >> inko; // 사용자로부터 국어 점수 입력 받음
        cout << "수학: "; // 수학 점수를 입력 받는 프롬프트 출력
        cin >> inmath; // 사용자로부터 수학 점수 입력 받음
        cout << "영어: "; // 영어 점수를 입력 받는 프롬프트 출력
        cin >> inEng; // 사용자로부터 영어 점수 입력 받음
        cout << endl;

        // Grade 객체 생성 및 정보 설정
        grade[ i ] = Grade(name, inko, inmath, inEng);

        // 각 과목의 총점 누적
        korTotal += inko;
        mathTotal += inmath;
        engTotal += inEng;
    }

    // 각 과목의 평균 계산
    double korAverage = static_cast<double>( korTotal ) / NUM_STUDENTS;
    double mathAverage = static_cast<double>( mathTotal ) / NUM_STUDENTS;
    double engAverage = static_cast<double>( engTotal ) / NUM_STUDENTS;

    // 학생 정보와 각 과목의 총점 및 평균 출력
    for ( int i = 0; i < NUM_STUDENTS; ++i ) {
        cout << "이름: " << grade[ i ].getName() << endl;
        cout << "국어: " << grade[ i ].getKor() << ", 수학: " << grade[ i ].getMath() << ", 영어: " << grade[ i ].getEng() << endl;
        cout << "총점: " << grade[ i ].getTotal() << ", 평균: " << grade[ i ].getAverage() << endl;
        cout << endl;
    }

    // 각 과목의 총점과 평균 출력
    cout << "국어 과목의 총점 : " << korTotal << ", 평균 : " << korAverage << endl;
    cout << "수학 과목의 총점: " << mathTotal << ", 평균: " << mathAverage << endl;
    cout << "영어 과목의 총점: " << engTotal << ", 평균: " << engAverage << endl;

    return 0;
}
