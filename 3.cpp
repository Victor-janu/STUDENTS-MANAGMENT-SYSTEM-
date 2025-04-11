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
    cout << "Welcome to the Student Management System!" << endl;

    StudentManager manager;
    manager.addStudent(Student(1, "Alice", 20, "Computer Science"));
    manager.addStudent(Student(2, "Bob", 22, "Mathematics"));

    manager.displayAllStudents();

    return 0;
}