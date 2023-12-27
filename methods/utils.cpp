#pragma once
#include "../classes/book.h"
#include "../classes/subscription.h"
#include "../classes/buy_history.h"
#include <iostream>
#include <algorithm>
#include <optional>
using namespace std;
#include <regex>

template <class V, class I>
optional<V> find(vector<V> vector, I ID)
{
    auto it = find_if(vector.begin(), vector.end(), [ID](const V &obj)
                      { return obj.ID == ID; });
    if (it != vector.end())
    {

        return *it;
    }
    else
    {
        return nullopt;
    }
};

string check_Item_status(bool choice)
{
    return choice ? "sellable" : "borrowable";
}

template <class V, class I>
void remove_elements_by_id(vector<V> &vector, I ID)
{
    vector.erase(remove_if(vector.begin(), vector.end(),
                           [ID](const V &obj)
                           { return obj.ID == ID; }),
                 vector.end());
};

bool regex_search_pattern(string sentence, string search)
{
    regex regex_pattern(".*" + search + ".*");
    smatch m;
    if (regex_search(sentence,m,regex_pattern))
    {
        return true;
    }
    return false;

}

ostream &operator<<(ostream &o, book &b)
{
    o << "Book ID: " << b.ID << endl;
    o << "Title: " << b.title << endl;
    o << "Author: " << b.author << endl;
    o << "Price: " << b.price << endl;
    o << "Available copies: " << b.available_copies << endl;

    o << "Availability: " << check_Item_status(b.is_sellable);

    return o;
}

ostream &operator<<(ostream &o, subscription &s)
{
    o << "Subscription ID: " << s.ID << endl;
    o << "Subscription name: " << s.name << endl;
    o << "Subscription price: " << s.price << endl;
    o << "Description: " << s.description << endl;

    return o;
}










// ostream &operator<<(ostream &o, buy_history &bh)
// {
//     o << "  Book ID: " << bh.ID_book << "\n";
//     o << "  Buyer ID: " << bh.ID_buyer << "\n";
//     o << "  Price:" << bh.price << "\n";
//     o << "  Created At: " << ctime(&bh.created_at);
//     return o;
// }