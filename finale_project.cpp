// النسخه3 مشروع برمجه2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StudentOperation.h"


int main()
{
    download_student();
    int choice = 0;
    bool exit = false;
    clearscrean();

    while (!exit) {
        cout << "=======================================" << endl;
        cout << "===Students Management System [SMS]====" << endl;
        cout << "=======================================" << endl;
        cout << "Please choose an option:\n";
        cout << "1) Add a new Student Record.\n";
        cout << "2) Edit a Student Record.\n";
        cout << "3) Delete a Student Record.\n";
        cout << "4) Search for a Student Record.\n";
        cout << "5) Display All of the Students Records.\n";
        cout << "6) Exit.\n";
        cout << ">>>>>>>>>>>>>>>>>>>>>>>> ";
        do
        {

            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice, please enter again: ";
            }
            else if (choice < 1 || choice  > 6)
            {
                cout << "Invalid choice. Please enter a number between " << 1 << " and " << 6 << "." << endl;
            }
        } while (choice < 1 || choice > 6);



        cout << "============================================================" << endl;
        switch (choice) {
        case 1:

            clearscrean();

            addStudent();
            break;
        case 2:

            clearscrean();

            editStudent();
            break;
        case 3:

            clearscrean();

            deleteStudent();
            break;
        case 4:

            clearscrean();

            searchStudent();
            break;
        case 5:

            clearscrean();

            displayStudent();
            break;
        case 6:
            exit = true;
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
