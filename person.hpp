#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
public:
    Person(string personID, string password);
    string getID();
    string getPassword();
    void setID(string personID);
    void setPassword(string password);


private:
    string _personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    string _password;
};

#endif // PERSON_H
