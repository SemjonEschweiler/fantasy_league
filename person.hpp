#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Application.hpp"

class Person
{
public:
    Person(std::string personID, std::string password, Application* applicationPtr);
    Person();
    std::string getID();
    std::string getPassword();
    void setID(std::string personID);
    void setPassword(std::string password);
    void setApplicationPtr(Application* newApplicationPtr);
    virtual void displayPerson() = 0;


private:
    std::string _personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    std::string _password;
protected:
    Application* _applicationPtr;
};

#endif // PERSON_H
