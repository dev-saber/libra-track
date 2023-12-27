#pragma once
#include <iostream>
#include <ctime>

class buy_history
{
    friend class storage;
private:
    int ID_book;
    int ID_buyer;
    double price;
    time_t created_at;

public:
    buy_history(int, int, double);
};