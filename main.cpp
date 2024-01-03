#include "methods/book.cpp"
#include "methods/buy_history.cpp"
#include "methods/borrow_history.cpp"
#include "methods/subscription.cpp"
#include "methods/subscription_history.cpp"
#include "methods/user.cpp"
#include "methods/storage.cpp"
#include <thread>
#include <stdexcept>

int main()
{
    admin a;
    a.login();
    storage storage_instance;
    user u;

    int choice;

    do
    {
        cout << "===== Menu =====" << endl;
    // Book management
    cout << "===== Book Management =====" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Show All Books" << endl;
    cout << "3. Update Book" << endl;
    cout << "4. Delete Book" << endl;
    cout << "5. Show Book" << endl;
    cout << "6. Search Book" << endl;
    // Subscription management
    cout << "===== Subscription Management =====" << endl;
    cout << "7. Add Subscription" << endl;
    cout << "8. Show All Subscriptions" << endl;
    cout << "9. Update Subscription" << endl;
    cout << "10. Delete Subscription" << endl;
    cout << "11. Show Subscription History" << endl;
    // User management
    cout << "===== User Management =====" << endl;
    cout << "12. Add User" << endl;
    cout << "13. Show All Users" << endl;
    cout << "14. Update User" << endl;
    cout << "15. Show User" << endl;
    // Borrow management
    cout << "===== Borrow Management =====" << endl;
    cout << "16. Add a Borrow" << endl;
    cout << "17. Show Current Borrow Count of a User" << endl;
    cout << "18. Show All Borrows" << endl;
    cout << "19. Return a Borrow" << endl;
    // Sale management
    cout << "===== Sale Management =====" << endl;
    cout << "20. Buy a Book" << endl;
    cout << "21. Show All Sales" << endl;
    cout << "22. Show Sale by ID" << endl;
    cout << "23. Delete Sale" << endl;
    cout << "24. Update Sale" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

        switch (choice)
        {
        case 1:
            storage_instance.add_book();
            break;
        case 2:
            storage_instance.all_books();
            break;
        case 3:
            int update_book_id;
            cout << "Enter the ID of the book to update: ";
            cin >> update_book_id;
            storage_instance.update_book(update_book_id);
            break;
        case 4:
            int delete_book_id;
            cout << "Enter the ID of the book to delete: ";
            cin >> delete_book_id;
            storage_instance.delete_book(delete_book_id);
            break;
        case 5:
            cout << "Search Book By characters: ";
            storage_instance.search();
            break;
        case 6:
            int show_book_id;
            cout << "Enter the ID of the book to be shown: ";
            cin >> show_book_id;
            storage_instance.show_book(show_book_id);
            break;
        case 7:
            storage_instance.add_sub();
            break;
        case 8:
            storage_instance.show_all_subs();
            break;
        case 9:
            int update_sub_id;
            cout << "Enter the ID of the subscription to update: ";
            cin >> update_sub_id;
            storage_instance.update_sub(update_sub_id);
            break;
        case 10:
            int show_sub_id;
            cout << "Enter the ID of the subscription to show: ";
            cin >> show_sub_id;
            storage_instance.show_sub(show_sub_id);
            break;
        case 11:
            int delete_sub_id;
            cout << "Enter the ID of the subscription to delete: ";
            cin >> delete_sub_id;
            storage_instance.delete_sub(delete_sub_id);
            break;
        case 12:

            u = storage_instance.add_user();
            storage_instance.add_new_user_row(u);

            break;
        case 13:
            storage_instance.show_all_user();
            break;
        case 14:
            int show_user_id;
            cout << "Enter the ID of the user to be shown: ";
            cin >> show_user_id;
            storage_instance.show_user(show_user_id);
            break;
        case 15:
            int update_user_id;
            cout << "Enter the ID of the user to be updaten: ";
            cin >> update_user_id;
            storage_instance.update_user(update_user_id);
            break;

        case 16:
            int member_inp_1;
            cout << "Enter the member id: ";
            cin >> member_inp_1;
            storage_instance.add_subscription_record(member_inp_1);
            break;
        case 17:
            storage_instance.show_all_sub_history();
            break;
        case 18:
            int member_inp_2;
            cout << "Enter the member id: ";
            cin >> member_inp_2;
            storage_instance.show_sub_history(member_inp_2);
            break;
        case 19:
            int member_inp_3;
            cout << "Enter the member id: ";
            cin >> member_inp_3;
            storage_instance.renew_subscription(member_inp_3);
            break;
        case 20:
            int sub_his_id;
            cout << "Enter the subscription id: ";
            cin >> sub_his_id;
            storage_instance.update_sub_history(sub_his_id);
            break;
        case 21:
            storage_instance.buy_book();
            break;
        case 22:
            storage_instance.show_all_sales();
            break;
        case 23:
            int show_sale_id;
            cout << "Enter the ID of the sales to show: ";
            cin >> show_sale_id;
            storage_instance.show_sale_by_ID(show_sale_id);
            break;
        case 24:
            int delete_sale_id;
            cout << "Enter the ID of the sales to delete: ";
            cin >> delete_sale_id;
            storage_instance.delete_sale(delete_sale_id);
            break;
        case 25:
            int update_sale_id;
            cout << "Enter the ID of the sales to update: ";
            cin >> update_sale_id;
            storage_instance.update_user(update_sale_id);
            break;
        case 26:
            storage_instance.borrow_book();
            break;
        case 27:
           
            storage_instance.show_all_borrowed();
            break;
        case 28:
            int member_id;
            cout << "Enter the ID of the  member: ";
            cin >> member_id;
            storage_instance.get_count_borrowed(member_id);
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            a.logout();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    storage_instance.check_to_change_is_active();

    return 0;
}