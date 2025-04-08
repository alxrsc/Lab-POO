// Pros:
// - permite crearea unei singure instante a unei clase, utila pentru resurse partajate, baze de date spre ex
// - evita crearea mai multor instante pentru acelasi obiect
// - fiind declarata global, instanta poate fi accesata de oriunde, simplificand design-ul aplicatiei

// Cons:
// - greu de testat, fiind greu de izolat blocuri de cod, avand in vedere ca este o variabila globala
// - dificil de gestionat in cazul aplicatiilor multithread
/// Sursa informatiilor : geeksforgeeks.org/implementation-of-singleton-class-in-cpp/

#include <iostream>

using namespace std;

class Punga {
private:
    // membrii clasei
    string continut;
    string dataExpriarii;

    // pointerul catre instantierea clasei
    static Punga* instancePtr;

    // constructorul clasei facut privat
    Punga() {};

public:
    // copy constructorul va fi sters din motive de securitate
    Punga(const Punga& obj) = delete;

    static Punga* getInstance() {
        if (instancePtr == nullptr) {
            instancePtr = new Punga();
            cout << "Am deschis o punga noua!" << endl;
        }
        else
            cout << "Avem o punga deja deschisa, nu deschidem alta!" << endl;

        return instancePtr;
    }

    void setContinut(string continut) {
        this->continut = continut;
    }

    void setDataExpirarii(string dataExpirarii) {
        this->dataExpriarii = dataExpirarii;
    }

    string getContinut() {
        return continut;
    }

    string getDataExpirarii() {
        return dataExpriarii;
    }

};

Punga* Punga::instancePtr = nullptr;

int main() {

    Punga* punga = Punga::getInstance();
    punga->setContinut("Chipsuri");
    punga->setDataExpirarii("12.12.2025");

    cout << "Continutul pungii este: " << punga->getContinut() << endl;
    cout << "Data expirarii pungii este: " << punga->getDataExpirarii() << endl;

    Punga* punga2 = Punga::getInstance();

    cout << "Continutul pungii este: " << punga2->getContinut() << endl;


    return 0;
}
