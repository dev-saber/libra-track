#include "../classes/buy_history.h"
buy_history::buy_history(int id,int bo, int bu, double p) :ID(id), ID_book(bo), ID_buyer(bu), price(p), created_at(time(0)) {}
ostream &operator<<(ostream &o,const buy_history &bh)
{
    o << "  Book ID: " << bh.ID_book << "\n";
    o << "  Buyer ID: " << bh.ID_buyer << "\n";
    o << "  Price:" << bh.price << "\n";
    o << "  Created At: " << ctime(&bh.created_at);
    return o;
}