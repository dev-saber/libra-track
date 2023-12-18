#include <iostream>
#include <vector>
using namespace std;

class book
{
    friend class storage;
    friend ostream &operator<<(ostream &o, book &b);

private:
    int ID;
    string title;
    string author;
    int available_copies;
    bool is_sellable;

public:
    book(int, string, string, int, bool);
};
