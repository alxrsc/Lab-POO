//
// Created by Alexandru Roșca on 13.12.2024.
//

// sursa de informare: https://www.geeksforgeeks.org/composite-pattern-cpp/
// sursa de informare aditionala: ChatGPT

// pros:
// - permite clientului sa trateze obiectele individuale si compuse uniform
// - usor de adaugat noi tipuri de componente fara a modifica codul existent
// - usor de modificat structura unui obiect compus

// cons:
// - poate face design-ul prea generalizat
// - poate sa faca design-ul prea complex pentru anumite scenarii

#include <iostream>

using namespace std;

// base class
class Employee {
protected:
    string name;
    string department;

public:
    virtual void showDetails() = 0;

    virtual void add(Employee* employee) {
        // Default implementation for leaf objects
        throw runtime_error("Cannot add employees to a leaf employee.");
    }
};


// leaf class
class Developer : public Employee {
public:
    Developer(string name, string department) {
        this->name = name;
        this->department = department;
    }

    void showDetails() override {
        cout << "Developer: " << name << " in " << department << endl;
    }
};

// leaf class
class Designer : public Employee {
public:
    Designer(string name, string department) {
        this->name = name;
        this->department = department;
    }

    void showDetails() override {
        cout << "Designer: " << name << " in " << department << endl;
    }
};

// composite class
class Manager : public Employee {
private:
    vector<Employee*> employees;

public:
    Manager(string name, string department) {
        this->name = name;
        this->department = department;
    }

    void showDetails() override {
        cout << "Manager: " << name << " in " << department << endl;
        for (Employee* employee : employees) {
            cout << "\t";
            employee->showDetails();
        }
    }

    void add(Employee* employee) override {
        employees.push_back(employee);
    }
};


int main() {

    Employee* developer1 = new Developer("Steve Jobs", "Apple");
    Employee* developer2 = new Developer("Mark Zuckerberg", "Meta");
    Employee* designer1 = new Designer("Jeff Bezos", "Amazon");
    Employee* designer2 = new Designer("Sundar Pichai", "Google");

    Employee* manager = new Manager("Donald Trump", "Management");
    manager->add(developer1);
    manager->add(developer2);
    manager->add(designer1);
    manager->add(designer2);

    manager->showDetails();

    return 0;
}