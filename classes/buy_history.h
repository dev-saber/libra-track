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
    // friend ostream &operator<<(ostream &o, buy_history &bh);
    
private:
    int ID;
    int ID_book;
    int ID_buyer;
    double price;
    time_t created_at;

public:
    static int ids_sales;
    buy_history(int,int, int, double);
    void show_sale();

};