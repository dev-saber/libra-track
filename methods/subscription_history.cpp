#include "../classes/subscription_history.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

subscription_history::subscription_history(int id,int id_m,int id_s):ID(id),ID_member(id_m),ID_subscription(id_s){
    start_date = time(0);
    seconds days_to_add(365 * 24 * 60 * 60);
    end_date = start_date + days_to_add.count();

}

bool subscription_history::is_expired(){
    return end_date < time(0) ? true : false;
}