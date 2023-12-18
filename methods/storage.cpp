#include "../classes/storage.h"

void storage::add_book(book &b)
{
    books.push_back(b);
}

void storage::show(int ID)
{
}

void storage::all_books()
{
    for (book b : books)
    {
        cout << b << endl;
    }
};

ostream &operator<<(ostream &o, book &b)
{
    o << "Book ID: " << b.ID << endl;
    o << "Title: " << b.title << endl;
    o << "Author: " << b.author << endl;
    o << "Available copies: " << b.available_copies << endl;

    if (b.is_sellable) {
        o << "Availability: Sellable\n";
    } else {
        o << "Availability: Borrowable\n";
    }



    return o;
}