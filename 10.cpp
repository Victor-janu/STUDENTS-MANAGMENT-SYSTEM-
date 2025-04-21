#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
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

    bool isValidAge(int age) {
        return age > 0 && age < 100;
    }

    bool isValidID(int id) {
        return id > 0;
    }

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
        if (!isValidAge(age)) {
            cout << "Invalid age entered. Please try again." << endl;
            return;
        }

        if (!isValidID(id)) {
            cout << "Invalid ID entered. Please try again." << endl;
            return;
        }

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

    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (Student& s : students) {
                outFile << s.id << "," << s.name << "," << s.age << "," << s.department << endl;
            }
            outFile.close();
            cout << "Student data saved successfully.\n";
        } else {
            cout << "Error saving data.\n";
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int id, age;
            string name, department;
            string line;
            while (getline(inFile, line)) {
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);
                size_t pos3 = line.find(",", pos2 + 1);

                id = stoi(line.substr(0, pos1));
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                department = line.substr(pos3 + 1);

                Student loadedStudent(id, name, age, department);
                addStudent(loadedStudent);
            }
            inFile.close();
            cout << "Student data loaded successfully.\n";
        } else {
            cout << "Error loading data or file not found.\n";
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    manager.loadFromFile("students.txt");  // Load data from file when program starts

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Edit Student\n";
        cout << "6. Sort Students by ID\n";
        cout << "7. Sort Students by Name\n";
        cout << "8. Save Data to File\n";
        cout << "9. Exit\n";
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

            if (age <= 0 || age >= 100) {
                cout << "Invalid age entered. Please enter a valid age.\n";
                continue;
            }

            if (id <= 0) {
                cout << "Invalid ID entered. Please enter a valid ID.\n";
                continue;
            }

            Student newStudent(id, name, age, department);
            manager.addStudent(newStudent);
        } 
        else if (choice == 2) {
            manager.displayAllStudents();
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            manager.searchStudentByID(id);
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            manager.deleteStudent(id);
        } 
        else if (choice == 5) {
            int id, age;
            string name, department;
            cout << "Enter student ID to edit: ";
            cin >> id;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new age: ";
            cin >> age;
            cout << "Enter new department: ";
            cin.ignore();
            getline(cin, department);

            manager.editStudent(id, name, age, department);
        } 
        else if (choice == 6) {
            manager.sortStudentsByID();
            cout << "Students sorted by ID.\n";
        } 
        else if (choice == 7) {
            manager.sortStudentsByName();
            cout << "Students sorted by Name.\n";
        } 
        else if (choice == 8) {
            manager.saveToFile("students.txt");
        } 
        else if (choice == 9) {
            break;
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}