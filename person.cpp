#include "Person.hpp"

Person::Person(string personID, string password){
    _personID = personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    _password = password;
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
