#include <iostream>
#include "Group.h"
using namespace std;

int main() {
    Group* group = nullptr;
    int choice = 0;

    do {
        cout << "\n1. Create group\n";
        cout << "2. Add student\n";
        cout << "3. Remove student\n";
        cout << "4. Show students\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            char name[50];

            cout << "Group name: ";
            cin >> name;

            if (group != nullptr) delete group;

            group = new Group(name);
        }

        else if (choice == 2) {
            if (group == nullptr) {
                cout << "Create group first!\n";
            }
            else {
                char name[50];
                int age;

                cout << "Student name: ";
                cin >> name;

                cout << "Age: ";
                cin >> age;

                group->addStudent(name, age);
            }
        }

        else if (choice == 3) {
            if (group == nullptr) {
                cout << "Create group first!\n";
            }
            else {
                int index;
                group->printGroupInfo();
                cout << "Student number: ";
                cin >> index;
                group->removeStudent(index - 1);
            }
        }

        else if (choice == 4) {
            if (group != nullptr) {
                group->printGroupInfo();
            }
            else {
                cout << "Create group first!\n";
            }
        }

    } while (choice != 0);

    if (group != nullptr) delete group;
}