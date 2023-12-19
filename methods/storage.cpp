#include "../classes/storage.h"
// #include "../classes/book.h"
#include <algorithm>
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
    auto it = find_if(books.begin(), books.end(), [ID](const book &obj)
                      { return obj.ID == ID; });
    if (it != books.end())
    {
        book &foundObject = *it;
        cout << foundObject << endl;
    }
    else
    {
        cout << "Object with id = " << ID << " not found." << endl;
    }
}

void storage::all_books()
{
    for (book b : books)
    {
        cout << b << endl;
    }
};
