#include <iostream>

using namespace std;

class Author {
private:
    string name;
    int age;

public:
    Author(string name, int age) {
        this->name = name;
        this->age = age;
    }

    friend class Book;
    friend class TheatrePlay;
    friend void authorGreet(Author author);
};

class Book {
protected:
    string name;

public:
    Book(string name) {
        this->name = name;
    }

    virtual void showName() {
        cout << "The name of the book is " << name << "." << endl;
    }

    virtual void showAuthor(Author author) {
        cout << "The author of the book is " << author.name << "." << endl;
    }

};

class TheatrePlay :  public Book {
private:
    int duration;

public:
    TheatrePlay(string name, int duration) : Book(name) {
        this->duration = duration;
    }
    void showName() {
        cout << "The name of the theatre play is " << name << "." << endl;
    }

    void showAuthor(Author author) {
        cout << "The author of the theatre play is " << author.name << "." << endl;
    }

    void showDuration() {
        cout << "The duration of the theatre play is " << duration << " minutes." << endl;
    }
};

void authorGreet(Author author) {
    cout << "Hello! My name is " << author.name << " and I am " << author.age << " years old." << endl;
}

int main() {

    Author author("Ion Creanga", 50);
    Book book("Amintiri din copilarie");
    TheatrePlay theatrePlay("Amintiri din copilarie", 120);

    authorGreet(author);
    cout << endl;

    book.showName();
    book.showAuthor(author);
    cout << endl;

    theatrePlay.showName();
    theatrePlay.showAuthor(author);
    theatrePlay.showDuration();
    cout << endl;

    return 0;
}