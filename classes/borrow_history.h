#pragma once
#include <iostream>

class borrow_history
{
    friend class storage;
    template <class V, class I>
    friend optional<V> find(vector<V> vector, I ID);
    friend ostream& operator<<(ostream& o, const borrow_history& bh);
private:
    int ID;
    int ID_member;
    int ID_book;
    time_t borrow_date;
    time_t return_date;
    bool is_returned;

public:
    static int borrowed_id;
    borrow_history(int, int,int);
    void show_borrow(int);
};
