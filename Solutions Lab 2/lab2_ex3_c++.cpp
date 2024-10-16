#include <iostream>

using namespace std;

class Sibling {
private:
    string* firstName;
    string* lastName;
    int* age;

public:
    Sibling(string* firstName, string* lastName, int* age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
    }

    // define deep copy constructor
    Sibling(const Sibling &sibling) {
        firstName = new string(*sibling.firstName);
        lastName = new string(*sibling.lastName);
        age = new int(*sibling.age);
    }

    ~Sibling() {
        free(firstName);
        free(lastName);
        free(age);
        cout << "Destructor called" << endl;
    }

    void display() {
        cout << "First name: " << *firstName << endl;
        cout << "Last name: " << *lastName << endl;
        cout << "Age: " << *age << endl;
        cout << endl;
    }

    void updateFirstName(string* newFirstName) {
        firstName = newFirstName;
    }

    void updateLastName(string* newLastName) {
        lastName = newLastName;
    }

    void updateAge(int* newAge) {
        age = newAge;
    }
};

int main() {

    Sibling sibling1(new string("Ciprian"), new string("Marica"), new int(25));
    Sibling sibling2 = sibling1;

    sibling2.updateFirstName(new string("Ionel"));
    sibling2.updateAge(new int(21));

    sibling1.display();
    sibling2.display();

    return 0;
}