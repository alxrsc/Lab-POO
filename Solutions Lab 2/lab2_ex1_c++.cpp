#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
    Time() {
        time_t t = time(0);
        tm *now = localtime(&t);
        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day = now->tm_mday;
        hour = now->tm_hour;
        minute = now->tm_min;
        second = now->tm_sec;

        cout << "Current date and time: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
        cout << "Hours left until the end of the day: " << 24 - hour << " hours " << 60 - minute << " minutes " << 60 - second << " seconds" << endl;

    }

    ~Time() {
        cout << "Destructor called" << endl;
    }

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

int main() {
    Time t;

    return 0;
}
