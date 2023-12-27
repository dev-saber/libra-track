#include "../classes/subscription.h"

subscription::subscription() : ID(0), name(""), price(0), description("") {}
subscription::subscription(int id, string n, double p, string d) : ID(id), name(n), price(p), description(d) {}