#ifndef USER_H
#define USER_H

#include "Person.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>
#include <string>

class User: public Person
{
public:
    User(string personID, string password, int budget, Team* team, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople);
    int getBudget();
    void setBudget(int budget);
    Team* getTeam();

    void seePlayers(int displayOption=0);
    void buyPlayer(int playerID);
    void sellPlayer(int playerID);
    void seeLineup();
    int changeStatusPlayer(int playerID);
    void displayScoreboard();
    void displayPerson();
    bool compareRanking(User* u1, User* u2);
    //void addPlayer(Player newPlayer);

private:
    int _budget;
    Team* _userTeam;
};

#endif // USER_H
