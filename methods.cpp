#include "classes.h"
#include <algorithm>
#include "utils.cpp"
// Book class
book::book(int id, string ti, string auth, int ac, bool sell) : ID(id), title(ti), author(auth), available_copies(ac), is_sellable(sell){};

// Storage class
ostream &operator<<(ostream &o, book &b)
{
    o << "Book ID: " << b.ID << endl;
    o << "Title: " << b.title << endl;
    o << "Author: " << b.author << endl;
    o << "Available copies: " << b.available_copies << endl;

    if (b.is_sellable)
    {
        o << "Availability: Sellable\n";
    }
    else
    {
        o << "Availability: Borrowable\n";
    }

    return o;
}
void storage::add_book(book &b)
{
    books.push_back(b);
}



void storage::show(int ID)
{
    
    auto foundBook1 = find(books, ID);
    if (foundBook1.has_value())
    {
        cout <<  foundBook1.value() << endl;
    }
    else
    {
        cout << "Book not found." << endl;
    }
}

void storage::all_books()
{
    for (book b : books)
    {
        cout << b << endl;
    }
};
