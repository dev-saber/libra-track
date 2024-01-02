#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

class book
{
    friend class storage;
    friend ostream &operator<<(ostream &, const book &);

    template <class V, class I>
    friend optional<V> find(vector<V>, I);

    template <class V, class I>
    friend void remove_elements_by_id(vector<V> &, I);

private:
    int ID;
    string title;
    string author;
    int available_copies;
    bool is_sellable;
    double price;

public:
    static int book_id;
    book(int, string, string, int, bool,double);
    book();
};