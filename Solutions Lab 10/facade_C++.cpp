//
// Created by Alexandru Roșca on 13.12.2024.
//

// sursa de informare: https://www.geeksforgeeks.org/facade-method-c-design-patterns/

// pros:
// - ascunde complexitatea sistemului
// - ofera o interfata simplificata pentru client

// cons:
// - poate duce la o interfata prea generalizata
// - poate fi prea complex in cazuri relativ simple

#include <iostream>

using namespace std;

class Engine {
public:
    void start() {
        cout << "\tEngine started." << endl;
    }
};

class SparkPlug {
public:
    void ignite() {
        cout << "\tSpark plug ignited." << endl;
    }
};

class FuelInjector {
public:
    void inject() {
        cout << "\tFuel injected." << endl;
    }
};

class doTheBmwStart {
public:
    void leak() {
        cout << "\tLeaking oil. It means that there's oil inside, no need to worry!" << endl;
    }
};



class Car {
private:
    Engine engine;
    SparkPlug sparkPlug;
    FuelInjector fuelInjector;
    doTheBmwStart doTheBmwStart;

public:

    void start() {
        engine.start();
        sparkPlug.ignite();
        fuelInjector.inject();
        doTheBmwStart.leak();

        cout << "Car started. Ready to drive!" << endl;
    }

};

int main() {

    Car car;

    car.start();


    return 0;
}