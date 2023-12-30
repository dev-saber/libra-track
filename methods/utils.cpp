#pragma once
#include "../classes/book.h"
#include "../classes/subscription.h"
#include "../classes/buy_history.h"
#include "../classes/user.h"
#include <iostream>
#include <algorithm>
#include <optional>
#include <regex>

using namespace std;

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

template <class V, class I>
optional<V> find_user_pointers(vector<V> vector, I ID)
{
    auto it = find_if(vector.begin(), vector.end(), [ID](const V &obj)
                      { return obj->ID == ID; });
    if (it != vector.end())
    {

        return *it;
    }
    else
    {
        return nullopt;
    }
}

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
    if (regex_search(sentence, m, regex_pattern))
    {
        return true;
    }
    return false;
}
bool check_member_active(optional<user*>& u) {
    if (u.has_value()) {
        member* derivedMember = dynamic_cast<member*>(u.value());
        if (derivedMember) {
            return derivedMember->get_is_active();
        }
    }

    // If not a member or u is empty
    return false;
}
