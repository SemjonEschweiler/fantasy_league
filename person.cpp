#include "Person.hpp"

Person::Person(string personID, string password, vector<Person*>* allPeople){
    _personID = personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    _password = password;
    _allPeoplePtr = allPeople;
    _allPeoplePtr->push_back(this);
}

string Person::getID(){
    return _personID;
}

string Person::getPassword(){
    return _password;
}

void Person::setID(string personID){
    _personID = personID;
}

void Person::setPassword(string password){
    _password = password;
}

vector<Person *> *Person::getAllPeoplePtr() const
{
    return _allPeoplePtr;
}

void Person::setAllPeoplePtr(vector<Person *> *newAllPeoplePtr)
{
    _allPeoplePtr = newAllPeoplePtr;
}
