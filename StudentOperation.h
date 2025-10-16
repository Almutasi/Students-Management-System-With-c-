#ifndef STUDENTOPERATION_H
#define STUDENTOPERATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <array>
#include <limits>

using namespace std;

struct Student {
    int id;
    string first_name;
    string last_name;
    string major;
    int level;
    int size = 6;
    int marks[6];
    int total_marks;
    float grade;
};


static const int N = 100;

static array<Student, N > student;

static fstream file;

static const int MIN_ID = 1;
static const int MAX_ID = 99999;

static const int set_width = 13;
static const int ID_WIDTH = 2;
static const int NAME_WIDTH = 20;
static const int MAJOR_WIDTH = 5;
static const int LEVEL_WIDTH = 5;
static const int MARK_WIDTH = 5;
static const int TOTAL_WIDTH = 6;
static const int GRADE_WIDTH = 8;




static void clearscrean() {
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}


static void download_student()
{
    string s, value;

    fstream file;
    file.open("student.txt", ios::in);
    int nav = 0;
    if (file.is_open()) {
        while (getline(file, s))
        {


            stringstream lindata(s);

            lindata >> value;

            student[nav].id = stoi(value);

            lindata >> value;
            student[nav].first_name = (value);
            lindata >> value;

            student[nav].last_name = (value);
            lindata >> value;
            student[nav].major = (value);
            lindata >> value;
            student[nav].level = stoi(value);
            for (int i = 0; i < 6; i++)
            {
                lindata >> value;
                student[nav].marks[i] = stoi(value);

            }
            lindata >> value;
            student[nav].total_marks = stoi(value);
            lindata >> value;
            student[nav].grade = stof(value);
            nav++;
        }

    }


    else {
        cout << "can not open the file " << endl;
    }


}

static bool checkname(string name)
{
    bool valid = true;


    for (char c : name)
    {
        if (!(isalpha(c)))
        {
            valid = false;

        }

    }
    return !valid;
}

static void inputStudent(Student& s, int edite = 0) {
    if (edite == 0)
    {
    enter:
        int id;
        do
        {
            cout << "Enter the id of the student: ";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else if (id < MIN_ID || id > MAX_ID)
            {
                cout << "Invalid id. Please enter a number between " << MIN_ID << " and " << MAX_ID << "." << endl;
            }
        } while (id < MIN_ID || id > MAX_ID);

        for (int i = 0; i < N - 1; i++)
        {
            if (id == student[i].id)
            {
                cout << "This id is already exist: ";
                goto enter;
            }
        }
        s.id = id;


    }
    else {
        cout << "The ID of student is: " << s.id << endl;
    }
    cout << "Enter the first name of the student: ";
    cin >> s.first_name;

    while (checkname(s.first_name))
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid first name, please enter again: ";
        cin >> s.first_name;
    }
    s.first_name[0] = toupper(s.first_name[0]);


    cout << "Enter the last name of the student: ";
    cin >> s.last_name;

    while (checkname(s.last_name))
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid last name, please enter again: ";
        cin >> s.last_name;
    }
    s.last_name[0] = toupper(s.last_name[0]);



    cout << "Enter the major of the student (IT, IS, CS, or CYS): ";
    cin >> s.major;
    for (char& c : s.major)
    {
        c = toupper(c);
    }
    while (s.major != "IT" && s.major != "IS" && s.major != "CS" && s.major != "CYS") {
        cout << "Invalid major, please enter again: ";
        cin >> s.major;
        for (char& c : s.major)
        {
            c = toupper(c);
        }
    }

    do
    {
        cout << "Enter the level of the student (1, 2, 3, or 4): ";
        cin >> s.level;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else if (s.level < 1 || s.level > 4)
        {
            cout << "Invalid level. Please enter a number between " << 1 << " and " << 4 << "." << endl;
        }
    } while (s.level < 1 || s.level > 4);
    s.total_marks = 0;
    for (int i = 0; i < s.size; i++)
    {

        do
        {
            cout << "Enter the mark of subject " << i + 1 << ": ";
            cin >> s.marks[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
            else if (s.marks[i] < 0 || s.marks[i] > 100)
            {
                cout << "Invalid marks. Please enter a number between " << 0 << " and " << 100 << "." << endl;
            }
        } while (s.marks[i] < 1 || s.marks[i] > 100);

        s.total_marks += s.marks[i];
    }
    s.grade = (float)s.total_marks / s.size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}




static void outputStudent(Student s, int choice = 0) {


    if (choice == 0)
    {
        cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
        cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << "ID" << "| " << setw(NAME_WIDTH) << "Name" << "| " << setw(MAJOR_WIDTH) << "Major" << "| " << setw(LEVEL_WIDTH) << "Level" << "| " << setw(TOTAL_WIDTH) << "Total" << "| " << setw(GRADE_WIDTH) << "Grade" << "|" << endl;
        cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;

        cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << s.id << "| " << setw(NAME_WIDTH) << s.first_name + " " + s.last_name << "| " << setw(MAJOR_WIDTH) << s.major << "| " << setw(LEVEL_WIDTH) << s.level << "| " << setw(TOTAL_WIDTH) << s.total_marks << "| " << setw(GRADE_WIDTH) << s.grade << "|" << endl;
        cout << setfill('-') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;

        for (int i = 0; i < s.size; i++) {
            cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << "" << "| " << setw(NAME_WIDTH) << "Subject " + to_string(i + 1) << "| " << setw(MAJOR_WIDTH) << "" << "| " << setw(LEVEL_WIDTH) << "" << "| " << setw(TOTAL_WIDTH) << s.marks[i] << "| " << setw(GRADE_WIDTH) << "" << "|" << endl;
        }

        cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl << endl << endl;
    }
    else
    {

        cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << s.id << "| " << setw(NAME_WIDTH) << s.first_name + " " + s.last_name << "| " << setw(MAJOR_WIDTH) << s.major << "| " << setw(LEVEL_WIDTH) << s.level << "| " << setw(TOTAL_WIDTH) << s.total_marks << "| " << setw(GRADE_WIDTH) << s.grade << "|" << endl;
        cout << setfill('-') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;

    }



}


static void displayStudentformanipulate()
{
    Student sorted[N];
    for (int i = 0; i < N; i++)
    {
        sorted[i] = student[i];
    }



    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (sorted[j].id > sorted[j + 1].id)
            {

                Student temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    int counter = 0;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    cout << "=============" << "Students Management System [SMS]" << "==============" << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << "ID" << "| " << setw(NAME_WIDTH) << "Name" << "| " << setw(MAJOR_WIDTH) << "Major" << "| " << setw(LEVEL_WIDTH) << "Level" << "| " << setw(TOTAL_WIDTH) << "Total" << "| " << setw(GRADE_WIDTH) << "Grade" << "|" << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    for (int i = 0; i < N; i++) {
        if (sorted[i].id != 0) {

            outputStudent(sorted[i], 1);
        }
    }
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl << endl << endl;

}

static void addStudent() {
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (student[i].id == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "The array is full, cannot add more students." << endl;
        return;
    }
    cout << "Enter the record of the new student: " << endl;
    inputStudent(student[index]);
    file.open("student.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << student[index].id << " " << student[index].first_name << " " << student[index].last_name << " " << student[index].major << " " << student[index].level << " ";
        for (int i = 0; i < student[index].size; i++) {
            file << student[index].marks[i] << " ";
        }
        file << student[index].total_marks << " " << student[index].grade << " " << endl;
        file.close();
        cout << "The record of the new student has been added successfully." << endl;
    }
    else {
        cout << "The file could not be opened." << endl;
    }
}






static void editStudent() {
here:
    displayStudentformanipulate();
    int id;

    do
    {
        cout << "Enter the id of the student to be edited: ";
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else if (id < MIN_ID || id > MAX_ID)
        {
            cout << "Invalid id. Please enter a number between " << MIN_ID << " and " << MAX_ID << "." << endl;
        }
    } while (id < MIN_ID || id > MAX_ID);

    int index = -1;
    for (int i = 0; i < N; i++) {
        if (student[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "The student with the given id does not exist." << endl;
        return;
    }
    clearscrean();
    cout << "The current record of the student is: " << endl;
    outputStudent(student[index]);
    string ensure;
    cout << "Do you want to edite this record: (Y , N or R)";
    cin >> ensure;
    ensure[0] = toupper(ensure[0]);
    if (ensure[0] != 'Y' && ensure[0] != 'R')
    {
        clearscrean();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto here;
    }
    else if (ensure[0] == 'R')
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter the new record of the student: " << endl;
    inputStudent(student[index], 1);
    cin.ignore(100, '\n');
    file.open("student.txt", ios::out | ios::trunc);
    if (file.is_open()) {
        for (int i = 0; i < N; i++) {
            if (student[i].id != 0) {
                file << student[i].id << " " << student[i].first_name << " " << student[i].last_name << " " << student[i].major << " " << student[i].level << " ";
                for (int j = 0; j < student[i].size; j++) {
                    file << student[i].marks[j] << " ";
                }
                file << student[i].total_marks << " " << student[i].grade << " " << endl;
            }
        }
        file.close();
        cout << "The record of the student has been edited successfully." << endl;
    }
    else {
        cout << "The file could not be opened." << endl;
    }
}





static void deleteStudent() {
here:
    displayStudentformanipulate();
    int id;

    do
    {
        cout << "Enter the id of the student to be deleted: ";
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else if (id < MIN_ID || id > MAX_ID)
        {
            cout << "Invalid id. Please enter a number between " << MIN_ID << " and " << MAX_ID << "." << endl;
        }
    } while (id < MIN_ID || id > MAX_ID);

    int index = -1;
    for (int i = 0; i < N; i++) {
        if (student[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "The student with the given id does not exist." << endl;
        return;
    }
    cout << "The current record of the student is: " << endl;
    outputStudent(student[index]);

    string ensure;
    cout << "Do you want to delete this record: (Y , N or R)";
    cin >> ensure;
    ensure[0] = toupper(ensure[0]);
    if (ensure[0] != 'Y' && ensure[0] != 'R')
    {
        clearscrean();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto here;
    }
    else if (ensure[0] == 'R')
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    student[index].id = 0;
    student[index].first_name = "";
    student[index].last_name = "";
    student[index].major = "";
    student[index].level = 0;
    for (int i = 0; i < student[index].size; i++) {
        student[index].marks[i] = 0;
    }
    student[index].total_marks = 0;
    student[index].grade = 0;
    file.open("student.txt", ios::out | ios::trunc);
    if (file.is_open()) {
        for (int i = 0; i < N; i++) {
            if (student[i].id != 0) {
                file << student[i].id << " " << student[i].first_name << " " << student[i].last_name << " " << student[i].major << " " << student[i].level << " ";
                for (int j = 0; j < student[i].size; j++) {
                    file << student[i].marks[j] << " ";
                }
                file << student[i].total_marks << " " << student[i].grade << endl;
            }
        }
        file.close();
        cout << "The record of the student has been deleted successfully." << endl;
    }
    else {
        cout << "The file could not be opened." << endl;
    }
}






static void searchStudent() {
    displayStudentformanipulate();
    int choice;
    cout << "======================================" << endl;
    cout << "===Students Management System [SMS]===" << endl;
    cout << "======================================" << endl;
    cout << "Enter the choice of the search criteria: " << endl;
    cout << "1) Search by the student's id" << endl;
    cout << "2) Search by the student's name" << endl;
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
        else if (choice < 1 || choice  > 2)
        {
            cout << "Invalid choice. Please enter a number between " << 1 << " and " << 2 << "." << endl;
        }
    } while (choice < 1 || choice > 2);
    cout << "" << endl;

    if (choice == 1)
    {
        int id;

        do
        {
            cout << "Enter the id of the student to be searched: ";
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid id. Please enter a valid integer." << endl;
            }
            else if (id < MIN_ID || id > MAX_ID)
            {
                cout << "Invalid id. Please enter a number between " << MIN_ID << " and " << MAX_ID << "." << endl;
            }
        } while (id < MIN_ID || id > MAX_ID);


        int index = -1;
        for (int i = 0; i < N; i++)
        {
            if (student[i].id == id)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "The student with the given id does not exist." << endl;
            return;
        }
        cout << "The record of the student is: " << endl;
        outputStudent(student[index]);
    }
    else if (choice == 2)
    {
        string fname, lname;
        cout << "Enter the name of the student to be searched: ";
        cin >> fname;
        cin >> lname;
        while (checkname(fname))
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid first name, please enter again: ";
            cin >> fname;
            while (checkname(lname))
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid last name, please enter again: ";

                cin >> lname;
            }
        }
        fname[0] = toupper(fname[0]);
        lname[0] = toupper(lname[0]);
        int index = -1;
        for (int i = 0; i < N; i++) {
            if (student[i].first_name == fname && student[i].last_name == lname) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "The student with the given name does not exist." << endl;
            return;
        }
        cout << "The record of the student is: " << endl;
        outputStudent(student[index]);
    }
}





static void displayStudent() {
    int choice;
    cout << "=======================================" << endl;
    cout << "===Students Management System [SMS]====" << endl;
    cout << "=======================================" << endl;
    cout << "Enter the choice of the display order: " << endl;
    cout << "1) Display the students ordered by id" << endl;
    cout << "2) Display the students ordered by name" << endl;
    cout << "3) Display the students ordered by grade" << endl;
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
        else if (choice < 1 || choice  > 3)
        {
            cout << "Invalid choice. Please enter a number between " << 1 << " and " << 3 << "." << endl;
        }
    } while (choice < 1 || choice > 3);

    Student sorted[N];
    for (int i = 0; i < N; i++) {
        sorted[i] = student[i];
    }

    if (choice == 1) {

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (sorted[j].id > sorted[j + 1].id) {

                    Student temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }
    }
    else if (choice == 2) {

        for (int i = 0; i < N - 1; i++) {

            int min = i;
            for (int j = i + 1; j < N; j++) {
                if (sorted[j].first_name < sorted[min].first_name) {
                    min = j;
                }
            }

            Student temp = sorted[i];
            sorted[i] = sorted[min];
            sorted[min] = temp;
        }
    }
    else if (choice == 3) {

        for (int i = 1; i < N; i++) {

            Student key = sorted[i];

            int j = i - 1;
            while (j >= 0 && sorted[j].grade < key.grade && sorted[i].id != 0) {

                sorted[j + 1] = sorted[j];
                j--;
            }

            sorted[j + 1] = key;
        }
    }
    int counter = 0;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    cout << "=============" << "Students Management System [SMS]" << "==============" << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    cout << setfill(' ') << "| " << left << setw(ID_WIDTH) << "ID" << "| " << setw(NAME_WIDTH) << "Name" << "| " << setw(MAJOR_WIDTH) << "Major" << "| " << setw(LEVEL_WIDTH) << "Level" << "| " << setw(TOTAL_WIDTH) << "Total" << "| " << setw(GRADE_WIDTH) << "Grade" << "|" << endl;
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl;
    for (int i = 0; i < N; i++) {
        if (sorted[i].id != 0) {

            outputStudent(sorted[i], 1);
        }
    }
    cout << setfill('=') << setw(ID_WIDTH + NAME_WIDTH + MAJOR_WIDTH + LEVEL_WIDTH + TOTAL_WIDTH + GRADE_WIDTH + set_width) << "" << endl << endl << endl;
}




#endif
