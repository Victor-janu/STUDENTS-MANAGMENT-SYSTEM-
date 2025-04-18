#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    void editDetails(string n, int a, string d) {
        name = n;
        age = a;
        department = d;
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

    void searchStudentByID(int id) {
        bool found = false;
        for (Student& s : students) {
            if (s.id == id) {
                s.displayInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void deleteStudent(int id) {
        auto it = students.begin();
        while (it != students.end()) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student with ID " << id << " has been deleted." << endl;
                return;
            }
            ++it;
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    void editStudent(int id, string name, int age, string department) {
        for (Student& s : students) {
            if (s.id == id) {
                s.editDetails(name, age, department);
                cout << "Student details updated.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    void sortStudentsByID() {
        sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
            return s1.id < s2.id;
        });
    }

    void sortStudentsByName() {
        sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
            return s1.name < s2.name;
        });
    }
};

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Edit Student\n";
        cout << "6. Sort Students by ID\n";
        cout << "7. Sort Students by Name\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, department;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore();
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
            int id;
            cout << "Enter student ID