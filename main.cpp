#include <iostream>
#include "methods/book.cpp"
#include "methods/storage.cpp"

using namespace std;

int main()
{
    book b1(1, "title 1", "auth 1", 4, false),
        b2(2, "title 2", "auth 2", 90, true);

    storage s;
    s.add_book(b1);
    s.add_book(b2);

    s.all_books();

    return 0;
}