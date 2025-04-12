#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;

    Student(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        department = d;
    }

    void displayInfo() {
        cout << "ID: " << id << ", Name: " << name 
             << ", Age: " << age << ", Department: " << department << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(Student s) {
        students.push_back(s);
    }

    void displayAllStudents() {
        for (Student& s : students) {
            s.displayInfo();
        }
    }
};

int main() {
    StudentManager manager;
    int choice;
    
    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, department;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore(); // to ignore the newline left by previous input
            getline(cin, name);
            cout << "Enter student age: ";
            cin >> age;
            cout << "Enter student department: ";
            cin.ignore();
            getline(cin, department);

            Student newStudent(id, name, age, department);
            manager.addStudent(newStudent);
        } 
        else if (choice == 2) {
            manager.displayAllStudents();
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}