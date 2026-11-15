#include <iostream>
#include <cstring>
#include "Group.h"
using namespace std;

Group::Group() {
    name = nullptr;
    students = nullptr;
    count = 0;
}

Group::Group(const char* initName) {
    name = nullptr;
    students = nullptr;
    count = 0;
    setName(initName);
}

Group::~Group() {
    for (int i = 0; i < count; i++) {
        delete students[i];
    }

    delete[] students;

    if (name != nullptr) delete[] name;
}

void Group::setName(const char* newName) {
    if (name != nullptr) delete[] name;

    if (newName != nullptr) {
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }
    else {
        name = nullptr;
    }
}

void Group::addStudent(const char* name, int age) {
    Student** newStudents = new Student * [count + 1];

    for (int i = 0; i < count; i++) {
        newStudents[i] = students[i];
    }

    newStudents[count] = new Student(name, age);

    delete[] students;
    students = newStudents;

    count = count + 1;
}

void Group::removeStudent(int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!\n";
        return;
    }

    delete students[index];

    Student** newStudents = nullptr;

    if (count > 1) {
        newStudents = new Student * [count - 1];

        int j = 0;

        for (int i = 0; i < count; i++) {
            if (i != index) {
                newStudents[j] = students[i];
                j = j + 1;
            }
        }
    }

    delete[] students;
    students = newStudents;

    count = count - 1;
}

void Group::printGroupInfo() {
    if (name != nullptr) {
        cout << "Group: " << name << '\n';
    }
    else {
        cout << "Group: Unknown\n";
    }

    cout << "Students: " << count << '\n';

    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << i + 1 << '\n';
        students[i]->printStudentInfo();
    }
}