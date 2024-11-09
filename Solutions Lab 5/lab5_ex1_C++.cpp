#include <iostream>

using namespace std;

class Volume {
private:
    int length;
    double radius;
    int height;

public:
    Volume(int length, double radius, int height) {
        this->length = length;
        this->radius = radius;
        this->height = height;
    }

    Volume() {
        this->length = 0;
        this->radius = 0;
        this->height = 0;
    }

    void setLength(int length) {
        this->length = length;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    void setHeight(int height) {
        this->height = height;
    }

    int getLength() {
        return this->length;
    }

    double getRadius() {
        return this->radius;
    }

    int getHeight() {
        return this->height;
    }

    void getVolume() {
        cout << "Trying to calculate volume!"<< endl << "Please wait..." << endl << "Failed!" << endl;
    }

    void getVolume(int lenght) {
        cout << "Volume of the cube is " << lenght * lenght * lenght << endl;
    }

    void getVolume(double radius) {
        // folosing 3.1415, avem o valoare usor diferita de cea din kotlin unde am folosit Math.PI, o aproximare cu mai multe zecimale
        cout << "Volume of the sphere is " << 4 * 3.1415 * radius * radius * radius / 3 << endl;
    }

    void getVolume(int length, int height) {
        // 3.0 folosit pentru conversie la double
        cout << "Volume of the pyramid is " << length * length * height / 3.0 << endl;
    }

};

int main() {

    Volume volume;

    volume.getVolume();

    volume.getVolume(5);

    volume.getVolume(5.0);

    volume.getVolume(5, 10);

    return 0;
}
