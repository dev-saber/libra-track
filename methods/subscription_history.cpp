#include "../classes/subscription_history.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int subscription_history::subs_history_id= 1;
subscription_history::subscription_history() : ID(0), ID_member(0), ID_subscription(0){
    start_date = time(0);
    // seconds days_to_add(365 * 24 * 60 * 60);
    seconds days_to_add(30 * 60); // just for testing
    end_date = start_date + days_to_add.count();
};
subscription_history::subscription_history(int id_m, int id_s) : ID(subscription_history::subs_history_id), ID_member(id_m), ID_subscription(id_s)
{
    start_date = time(0);
    // seconds days_to_add(365 * 24 * 60 * 60);
    seconds days_to_add(30 * 60); // just for testing
    end_date = start_date + days_to_add.count();
}

bool subscription_history::is_expired()
{
    return end_date < time(0) ? true : false;
}

ostream &operator<<(ostream &o,const subscription_history &sh)
{

    
    o << "  ID: " << sh.ID<< "\n";
    o << "  Member ID: " << sh.ID_member << "\n";
    o << "  subscription ID: " << sh.ID_subscription << "\n";
    o << "  Start At: " << ctime(&sh.start_date);
    o << "  End date: " << ctime(&sh.end_date);
    return o;
}