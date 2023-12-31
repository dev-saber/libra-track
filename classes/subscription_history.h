#pragma once
#include <ctime>

class subscription_history
{
    friend class storage;
private:
    int ID,ID_member, ID_subscription;
    time_t start_date, end_date;

public:
    static int subs_history_id;
    subscription_history(int,int, int);
    bool is_expired();
};
