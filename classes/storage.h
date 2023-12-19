#include <iostream>
#include <vector>
// #include "../classes/book.h" 
// main prb shoudnt include book.h here ?
using namespace std;

class storage
{

private:
    vector<book> books;

public:
    // Books management
    void add_book(book &);
    void update_book(int);
    void delete_book(int);
    void all_books();
    void show(int);
    // void display(book);
    bool is_available(int);

    // Users management
};
