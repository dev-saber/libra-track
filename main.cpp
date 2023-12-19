#include "methods.cpp"
using namespace std;

int main()
{
    book b1(1, "title 1", "auth 1", 4, false),
        b2(2, "title 2", "auth 2", 90, true),
        b3(3, "title 2", "auth 2", 90, true),
        b4(4, "title 2", "auth 2", 90, true),
        b5(5, "title 2", "auth 2", 90, true),
        b6(6, "title 2", "auth 2", 90, true),
        b7(7, "title 2", "auth 2", 90, true),
        b8(8, "title 2", "auth 2", 90, true),
        b9(9, "title 2", "auth 2", 90, true),
        b10(10, "title 2", "auth 2", 90, true),
        b11(11, "title 2", "auth 2", 90, true);

    storage s;
    s.add_book(b1);
    s.add_book(b2);
    s.add_book(b3);
    s.add_book(b4);
    s.add_book(b5);
    s.add_book(b6);
    s.add_book(b7);
    s.add_book(b8);
    s.add_book(b9);
    s.add_book(b10);
    s.add_book(b11);

    // s.all_books();
    s.show(1);
    s.show(111);
    // optional<book> foundBook1 = s.find(2);
    // if (foundBook1.has_value()) {
    //     cout << "Book found: " << foundBook1.value() << endl;
    // } else {
    //     cout << "Book not found." << endl;
    // }

    // optional<book> foundBook2= s.find(111);
    // if (foundBook2.has_value()) {
    //     cout << "Book found: " << foundBook1.value() << endl;
    // } else {
    //     cout << "Book not found." << endl;}



    return 0;
}