#pragma once
#include <iostream>
using namespace std;

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