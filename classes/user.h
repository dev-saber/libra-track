#pragma once
#include <iostream>
using namespace std;

class user
{
    friend class storage;

public:
    static int user_id;

protected:
    int ID;
    string full_name;
    string email;
    string phone;
    string role;

public:
    user(int, string, string, string, string);
    virtual void output();
};

class buyer : protected user
{
    friend class storage;

public:
    buyer(int, string, string, string, string);
    void output();
};

class member : private buyer
{
    friend class storage;
    bool is_active;

public:
    member(int, string, string, string, string);
    void output();
};