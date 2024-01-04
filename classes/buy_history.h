#pragma once
#include <iostream>
#include <ctime>
#include "../methods/utils.cpp"

class buy_history
{
    friend class storage;
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend void remove_elements_by_id(vector<V> &vector, I ID);
    friend ostream &operator<<(ostream &o,const buy_history &bh);
    
private:
    int ID;
    int ID_book;
    int ID_buyer;
    double price;
    int quantity;
    time_t created_at;

public:
    static int sale_id;
    buy_history(int , int , double , int );
    void show_sale();
};