#include "methods.cpp"
using namespace std;

int main()
{
    book b1(1, "title 1", "auth 1", 4, false),
        b2(2, "title 2", "auth 2", 90, true),
        // b3(3, "title 4", "auth 2", 70, true),
        // b4(4, "title 3", "auth 2", 80, true),
        // b5(5, "title 5", "auth 2", 90, true),
        // b6(6, "title 6", "auth 2", 50, true),
        // b7(7, "title 7", "auth 2", 40, true),
        // b8(8, "title 8", "auth 2", 3430, true),
        // b9(9, "title 9", "auth 2", 20, true),
        b10(10, "title 10", "auth 2", 60, true),
        b11(11, "title 2", "auth 2", 440, true);

    storage s;
    s.add_book(b1);
    s.add_book(b2);
    // s.add_book(b3);
    // s.add_book(b4);
    // s.add_book(b5);
    // s.add_book(b6);
    // s.add_book(b7);
    // s.add_book(b8);
    // s.add_book(b9);
    // s.add_book(b10);
    // s.add_book(b11);
    // s.add_book();

    // s.show_book(111);
    // s.show_book(1);
    // s.show(2);
    // s.show(3);
    // s.all_books();

    // s.add_book();
    // s.all_books();

    // s.delete_book(10);
    // s.delete_book(9);
    // s.delete_book(11);
    // s.all_books();
    // s.update_book(111);

    // s.search();
    // cout << regex_search_pattern("meryem","mer");

    s.add_sub();
    s.add_sub();
    // s.all_subs();

    s.all_subs();
    // s.update_sub(1);
    // s.update_sub(2);
    s.delete_sub(1);  
    s.all_subs();  

    return 0;
}