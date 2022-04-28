#ifndef ADMIN_H
#define ADMIN_H

#include "Player.hpp"
#include "Person.hpp"
#include "Application.hpp"
#include <iostream>
#include <string>
#include <vector>


class Admin: public Person
{
public:
    Admin();
    //Admin(std::string personID, std::string password, Application* applicationPtr);
    Player *createNewPlayer(std::string name, int position, bool is_able_playing, int market_value);
    void deletePlayer(int playerID);
    void addPersonToSystem(bool isAdmin, int numericID, std::string password, int budget);
    void updateScorePlayer(int playerID, int score);
    void changeHealthStatusPlayer(int playerID, bool isHealthy);
    int assignCurrentPlayerID();
    std::string assignCurrentPersonID(bool isAdmin);


    void setCurrentPlayerIDPtr(int *newCurrentPlayerIDPtr);
    int *getCurrentPlayerIDPtr() const;
    void setAllPlayersPtr(std::vector<Player *> *newAllPlayersPtr);
    void setAllPlayersOnMarketPtr(std::vector<Player *> *newAllPlayersOnMarketPtr);

    int *currentPersonIDPtr() const;
    void setCurrentPersonIDPtr(int *newCurrentPersonIDPtr);

    std::vector<Person *> *allPeoplePtr() const;
    void setAllPeoplePtr(std::vector<Person *> *newAllPeople);

    void displayPerson();


};

#endif // ADMIN_H
