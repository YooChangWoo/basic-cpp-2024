#pragma once
/*
Filedivi.h 해더파일 선언
*/
class AClass {
public:
    int num;

public:					//접근제어 지시자
    AClass(int anum) { // 생성자: 초기화 담당자
        num = anum;
    }
    void AInfo();
};