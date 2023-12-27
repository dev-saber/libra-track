#include "../classes/buy_history.h"
buy_history::buy_history(int id,int bo, int bu, double p) :ID(id), ID_book(bo), ID_buyer(bu), price(p), created_at(time(0)) {}
