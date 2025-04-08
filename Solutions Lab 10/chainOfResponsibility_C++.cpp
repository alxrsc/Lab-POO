//
// Created by Alexandru Roșca on 14.12.2024.
//

// sursa de informare: https://www.geeksforgeeks.org/chain-of-responsibility-method-design-patterns-in-c/

// pros:
// - permite unui obiect sa trateze o cerere fara a fi nevoie sa stie detalii despre cerere
// - permite mai multor obiecte sa trateze cererea
// - permite clientului sa trateze obiectele individuale si compuse uniform

// cons:
// - poate duce la o serie de update-uri in cascada
// - poate fi prea complex in cazuri relativ simple

#include <iostream>

using namespace std;

class AuthenticationHandler {
public:
    virtual void setNextHandler(AuthenticationHandler* handler) = 0;
    virtual void handleRequest(string request) = 0;
};

class UsernamePasswordHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;
public:
    void setNextHandler(AuthenticationHandler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(string request) override {
        if(request == "username-password") {
            cout << "Username and password authentication successful." << endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            cout << "Invalid authentication method." << endl;
        }
    }
};

class TwoFactorHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;

public:
    void setNextHandler(AuthenticationHandler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(string request) override {
        if(request == "two-factor") {
            cout << "Two-factor authentication successful." << endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            cout << "Invalid authentication method." << endl;
        }
    }
};

class TextMessageHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;

public:

    void setNextHandler(AuthenticationHandler* handler) override {
        nextHandler = handler;
    }

    void handleRequest(string request) override {
        if(request == "text-message") {
            cout << "Text message authentication successful." << endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            cout << "Invalid authentication method." << endl;
        }
    }
};

int main() {

    AuthenticationHandler* usernamePasswordHandler = new UsernamePasswordHandler();
    AuthenticationHandler* twoFactorHandler = new TwoFactorHandler();
    AuthenticationHandler* textMessageHandler = new TextMessageHandler();

    usernamePasswordHandler->setNextHandler(twoFactorHandler);
    twoFactorHandler->setNextHandler(textMessageHandler);

    usernamePasswordHandler->handleRequest("username-password");
    usernamePasswordHandler->handleRequest("two-factor");
    usernamePasswordHandler->handleRequest("text-message");
    usernamePasswordHandler->handleRequest("invalid");

    delete usernamePasswordHandler;
    delete twoFactorHandler;
    delete textMessageHandler;

    return 0;
}