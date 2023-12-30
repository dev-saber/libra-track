#pragma once
#include <iostream>

using namespace std;

class user
{
    friend class storage;
    template <class V, class I>
    friend optional<V> find_user_pointers(vector<V> vector, I ID);

    public : 
    static int user_id;

protected:
    int ID;
    string full_name;
    string email;
    string phone;
    string role;

public:
user();
    user(int, string, string, string, string);
    user(user&);
    virtual void output();
};

class buyer : public user
{
    // friend class storage;

public:
    buyer(int, string, string, string, string);
    buyer(user&);
    void output();

};

class member : public buyer
{
    // friend class storage;
    bool is_active;

public:
    member(int, string, string, string, string, bool);
    member(user&);
    member(user&, bool);
    void output();
    bool get_is_active(){
        return is_active;
    };
};