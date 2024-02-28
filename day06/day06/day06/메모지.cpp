/*

복사 생성자
얕은 복사
깊은 복사
복사 생성자의 호출시점

case 1 : 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
case 2 : Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
case 3 : 객체를 반한하되, 참조형으로 반환하지 않는 경우
콜발 벨류 경우(값을 전달 해서 주는) 경우

임시 객체 

매개 변수 복사

int func(int a) {        // a= 10;, num의 10을 복사해서 사용한다.
a = 10 + 10;
return a;                // a를 리턴한다
}

int num = 10;
int res = func(num);




*/