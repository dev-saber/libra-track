#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

class book
{
    friend class storage;
    friend ostream &operator<<(ostream &, book &);

    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    int ID;
    string title;
    string author;
    int available_copies;
    bool is_sellable;

public:
    book(int, string, string, int, bool);
};
class storage
{
    friend bool is_confirmed(string);

private:
    vector<book> books;

public:
    void add_book(book &);
    void update_book(int);
    void delete_book(int);
    void all_books();
    void show(int);

    bool is_available(int);
};