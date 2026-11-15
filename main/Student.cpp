#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

Student::Student() {
    name = nullptr;
    age = 0;
}

Student::Student(const char* initName, int initAge) {
    name = nullptr;
    age = initAge >= 0 ? initAge : 0;
    setName(initName);
}

Student::~Student() {
    if (name != nullptr) delete[] name;
}

void Student::printStudentInfo() {
    if (name != nullptr) {
        cout << "Name: " << name << '\n';
    }
    else {
        cout << "Name: Unknown" << '\n';
    }

    cout << "Age: " << age << '\n';
}

void Student::setName(const char* newName) {
    if (name != nullptr) delete[] name;

    if (newName != nullptr) {
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }
    else {
        name = nullptr;
    }
}

void Student::setAge(int newAge) {
    if (newAge < 0) return;
    age = newAge;
}