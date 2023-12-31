#include "methods/book.cpp"
#include "methods/buy_history.cpp"
#include "methods/borrow_history.cpp"
#include "methods/subscription.cpp"
#include "methods/subscription_history.cpp"
#include "methods/user.cpp"
#include "methods/storage.cpp"
#include <thread>
int main()
{
    storage storage_instance;

    book b1(1, "title 1", "auth 1", 4, false, 12),
        b2(2, "title 2", "auth 2", 1, true, 15.7),
        b3(3, "title 3", "auth 1", 1, false, 18.9),
        b4(4, "title 4", "auth 2", 0, false, 18.9);

    buyer bu(1, "sifeddineedr", " @ ", "0934", "buyer");
    member m1(2, "meryem", "yunogasai@gmail.com", "2345", "member", true);
    member m2(3, "sifeddine", "yi@gmail.com", "45", "member", false);

    // storage_instance.add_book(b1);
    // storage_instance.add_book(b3);
    storage_instance.add_book();
    storage_instance.add_book();

    storage_instance.all_books();

    // storage_instance.add_new_user_row(bu);
    // storage_instance.add_new_user_row(m1);
    // storage_instance.add_new_user_row(m2);

    // storage_instance.show_all_user();
    // storage_instance.search();

    // storage_instance.show_book(1);
    // storage_instance.buy_book();
    // storage_instance.show_all_sales();
    storage_instance.show_book(1);

    // storage_instance.show_all_sales();
    // storage_instance.show_sale_by_ID(1);
    // storage_instance.update_sale(1);
    // storage_instance.show_all_sales();
    // storage_instance.delete_sale(1);
    // storage_instance.show_all_sales();
    // storage_instance.show_all_user();
    // storage_instance.show_all_sales();
    // storage_instance.buy_book();
    // storage_instance.show_all_sales();
    // storage_instance.buy_book();
    // storage_instance.show_all_sales();
    // borrow_history br(1, 2,3);
    // cout << br;
    // br.show_borrow();

    // storage_instance.show_all_borrowed();
    // storage_instance.borrow_book();
    // storage_instance.show_all_borrowed();
    // storage_instance.borrow_book();
    // storage_instance.show_all_borrowed();
    // storage_instance.borrow_book();

    // storage_instance.update_user(4);
    // storage_instance.show_all_user();
    // storage_instance.update_user(2);
    // storage_instance.show_all_user();
    // storage_instance.update_user(3);
    // storage_instance.show_all_user();
    // cout << br;

    

    return 0;
}