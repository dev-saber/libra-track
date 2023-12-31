#pragma once
#include "../classes/book.h"
#include "../classes/subscription.h"
#include "../classes/buy_history.h"
#include "../classes/subscription_history.h"
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

bool check_member_active(optional<user *> &u)
{
    if (u.has_value())
    {
        member *derivedMember = dynamic_cast<member *>(u.value());
        if (derivedMember)
        {
            return derivedMember->get_is_active();
        }
    }

    // If not a member or u is empty
    return false;
}

void update_member_active(std::optional<user *> &u, bool newActiveValue)
{
    if (u.has_value())
    {
        member *derivedMember = dynamic_cast<member *>(u.value());
        if (derivedMember)
        {
            derivedMember->set_is_active(newActiveValue);
        }
    }
}

string string_to_lower(string s){
    transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return s;
}

// void check_to_change_is_active(vector<subscription_history> subs){
//     while (true) {

//         for (subscription_history &sub : subs)
//         {
            
//         if (sub.is_expired()) {
//            cout << "The subscription has expired." <<endl;
//             break; // Exit the loop if expired
//         } else {
//            cout << "The subscription is active." <<endl;
//         }

//         // Delay for 24 hours (86400 seconds)
//        this_thread::sleep_for(std::chrono::hours(24));
            
//         }
        

//     }
// }