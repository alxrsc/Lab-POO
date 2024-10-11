#include <iostream>
#include <string>

using namespace std;

class Student {
    string firstName;
    string lastName;
    string group;
    string whatILike;
    string whatIDontLike;
    string mySummer;
    string myGoals;

public:
    void setFirstName(string newFirstName) {
        firstName = newFirstName;
    }

    void setLastName(string newLastName) {
        lastName = newLastName;
    }

    void setGroup(string newGroup) {
        group = newGroup;
    }

    void setWhatILike(string newWhatILike) {
        whatILike = newWhatILike;
    }

    void setWhatIDontLike(string newWhatIDontLike) {
        whatIDontLike = newWhatIDontLike;
    }

    void setMySummer(string newMySummer) {
        mySummer = newMySummer;
    }

    void setMyGoals(string newMyGoals) {
        myGoals = newMyGoals;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getGroup() {
        return group;
    }

    string getWhatILike() {
        return whatILike;
    }

    string getWhatIDontLike() {
        return whatIDontLike;
    }

    string getMySummer() {
        return mySummer;
    }

    string getMyGoals() {
        return myGoals;
    }

};

int main() {

    Student student;

    student.setFirstName("Alexandru");
    student.setLastName("Roșca");
    student.setGroup("323AC");
    student.setWhatILike("Mi-a placut faptul ca am putut invata de la cineva care activeaza in industrie,\n\t\t"
                         "care a trecut prin aceleasi experiente cu noi, inclusiv aceeasi facultate. Pe langa toate conceptele \n\t\t"
                         "de programare, am apreciat foarte mult si tips and tricks-urile in ceea ce priveste angajarea si \n\t\t"
                         "mi-as dori sa avem parte de ele in continuare.");
    student.setWhatIDontLike("Mi-ar fi placut ca o data la cateva laboratoare, eventual 4, ca sa fie o data \n\t\t"
                             "pe luna, sa fie atribuit si un task cu un proiect mai mare care sa includa conceptele laboratoarelor, \n\t\t"
                             "pentru ca de cele mai multe ori in lab-uri aveam doar de replicat, eventual intelegand, cativa \n\t\t"
                             "algoritmi, dar punerea lor in practica ar fi lamurit si mai mult conceptele, dar ar fi de ajutor \n\t\t"
                             "si prin acumularea de proiecte de pus pe GitHub si de a avea mai multa experienta cu git, lucrand \n\t\t"
                             "fie singuri, fie in mici echipe.");
    student.setMySummer("Vara asta a fost plina de lucruri interesante care intr-un fel sau altul m-au dezvoltat... \n\t\t"
                        "Am inceput prin a-mi cumpara un BMW e46 coupe din 2000 care m-a invatat ce inseamna rabdarea (am mers la RAR de 3 ori), \n\t\t"
                        "mecanica auto, dezamagirea (repari una, strici alte doua) si urmarirea pretului la peco (6 cilindri benzina...). \n\t\t"
                        "Am participat si la primul meu interview pentru un internship pe Java unde am avut si experienta unui interview tehnic \n\t\t"
                        "ce mi-a aratat atat la ce sa ma astept, tehnic vorbind, dar si ce as putea adauga la CV-ul meu si ce proiecte intereseaza angajatorii. \n\t\t"
                        "Am experimentat si cu noi concepte, utilizarea bazelor de date in aplicatii, limbaje de programare, Swift pentru o aplicatie \n\t\t"
                        "de iOS, dar si cu ideea de low-level, embedded, folosind o replica chinezeasca a unui Ardiuno");
    student.setMyGoals("Dupa faculate, eventual din timpul ei, mi-as dori sa ma angajez ca software engineer, momentan nu stiu pe ce tehnologie, dar voi experimenta pana voi afla\n\t\t"
                       ", intrucat vreau ca locul de munca sa imi aduca un set de provocari de care sa fiu entuziasmat, cel putin in primii ani :), scopul final \n\t\t"
                       "ar fi sa ajung la Google, avand exemplul si auzind experientele unchiului meu care a inceput la Fitbit in Bucuresti, \n\t\t"
                       "trecand la Google Bucuresti iar de cativa ani, este in Mountain View tot la Google. Avand ocazia sa merg si eu acolo, \n\t\t"
                       "sa vad ce inseamna atat viata la o astfel de companie cat si experientele ce vin odata cu task-urile de la locul de munca, \n\t\t"
                       "imi doresc sa am aceasta experienta, sa imi permit un stil de viata relaxat, care sa imi ofere sansa de a ma bucura de tot \n\t\t"
                       "ceea ce imi place, chiar daca drumul pana acolo va presupune mult timp, multa munca si, suficient de probabil, multe refuzuri.");

    cout<<"Nume: "<<student.getFirstName()<<" "<<student.getLastName()<<endl;
    cout<<"Grupa: "<<student.getGroup()<<endl;
    cout<<"Ce mi-a placut: "<<student.getWhatILike()<<endl<<endl;
    cout<<"Ce nu mi-a placut: "<<student.getWhatIDontLike()<<endl<<endl;
    cout<<"Vara mea: "<<student.getMySummer()<<endl<<endl;
    cout<<"Scopuri: "<<student.getMyGoals()<<endl<<endl;

    return 0;
}
