#include <iostream>
#include <string>
using namespace std;

// 부모 클래스인 Product 정의
class Product {
    int id;
    string price, description, producer;

public:
    // 기본 생성자 및 매개변수를 받는 생성자 정의
    Product() {}
    Product(int id, string price, string des, string pro) {
        this->id = id; this->price = price;
        description = des; producer = pro;
    }

    // 순수 가상 함수로, 파생 클래스에서 구현될 것임
    virtual void show() = 0;

    // 멤버 변수에 대한 getter 함수들
    int getId() { return id; }
    string getPrice() { return price; }
    string getDes() { return description; }
    string getPro() { return producer; }
};

// Book 클래스는 Product를 상속함
class Book : public Product {
    string isbn, author, bookName;

public:
    // 생성자 정의
    Book(int id, string des, string pro, string price, string bookName, string author, string isbn)
        :Product(id, price, des, pro) {
        this->isbn = isbn; this->author = author; this->bookName = bookName;
    }

    // 부모 클래스의 순수 가상 함수를 구현
    void show();

    // 멤버 변수에 대한 getter 함수들
    string getName() { return bookName; }
    string getAut() { return author; }
    string getISBN() { return isbn; }
};

// CompactDisc 클래스는 Product를 상속함
class CompactDisc : public Product {
    string title, singer;

public:
    // 생성자 정의
    CompactDisc(int id, string des, string pro, string price, string title, string singer) : Product(id, price, des, pro) {
        this->title = title; this->singer = singer;
    }

    // 부모 클래스의 순수 가상 함수를 구현
    void show();
};

// ConversationBook 클래스는 Book를 상속함
class ConversationBook : public Book {
    string language;

public:
    // 생성자 정의
    ConversationBook(int id, string des, string pro, string price, string bookName, string author, string lan, string isbn)
        :Book(id, des, pro, price, bookName, author, isbn) {
        this->language = lan;
    }

    // 부모 클래스의 순수 가상 함수를 구현
    void show();
};

// Book 클래스의 show 함수 정의
void Book::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "책제목 : " << bookName << endl;
    cout << "저자 : " << author << endl;
    cout << "ISBN : " << isbn << endl;
}

// CompactDisc 클래스의 show 함수 정의
void CompactDisc::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "앨범제목 : " << title << endl;
    cout << "가수 : " << singer << endl;
}

// ConversationBook 클래스의 show 함수 정의
void ConversationBook::show() {
    cout << "--- 상품ID : " << getId() << endl;
    cout << "상품설명 : " << getDes() << endl;
    cout << "생산자 : " << getPro() << endl;
    cout << "가격 : " << getPrice() << endl;
    cout << "책제목 : " << getName() << endl;
    cout << "저자 : " << getAut() << endl;
    cout << "언어 : " << language << endl;
    cout << "ISBN : " << getISBN() << endl;
}

int main() {
    Product* p[ 100 ]; // Product 포인터 배열 선언
    int id = 0;
    string des, pro, price, isbn, aut, name, title, singer, lan;

    cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;

    for ( ;;) {
        cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
        int n;
        cin >> n;

        if ( n == 1 ) {
            if ( id >= 100 ) break;
            cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
            cin >> n;
            cin.ignore();

            if ( n == 1 ) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "책제목>>"; getline(cin, name);
                cout << "저자>>"; getline(cin, aut);
                cout << "ISBN>>"; getline(cin, isbn);
                Book* b = new Book(id, des, pro, price, name, aut, isbn);
                p[ id ] = b;
                ++id;
            }
            else if ( n == 2 ) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "앨범제목>>"; getline(cin, title);
                cout << "가수>>"; getline(cin, singer);
                CompactDisc* c = new CompactDisc(id, des, pro, price, title, singer);
                p[ id ] = c;
                ++id;
            }
            else if ( n == 3 ) {
                cout << "상품설명>>"; getline(cin, des);
                cout << "생산자>>"; getline(cin, pro);
                cout << "가격>>"; getline(cin, price);
                cout << "책제목>>"; getline(cin, name);
                cout << "저자>>"; getline(cin, aut);
                cout << "언어>>"; getline(cin, lan);
                cout << "ISBN>>"; getline(cin, isbn);
                ConversationBook* cb = new ConversationBook(id, des, pro, price, name, aut, lan, isbn);
                p[ id ] = cb;
                ++id;
            }
            else
                cout << "숫자 입력 오류" << endl;
        }
        else if ( n == 2 ) {
            for ( int i = 0; i < id; ++i )
                p[ i ]->show();
        }
        else if ( n == 3 ) {
            break;
        }
        else
            cout << "숫자 입력 오류" << endl;

        cout << endl;
    }
}

/*
클래스와 상속:

클래스들은 상속을 사용하여 관련된 속성과 행동을 그룹화합니다.
상속 관계를 통해 코드 재사용과 유지보수성을 향상시킵니다.

가상 함수와 다형성:

가상 함수를 사용하여 객체의 타입에 따라 실행되는 함수가 동적으로 결정됩니다.
이를 통해 다형성을 구현하여 코드의 유연성을 높입니다.

포인터와 배열:

포인터를 사용하여 객체의 동적 할당 및 메모리 관리를 합니다.
배열을 사용하여 여러 객체를 관리합니다.

사용자 입력과 데이터 처리:

사용자로부터 입력을 받고, 이를 객체의 속성으로 저장하여 처리합니다.
사용자 입력에 대한 오류 처리를 수행하여 안정성을 높입니다.
*/