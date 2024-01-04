
#include "../classes/user.h"
#include "../methods/utils.cpp"

user::user() : ID(0), full_name(""), email(""), phone(""), role(""){};
user::user(int id, string fn, string em, string ph, string r) : ID(id), full_name(fn), email(em), phone(ph), role(r){};
user::user(user &u) : ID(u.ID), full_name(u.full_name), email(u.email), phone(u.phone), role(u.role){};
int user::user_id = 1;
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
buyer::buyer(user &u) : user(u){};
void buyer::output()
{
    user::output();
}

// Member class
member::member(int id, string fn, string em, string ph, string r, bool ac) : buyer(id, fn, em, ph, r), is_active(ac){};

member::member(user &u) : buyer(u), is_active(true){};
member::member(user &m, bool b) : buyer(m), is_active(b){};

void member::output()
{
    user::output();
    cout << "is active : "  ;
    is_active==1 ? cout << "yes" : cout << "no" << endl;
}

bool member::get_is_active()
{
    return is_active;
}

void member::set_is_active(bool b)
{
    is_active = b;
}

admin::admin() : username("admin"), password("admin") {}

void admin::login()
{
    string username_inp, password_inp;
    
    while (true)
    {
        cout << "Enter your username: ";
        getline(cin, username_inp);
        cout << "Enter your password: ";
        getline(cin, password_inp);

        if (username == username_inp && password == password_inp)
        {
            cout << "Login successful. Welcome, " << username << "!" << endl;
            break;
        }

        cout << "Incorrect credentials. Please reenter your username and password." << endl;
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void admin::logout()
{
    exit(0);
}