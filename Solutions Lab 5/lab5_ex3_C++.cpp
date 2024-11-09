#include <iostream>

using namespace std;

class String {
private:
    string str;

public:
    void operator + (char* s) {
        this->str += s;
    }

    string operator - () {
        // separam cand gasim "." sau ","
        string result = "";
        for(int i = 0; i < this->str.length(); i++) {
           if(this->str[i] == '.' || this->str[i] == ',') {
               result = str.substr(i+1, this->str.length());
               str = str.substr(0, i);
           }
        }
        return result;
    }

    void setString(string s) {
        this->str = s;
    }

    void getString() {
        cout << this->str << endl;
    }
};



int main() {

    String s1, s2;

    s1.setString("Hello");

    s1 + " World!";

    s1.getString();

    s1 + ".Good Morning!";

    s1.getString();

    // daca am fi apelat simplu "-s1;", s-ar fi vazut lipsa partii cu ".Good Morning!"
    // dar cum am facut operatorul sa si returneze stringul scos, l-am atribuit in s2
    // pentru a fi vizualizata mai clar separarea
    s2.setString(-s1);

    s1.getString();
    s2.getString();

    return 0;
}