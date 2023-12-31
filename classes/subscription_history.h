#pragma once
#include <ctime>
#include <iostream>
class subscription_history
{
    friend class storage;
    template <class V, class I>
    friend optional<V> find(vector<V> vector, I ID);
    friend ostream &operator<<(ostream &o,const subscription_history &sh);
private:
    int ID,ID_member, ID_subscription;
    time_t start_date, end_date;


public:
    static int subs_history_id;
    subscription_history();
    subscription_history(int, int);
    bool is_expired();
};
