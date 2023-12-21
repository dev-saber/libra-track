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
        cout << foundBook1.value() << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void storage::all_books()
{
    for (book b : books)
    {
        cout << b << endl;
    }
}

void storage::update_book(int ID)
{
    this->show(ID);
    auto found_Book = find(books, ID);

    if (found_Book.has_value())
    {
        string title_inp, author_inp, a_copies_inp, is_sellable_inp;

        cout << "if u dont wanna change the attribute value press enter only" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update title  (" << found_Book.value().title << ") : ";
        getline(cin, title_inp);
        cout << "Update author (" << found_Book.value().author << ") : " << endl;
        getline(cin, author_inp);
        cout << "Update available copies value ( " << found_Book.value().available_copies << ") : " << endl;
        getline(cin, a_copies_inp);
        cout << "Update sellable status (" << found_Book.value().is_sellable << ") : " << endl;
        getline(cin, is_sellable_inp);
        cout << "-----------------------------------------------------" << endl;

        for (book &book : books)
        {
            if (book.ID == ID)
            {
                book.title = title_inp.empty() ? found_Book->title : title_inp;
                book.author = author_inp.empty() ? found_Book->author : author_inp;
                book.available_copies = a_copies_inp.empty() ? found_Book->available_copies : stoi(a_copies_inp);
                book.is_sellable = is_sellable_inp.empty() ? found_Book->is_sellable : is_confirmed(is_sellable_inp);
            }
        }

        this->show(ID);
    }
}
