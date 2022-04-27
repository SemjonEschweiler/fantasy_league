#include "Player.hpp"
#include "Person.hpp"
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
    Player *createNewPlayer(string name, int position, bool is_able_playing, int market_value);
    void deletePlayer(int playerID);
    void addPersonToSystem(bool isAdmin, int numericID, string password, int budget);
    void updateScorePlayer(int playerID, int score);
    void changeHealthStatusPlayer(int playerID, bool isHealthy);
    int assignCurrentPlayerID();
    string assignCurrentPersonID(bool isAdmin);


    void setCurrentPlayerIDPtr(int *newCurrentPlayerIDPtr);
    int *getCurrentPlayerIDPtr() const;
    void setAllPlayersPtr(vector<Player *> *newAllPlayersPtr);
    void setAllPlayersOnMarketPtr(vector<Player *> *newAllPlayersOnMarketPtr);

    int *currentPersonIDPtr() const;
    void setCurrentPersonIDPtr(int *newCurrentPersonIDPtr);

    vector<Person *> *allPeoplePtr() const;
    void setAllPeoplePtr(vector<Person *> *newAllPeople);

private:
    int* _currentPlayerIDPtr;
    int* _currentPersonIDPtr;
    vector<Player*>* _allPlayersPtr;
    vector<Player*>* _allPlayersOnMarketPtr;
    vector<Person*>* _allPeoplePtr;

};

#endif // ADMIN_H
