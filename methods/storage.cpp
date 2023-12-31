#include "../classes/storage.h"
#include "utils.cpp"
#include <algorithm>
#include <limits>
#include <thread>

int storage::id_generator = 1;
int storage::ids_subs = 1;
int buy_history::ids_sales = 1;
int user::user_id = 1;

void storage::add_book(book &b)
{
    books.push_back(b);
}

void storage::add_book()
{
    book b;
    string bool_input;
    cout << "=== Add New Book ===\n";
    cout << "Enter a title book : ";
    getline(cin >> ws, b.title);
    cout << "Enter the book's author : ";
    getline(cin, b.author);
    while (true)
    {
        cout << "How many available copies : ";
        string copies_input;
        cin >> copies_input;

        if (regex_match(copies_input, regex("\\d+")))
        {
            b.available_copies = stoi(copies_input);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid available copies number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true)
    {
        cout << "Enter Price of the Book : ";
        string price_input;
        cin >> price_input;

        if (regex_match(price_input, regex("[+-]?([0-9]*[.])?[0-9]+")))
        {
            b.price = stof(price_input);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid Price : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    do
    {
        cout << "Is the book sellable (yes / no) : ";
        cin >> bool_input;
        bool_input = string_to_lower(bool_input);
        cin.ignore();
    } while (bool_input != "yes" && bool_input != "no");

    b.is_sellable = "yes" ? true : false;
    b.ID = id_generator;
    books.push_back(b);
    id_generator++;
}

void storage::show_book(int ID)
{

    auto foundBook1 = find(books, ID);
    if (foundBook1.has_value())
    {
        cout << "---- Book ----" << endl;

        cout << foundBook1.value() << endl;
        cout << "-----------------------------" << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void storage::all_books()
{
    cout << "=== All Books in Storage ===" << endl;

    if (books.empty())
    {
        cout << "No books found in the storage." << endl;
    }
    else
    {

        cout << "Number of books in the library: " << books.size() << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << "---- Book " << i + 1 << " ----" << endl;
            cout << books[i] << endl;
            cout << "-----------------------------" << endl;
        }
    }

    cout << "===========================" << endl;
}

void storage::update_book(int ID)
{
    auto found_book = find(books, ID);

    if (found_book.has_value())
    {
        string title_inp, author_inp, a_copies_inp, is_sellable_inp, price_inp;

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update title  (" << found_book.value().title << ") : ";
        getline(cin, title_inp);
        cout << "Update author (" << found_book.value().author << ") : ";
        getline(cin, author_inp);
        cout << "Update price (" << found_book.value().price << ") : ";
        getline(cin, price_inp);

        while (!price_inp.empty())
        {

            if (regex_match(price_inp, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid price : ";
                cin.clear();
                getline(cin, price_inp);
            }
        }

        cout << "Update available copies ( " << found_book.value().available_copies << " ) : ";
        getline(cin, a_copies_inp);

        while (!a_copies_inp.empty())
        {

            if (regex_match(a_copies_inp, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid number of available copies : ";
                cin.clear();
                getline(cin, a_copies_inp);
            }
        }

        do
        {
            cin.clear();
            cout << "Change book status ( from " << check_Item_status(found_book.value().is_sellable) << " to " << check_Item_status(!found_book.value().is_sellable) << " ) (yes/no): ";

            getline(cin, is_sellable_inp);
            is_sellable_inp = string_to_lower(is_sellable_inp);
        } while (is_sellable_inp != "yes" && is_sellable_inp != "no" && !is_sellable_inp.empty());

        cout << "-----------------------------------------------------" << endl;

        for (book &book : books)
        {
            if (book.ID == ID)
            {
                book.title = title_inp.empty() ? found_book->title : title_inp;
                book.author = author_inp.empty() ? found_book->author : author_inp;
                book.available_copies = a_copies_inp.empty() ? found_book->available_copies : stoi(a_copies_inp);
                book.price = price_inp.empty() ? found_book->price : stof(price_inp);
                bool check = string_to_lower(is_sellable_inp) == "yes" ? !found_book->is_sellable : found_book->is_sellable;
                book.is_sellable = is_sellable_inp.empty() ? found_book->is_sellable : check;

                break;
            }
        }
    }
}

void storage::delete_book(int ID)
{
    auto found_book = find(books, ID);

    if (found_book.has_value())
    {

        remove_elements_by_id(books, ID);

        // try except is remove
        // cout << "Book removed successfully" << endl;
    }
}

void storage::search()
{
    string author, title, is_sellable_inp, is_sellable;
    bool query_condition = true;

    do
    {
        cout << "Enter the title : " << endl;
        getline(cin, title);
        cout << "Enter the author : " << endl;
        getline(cin, author);
        cout << "Is the book for sell (yes/no) : " << endl;
        getline(cin, is_sellable_inp);

        title = title.empty() ? "" : title;
        author = author.empty() ? "" : author;

    } while (author == "" && title == "");

    for (auto book : books)
    {
        query_condition = true;

        if (!title.empty())
        {
            query_condition = query_condition && regex_search_pattern(book.title, title);
        }

        if (!author.empty())
        {
            query_condition = query_condition && regex_search_pattern(book.author, author);
        }

        if (is_sellable_inp == "yes")
        {
            query_condition = query_condition && (book.is_sellable == true);
        }

        if (is_sellable_inp == "no")
        {
            query_condition = query_condition && (book.is_sellable == false);
        }

        if (query_condition)
        {
            cout << "======================" << endl;
            cout << book << endl;
        }
    }
}

void storage::show_sub(int ID)
{
    cout << "===========================\n";
    auto found_sub = find(subs, ID);
    if (found_sub.has_value())
    {
        cout << found_sub.value() << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    cout << "===========================\n";
}

void storage::update_sub(int ID)
{
    this->show_sub(ID);
    auto found_sub = find(subs, ID);

    if (found_sub.has_value())
    {
        string name_inp, desc_inp, price_inp;

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update subs  (" << found_sub.value().name << ") : ";
        getline(cin, name_inp);

        cout << "Update price (" << found_sub.value().price << ") : ";
        getline(cin, price_inp);

        while (!price_inp.empty())
        {

            if (regex_match(price_inp, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid price : ";
                cin.clear();
                getline(cin, price_inp);
            }
        }

        cout << "Update description (" << found_sub.value().description << ") : ";
        getline(cin, desc_inp);
        cout << endl;
        cout << "-----------------------------------------------------" << endl;

        for (subscription &sub : subs)
        {
            if (sub.ID == ID)
            {
                sub.name = name_inp.empty() ? found_sub->name : name_inp;
                sub.price = price_inp.empty() ? found_sub->price : stod(price_inp);
                sub.description = desc_inp.empty() ? found_sub->description : desc_inp;
            }
        }

        this->show_sub(ID);
    }
}

void storage::delete_sub(int ID)
{
    auto found_sub = find(subs, ID);

    if (found_sub.has_value())
    {
        remove_elements_by_id(subs, ID);
    }
    else
    {
        cout << "no element with this id" << endl;
    }
}

user storage::add_user(string r = "")
{
    string full_name_inp, mail_inp, phone_inp;
    int role_inp;
    cout << "Enter the full name : ";
    getline(cin >> ws, full_name_inp);
    cout << "Enter the email : ";
    getline(cin >> ws, mail_inp);
    cout << "phone: ";
    getline(cin >> ws, phone_inp);

    if (r == "")
    {
        do
        {
            cout << "Role user (1 for member - 0 for buyer): ";
            cin >> role_inp;
        } while (role_inp != 1 && role_inp != 0);
        r = role_inp == 1 ? "member" : "buyer";
    }
    user u(user::user_id, full_name_inp, mail_inp, phone_inp, r);

    return u;
}

int storage::add_new_user_row(user &u)
{
    if (u.role == "member")
    {
        users.push_back(new member(u, true));
        add_subscription_record(u.ID);
    }
    else
    {
        users.push_back(new buyer(u));
    }
    user::user_id++;
    return user::user_id - 1;
}

void storage::buy_book()
{
    int book_id, user_id, role_inp;
    bool is_active_bool = true;

    cout << "enter the role (member 1 - buyer 0): ";
    cin >> role_inp;
    if (role_inp == 1)
    {
        bool is_found = true;
        do
        {
            cout << "Enter the member ID: ";
            cin >> user_id;
            cout << user_id;
            auto found_member = find_user_pointers(users, user_id);

            if (!found_member.has_value())
            {
                is_found = false;
            }
            else
            {
                is_active_bool = check_member_active(found_member);
            }
        } while (!is_found);
    }
    else
    {
        user user_instance;
        user_instance = add_user("buyer");
        user_id = add_new_user_row(user_instance);
    }

    cout << "enter the book id: ";
    cin >> book_id;

    auto foundBook = find(books, book_id);

    if (foundBook.has_value() && (foundBook.value().is_sellable == true) && (foundBook.value().available_copies > 0) && is_active_bool)
    {

        for (book &book : books)
        {
            if (book.ID == book_id)
            {
                book.available_copies--;
                buy_history bh(buy_history::ids_sales, book_id, user_id, book.price);
                sales.push_back(bh);
                buy_history::ids_sales++;

                cout << "new row has been added to the fake database" << endl;
                break;
            }
        }
    }
    else
    {
        !foundBook.has_value() ? cout << "Book isn't available" << endl
                               : (foundBook.value().is_sellable == false
                                      ? cout << "The book is not for sale" << endl
                                      : (!is_active_bool ? cout << "member not active" << endl : cout << "The book is out of stock" << endl));
    }
}

void buy_history::show_sale()
{
    cout << "  Book ID: " << ID_book << "\n";
    cout << "  Buyer ID: " << ID_buyer << "\n";
    cout << "  Price:" << price << "\n";
    cout << "  Created At: " << ctime(&created_at);
}

void storage::show_all_sales()
{
    if (sales.size())
    {
        for (buy_history &purchase : sales)
        {
            cout << purchase;
        }
    }
    else
    {
        cout << "no sales" << endl;
    }
}

void storage::show_sale_by_ID(int ID)
{
    // add checking user exixstence

    auto found_user = find_user_pointers(users, ID);
    if (found_user.has_value())
    {
        for (buy_history sale : sales)
        {
            if (sale.ID_buyer == ID)
            {
                cout << sale;
            }
        }
    }
}

void storage::delete_sale(int ID)
{
    auto found_sale = find(sales, ID);

    if (found_sale.has_value())
    {
        remove_elements_by_id(sales, ID);
    }
}

void storage::update_sale(int ID)
{
    auto found_sale = find(sales, ID);

    if (found_sale.has_value())
    {
        string ID_book_inp = "", ID_buyer_inp = "", price_inp = "";

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update ID_book  (" << found_sale.value().ID_book << ") : ";
        getline(cin >> ws, ID_book_inp);
        cout << "Update ID_buyer (" << found_sale.value().ID_buyer << ") : ";
        getline(cin, ID_buyer_inp);
        cout << "Update price (" << found_sale.value().price << ") : ";
        getline(cin, price_inp);
        cout << "-----------------------------------------------------" << endl;

        for (buy_history &sale : sales)
        {
            if (sale.ID == ID)
            {
                sale.ID_book = ID_book_inp.empty() ? found_sale->ID_book : stoi(ID_book_inp);
                sale.ID_buyer = ID_buyer_inp.empty() ? found_sale->ID_buyer : stoi(ID_buyer_inp);
                sale.price = price_inp.empty() ? found_sale->price : stof(price_inp);
                break;
            }
        }
    }
}

int storage::get_count_borrowed(int ID)
{
    int counter = 0;

    for (borrow_history &b : borrows)
    {
        if (b.ID_member == ID && !b.is_returned)
        {
            counter += 1;
        }
    }

    return counter;
}

void storage::borrow_book()
{
    int book_id, user_id;
    cout << "enter the book id: ";
    cin >> book_id;
    cout << "enter the member id: ";
    cin >> user_id;

    auto foundBook = find(books, book_id);
    // add checking existance of user
    auto found_user = find_user_pointers(users, user_id);
    if (found_user.has_value() && found_user.value()->role == "member" && check_member_active(found_user) == true && foundBook.has_value() && (foundBook.value().is_sellable == false) && foundBook.value().available_copies > 0 && get_count_borrowed(user_id) < 3)
    {
        for (book &book : books)
        {
            if (book.ID == book_id)
            {
                book.available_copies--;
                borrow_history bh(borrow_history::borrowed_id, user_id, book_id);
                borrows.push_back(bh);
                borrow_history::borrowed_id++;
                break;
            }
        }
    }
    else
    {
        // (!found_user.has_value() || found_user.value()->role != "member") ? cout << "No member with that ID" << endl : (!foundBook.has_value() ? cout << "The book isn't available" << endl : (foundBook.value().is_sellable ? cout << "Book not for borrow" << endl : (!check_member_active(found_user) ? cout << "Member not active" << endl : (foundBook.value().available_copies == 0 ? cout << "No available copies in stock" : cout << "Couldn't borrow already borrowed books without return" << endl))));

        if (!found_user.has_value() || found_user.value()->role != "member")
        {
            cout << "No member with that ID" << endl;
        }
        else
        {
            if (!foundBook.has_value())
            {
                cout << "The book isn't available" << endl;
            }
            else
            {
                if (foundBook.value().is_sellable)
                {
                    cout << "Book not for borrow" << endl;
                }
                else
                {
                    if (!check_member_active(found_user))
                    {
                        cout << "Member not active" << endl;
                    }
                    else
                    {
                        if (foundBook.value().available_copies == 0)
                        {
                            cout << "No available copies in stock" << endl;
                        }
                        else
                        {
                            cout << "Couldn't borrow already borrowed books without return" << endl;
                        }
                    }
                }
            }
        }
    }
}

void storage::show_all_user()
{
    if (!users.empty())
    {
        for (const auto &user : users)
        {
            user->output();
        }
    }
    else
    {
        cout << "no users been registered";
    }
}

// void borrow_history::show_borrow(){
//     cout << ID << endl;
//     cout << ID_member<< endl;
//     cout << ID_book<< endl;
//     cout << ctime(&borrow_date)<< endl;
//     cout <<ctime(&return_date)<< endl;
//     is_returned ? cout << "not returned yet " : cout << "returned back"<< endl;

// }
void storage::show_all_borrowed()
{
    if (!borrows.empty())
    {
        for (borrow_history &b : borrows)
        {
            // b.show_borrow();
            cout << b;
        }
    }
    else
    {
        cout << "no users been registered";
    }
}

void storage::update_user(int ID)
{
    auto found_user = find_user_pointers(users, ID);
    if (found_user.has_value())
    {
        string full_name_inp, email_inp, phone_inp;
        bool is_active_inp;

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update full name  (" << found_user.value()->full_name << ") : ";
        getline(cin, full_name_inp);
        cout << "Update email (" << found_user.value()->email << ") : ";
        cin >> email_inp;
        cout << "Update phone (" << found_user.value()->phone << ") : ";
        cin >> phone_inp;

        if (found_user.value()->role == "member")
        {
            cout << "Update the is active value (1 for true et 0 for false): ";
            cin >> is_active_inp;
        }

        for (auto &&u : users)
        {
            if (u->ID == ID)
            {
                u->full_name = full_name_inp.empty() ? u->full_name : full_name_inp;
                u->email = email_inp.empty() ? u->email : email_inp;
                u->phone = phone_inp.empty() ? u->phone : phone_inp;
                //    found_user.value()->role=="member" ?  update_member_active(found_user,is_active_inp): void(0);
                if (found_user.value()->role == "member")
                {
                    is_active_inp == 1 ? true : false;
                    update_member_active(found_user, is_active_inp);
                }
            }
        }

        cout << "-----------------------------------------------------" << endl;
    }
    else
    {
        cout << "No user with the given ID" << endl;
    }
}

void storage::check_to_change_is_active()
{
    while (true)
    {
        if (subs_history.size() > 0)
        {
            for (subscription_history &sub : subs_history)
            {

                if (sub.is_expired())
                {
                    cout << "The subscription of the member with the ID" << sub.ID_member << " has expired." << endl;
                    //    call update member

                    auto found_member = find_user_pointers(users, sub.ID_member);

                    bool is_active_getter = check_member_active(found_member);

                    update_member_active(found_member, is_active_getter);
                }
                else
                {
                    cout << "The subscription is active." << endl;
                }
            }
        }
        // Delay for 24 hours (86400 seconds)
        this_thread::sleep_for(chrono::hours(24));
    }
}

void storage::add_subscription()
{
    subscription s;

    string name, desc;
    do
    {
        cout << "Enter a subscription name: ";
        getline(cin, name);
        s.name = name;
    } while (name.empty());

    while (true)
    {
        cout << "Enter the subscription price : ";
        string price_input;
        cin >> price_input;

        if (regex_match(price_input, regex("[+-]?([0-9]*[.])?[0-9]+")))
        {
            s.price = stof(price_input);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid Price" << endl;
            cin.clear();
        }
    }
    cin.ignore();

    do
    {
        cout << "Enter a subscription description: ";
        getline(cin, desc);
        s.description = desc;
    } while (desc.empty());

    s.ID = subscription::subsc_ids;
    subscription::subsc_ids++;
    subs.push_back(s);
    cout << endl;
}

void storage::show_all_subs()
{
    if (!subs.empty())
    {
        for (subscription &sub : subs)
        {
            cout << sub << endl;
        }
    }
    else
    {
        cout << "no sub has been added" << endl;
    }
}

void storage::add_subscription_record(int member_id)
{
    int sub_id;
    subscription_history sh;
    cout << "Choose the subscription id: ";
    cin >> sub_id;
    auto found_sub = find(subs, sub_id);

    if (found_sub.has_value())
    {
        sh.ID = subscription_history::subs_history_id;
        sh.ID_member = member_id;
        sh.ID_subscription = sub_id;
        subs_history.push_back(sh);
        subscription_history::subs_history_id++;
    }
    else
    {
        cout << "Invalid subscription id." << endl;
    }
}

void storage::show_sub_history(int ID)
{
    auto found_sub = find(subs_history, ID);
    if (found_sub.has_value())
    {
        cout << found_sub.value() << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
void storage::show_all_sub_history()
{
    for (subscription_history sh : subs_history)
    {
        cout << sh;
    }
}

void storage::renew_subscription(int ID)
{
    auto found_member = find_user_pointers(users, ID);
    if (found_member.has_value())
    {
        if (found_member.value()->role == "member" && check_member_active(found_member) == false)
        {
            update_member_active(found_member, false);
            add_subscription_record(ID);
            cout << "Member subscription renewed successfully" << endl;
        }
        else
        {
            cout << "Member subscription hasn't ended yet." << endl;
        }
    }
    else
    {
        cout << "Member with the given id not found." << endl;
    }
}