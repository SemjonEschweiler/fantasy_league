#include <iostream>
#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

using namespace std;

class Person
{
public:
    Person();
    string getID();
    string getPassword();
    void setID(string personID);
    void setPassword(string password);


private:
    string personID;
    string password;
};

#endif // PERSON_HPP
