#include "classes.h"
#include <algorithm>
#include "utils.cpp"

// Book class
int storage::id_generator=0;
book::book(int id, string ti, string auth, int ac, bool sell) : ID(id), title(ti), author(auth), available_copies(ac), is_sellable(sell){};
book::book(): ID(0), title(""), author(""), available_copies(0), is_sellable(false){};

// Storage class
ostream &operator<<(ostream &o, book &b)
{
    o << "Book ID: " << b.ID << endl;
    o << "Title: " << b.title << endl;
    o << "Author: " << b.author << endl;
    o << "Available copies: " << b.available_copies << endl;

    o << "Availability: " << check_Item_status(b.is_sellable);

    return o;
}

void storage::add_book(book &b)
{
    books.push_back(b);
}

void storage::add_book()
{
    book b;
    string bool_input;

    cout << "Enter a title book : ";
    getline(cin >> ws, b.title) ;
    cout << "Enter the book's author : " ;
    getline(cin, b.author) ;
    cout << "How many available copies : " ;
    cin >> b.available_copies;

    do
    {
        cout << "Is the book sellable (yes / no) : " ;
        cin >> bool_input;
        cin.ignore();
    } while (bool_input != "yes" && bool_input != "no");
    
    b.is_sellable="yes" ? true : false;
    b.ID=id_generator;

    books.push_back(b);
    id_generator++;

    // add later an if statement wether we add a new book or not (the fct calls itself)
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
    cout << "=== All Books in Storage ===\n";

    if (books.empty())
    {
        cout << "No books found in the storage.\n";
    }
    else
    {
        for ( book& b : books)
        {
            cout << b << "\n \n";
        }
    }

    cout << "===========================\n";
}

void storage::update_book(int ID)
{
    this->show(ID);
    auto found_Book = find(books, ID);

    if (found_Book.has_value())
    {
        string title_inp, author_inp, a_copies_inp, is_sellable_inp;

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update title  (" << found_Book.value().title << ") : ";
        getline(cin, title_inp);
        cout << "Update author (" << found_Book.value().author << ") : ";
        getline(cin, author_inp);
        cout << "Update available copies ( " << found_Book.value().available_copies << ") : ";
        getline(cin, a_copies_inp);
        cout << "Change book status ( from " << check_Item_status(found_Book.value().is_sellable) << " to " << check_Item_status(!found_Book.value().is_sellable) << ")   (yes/no): ";
        getline(cin, is_sellable_inp);
        cout << "-----------------------------------------------------" << endl;

        for (book &book : books)
        {
            if (book.ID == ID)
            {
                book.title = title_inp.empty() ? found_Book->title : title_inp;
                book.author = author_inp.empty() ? found_Book->author : author_inp;
                book.available_copies = a_copies_inp.empty() ? found_Book->available_copies : stoi(a_copies_inp);
                bool check = is_sellable_inp == "yes" ? !found_Book->is_sellable : found_Book->is_sellable;
                book.is_sellable = is_sellable_inp.empty() ? found_Book->is_sellable : check;
            }
        }

        this->show(ID);
    }
}

void storage::delete_book(int ID){
    auto found_Book = find(books, ID);

    if (found_Book.has_value()){
   
        remove_elements_by_id(books,ID);

    }
}