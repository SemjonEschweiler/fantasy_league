#include "Admin.hpp"
#include "User.hpp"
#include "Team.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

Admin::Admin(string personID, string password, int* currentPlayerID, int* currentPersonID, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople): Person(personID, password, _allPeople){

    _currentPlayerIDPtr = currentPlayerID;
    _currentPersonIDPtr = currentPersonID;
    _allPlayersPtr = _allPlayers;
    _allPlayersOnMarketPtr = _allPlayersOnMarket;
}

Player* Admin::createNewPlayer(string name, int position, bool is_able_playing, int market_value){
    Player* newplayer = new Player(name, assignCurrentPlayerID(), is_able_playing, "", market_value, false, position);

    //TODO add to different lists market and allplayers
    _allPlayersPtr->push_back(newplayer);
    _allPlayersOnMarketPtr->push_back(newplayer);
    cout << "Creation of player worked: " << endl;
    newplayer->displayPlayer();
    return newplayer;
}

void Admin::deletePlayer(int playerID){
    // Frees Player from both vectors and releases memory
    // Add functionality: Give User the amount of money what the deleted player is worth.

    for (int i=0;i < (int) _allPlayersPtr->size(); i++){
        if ((*_allPlayersPtr)[i]->getPlayerID() == playerID){
            cout << "delete this guy: " << (*_allPlayersPtr)[i]->getName() << endl;
            delete (*_allPlayersPtr)[i]; //delete Player to avoid memory leak
            _allPlayersPtr->erase(_allPlayersPtr->begin() + i); // remove Player from all Players vector

        }
    }

    for (int i=0;i < (int) _allPlayersOnMarketPtr->size(); i++){
        if ((*_allPlayersOnMarketPtr)[i]->getPlayerID() == playerID){
            //delete (*_allPlayersPtr)[i]; //not necessary anymore, since it has been removed in the previous for loop
            _allPlayersOnMarketPtr->erase(_allPlayersOnMarketPtr->begin() + i); // remove Player from all Players vector

        }
    }
}

void Admin::addPersonToSystem(bool isAdmin, int numericID, string password, int budget){
    //Adds a person to the system (either User or Admin) if it is a Person it will get a budget too
    if (isAdmin == 1){
        Admin newadmin = Admin(this->assignCurrentPersonID(isAdmin), "random", _currentPlayerIDPtr, _currentPersonIDPtr, _allPlayersPtr, _allPlayersOnMarketPtr, this->getAllPeoplePtr());
    }else{
        Team newteam = Team();
        User newuser = User(this->assignCurrentPersonID(isAdmin), "randompw", 100000, newteam, this->getAllPeoplePtr());

        for (int i=0; i<7; i++){
            //add Player to User(to do so add the UserID to Player/Team (Add Player to Substitutes of a team)
        }

    }
}

void Admin::updateScorePlayer(int playerID, int score){

}

void Admin::changeHealthStatusPlayer(int playerID, bool isHealthy){

}

void Admin::setCurrentPlayerIDPtr(int *newCurrentPlayerIDPtr)
{
    _currentPlayerIDPtr = newCurrentPlayerIDPtr;
}

int* Admin::getCurrentPlayerIDPtr() const
{
    return _currentPlayerIDPtr;
}

void Admin::setAllPlayersPtr(vector<Player *> *newAllPlayersPtr)
{
    _allPlayersPtr = newAllPlayersPtr;
}

void Admin::setAllPlayersOnMarketPtr(vector<Player *> *newAllPlayersOnMarketPtr)
{
    _allPlayersOnMarketPtr = newAllPlayersOnMarketPtr;
}

int *Admin::currentPersonIDPtr() const
{
    return _currentPersonIDPtr;
}

void Admin::setCurrentPersonIDPtr(int *newCurrentPersonIDPtr)
{
    _currentPersonIDPtr = newCurrentPersonIDPtr;
}

int Admin::assignCurrentPlayerID(){
    //this function assigns the next PlayerID and updates the currentPlayerID
    *_currentPlayerIDPtr += 1;
    return (*_currentPlayerIDPtr - 1);
}

string Admin::assignCurrentPersonID(bool isAdmin){
    //this function assigns the next PersonID and updates the currentPersonID
    stringstream aux;
    if (isAdmin){
        aux << "A" << *_currentPersonIDPtr;
    }else{
        aux << "U" << *_currentPersonIDPtr;
    }
    *_currentPersonIDPtr += 1;
    return aux.str();
}


void Admin::displayPerson(){
    cout << "Admin: " << this->getID() << endl;
}

void Admin::createRandomPlayers(int amountOfPlayers, string *firstNames, string *lastNames, int sizeFirstNames, int sizeLastNames)
{
    int randIndexFirstName, randIndexLastName, randPosition, randHealthy, randMarketValueMultiplication, marketValue;
    string firstName, lastName, fullName;
    stringstream fullNameSs;
    bool isHealthy;

    srand ( time(NULL) );

    cout << "Declaration of variables worked" << endl;

    for (int i=0; i<amountOfPlayers; i++){
        fullNameSs.str(std::string());
        randIndexFirstName = rand() % sizeFirstNames;
        randIndexLastName = rand() % sizeLastNames;
        randPosition = rand() % 5; //As there are 5 positions
        randHealthy = rand() % 100; //95% probability that person is healthy
        randMarketValueMultiplication = (rand() % 20) + 1;

        firstName = (*(firstNames + randIndexFirstName));
        lastName = (*(lastNames + randIndexLastName));
        fullNameSs << firstName << " " << lastName;
        fullName = fullNameSs.str();


        if (randHealthy >= 95){
            isHealthy = true;
        }else {
            isHealthy = false;
        }
        marketValue = randMarketValueMultiplication * 50000; //Marketvalue is a random number between 1 and 20 multiplied by 50000

        this->createNewPlayer(fullName, randPosition, isHealthy, marketValue);
    }
}
