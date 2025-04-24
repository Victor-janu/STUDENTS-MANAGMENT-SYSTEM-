void searchStudentByName(string name) {
    bool found = false;
    for (Student& s : students) {
        if (s.name == name) {
            s.displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No student with name " << name << " found." << endl;
    }
}