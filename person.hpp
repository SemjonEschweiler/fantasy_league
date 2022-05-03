#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
public:
    Person(string personID, string password, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople);
    string getID();
    string getPassword();
    void setID(string personID);
    void setPassword(string password);
    virtual void displayPerson() = 0;


    vector<Person *> *getAllPeoplePtr() const;
    void setAllPeoplePtr(vector<Person *> *newAllPeoplePtr);
    Person* getPersonPtrFromID(string personID);
    void setAllPlayersPtr(vector<Player *> *newAllPlayersPtr);
    void setAllPlayersOnMarketPtr(vector<Player *> *newAllPlayersOnMarketPtr);
    Player* getPlayerPtrFromID(int playerID);

private:
    string _personID;//Uxxxxxxx for Users, Axxxxxxx for Admins
    string _password;
protected:
    vector<Person*>* _allPeoplePtr;
    vector<Player*>* _allPlayersPtr;
    vector<Player*>* _allPlayersOnMarketPtr;
};

#endif // PERSON_H
