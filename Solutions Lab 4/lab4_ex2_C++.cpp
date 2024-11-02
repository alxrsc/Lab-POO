//
// Created by Alexandru Roșca on 02.11.2024.
//

#include <iostream>

using namespace std;

class Animal {
protected:
    string name = "Unknown";
    int age = 0;
    string color = "Unknown";
    int numOfLegs = 0;

public:
    // constructor default
    Animal() {
        cout << "Animal object created!" << endl;
    }

    // constructor cu initializarea atributelor
    Animal(string name, int age, string color, int numOfLegs) {
        this->name = name;
        this->age = age;
        this->color = color;
        this->numOfLegs = numOfLegs;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setNumOfLegs(int numOfLegs) {
        this->numOfLegs = numOfLegs;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    string getColor() {
        return this->color;
    }

    int getNumOfLegs() {
        return this->numOfLegs;
    }

};

// clasele pig si crow sunt mostenite virtual de la clasa animal pentru a evita ambiguitatea
// intre settere si gettere cand clasa mutation mosteneste ambele clase

class Pig : virtual public Animal {

public:
    void playInMud() {
        cout << "I am playing in mud!";
    }

    void groh() {
        cout << "Groh!";
    }
};

class Crow : virtual public Animal {

public:
    void fly() {
        cout << "I am flying!";
    }

    void caw() {
        cout << "Caw!";
    }
};

class Mutation : public Pig, public Crow {

public:
    void couldYouBelieve() {
        cout << "I am a pig and a crow at the same time! So pigs are flying now!";
    }

    Mutation() {
        cout << "Mutation object created!" << endl;
    }

};

int main() {

    Mutation mutation = Mutation();

    mutation.setAge(2);
    mutation.setColor("Pink");
    mutation.setName("PigCrow");
    mutation.setNumOfLegs(3);

    cout << "Name: " << mutation.getName() << endl;
    cout << "Age: " << mutation.getAge() << endl;
    cout << "Color: " << mutation.getColor() << endl;
    cout << "Number of legs: " << mutation.getNumOfLegs() << endl;
    cout << endl;

    mutation.playInMud();
    cout << endl;
    mutation.fly();
    cout << endl;
    mutation.couldYouBelieve();




    return 0;
}