#include <iostream>
#include <string>
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

int main() {
    cout << "Welcome to the Student Management System!" << endl;

    Student s1(1, "VICTOR HAULE ", 23100523140029 , "Computer Science");
    s1.displayInfo();

    return 0;
}