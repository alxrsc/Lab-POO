#include <iostream>

using namespace std;

class Country {
protected:
    int population;
    string name;
    int foundationYear;
public:
    virtual void showPopulation() = 0;
    virtual void showName() = 0;
    virtual void showFoundationYear() = 0;
};

class Romania : public Country {
public:
    Romania() {
        population = 19;
        name = "Romania";
        foundationYear = 1918;
    }
    void showPopulation() {
        cout << "Romania has a population of " << population << " million people." << endl;
    }
    void showName() {
        cout << "The name of the country is " << name << "." << endl;
    }
    void showFoundationYear() {
        cout << "The country was founded in " << foundationYear << "." << endl;
    }
};

class Azerbaijan : public Country {
public:
    Azerbaijan() {
        population = 10;
        name = "Azerbaijan";
        foundationYear = 1918;
    }
    void showPopulation() {
        cout << "Azerbaijan has a population of " << population << " million people." << endl;
    }
    void showName() {
        cout << "The name of the country is " << name << "." << endl;
    }
    void showFoundationYear() {
        cout << "The country was founded in " << foundationYear << "." << endl;
    }
};

class Kazakhstan : public Country {
public:
    Kazakhstan() {
        population = 18;
        name = "Kazakhstan";
        foundationYear = 1991;
    }
    void showPopulation() {
        cout << "Kazakhstan has a population of " << population << " million people." << endl;
    }
    void showName() {
        cout << "The name of the country is " << name << "." << endl;
    }
    void showFoundationYear() {
        cout << "The country was founded in " << foundationYear << "." << endl;
    }
};

int main() {

    Romania romania;

    romania.showName();
    romania.showFoundationYear();
    romania.showPopulation();
    cout << endl;

    Azerbaijan azerbaijan;

    azerbaijan.showName();
    azerbaijan.showFoundationYear();
    azerbaijan.showPopulation();
    cout << endl;

    Kazakhstan kazakhstan;

    kazakhstan.showName();
    kazakhstan.showFoundationYear();
    kazakhstan.showPopulation();

    return 0;
}
