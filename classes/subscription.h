
#pragma once
#include <iostream>
#include <optional>
#include "../methods/utils.cpp"
using namespace std;

class subscription
{

    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    friend class storage;
    friend ostream &operator<<(ostream &, subscription &);
    template <class V, class I>
    friend void remove_elements_by_id(vector<V> &, I);

private:
    int ID;
    string name;
    double price;
    string description;

public:
    subscription(int, string, double, string);
    subscription();
};