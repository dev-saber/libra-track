
#include "../classes/user.h"

user::user(int id, string fn, string em, string ph, string r) : ID(id), full_name(fn), email(em), phone(ph), role(r){};

// Buyer class
buyer::buyer(int id, string fn, string em, string ph, string r) : user(id, fn, em, ph, r){};

// Member class
member::member(int id, string fn, string em, string ph, string r) : buyer(id, fn, em, ph, r), is_active(true){};

void user::output() 
{
    cout << "user id: " << ID << endl;
    cout << "full name : " << full_name << endl;
    cout << "email : " << email << endl;
    cout << "phone : " << phone << endl;
    cout << "role : " << role << endl;
}

void buyer::output(){
    user::output();
}
void member::output(){
    user::output();
    cout << is_active << endl;
}