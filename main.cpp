#include "methods/book.cpp"
#include "methods/buy_history.cpp"
#include "methods/subscription.cpp"
#include "methods/user.cpp"
#include "methods/storage.cpp"

int main()
{
    storage storage_instance;

    book b1(1, "title 1", "auth 1", 4, false, 12),
        b2(2, "title 2", "auth 2", 1, true, 15.7),
        b3(3, "title 3", "auth 1", 4, true, 18.9),
        b4(4, "title 4", "auth 2", 0, true, 18.9);

    buyer bu(1, "sifeddineedr", " @ ", "0934", "buyer");
    member m1(2, "meryem", "yunogasai@gmail.com", "2345","member", true);
    member m2(3, "sifeddine", "yi@gmail.com", "45", "member", false);

    storage_instance.add_book(b1);
    storage_instance.add_book(b3);
    storage_instance.add_book(b2);
    storage_instance.add_book(b4);

    int b=storage_instance.add_new_user_row(m1);
    int h=storage_instance.add_new_user_row(m2);

    // storage_instance.show_all_user();
    // storage_instance.search();

    // storage_instance.show_book(1);
    storage_instance.buy_book();
    // storage_instance.show_all_sales();
    // storage_instance.show_book(1);

    // storage_instance.show_all_sales();
    // storage_instance.show_sale_by_ID(1);
    // storage_instance.update_sale(1);
    // storage_instance.show_all_sales();
    // storage_instance.delete_sale(1);
    // storage_instance.show_all_sales();
    // storage_instance.show_all_user();
    storage_instance.show_all_sales();
    storage_instance.buy_book();
    storage_instance.show_all_sales();
    storage_instance.buy_book();
    storage_instance.show_all_sales();

    return 0;
}