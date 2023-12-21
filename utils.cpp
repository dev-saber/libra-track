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

bool is_confirmed(string choice){
    return "yes" ? true : false;
}

