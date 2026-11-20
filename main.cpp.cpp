
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
    string department;
};

// Function to add student
void addStudent()
{
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    getline(cin >> ws, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Department: ";
    getline(cin >> ws, s.department);

    ofstream file("students.txt", ios::app);

    if (!file.is_open())
    {
        cout << "\nUnable to open file!\n";
        return;
    }

    file << s.rollNo << endl;
    file << s.name << endl;
    file << s.age << endl;
    file << s.department << endl;

    file.close();

    cout << "\nStudent Added Successfully!\n";
}

// Function to display students
void displayStudents()
{
    Student s;
    ifstream file("students.txt");

    if (!file.is_open())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    bool found = false;

    while (file >> s.rollNo)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.department);

        cout << "\nRoll Number: " << s.rollNo;
        cout << "\nName: " << s.name;
        cout << "\nAge: " << s.age;
        cout << "\nDepartment: " << s.department << endl;

        found = true;
    }

    if (!found)
        cout << "\nNo student records found.\n";

    file.close();
}

// Function to search student
void searchStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    ifstream file("students.txt");

    while (file >> s.rollNo)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.department);

        if (s.rollNo == roll)
        {
            cout << "\nStudent Found!";
            cout << "\nName: " << s.name;
            cout << "\nAge: " << s.age;
            cout << "\nDepartment: " << s.department << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent Not Found!\n";

    file.close();
}

// Function to update student
void updateStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if (!temp.is_open())
    {
        cout << "\nUnable to create temporary file!\n";
        return;
    }

    while (file >> s.rollNo)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.department);

        if (s.rollNo == roll)
        {
            cout << "Enter New Name: ";
            getline(cin >> ws, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Department: ";
            getline(cin >> ws, s.department);

            found = true;
        }

        temp << s.rollNo << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.department << endl;
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "\nStudent Updated Successfully!\n";
    }
    else
    {
        remove("temp.txt");
        cout << "\nStudent Not Found!\n";
    }
}

// Function to delete student
void deleteStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if (!temp.is_open())
    {
        cout << "\nUnable to create temporary file!\n";
        return;
    }

    while (file >> s.rollNo)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.department);

        if (s.rollNo == roll)
        {
            found = true;
            continue;
        }

        temp << s.rollNo << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.department << endl;
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "\nStudent Deleted Successfully!\n";
    }
    else
    {
        remove("temp.txt");
        cout << "\nStudent Not Found!\n";
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Update Student";
        cout << "\n4. Search Student";
        cout << "\n5. Display Students";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                deleteStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                displayStudents();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
