#include <iostream>
#define PI 3.14159265
using namespace std;

class Beer {
protected:
    string type = "Unknown";
    string origin = "Unknown";

public:
    // constructor default
    Beer() {
        cout << "Beer object created!" << endl;
    }

    // constructor cu initializarea atributelor
    Beer(string type, string origin) {
        this->type = type;
        this->origin = origin;
    }

    void setType(string type) {
        this->type = type;
    }

    void setOrigin(string origin) {
        this->origin = origin;
    }

    string getType() {
        return this->type;
    }

    string getOrigin() {
        return this->origin;
    }

};

class Beer_TypeA : private Beer {
private:
    int length = 0;
public:
    // constructor default
    Beer_TypeA() {
        cout << "Beer TypeA object created!" << endl;
    }

    // constructor cu initializarea atributelor
    Beer_TypeA(string type, string origin, int length) {
        this->type = type;
        this->origin = origin;
        this->length = length;
    }

    void setType(string type) {
        this->type = type;
    }

    void setOrigin(string origin) {
        this->origin = origin;
    }

    void setLength(int length) {
        this->length = length;
    }

    string getType() {
        return this->type;
    }

    string getOrigin() {
        return this->origin;
    }

    int getLength() {
        return this->length;
    }

    int getArea() {
        return this->length * this->length;
    }
};

class Beer_TypeB : private Beer {
private:
    int radius = 0;

public:
    // constructor default
    Beer_TypeB() {
        cout << "Beer TypeB object created!" << endl;
    }

    // constructor cu initializarea atributelor
    Beer_TypeB(string type, string origin, int radius) {
        this->type = type;
        this->origin = origin;
        this->radius = radius;
    }

    void setType(string type) {
        this->type = type;
    }

    void setOrigin(string origin) {
        this->origin = origin;
    }

    void setRadius(int radius) {
        this->radius = radius;
    }

    string getType() {
        return this->type;
    }

    string getOrigin() {
        return this->origin;
    }

    int getRadius() {
        return this->radius;
    }

    float getArea() {
        return PI * this->radius * this->radius;
    }
};

class Beer_TypeC : private Beer {
private:
    int base = 0;
    int height = 0;

public:
    // constructor default
    Beer_TypeC() {
        cout << "Beer TypeC object created!" << endl;
    }

    // constructor cu initializarea atributelor
    Beer_TypeC(string type, string origin, int base, int height) {
        this->type = type;
        this->origin = origin;
        this->base = base;
        this->height = height;
    }

    void setType(string type) {
        this->type = type;
    }

    void setOrinin(string origin) {
        this->origin = origin;
    }

    void setBase(int base) {
        this->base = base;
    }

    void setHeight(int height) {
        this->height = height;
    }

    string getType() {
        return this->type;
    }

    string getOrigin() {
        return this->origin;
    }

    int getBase() {
        return this->base;
    }

    int getHeight() {
        return this->height;
    }

    int getArea() {
        return this->base * this->height;
    }
};


int main() {

    Beer_TypeA bereA = Beer_TypeA("Heineken", "Netherlands", 2);
    Beer_TypeB bereB = Beer_TypeB("Tuborg", "Denmark", 3);
    Beer_TypeC bereC = Beer_TypeC("Ursus", "Romania", 4, 5);

    cout << "Type is: " << bereA.getType() << endl;
    cout << "Origin is: " << bereA.getOrigin() << endl;
    cout << "Length is: " << bereA.getLength() << endl;
    cout << "Area is: " << bereA.getArea() << " cm^2" << endl << endl;

    cout << "Type is: " << bereB.getType() << endl;
    cout << "Origin is: " << bereB.getOrigin() << endl;
    cout << "Radius is: " << bereB.getRadius() << endl;
    cout << "Area is: " << bereB.getArea() << " cm^2" << endl << endl;

    cout << "Type is: " << bereC.getType() << endl;
    cout << "Origin is: " << bereC.getOrigin() << endl;
    cout << "Base is: " << bereC.getBase() << endl;
    cout << "Height is: " << bereC.getHeight() << endl;
    cout << "Area is: " << bereC.getArea() << " cm^2" << endl << endl;

    return 0;
}
