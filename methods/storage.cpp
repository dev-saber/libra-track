#include "../classes/storage.h"
#include "utils.cpp"

int storage::id_generator = 1;
int storage::ids_subs = 1;
int buy_history::ids_sales = 1;

void storage::add_book(book &b)
{
    books.push_back(b);
}

void storage::add_book()
{
    book b;
    string bool_input;

    cout << "Enter a title book : ";
    getline(cin >> ws, b.title);
    cout << "Enter the book's author : ";
    getline(cin, b.author);
    cout << "How many available copies : ";
    cin >> b.available_copies;
    cout << "Enter Price of the Book : ";
    cin >> b.price;

    do
    {
        cout << "Is the book sellable (yes / no) : ";
        cin >> bool_input;
        cin.ignore();
    } while (bool_input != "yes" && bool_input != "no");

    b.is_sellable = "yes" ? true : false;
    b.ID = id_generator;

    books.push_back(b);
    id_generator++;

    // add later an if statement wether we add a new book or not (the fct calls itself)
}

void storage::show_book(int ID)
{

    auto foundBook1 = find(books, ID);
    if (foundBook1.has_value())
    {
        cout << foundBook1.value() << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void storage::all_books()
{
    cout << "=== All Books in Storage ===\n";

    if (books.empty())
    {
        cout << "No books found in the storage.\n";
    }
    else
    {
        for (book &b : books)
        {
            cout << b << "\n \n";
        }
    }

    cout << "===========================\n";
}

void storage::update_book(int ID)
{
    this->show_book(ID);
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
        cout << "Update available copies ( " << found_book.value().available_copies << ") : ";
        getline(cin, a_copies_inp);
        cout << "Change book status ( from " << check_Item_status(found_book.value().is_sellable) << " to " << check_Item_status(!found_book.value().is_sellable) << ")   (yes/no): ";
        getline(cin, is_sellable_inp);
        cout << "-----------------------------------------------------" << endl;

        for (book &book : books)
        {
            if (book.ID == ID)
            {
                book.title = title_inp.empty() ? found_book->title : title_inp;
                book.author = author_inp.empty() ? found_book->author : author_inp;
                book.available_copies = a_copies_inp.empty() ? found_book->available_copies : stoi(a_copies_inp);
                book.price = price_inp.empty() ? found_book->price : stoi(price_inp);
                bool check = is_sellable_inp == "yes" ? !found_book->is_sellable : found_book->is_sellable;
                book.is_sellable = is_sellable_inp.empty() ? found_book->is_sellable : check;

                break;
            }
        }

        this->show_book(ID);
    }
}

void storage::delete_book(int ID)
{
    auto found_book = find(books, ID);

    if (found_book.has_value())
    {

        remove_elements_by_id(books, ID);
        cout << "Book removed successfully" << endl;
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

void storage::add_sub(subscription &s)
{
    subs.push_back(s);
}

void storage::add_sub()
{
    subscription s;
    s.ID = ids_subs;

    cout << "Enter the subscription name : ";
    getline(cin >> ws, s.name);
    cout << "Enter the subscription price : ";
    cin >> s.price;
    cout << "Subscription description: ";
    getline(cin >> ws, s.description);

    ids_subs++;

    subs.push_back(s);
}

void storage::all_subs()
{
    cout << "=== All subscriptions in Storage ===\n";

    if (subs.empty())
    {
        cout << "No subscription found in the storage.\n";
    }
    else
    {
        for (subscription &s : subs)
        {
            cout << s << "\n \n";
        }
    }

    cout << "===========================\n";
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
        cout << "Update description ( " << found_sub.value().description << ") : ";
        getline(cin, desc_inp);
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
        cout << "Subscription removed successfully" << endl;
    }
}

void storage::buy_book()
{
    int book_id, user_id;
    cout << "enter the book id: ";
    cin >> book_id;
    cout << "enter the user id: ";
    cin >> user_id;

    auto foundBook = find(books, book_id);
    // add checking existance of user

    if (foundBook.has_value() && (foundBook.value().is_sellable == true))
    {
        for (book &book : books)
        {
            if (book.ID == book_id)
            {
                book.available_copies--;
                buy_history bh(buy_history::ids_sales, book_id ,user_id, book.price);
                sales.push_back(bh);
                buy_history::ids_sales++;
                break;
            }
        }
    }
    else
    {
        cout << "the book with the is either not available or not for sale" << endl;
    }
}

void buy_history::show_sale(){
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
            // cout << "Purchase Info:\n";
            // cout << "  Book ID: " << purchase.ID_book << "\n";
            // cout << "  Buyer ID: " << purchase.ID_buyer << "\n";
            // cout << "  Price:" << purchase.price << "\n";
            // cout << "  Created At: " << ctime(&purchase.created_at);
            purchase.show_sale();
            // cout << purchase;
        }
    }
    else
    {
        cout << "no sales" << endl;
    }
}

void storage::show_sale_by_ID(int ID){
    // add checking user exixstence
for (buy_history sale : sales)
{
    if (sale.ID_buyer==ID)
    {
        // cout << sale << endl;
        sale.show_sale();
    }
    
}

}

void storage::delete_sale(int ID){
    auto found_sale = find(sales, ID);

    if (found_sale.has_value())
    {
        remove_elements_by_id(sales, ID);
        cout << "sale removed successfully" << endl;
    }
}

void storage::update_sale(int ID){
    auto found_sale = find(sales, ID);

    if (found_sale.has_value())
    {
        string ID_book_inp="", ID_buyer_inp="", price_inp="";

        cout << "Press enter to keep the current value unchanged." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Update ID_book  (" << found_sale.value().ID_book << ") : ";
        getline(cin >> ws, ID_book_inp);
        cout << "Update ID_buyer (" << found_sale.value().ID_buyer << ") : ";
        getline(cin , ID_buyer_inp);
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

