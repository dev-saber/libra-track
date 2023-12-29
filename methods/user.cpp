
#include "../classes/user.h"

user::user() : ID(0), full_name(""), email(""), phone(""), role(""){};
user::user(int id, string fn, string em, string ph, string r) : ID(id), full_name(fn), email(em), phone(ph), role(r){};
user::user(user& u):ID(u.ID), full_name(u.full_name), email(u.email), phone(u.phone), role(u.role){};

void user::output() 
{
    cout << "user id: " << ID << endl;
    cout << "full name : " << full_name << endl;
    cout << "email : " << email << endl;
    cout << "phone : " << phone << endl;
    cout << "role : " << role << endl;
}

// Buyer class
buyer::buyer(int id, string fn, string em, string ph, string r) : user(id, fn, em, ph, r){};
buyer::buyer(user& u):user(u){};
void buyer::output(){
    user::output();
}

// Member class
member::member(int id, string fn, string em, string ph, string r, bool ac) : buyer(id, fn, em, ph, r), is_active(ac){};

member::member(user& u): buyer(u), is_active(true){};
member::member(user& m,bool b): buyer(m), is_active(b){};

void member::output(){
    user::output();
    cout << is_active << endl;
}