#include <iostream>

using namespace std;

class Owner {
public:
    void getSalary() {
        cout << "Banii se reinvestesc in companie!" << endl;
    }

    void greet() {
        cout << "Salut! Sunt patronul companiei!" << endl;
    }
};

class Manager: public Owner {
public:
    void getSalary() {
        cout << "Salariul este confidential!" << endl;
    }

    void greet() {
        cout << "Salut! Sunt managerul companiei!" << endl;
    }

};

class Employee : public Manager {
public:
    void getSalary() {
        cout << "Salariul este \"motivant\"!" << endl;
    }

    void greet() {
        cout << "Salut! Sunt angajatul companiei!" << endl;
    }

};

int main() {

    Owner owner;
    Manager manager;
    Employee employee;

    owner.greet();
    owner.getSalary();
    cout << endl;

    manager.greet();
    manager.getSalary();
    cout << endl;

    employee.greet();
    employee.getSalary();
    cout << endl;


    return 0;
}