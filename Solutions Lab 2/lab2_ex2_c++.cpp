#include <iostream>

using namespace std;

class MotorBike {
private:
    string manufacturer;
    string model;
    int year;
    int mileage;
    int engineSize;

public:
    MotorBike(string manufacturer, string model, int year, int mileage, int engineSize);
    MotorBike(string manufacturer, string model, int year, int engineSize);
    MotorBike(string manufacturer, string model, int year);
    MotorBike(string manufacturer);
    MotorBike();

    ~MotorBike() {
        cout << "Destructor called" << endl;
    }

    void display() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Engine size: " << engineSize << " cc" << endl;
        cout << endl;
    }

    void updateMileage(int newMileage) {
        mileage = newMileage;
    }

    void updateEngineSize(int newEngineSize) {
        engineSize = newEngineSize;
    }

    void updateYear(int newYear) {
        year = newYear;
    }

    void updateManufacturer(string newManufacturer) {
        manufacturer = newManufacturer;
    }

    void updateModel(string newModel) {
        model = newModel;
    }
};

MotorBike::MotorBike(string manufacturer, string model, int year, int mileage, int engineSize) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->mileage = mileage;
    this->engineSize = engineSize;
}

MotorBike::MotorBike(string manufacturer, string model, int year, int engineSize) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->mileage = 0;
    this->engineSize = engineSize;
}

MotorBike::MotorBike(string manufacturer, string model, int year) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->mileage = 0;
    this->engineSize = 0;
}

MotorBike::MotorBike(string manufacturer) {
    this->manufacturer = manufacturer;
    this->model = "Unknown";
    this->year = 0;
    this->mileage = 0;
    this->engineSize = 0;
}

MotorBike::MotorBike() {
    this->manufacturer = "Unknown";
    this->model = "Unknown";
    this->year = 0;
    this->mileage = 0;
    this->engineSize = 0;
}

int main() {
    MotorBike bike1("Yamaha", "YZF-R1", 2021, 0, 1000);
    MotorBike bike2("Kawasaki", "Ninja", 2020, 0);
    MotorBike bike3("Suzuki", "GSX-R1000", 2019);
    MotorBike bike4("Honda");
    MotorBike bike5;

    bike1.display();
    bike2.display();
    bike3.display();
    bike4.display();
    bike5.display();


    return 0;
}