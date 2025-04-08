//
// Created by Alexandru Roșca on 13.12.2024.
//

// sursa de informare: https://www.geeksforgeeks.org/observer-pattern-c-design-patterns/

// pros:
// - permite unui obiect sa notifice alte obiecte fara a fi nevoie sa stie detalii despre acele obiecte
// - incapsuleaza transmiterea update-urile parametrilor catre alte obiecte

// cons:
// - poate duce la o serie de update-uri in cascada
// - ma gandesc ca daca nu este suficient de securizat, pot aparea observeri nedoriti care sa citeasca eventualele date

#include <iostream>

using namespace std;

// observer class
class Observer{
public:
    virtual void update(int powerLeft, int timeLeft) = 0;
};

// subject class
class Battery {
private:
    int powerLeft;
    int timeLeft;
    vector<Observer*> observers;

public:
    void registerObserver(Observer* observer){
        observers.push_back(observer);
    }

    void notifyObservers() {
        for(Observer* observer : observers)
            observer->update(powerLeft, timeLeft);
    }

    void setValues(int powerLeft, int timeLeft){
        this->powerLeft = powerLeft;
        this->timeLeft = timeLeft;
        notifyObservers();
    }
};

// display class
class User : public Observer{
public:
    void update(int powerLeft, int timeLeft) override {
        cout << "Power left: " << powerLeft << "% -> Time left: " << timeLeft  << " minutes" << endl;
    }
};


int main() {

    Battery battery;

    User user;

    battery.registerObserver(&user);

    battery.setValues(50, 30);
    battery.setValues(20, 10);


    return 0;
}