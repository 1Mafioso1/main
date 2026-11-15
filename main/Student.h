#pragma once

class Student {
private:
    char* name;
    int age;
public:
    Student();
    Student(const char* initName, int initAge);
    ~Student();

    void printStudentInfo();

    void setName(const char* newName);
    void setAge(int newAge);

    const char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};