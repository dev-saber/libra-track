#include "../classes/book.h"
#include "../methods/utils.cpp"

book::book(int id, string ti, string auth, int ac, bool sell, double price) : ID(id), title(ti), author(auth), available_copies(ac), is_sellable(sell), price(price){};
book::book() : ID(0), title(""), author(""), available_copies(0), is_sellable(false){};

ostream &operator<<(ostream &o, const book &b)
{
    o << "Book ID: " << b.ID << endl;
    o << "Title: " << b.title << endl;
    o << "Author: " << b.author << endl;
    o << "Price: " << b.price << endl;
    o << "Available copies: " << b.available_copies << endl;

    o << "Availability: " << check_Item_status(b.is_sellable);

    return o;
}