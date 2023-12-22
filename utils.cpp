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

string check_Item_status(bool choice){
    return choice  ? "sellable" : "borrowable" ;
}

// template <class C>
// int get_element_position(vector<C> v, C to_delete){
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i].ID == to_delete.ID)
//         {
//             return i;
//         }
        
//     }
// };