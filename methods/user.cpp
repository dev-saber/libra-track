
#include "../classes/user.h"

user::user(int id, string fn, string em, string ph, string r) : ID(id), full_name(fn), email(em), phone(ph), role(r) {}

// Buyer class
buyer::buyer(int id, string fn, string em, string ph, string r) : user(id, fn, em, ph, r) {}