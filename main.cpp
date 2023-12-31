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
    
    storage_instance.add_subscription();
    storage_instance.add_subscription();

    book b1(1, "title 1", "auth 1", 4, false, 12),
        b2(2, "title 2", "auth 2", 1, true, 15.7),
        b3(3, "title 3", "auth 1", 1, false, 18.9),
        b4(4, "title 4", "auth 2", 0, false, 18.9);

    // buyer bu(1, "sifeddineedr", " @ ", "0934", "buyer");
    // member m1(2, "meryem", "yunogasai@gmail.com", "2345", "member", true);
    // member m2(3, "sifeddine", "yi@gmail.com", "45", "member", true);

    storage_instance.add_book(b1);
    storage_instance.add_book(b2);
    storage_instance.add_book(b4);
    storage_instance.add_book(b3);


    user u1=storage_instance.add_user();
    storage_instance.add_new_user_row(u1);
    // storage_instance.add_new_user_row(m1);
    // storage_instance.add_new_user_row(m2);



    // storage_instance.add_subscription();
    // storage_instance.add_subscription();
    // storage_instance.delete_sub(1);
    // storage_instance.delete_sub(199);

    // storage_instance.show_all_subs();
    
    storage_instance.show_all_sub_history();
    return 0;
}