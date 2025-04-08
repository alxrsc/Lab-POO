// Pros:
// - este mai flexibil, separand crearea obiectelor de utilizarea lor, premitand schimbarea tipurilor de produse create fara a modifica codul client
// - este consistent, asigura ca obiectele dintr-o familie de produse sunt compatibile intre ele
// - este extensibil, adaugarea unor noi familii de produse este simpla, fara a afecta codul deja existent

// Cons:
// - mai complex, crescand numarul de clase din cod, ineficient pentru proiecte mici
// - dificil de configurat, este nevoie de setari suplimentare pentru a determina fabrica utilizata
// - relativ ridig, adaugarea de noi metode la fabrica abstracta necesita modificari in toate clasele ce o mostentesc
/// Sursa informatiilor : geeksforgeeks.org/abstract-factory-pattern-c-design-patterns/

#include <iostream>

using namespace std;

// abstract product interface
class Airplane {
private:
    string model;
    string engine;
    int enginesNumber;

public:
    void setModel(string model) {
        this->model = model;
    }

    void setEngine(string engine) {
        this->engine = engine;
    }

    void setEnginesNumber(int enginesNumber) {
        this->enginesNumber = enginesNumber;
    }

    string getModel() {
        return model;
    }

    string getEngine() {
        return engine;
    }

    int getEnginesNumber() {
        return enginesNumber;
    }
};

// Abstract Factory interface
class AirplaneFactory {
public:
    virtual Airplane* createBoeingAirplane() = 0;
    virtual Airplane* createBombardierAirplane() = 0;

};

// Concrete Factories
class BoeingFactory : public AirplaneFactory {
public:
    Airplane* createBoeingAirplane() {
        Airplane* airplane = new Airplane();
        airplane->setModel("Boeing 747");
        airplane->setEngine("GE CF6-80C2B1F");
        airplane->setEnginesNumber(4);

        return airplane;
    }

    Airplane* createBombardierAirplane() {
        return nullptr;
    }
};

class BombardierFactory : public AirplaneFactory {
public:
    Airplane* createBoeingAirplane() {
        return nullptr;
    }

    Airplane* createBombardierAirplane() {
        Airplane* airplane = new Airplane();
        airplane->setModel("De Havilland Canada DHC-8-315");
        airplane->setEngine("PW123E made in 1995");
        airplane->setEnginesNumber(2);

        return airplane;
    }
};

int main() {

    AirplaneFactory* boeingFactory = new BoeingFactory();
    Airplane* airplane = boeingFactory->createBoeingAirplane();

    cout << "Model: " << airplane->getModel() << endl;
    cout << "Engine: " << airplane->getEngine() << endl;
    cout << "Engines number: " << airplane->getEnginesNumber() << endl << endl;

    AirplaneFactory* bombardierFactory = new BombardierFactory();
    airplane = bombardierFactory->createBombardierAirplane();

    cout << "Model: " << airplane->getModel() << endl;
    cout << "Engine: " << airplane->getEngine() << endl;
    cout << "Engines number: " << airplane->getEnginesNumber() << endl;




    return 0;
}
