#pragma once
#include "../classes/borrow_history.h"
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
int borrow_history::borrowed_id = 1;

borrow_history::borrow_history(int id, int member, int book) : ID(id), ID_member(member),ID_book(book)
{
    borrow_date = time(0);
    seconds days_to_add(15 * 24 * 60 * 60);
    return_date = borrow_date + days_to_add.count();
    is_returned = false;
}

ostream &operator<<(ostream &o, const borrow_history &bh)
{
    o << "  Borrow ID: " << bh.ID << endl;
    o << "  Member ID: " << bh.ID_member << endl;
    o << "  Book ID:" << bh.ID_book << endl;
    o << "  Borrow date: " << ctime(&bh.borrow_date) << endl;
    o << "  Return date: " << ctime(&bh.return_date) << endl;
    o << "  Return status: ";
    bh.is_returned ? o << "returned" : o << "not returned yet" << endl;
    return o;
}