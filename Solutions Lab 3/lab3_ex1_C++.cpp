#include <iostream>
#include <random>

using namespace std;

class Exchange {
private:
    string money = "Unknown";
    int amount;
    static int amountCount;

public:
    Exchange() {
        this->amount = generateRandomAmount();

        if (this->amount > 50)
            amountCount++;
    }

    Exchange(string money) {
        this->amount = generateRandomAmount();
        this->money = money;

        if (this->amount > 50)
            amountCount++;
    }

    int getAmount() {
        return this->amount;
    }

    string getMoney() {
        return this->money;
    }

    static int getCount() {
        return amountCount;
    }

private:
    int generateRandomAmount() {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 100);
        return dis(gen);
    }
};

int Exchange::amountCount = 0;

int main() {
    Exchange value1, value2("EUR"), value3, value4("RON"), value5("USD");

    cout << value1.getAmount() << " " << value2.getAmount() << " " << value3.getAmount() << " " << value4.getAmount() << " " << value5.getAmount() << endl;
    cout << "Number of values with the amount >50 is " << Exchange::getCount();

    return 0;
}