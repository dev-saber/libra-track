#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <ctime>

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
    double price;

public:
    book(int, string, string, int, bool,double);
    book();
};

class user
{
protected:
    int ID;
    string full_name;
    string email;
    string phone;
    string role;

public:
    user(int, string, string, string, string);
};

class buyer : private user
{
public:
    buyer(int, string, string, string, string);
};

class buy_history
{
    friend class storage;
private:
    int ID_book;
    int ID_buyer;
    double price;
    time_t created_at;

public:
    buy_history(int, int, double);
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
    vector<buy_history> sales;

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

    void buy_book();
    void show_all_sales();
};
