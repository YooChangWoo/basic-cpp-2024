/*
1. Parent class = class Product: id, price, producer
2. Child Class
	- class  Book = ISBN, authoer,title // 978-89-001-0001-1
	- class Handphone: model, Ram
	- class Computer: Model, cpu, Ram
3. 객체포인터 배열 사용:product[100]
4. string 클래스 사용 가능

5. 메인 화면
    - 상품관리 프로그램 = 1. 상품추가 2. 상품출력 3. 상품검색 0. 종료
    = 1 또는 2 또는 삼 선택 한 경우
        1. 책 2. 핸드폰 3. 컴퓨터
    선택 목롬을 띄워 해당 상품을 선택 한 후 추가, 출력 또는 검색을 실행한다
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 부모 클래스 Product 정의
class Product {
protected:
    int id;
    double price;
    string producer;
public:
    Product(int _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

    virtual void printInfo() const {
        cout << "ID: " << id << ", Price: " << price << ", Producer: " << producer << endl;
    }
};

// 자식 클래스 Book 정의
class Book : public Product {
private:
    string ISBN;
    string author;
    string title;
public:
    Book(int _id, double _price, string _producer, string _ISBN, string _author, string _title)
        : Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

    void printInfo() const override {
        Product::printInfo();
        cout << "ISBN: " << ISBN << ", Author: " << author << ", Title: " << title << endl;
    }
};

// 자식 클래스 Handphone 정의
class Handphone : public Product {
private:
    string model;
    int ram;
public:
    Handphone(int _id, double _price, string _producer, string _model, int _ram)
        : Product(_id, _price, _producer), model(_model), ram(_ram) {}

    void printInfo() const override {
        Product::printInfo();
        cout << "Model: " << model << ", RAM: " << ram << "GB" << endl;
    }
};

// 자식 클래스 Computer 정의
class Computer : public Product {
private:
    string model;
    string cpu;
    int ram;
public:
    Computer(int _id, double _price, string _producer, string _model, string _cpu, int _ram)
        : Product(_id, _price, _producer), model(_model), cpu(_cpu), ram(_ram) {}

    void printInfo() const override {
        Product::printInfo();
        cout << "Model: " << model << ", CPU: " << cpu << ", RAM: " << ram << "GB" << endl;
    }
};

// 메인 함수
int main() {
    vector<Product*> products; // 객체포인터 배열 사용

    int choice;
    while (true) {
        cout << "상품관리 프로그램" << endl;
        cout << "1. 상품추가 2. 상품출력 3. 상품검색 0. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1) {
            int productType;
            cout << "1. 책 2. 핸드폰 3. 컴퓨터" << endl;
            cout << "상품 종류 선택: ";
            cin >> productType;

            int id;
            double price;
            string producer;
            cout << "ID: ";
            cin >> id;
            cout << "Price: ";
            cin >> price;
            cout << "Producer: ";
            cin >> producer;

            if (productType == 1) {
                string ISBN, author, title;
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "Author: ";
                cin >> author;
                cout << "Title: ";
                cin >> title;
                products.push_back(new Book(id, price, producer, ISBN, author, title));
            }
            else if (productType == 2) {
                string model;
                int ram;
                cout << "Model: ";
                cin >> model;
                cout << "RAM: ";
                cin >> ram;
                products.push_back(new Handphone(id, price, producer, model, ram));
            }
            else if (productType == 3) {
                string model, cpu;
                int ram;
                cout << "Model: ";
                cin >> model;
                cout << "CPU: ";
                cin >> cpu;
                cout << "RAM: ";
                cin >> ram;
                products.push_back(new Computer(id, price, producer, model, cpu, ram));
            }
        }
        else if (choice == 2) {
            cout << "상품 출력" << endl;
            for (const auto& product : products) {
                product->printInfo();
            }
        }
        else if (choice == 3) {
            cout << "상품 검색" << endl;
            // 상품 검색 기능 추가
        }
        else {
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
    }

    // 동적 할당한 객체들 삭제
    for (auto& product : products) {
        delete product;
    }

    return 0;
}
