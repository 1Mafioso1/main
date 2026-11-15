#pragma once
#include "Student.h"

class Group {
private:
    char* name;
    Student** students;
    int count;
public:
    Group();
    Group(const char* initName);
    ~Group();

    void addStudent(const char* name, int age);
    void removeStudent(int index);
    void printGroupInfo();

    void setName(const char* newName);

    const char* getName() {
        return name;
    }

    int getCount() {
        return count;
    }
};