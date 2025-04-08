// Pros:
// - flexibil, permite crearea obiectelor complexe pas cu pas
// - ofera cod clar prin separarae componentelor, logica si constructia obiectului
// - ofera cod reutilizabil, putem avea acelasi proces de constructie pentru a crea diferite reprezentari ale unui obiect

// Cons:
// - introduce mai multe clase si interfete, complicand inutil proiectele mici
// - excesiv pentru obiecte simple, adauga complexitate inutila
// - consuma mai multe resurse

/// Sursa informatiilor : geeksforgeeks.org/builder-pattern-c-design-patterns/

#include <iostream>

using namespace std;

class Salad {
private:
    string dressing;
    string vegetables;
    string toppings;

public:
    void setDressing(string dressing) {
        this->dressing = dressing;
    }

    void setVegetables(string vegetables) {
        this->vegetables = vegetables;
    }

    void setToppings(string toppings) {
        this->toppings = toppings;
    }

    string getDressing() {
        return dressing;
    }

    string getVegetables() {
        return vegetables;
    }

    string getToppings() {
        return toppings;
    }
};

// builder interface
class SaladBuilder {
public:
    virtual void buildDressing(const string dressing) = 0;
    virtual void buildVegetables(const string vegetables) = 0;
    virtual void buildToppings(const string toppings) = 0;
    virtual Salad getSalad() = 0;

};

// concrete builder
class CaesarSaladBuilder : public SaladBuilder {
private:
    Salad salad;

public:
    CaesarSaladBuilder() {
        salad = Salad();
    }

    void buildDressing(const string dressing) {
        salad.setDressing(dressing);
    }

    void buildVegetables(const string vegetables) {
        salad.setVegetables(vegetables);
    }

    void buildToppings(const string toppings) {
        salad.setToppings(toppings);
    }

    Salad getSalad() {
        return salad;
    }
};

// director
class CeasarSaladAssembler {
public:
    Salad assembleCeasarSalad(SaladBuilder& builder) {
        builder.buildDressing("Caesar");
        builder.buildVegetables("Lettuce, Spinach, Kale");
        builder.buildToppings("Croutons, Parmesan Cheese");
        return builder.getSalad();
    }
};

class GreekSaladBuilder : public SaladBuilder {
private:
    Salad salad;

public:
    GreekSaladBuilder() {
        salad = Salad();
    }

    void buildDressing(const string dressing) {
        salad.setDressing(dressing);
    }

    void buildVegetables(const string vegetables) {
        salad.setVegetables(vegetables);
    }

    void buildToppings(const string toppings) {
        salad.setToppings(toppings);
    }

    Salad getSalad() {
        return salad;
    }
};

class GreekSaladAssembler {
public:
    Salad assembleGreekSalad(SaladBuilder& builder) {
        builder.buildDressing("Greek");
        builder.buildVegetables("Tomatoes, Cucumbers, Onions");
        builder.buildToppings("Feta Cheese, Olives");
        return builder.getSalad();
    }
};

int main() {

    CaesarSaladBuilder builder;
    CeasarSaladAssembler assembler;
    Salad salad = assembler.assembleCeasarSalad(builder);

    cout << "New salad" << endl;
    cout << "Salad dressing: " << salad.getDressing() << endl;
    cout << "Salad vegetables: " << salad.getVegetables() << endl;
    cout << "Salad toppings: " << salad.getToppings() << endl << endl;

    GreekSaladBuilder builder2;
    GreekSaladAssembler assembler2;
    Salad salad2 = assembler2.assembleGreekSalad(builder2);

    cout << "New salad" << endl;
    cout << "Salad dressing: " << salad2.getDressing() << endl;
    cout << "Salad vegetables: " << salad2.getVegetables() << endl;
    cout << "Salad toppings: " << salad2.getToppings() << endl;



    return 0;
}
