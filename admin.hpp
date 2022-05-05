#include "Player.hpp"
#include "Person.hpp"
#include "User.hpp"
#include <iostream>
#include <string>
#include <vector>

#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin: public Person
{
public:
    Admin(string personID, string password, int* currentPlayerID, int* currentPersonID, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople);
    ~Admin();
    Player* createNewPlayer(int ID, string name, int position, bool is_able_playing, int market_value);
    void deletePlayer(int playerID);
    void addPersonToSystem(bool isAdmin, string numericID, string password, int budget);
    void updateScorePlayer(int playerID, int points, int rebounds, int assists, int steals, int blocks, int turnovers);
    void changeHealthStatusPlayer(int playerID, bool isHealthy);
    int assignCurrentPlayerID();
    string assignCurrentPersonID(bool isAdmin);
    void addPlayerToUser(int playerID, string personID);
    void displayAllPlayers();
    void displayAllPeople();
    void displayPerson();
    void createRandomPlayers(int amountOfPlayers, string *firstNames, string *lastNames, int sizeFirstNames, int sizeLastNames);

    User* getUserPtrFromID(string personID);
    void setCurrentPlayerIDPtr(int *newCurrentPlayerIDPtr);
    int *getCurrentPlayerIDPtr() const;

    int *currentPersonIDPtr() const;
    void setCurrentPersonIDPtr(int *newCurrentPersonIDPtr);

private:
    int* _currentPlayerIDPtr;
    int* _currentPersonIDPtr;
    //vector<Person*>* _allPeoplePtr; gets declared already in Person

};

#endif // ADMIN_H
