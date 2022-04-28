#include <iostream>
#include <string>
#include <vector>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
public:
    Person(string personID, string password, vector<Person*>* _allPeople);
    string getID();
    string getPassword();
    void setID(string personID);
    void setPassword(string password);
    virtual void displayPerson() = 0;


    vector<Person *> *getAllPeoplePtr() const;
    void setAllPeoplePtr(vector<Person *> *newAllPeoplePtr);

private:
    string _personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    string _password;
    vector<Person*>* _allPeoplePtr;
};

#endif // PERSON_H
