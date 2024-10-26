#include <iostream>
#include <unordered_map>
#include <chrono>
#include <ctime>

using namespace std;

unordered_map<string, int> generateHashMapOfPlaces();
int toInt(char c);

class Student {
private:
    string lastName = "Unknown";
    string firstName = "Unknown";
    string CNP = "Unknown";
    int yearOfBirth = 0;
    string faculty = "-";
    int foundationYear = 0;

public:
    Student(string lastName, string firstName, string CNP, int yearOfBirth, string faculty, int foundationYear) {
        this->lastName = lastName;
        this->firstName = firstName;
        this->CNP = CNP;
        this->yearOfBirth = yearOfBirth;
        this->faculty = faculty;
        this->foundationYear = foundationYear;
    }

    string generateCNP() {
        char s;
        int month, day;
        string placeOfBirth;
        string newCNP = "0000000000000";
        unordered_map<string, int> umap = generateHashMapOfPlaces();

        // stabilim prima cifra din CNP
        cout << "Introduceti sexul (m/f): ";
        cin >> s;
        if(yearOfBirth < 1900) {
            if(s == 'm')
                newCNP[0] = '3';
            else
                newCNP[0] = '4';
        }
        else if(yearOfBirth < 2000) {
            if(s == 'm')
                newCNP[0] = '1';
            else
                newCNP[0] = '2';
        }
        else {
            if(s == 'm')
                newCNP[0] = '5';
            else
                newCNP[0] = '6';
        }


        // stabilim urmatoarele 6 cifre in baza zilei de nastere
        newCNP[1] = yearOfBirth / 10 % 10 + '0';
        newCNP[2] = yearOfBirth % 10 + '0';

        cout << "Introduceti luna nasterii: ";
        cin >> month;

        newCNP[3] = month / 10 % 10 + '0';
        newCNP[4] = month % 10 + '0';

        cout << "Introduceti ziua nasterii: ";
        cin >> day;

        newCNP[5] = day / 10 % 10 + '0';
        newCNP[6] = day % 10 + '0';

        // stabilim locul nasterii pentru urmatoarele 2 cifre
        cout << "Introduceti locul nasterii (judet, se exclud sectoarele Bucurestiului): ";
        cin >> placeOfBirth;

        newCNP[7] = umap[placeOfBirth] / 10 % 10 + '0';
        newCNP[8] = umap[placeOfBirth] % 10 + '0';

        // stabilim urmatoarele 3 cifre
        /*
         NNN - reprezintă un număr de secvenţă (între 001 şi 999), repartizat pe puncte de atribuire,
         prin care se diferenţiază persoanele de acelaşi sex, născute în acelaşi loc şi cu aceeaşi dată de naştere (an, lună, zi).
         */
        // nu am gasit mai clar de atat cum se aloca, asa ca voi folosi un numar random intre 001 si 999
        srand(time(0));
        newCNP[9] = rand() % 10 + '0';
        newCNP[10] = rand() % 10 + '0';
        newCNP[11] = rand() % 10 + '0';

        // stabilim cifra de control
        string control = "279146358279";
        int test = 0;

        for(int i = 0; i < 12; i++) {
            test += toInt(newCNP[i]) * toInt(control[i]);
        }

        test %= 11;

        if(test == 10)
            test = 1;

        newCNP[12] = test + '0';

        return newCNP;
    }

    string getLastName() {
        return this->lastName;
    }

    string getFirstName() {
        return this->firstName;
    }

    string getCNP() {
        return this->CNP;
    }

    int getYearOfBirth() {
        return this->yearOfBirth;
    }

    string getFaculty() {
        return this->faculty;
    }

    int getFoundationYear() {
        return this->foundationYear;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setFirstName(string firstName) {
        this->lastName = firstName;
    }

    void setCNP(string CNP) {
        this->CNP = CNP;
    }

    void setYearOfBirth(int yearOfBirth) {
        this->yearOfBirth = yearOfBirth;
    }

    void setFaculty(string faculty) {
        this->faculty = faculty;
    }

    void setFoundationYear(int foundationYear) {
        this->foundationYear = foundationYear;
    }

    char getGender(){
        switch ( this->CNP[0] ) {
            case '1':
                return 'm';
            case '2':
                return 'f';
            case '3':
                return 'm';
            case '4':
                return 'f';
            case '5':
                return 'm';
            case '6':
                return 'f';
            default:
                return '-';
        }
    }

    int getAge() {
        int year, month, day;
        int age = 0;

        // stabilim anul nasterii
        if(toInt(this->CNP[0]) < 3)
            year = 1900 + toInt(this->CNP[1]) * 10 + toInt(this->CNP[2]);
        else if(toInt(this->CNP[0]) < 5)
            year = 1800 + toInt(this->CNP[1]) * 10 + toInt(this->CNP[2]);
        else
            year = 2000 + toInt(this->CNP[1]) * 10 + toInt(this->CNP[2]);

        // extragem luna nasterii
        month = toInt(this->CNP[3]) * 10 + toInt(this->CNP[4]);

        // extragem ziua nasterii
        day = toInt(this->CNP[5]) * 10 + toInt(this->CNP[6]);

        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* local_tm = std::localtime(&now_c);

        if(local_tm->tm_mon + 1 < month) {
            age = (local_tm->tm_year + 1900) - year - 1;
        }
        else if(local_tm->tm_mon + 1 == month) {
            if(local_tm->tm_mday < day)
                age = (local_tm->tm_year + 1900) - year - 1;
            else if (local_tm->tm_mday == day) {
                age = (local_tm->tm_year + 1900) - year;
                cout << "\nHAPPY BIRTHDAY! :D\n";
            }
            else
                age = (local_tm->tm_year + 1900) - year;
        }
        else {
            age = (local_tm->tm_year + 1900) - year;
        }

        return age;
    }

    int getDifference() {
        return abs(this->yearOfBirth - this->foundationYear);
    }
};

int main() {

    Student student1("Roșca", "Alexandru", "5040224373249", 2004, "Facultatea de Automatica si Calculatoare", 1967);
    Student student2("Surugiu", "Maria", "6041130279382", 2004, "Facultatea de Automatica si Calculatoare", 1967);
    Student student3("Dan", "Nicușor", "1691220401233", 1969, "Facultatea de Automatica si Calculatoare", 1967);

    student1.setCNP(student1.generateCNP());
    cout << "CNP generat: " << student1.getCNP() << endl;
    cout << "Pentru studentul " << student1.getFirstName() << " " << student1.getLastName() << ":\n";
    cout << "Sexul extras din CNP: " << student1.getGender() << endl;
    cout << "Varsta extrasa din CNP: " << student1.getAge() << endl;
    cout << "Diferența de ani dintre anul înființării facultății și data nașterii studentului: " << student1.getDifference() << endl << endl;

    cout << "Pentru studentul " << student2.getFirstName() << " " << student2.getLastName() << ":\n";
    cout << "Sexul extras din CNP: " << student2.getGender() << endl;
    cout << "Varsta extrasa din CNP: " << student2.getAge() << endl;
    cout << "Diferența de ani dintre anul înființării facultății și data nașterii studentului: " << student2.getDifference() << endl;

    student2.setFaculty("Facultatea de Matematica si Informatica");
    student2.setFoundationYear(1968);

    cout << "Dupa modificare:\n";
    cout << "Noua facultate: " << student2.getFaculty() << endl;
    cout << "Noua diferenta intre anul infiintarii facultatii si data nasterii studentului: " << student2.getDifference() << endl << endl;


    cout << "Pentru studentul " << student3.getFirstName() << " " << student3.getLastName() << ":\n";
    cout << "Sexul extras din CNP: " << student3.getGender() << endl;
    cout << "Varsta extrasa din CNP: " << student3.getAge() << endl;
    cout << "Diferența de ani dintre anul înființării facultății și data nașterii studentului: " << student3.getDifference() << endl;

    student3.setFaculty("Facultatea de Antreprenoriat si Management");
    student3.setFoundationYear(2019);

    cout << "Dupa modificare:\n";
    cout << "Noua facultate: " << student3.getFaculty() << endl;
    cout << "Noua diferenta intre anul infiintarii facultatii si data nasterii studentului: " << student3.getDifference() << endl;


    return 0;
}

unordered_map<string, int> generateHashMapOfPlaces() {
    unordered_map<string, int> umap;

    umap["Alba"] = 1;
    umap["Arad"] = 2;
    umap["Argeș"] = 3;
    umap["Bacău"] = 4;
    umap["Bihor"] = 5;
    umap["Bistrița-Năsăud"] = 6;
    umap["Botoșani"] = 7;
    umap["Brașov"] = 8;
    umap["Brăila"] = 9;
    umap["Buzău"] = 10;
    umap["Caraș-Severin"] = 11;
    umap["Cluj"] = 12;
    umap["Constanța"] = 13;
    umap["Covasna"] = 14;
    umap["Dâmbovița"] = 15;
    umap["Dolj"] = 16;
    umap["Galați"] = 17;
    umap["Gorj"] = 18;
    umap["Harghita"] = 19;
    umap["Hunedoara"] = 20;
    umap["Ialomița"] = 21;
    umap["Iași"] = 22;
    umap["Ilfov"] = 23;
    umap["Maramureș"] = 24;
    umap["Mehedinți"] = 25;
    umap["Mureș"] = 26;
    umap["Neamț"] = 27;
    umap["Olt"] = 28;
    umap["Prahova"] = 29;
    umap["Satu Mare"] = 30;
    umap["Sălaj"] = 31;
    umap["Sibiu"] = 32;
    umap["Suceava"] = 33;
    umap["Teleorman"] = 34;
    umap["Timiș"] = 35;
    umap["Tulcea"] = 36;
    umap["Vaslui"] = 37;
    umap["Vâlcea"] = 38;
    umap["Vrancea"] = 39;
    umap["București"] = 40;
    umap["Călărași"] = 51;
    umap["Giurgiu"] = 52;

    return umap;
}

int toInt(char c) {
    return c - '0';
}