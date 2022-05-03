#include "Person.hpp"

Person::Person(string personID, string password, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* allPeople){
    _personID = personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    _password = password;
    _allPeoplePtr = allPeople;
    _allPeoplePtr->push_back(this);
    _allPlayersPtr = _allPlayers;
    _allPlayersOnMarketPtr = _allPlayersOnMarket;

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

void Person::setAllPlayersPtr(vector<Player *> *newAllPlayersPtr)
{
    _allPlayersPtr = newAllPlayersPtr;
}

void Person::setAllPlayersOnMarketPtr(vector<Player *> *newAllPlayersOnMarketPtr)
{
    _allPlayersOnMarketPtr = newAllPlayersOnMarketPtr;
}


Person* Person::getPersonPtrFromID(string personID){
    char firstChar = personID[0];
    if (firstChar == 'A'){
        throw "Error: You can not obtain a User if you are giving an Admin ID";
    }

    for (int i=0; i < (int) _allPeoplePtr->size();i++){
        if (personID == (*_allPeoplePtr)[i]->getID()){
            return (*_allPeoplePtr)[i];
        }
    }

    throw "Error: Person not found";
}

Player* Person::getPlayerPtrFromID(int playerID){
    for (int i=0; i < (int) _allPlayersPtr->size(); i++){
        if (playerID == (*_allPlayersPtr)[i]->getPlayerID()){
            return (*_allPlayersPtr)[i];
        }
    }
    throw "Didnt find player with ID";
}
