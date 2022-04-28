#include "Person.hpp"

using namespace std;

Person::Person(string personID, string password, Application* applicationPtr){
    _personID = personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    _password = password;
    //this->setApplicationPtr(applicationPtr);

}

Person::Person(){

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

void Person::setApplicationPtr(Application* newApplicationPtr)
{
    _applicationPtr = newApplicationPtr;
}
