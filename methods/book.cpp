#include "../classes/book.h"

book::book(int id, string ti, string auth, int ac, bool sell, double price) : ID(id), title(ti), author(auth), available_copies(ac), is_sellable(sell), price(price){};
book::book() : ID(0), title(""), author(""), available_copies(0), is_sellable(false){};
