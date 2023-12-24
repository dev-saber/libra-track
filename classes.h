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

    template <class V, class I>
    friend void remove_elements_by_id(vector<V> &, I);

private:
    int ID;
    string title;
    string author;
    int available_copies;
    bool is_sellable;

public:
    book(int, string, string, int, bool);
    book();
};

class subscription
{

    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    friend class storage;
    friend ostream &operator<<(ostream &, subscription &);
    template <class V, class I>
    friend void remove_elements_by_id(vector<V> &, I);

private:
    int ID;
    string name;
    double price;
    string description;

public:
    subscription(int, string, double, string);
    subscription();
};

class storage
{
    friend string check_Item_status(bool);
    friend bool regex_search_pattern(string, string);

private:
    vector<book> books;
    vector<subscription> subs;

public:
    static int id_generator;
    static int ids_subs;
    void add_book(book &);
    void add_book();
    void update_book(int);
    void delete_book(int);
    void all_books();
    void show_book(int);
    void search();

    void all_subs();
    void show_sub(int);

    void add_sub(subscription &);
    void add_sub();
    void update_sub(int);
    void delete_sub(int);
};
