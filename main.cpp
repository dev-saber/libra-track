#include "methods.cpp"
using namespace std;

int main()
{

    storage storage_instance;

    int choice;
    // do {
    //     cout << "===== Menu =====" << endl;
    //     cout << "===== Book Management =====" << endl;
    //     cout << "1. Add Book" << endl;
    //     cout << "2. Show All Books" << endl;
    //     cout << "3. Update Book" << endl;
    //     cout << "4. Delete Book" << endl;
    //     cout << "===== Subscription Management =====" << endl;
    //     cout << "5. Add Subscription" << endl;
    //     cout << "6. Show All Subscriptions" << endl;
    //     cout << "7. Update Subscription" << endl;
    //     cout << "8. Delete Subscription" << endl;
    //     cout << "0. Exit" << endl;
    //     cout << "Enter your choice: ";
    //     cin >> choice;
    //     cin.ignore();

    //     switch (choice) {
    //         case 1:
    //             storage_instance.add_book();
    //             break;
    //         case 2:
    //             storage_instance.all_books();
    //             break;
    //         case 3:
    //             int updateBookID;
    //             cout << "Enter the ID of the book to update: ";
    //             cin >> updateBookID;
    //             storage_instance.update_book(updateBookID);
    //             break;
    //         case 4:
    //             int deleteBookID;
    //             cout << "Enter the ID of the book to delete: ";
    //             cin >> deleteBookID;
    //             storage_instance.delete_book(deleteBookID);
    //             break;
    //         case 5:
    //             storage_instance.add_sub();
    //             break;
    //         case 6:
    //             storage_instance.all_subs();
    //             break;
    //         case 7:
    //             int updateSubID;
    //             cout << "Enter the ID of the subscription to update: ";
    //             cin >> updateSubID;
    //             storage_instance.update_sub(updateSubID);
    //             break;
    //         case 8:
    //             int deleteSubID;
    //             cout << "Enter the ID of the subscription to delete: ";
    //             cin >> deleteSubID;
    //             storage_instance.delete_sub(deleteSubID);
    //             break;
    //         case 0:
    //             cout << "Exiting the program. Goodbye!" << endl;
    //             break;
    //         default:
    //             cout << "Invalid choice. Please try again." << endl;
    //     }
    // } while (choice != 0);

    book b1(1, "title 1", "auth 1", 4, false),
        b2(2, "title 2", "auth 2", 90, true),
        b3(3, "title 3", "auth 1", 4, true);

    storage_instance.add_book(b1);
    storage_instance.add_book(b3);
    storage_instance.add_book(b2);

    storage_instance.search();

    return 0;
}