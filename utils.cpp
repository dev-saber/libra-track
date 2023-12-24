#include <iostream>
#include <algorithm>
#include <optional>
using namespace std;
#include <regex>

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