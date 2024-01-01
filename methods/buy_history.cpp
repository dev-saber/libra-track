#include "../classes/buy_history.h"
int  buy_history::ids_sales = 1;

buy_history::buy_history(int bo, int bu, double p, int q) :ID(buy_history::ids_sales), ID_book(bo), ID_buyer(bu), price(p),quantity(q), created_at(time(0)) {}
ostream &operator<<(ostream &o,const buy_history &bh)
{
    o << "  Book ID: " << bh.ID_book << "\n";
    o << "  Buyer ID: " << bh.ID_buyer << "\n";
    o << "  Price:" << bh.price << "\n";
    o << "  Created At: " << ctime(&bh.created_at);
    return o;
}