#pragma once
#include "book.h"
#include "subscription.h"
#include "buy_history.h"
#include "borrow_history.h"
#include "subscription_history.h"
#include "../methods/utils.cpp"

class storage
{
    friend string check_Item_status(bool);
    friend bool regex_search_pattern(string, string);
    friend bool check_member_active(optional<user *> &);
    friend void update_member_active(std::optional<user *> &u, bool newActiveValue);
    // friend void check_to_change_is_active();

private:
    vector<book> books;
    vector<subscription> subs;
    vector<buy_history> sales;
    vector<user *> users;
    vector<borrow_history> borrows;
    vector<subscription_history> subs_history;

public:
    static int id_generator;
    static int ids_subs;
    // static int ids_sales;
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
    void show_sale_by_ID(int);
    void delete_sale(int);
    void update_sale(int);

    void subscribe();
    void borrow_book();

    user add_user(string);
    void show_all_user();
    int add_new_user_row(user &);
    void update_user(int);

    int get_count_borrowed(int);
    void show_all_borrowed();
};