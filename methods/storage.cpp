#include "../classes/storage.h"
#include "utils.cpp"
#include <algorithm>
#include <thread>

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

    b.is_sellable = bool_input == "yes" ? true : false;
    b.ID = book::book_id;
    books.push_back(b);
    book::book_id++;
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    }
}

void storage::search()
{
    string author, title, is_sellable_inp, is_sellable;
    bool query_condition = true;

    do
    {
        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter the title : ";
        getline(cin, title);
        cout << "Enter the author : ";
        getline(cin, author);
        cout << "Is the book for sell (yes/no) : ";
        getline(cin, is_sellable_inp);

        title = title.empty() ? "" : title;
        author = author.empty() ? "" : author;

    } while (author == "" && title == "");
    bool found = false;

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
            cout << "================ Books Found ================" << endl;
            cout << book << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No books match the given criteria." << endl;
    }
}

void storage::show_sub(int ID)
{
    cout << "=========================== Subscription Details ===========================\n";
    auto found_sub = find(subs, ID);
    if (found_sub.has_value())
    {
        cout << "------------------- Subscription " << ID << "----------------------\n";
        cout << found_sub.value() << endl;
    }
    else
    {
        cout << "No subscription found with ID " << ID << ".\n";
    }
    cout << "=========================== End of Subscription Details =====================\n";
}

void storage::update_sub(int ID)
{
    auto found_sub = find(subs, ID);

    if (found_sub.has_value())
    {
        string name_inp, desc_inp, price_inp;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update subscription name  (" << found_sub.value().name << ") : ";
        getline(cin, name_inp);

        cout << "Update subscription price (" << found_sub.value().price << ") : ";
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

        cout << "Update subscription description (" << found_sub.value().description << ") : ";
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
        cout << "Subscription with ID " << ID << " updated successfully." << endl;
    }
    else
    {
        cout << "Subscription with ID " << ID << " not found." << endl;
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
    string full_name_inp, mail_inp, phone_inp, role_inp;
    const regex email_regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    const regex phone_regex("^\\d{10}$");

    cout << "Enter the full name: ";
    getline(cin, full_name_inp);

    while (true)
    {
        cout << "Enter the email: ";
        getline(cin, mail_inp);

        if (!mail_inp.empty() && !regex_match(mail_inp, email_regex))
        {
            cout << "Invalid email address. Please enter a valid email." << endl;
            continue;
        }
        break;
    }

    while (true)
    {
        cout << "Enter the phone number (press Enter to skip): ";
        getline(cin, phone_inp);

        if (!phone_inp.empty() && !regex_match(phone_inp, phone_regex))
        {
            cout << "Invalid phone number. Please enter a valid number." << endl;
            continue;
        }
        break;
    }

    if (r == "")
    {
        do
        {
            cout << "Role user (1 for member - 0 for buyer): ";
            getline(cin, role_inp);

            if (role_inp.empty())
            {
                cout << "Role cannot be empty. Please enter a valid role." << endl;
            }
            else
            {
                if (role_inp != "0" && role_inp != "1")
                {
                    cout << "Invalid role. Please enter either 1 for member or 0 for buyer." << endl;
                }
            }

        } while (role_inp.empty() || (role_inp != "0" && role_inp != "1"));
        r = (role_inp == "1") ? "member" : "buyer";
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // try removing it
    return user::user_id - 1;
}

void storage::buy_book()
{
    int book_id, user_id, role_inp, quantity_inp;
    bool is_active_bool = true;
    while (true)
    {
        cout << "Enter the role (member 1 - buyer 0): ";
        if (cin.peek() == '\n')
        {
            cout << "Invalid input. Role cannot be empty." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (!(cin >> role_inp))
        {
            cout << "Invalid input. Please enter a valid integer for role." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {

            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (role_inp == 1)
    {
        bool is_found = true;
        do
        {
            cout << "Enter the member ID: ";

            if (cin.peek() == '\n')
            {
                cout << "Invalid input. Member ID cannot be empty." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                is_found = false; // Set flag to false to repeat the loop
            }
            else if (!(cin >> user_id))
            {
                cout << "Invalid input. Please enter a valid integer for member ID." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                is_found = false; // Set flag to false to repeat the loop
            }
            else
            {
                // Clear any remaining characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                auto found_member = find_user_pointers(users, user_id);

                if (!found_member.has_value())
                {
                    is_found = false;
                }
                else
                {
                    is_active_bool = check_member_active(found_member);
                }
            }
        } while (!is_found);
    }
    else
    {
        user user_instance;
        user_instance = add_user("buyer");
        user_id = add_new_user_row(user_instance);
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true)
    {
        cout << "Enter the book ID: ";
        if (cin.peek() == '\n')
        {
            cout << "Invalid input. Book ID cannot be empty." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (!(cin >> book_id))
        {
            cout << "Invalid input. Please enter a valid integer for book ID." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    auto foundBook = find(books, book_id);

    if (foundBook.has_value() && (foundBook.value().is_sellable == true) && (foundBook.value().available_copies > 0) && is_active_bool)
    {
        do
        {
            cout << "Enter the quantity: ";
            if (!(cin >> quantity_inp) || quantity_inp <= 0 || quantity_inp > foundBook.value().available_copies)
            {
                cout << "Invalid input. Please enter a valid quantity." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (quantity_inp > foundBook.value().available_copies || quantity_inp <= 0);

        for (book &book : books)
        {
            if (book.ID == book_id)
            {
                book.available_copies -= quantity_inp;
                buy_history bh(book_id, user_id, book.price, quantity_inp);
                sales.push_back(bh);
                buy_history::sale_id++;

                cout << "New row has been added to sales." << endl;
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
    if (!sales.empty())
    {
        cout << "---------- Sales History ----------" << endl;
        for (const buy_history &purchase : sales)
        {
            cout << purchase;
            cout << "-----------------------------------" << endl;
        }
    }
    else
    {
        cout << "No sales recorded yet." << endl;
    }
}

void storage::show_sale_by_ID(int ID)
{
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

// void storage::update_sale(int ID)
// {
//     auto found_sale = find(sales, ID);

//     if (found_sale.has_value())
//     {
//         string ID_book_inp = "", ID_buyer_inp = "", price_inp = "", quantity_inp = "0";
//         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//         cout << "Press enter to keep the current value unchanged." << endl;
//         cout << "-----------------------------------------------------" << endl;
//         cout << "Update ID_book  (" << found_sale.value().ID_book << ") : ";
//         getline(cin >> ws, ID_book_inp);
//         cout << "Update ID_buyer (" << found_sale.value().ID_buyer << ") : ";
//         getline(cin, ID_buyer_inp);
//         cout << "Update price (" << found_sale.value().price << ") : ";
//         getline(cin, price_inp);
//         cout << "Update quantity (" << found_sale.value().quantity << ") : ";
//         getline(cin, quantity_inp);
//         cout << "-----------------------------------------------------" << endl;

//         if (!ID_book_inp.empty())
//         {
//             for (book &b : books)
//             {
//                 if (b.ID == found_sale.value().ID_book)
//                 {
//                     b.available_copies += found_sale.value().quantity;
//                     break;
//                 }

//             }

//         }

//         for (buy_history &sale : sales)
//         {
//             if (sale.ID == ID)
//             {
//                 // ID_book_inp.empty() ? sale.
//                 sale.ID_book = ID_book_inp.empty() ? found_sale->ID_book : stoi(ID_book_inp);
//                 sale.ID_buyer = ID_buyer_inp.empty() ? found_sale->ID_buyer : stoi(ID_buyer_inp);
//                 sale.price = price_inp.empty() ? found_sale->price : stof(price_inp);
//                 sale.quantity += quantity_inp.empty() ? found_sale->quantity : stof(quantity_inp);
//                 break;
//             }
//         }
//     }
// }

void storage::update_sale(int ID)
{
    auto found_sale = find(sales, ID);

    if (found_sale.has_value())
    {
        string ID_book_inp = "", ID_buyer_inp = "", price_inp = "", quantity_inp = "0";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;

        bool invalidInput = false;

        // Update ID_book
        do
        {
            if (invalidInput)
            {
                cout << "Invalid input. Please re-enter: ";
            }

            cout << "Update ID_book  (" << found_sale.value().ID_book << ") : ";
            getline(cin >> ws, ID_book_inp);

            invalidInput = false;

            if (!ID_book_inp.empty() && !regex_match(ID_book_inp, regex("\\d+")))
            {
                cout << "Invalid input. Please enter a valid integer for ID_book.";
                invalidInput = true;
            }
            else if (!ID_book_inp.empty() && !find(books, stoi(ID_book_inp)).has_value())
            {
                cout << "Book with ID " << ID_book_inp << " does not exist.";
                invalidInput = true;
            }
        } while (!ID_book_inp.empty() && invalidInput);

        // Update ID_buyer
        invalidInput = false;
        do
        {
            if (invalidInput)
            {
                cout << "Invalid input. Please re-enter: ";
            }

            cout << "Update ID_buyer (" << found_sale.value().ID_buyer << ") : ";
            getline(cin >> ws, ID_buyer_inp);

            invalidInput = false;

            if (!ID_buyer_inp.empty() && !regex_match(ID_buyer_inp, regex("\\d+")))
            {
                cout << "Invalid input. Please enter a valid integer for ID_buyer.";
                invalidInput = true;
            }
            else if (!ID_buyer_inp.empty() && !find_user_pointers(users, stoi(ID_buyer_inp)).has_value())
            {
                cout << "Buyer with ID " << ID_buyer_inp << " does not exist.";
                invalidInput = true;
            }
        } while (!ID_buyer_inp.empty() && invalidInput);

        // Update price (you have a duplicated line here, fix it)
        invalidInput = false;
        do
        {
            if (invalidInput)
            {
                cout << "Invalid input. Please re-enter: ";
            }

            cout << "Update price (" << found_sale.value().price << ") : ";
            getline(cin, price_inp);

            invalidInput = false;

            if (!price_inp.empty() && !regex_match(price_inp, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                cout << "Invalid input. Please enter a valid float for price.";
                invalidInput = true;
            }
        } while (!price_inp.empty() && invalidInput);

        // Update quantity (you have a duplicated line here, fix it)
        invalidInput = false;
        do
        {
            if (invalidInput)
            {
                cout << "Invalid input. Please re-enter: ";
            }

            cout << "Update quantity (" << found_sale.value().quantity << ") : ";
            getline(cin, quantity_inp);

            invalidInput = false;

            if (!quantity_inp.empty() && !regex_match(quantity_inp, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                cout << "Invalid input. Please enter a valid float for quantity.";
                invalidInput = true;
            }
        } while (!quantity_inp.empty() && invalidInput);

        // If the user provided a new ID_book, adjust the corresponding book's available copies
        if (!ID_book_inp.empty())
        {
            for (book &b : books)
            {
                if (b.ID == found_sale.value().ID_book)
                {
                    b.available_copies += found_sale.value().quantity; // Increase old book's available copies
                    break;
                }
            }
        }

        // Update sale information
        for (buy_history &sale : sales)
        {
            if (sale.ID == ID)
            {
                // Update ID_book if provided, otherwise keep the current value
                sale.ID_book = ID_book_inp.empty() ? found_sale->ID_book : stoi(ID_book_inp);

                // Update ID_buyer if provided, otherwise keep the current value
                sale.ID_buyer = ID_buyer_inp.empty() ? found_sale->ID_buyer : stoi(ID_buyer_inp);

                // Update price if provided, otherwise keep the current value
                sale.price = price_inp.empty() ? found_sale->price : stof(price_inp);

                // Update quantity if provided, otherwise keep the current value
                sale.quantity = quantity_inp.empty() ? found_sale->quantity : stof(quantity_inp);

                // Decrease old book's available copies
                for (book &b : books)
                {
                    if (b.ID == found_sale.value().ID_book)
                    {
                        b.available_copies -= stof(quantity_inp);
                    }
                    // Increase new book's available copies
                    else if (b.ID == stoi(ID_book_inp))
                    {
                        b.available_copies += stof(quantity_inp);
                    }
                }

                break;
            }
        }
    }
}

int storage::get_count_borrowed(int ID, bool printOutput)
{
    int counter = 0;
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (printOutput)
    {
        cout << "===== Borrow History for Member ID " << ID << " =====" << endl;
    }

    for (borrow_history &b : borrows)
    {
        if (b.ID_member == ID && !b.is_returned)
        {
            if (printOutput)
            {
                cout << b << endl;
            }
            counter += 1;
        }
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return counter;
}

void storage::borrow_book()
{

    int book_id, user_id;

    while (true)
    {
        cout << "Enter the book ID: ";
        if (cin.peek() == '\n')
        {
            cout << "Invalid input. Book ID cannot be empty." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (!(cin >> book_id))
        {
            cout << "Invalid input. Please enter a valid integer for book ID." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character

    while (true)
    {
        cout << "Enter the member ID: ";
        if (cin.peek() == '\n')
        {
            cout << "Invalid input. Member ID cannot be empty." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (!(cin >> user_id) || user_id <= 0)
        {
            cout << "Invalid input. Please enter a valid positive integer for member ID." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
            break;
        }
    }

    auto foundBook = find(books, book_id);
    auto found_user = find_user_pointers(users, user_id);
    if (found_user.has_value() && found_user.value()->role == "member" && check_member_active(found_user) == true && foundBook.has_value() && (foundBook.value().is_sellable == false) && foundBook.value().available_copies > 0 && get_count_borrowed(user_id, false) < 3)
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
        cout << "========== All Users ==========" << endl;
        for (size_t i = 0; i < users.size(); ++i)
        {
            cout << "--------------------User " << (i + 1) << "------------------------" << endl;
            users[i]->output();
            cout << "-------------------------------" << endl;
        }
    }
    else
    {
        cout << "No users have been registered." << endl;
    }
}

void storage::show_all_borrowed()
{
    if (!borrows.empty())
    {
        cout << "---------- Borrowed Items History ----------" << endl;
        for (const borrow_history &b : borrows)
        {
            cout << b;
            cout << "-------------------------------------------" << endl;
        }
    }
    else
    {
        cout << "No items have been borrowed yet." << endl;
        cout << "Encourage users to explore and borrow items from your collection!" << endl;
    }
}

void storage::update_user(int ID)
{
    auto found_user = find_user_pointers(users, ID);
    if (found_user.has_value())
    {
        string full_name_inp, mail_inp, phone_inp, is_active_inp;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        const regex email_regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
        const regex phone_regex("^\\d{10}$");
        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update full name  (" << found_user.value()->full_name << ") : ";
        getline(cin, full_name_inp);
        while (true)
        {
            cout << "Update email (" << found_user.value()->email << ") : ";
            getline(cin, mail_inp);

            if (!mail_inp.empty() && !regex_match(mail_inp, email_regex))
            {
                cout << "Invalid email address. Please enter a valid email." << endl;
                continue;
            }
            break;
        }

        while (true)
        {
            cout << "Update phone number (" << found_user.value()->phone << ") : ";
            getline(cin, phone_inp);

            if (!phone_inp.empty() && !regex_match(phone_inp, phone_regex))
            {
                cout << "Invalid phone number. Please enter a valid number." << endl;
                continue;
            }
            break;
        }

        if (found_user.value()->role == "member")
        {
            while (true)
            {
                cout << "Update active status (1 for active and 0 for not active): ";
                getline(cin, is_active_inp);

                if (!is_active_inp.empty())
                {
                    if (is_active_inp == "1" || is_active_inp == "0")
                    {
                        break;
                    }
                    cout << "Invalid input. Please enter 1 for active or 0 for not active." << endl;
                }
                else
                {
                    break;
                }
            }
        }

        for (auto &&u : users)
        {
            if (u->ID == ID)
            {
                u->full_name = full_name_inp.empty() ? u->full_name : full_name_inp;
                u->email = mail_inp.empty() ? u->email : mail_inp;
                u->phone = phone_inp.empty() ? u->phone : phone_inp;

                if (found_user.value()->role == "member")
                {

                    bool is_active;
                    if (!is_active_inp.empty())
                    {
                        is_active = is_active_inp == "1" ? true : false;
                    }
                    else
                    {
                        is_active = check_member_active(found_user);
                    }

                    update_member_active(found_user, is_active);
                }
            }
        }
        cout << "User with ID " << ID << " has been updated successfully." << endl;

        cout << "-----------------------------------------------------" << endl;
    }
    else
    {
        cout << "No user with the given ID" << endl;
    }
}

void storage::check_to_change_is_active()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true)
    {
        if (subs_history.size() > 0)
        {
            for (subscription_history &sub : subs_history)
            {

                if (sub.is_expired())
                {
                    cout << "The subscription of the member with the ID" << sub.ID_member << " has expired." << endl;

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
        this_thread::sleep_for(chrono::hours(24));
    }
}

void storage::add_sub()
{
    subscription s;
    string name, desc;

    do
    {
        cout << "Enter a subscription name: ";
        getline(cin, name);

        if (name.empty())
        {
            cout << "Invalid input. Subscription name cannot be empty." << endl;
            continue;
        }

        s.name = name;
        break;
    } while (true);

    while (true)
    {
        cout << "Enter the subscription price: ";

        // Check if the next character is '\n' (empty input)
        if (cin.peek() == '\n')
        {
            cout << "Invalid input. Please enter a valid Price: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            string price_input;
            cin >> price_input;

            if (!regex_match(price_input, regex("[+-]?([0-9]*[.])?[0-9]+")))
            {
                cout << "Invalid input. Please enter a valid Price: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                s.price = stof(price_input);
                break;
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        cout << "Enter a subscription description: ";
        getline(cin, desc);

        if (desc.empty())
        {
            cout << "Invalid input. Subscription description cannot be empty." << endl;
            continue;
        }

        s.description = desc;
        break;
    } while (true);

    s.ID = subscription::subsc_ids;
    subscription::subsc_ids++;
    subs.push_back(s);
    cout << endl;
}

void storage::show_all_subs()
{
    if (!subs.empty())
    {
        cout << "================ Subscriptions List ================" << endl;
        for (int i = 0; i < subs.size(); ++i)
        {
            cout << "------------------- Subscription " << (i + 1) << "----------------------\n";

            cout << subs[i] << endl;
        }
        cout << "===================================================" << endl;
    }
    else
    {
        cout << "No subscriptions have been added yet." << endl;
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
    cout << "===========================\n";
    auto found_sub = find(subs_history, ID);
    if (found_sub.has_value())
    {
        cout << "------------------Subscription History Details------------------" << endl;
        cout << found_sub.value() << endl;
    }
    else
    {
        cout << "Subscription history not found for ID: " << ID << endl;
    }
    cout << "===========================\n";
}
void storage::show_all_sub_history()
{
    if (!subs_history.empty())
    {
        cout << "========== All Subscription History ==========" << endl;
        for (size_t i = 0; i < subs_history.size(); ++i)
        {
            cout << "-------------------Subscription " << i + 1 << "----------------------" << endl;
            cout << subs_history[i] << endl;
            cout << "-------------------------------" << endl;
        }
    }
    else
    {
        cout << "No subscription history available." << endl;
    }
}

void storage::renew_subscription(int ID)
{

    auto found_member = find_user_pointers(users, ID);
    if (found_member.has_value())
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

void storage::show_user(int ID)
{

    cout << "===========================" << endl;
    auto found_user = find_user_pointers(users, ID);
    if (found_user.has_value())
    {
        cout << "----------------User Information for ID " << ID << "-------------------------------:" << endl;
        found_user.value()->output();
        cout << "===========================" << endl;
    }
    else
    {
        cout << "User with ID " << ID << " not found." << endl;
        cout << "===========================" << endl;
    }
}

void storage::update_sub_history(int ID)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto found_record = find(subs_history, ID);
    if (found_record.has_value() && found_record.value().end_date >= time(0))
    {
        string member_inp, sub_inp;
        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update subscription category ID (" << found_record.value().ID_subscription << "): ";
        getline(cin, sub_inp);
        if (!sub_inp.empty())
        {
            auto found_sub = find(subs, stoi(sub_inp));
            while (!found_sub.has_value())
            {
                cout << "Invalid subscription ID, try again: ";
                getline(cin, sub_inp);
                found_sub = find(subs, stoi(sub_inp));
            }
        }
        cout << "Update subscription member ID (" << found_record.value().ID_member << "): ";
        getline(cin, member_inp);

        if (!member_inp.empty())
        {
            auto found_user = find_user_pointers(users, stoi(member_inp));
            while (!found_user.has_value() || found_user.value()->role != "member")
            {
                cout << "Invalid member ID, try again: ";
                getline(cin, member_inp);
                found_user = find_user_pointers(users, stoi(member_inp));
            }
        }

        for (subscription_history &sh : subs_history)
        {
            if (sh.ID == ID)
            {
                sh.ID_subscription = sub_inp.empty() ? sh.ID_subscription : stoi(sub_inp);
                sh.ID_member = member_inp.empty() ? sh.ID_member : stoi(member_inp);
            }
        }
        cout << "Subscription history updated successfully!" << endl;
    }
    else
    {
        cout << "No record with that given ID" << endl;
    }
}

void storage::return_a_borrow(int ID)
{
    auto found_borrow = find(borrows, ID);
    if (found_borrow.has_value())
    {
        for (borrow_history &b : borrows)
        {
            if (b.ID == ID)
            {
                b.is_returned = true;
                b.return_date = time(0);
            }
        }
        for (book &b : books)
        {
            if (b.ID == found_borrow.value().ID_book)
            {
                b.available_copies++;
            }
        }
    }
}
