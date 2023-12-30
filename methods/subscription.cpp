#include "../classes/subscription.h"

subscription::subscription() : ID(0), name(""), price(0), description("") {}
subscription::subscription(int id, string n, double p, string d) : ID(id), name(n), price(p), description(d) {}

ostream &operator<<(ostream &o,const subscription &s)
{
    o << "Subscription ID: " << s.ID << endl;
    o << "Subscription name: " << s.name << endl;
    o << "Subscription price: " << s.price << endl;
    o << "Description: " << s.description << endl;

    return o;
}