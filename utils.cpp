#include <iostream>
#include <algorithm>
#include <optional>
using namespace std;

template <class V, class I>
optional<V> find(vector<V> vector, I ID)
{
    auto it = find_if(vector.begin(), vector.end(), [ID](const book &obj)
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
void remove_elements_by_id(vector<V>& vector, I ID)
{
    vector.erase(remove_if(vector.begin(), vector.end(),
                           [ID](const V &obj)
                           { return obj.ID == ID; }),
                 vector.end());
};