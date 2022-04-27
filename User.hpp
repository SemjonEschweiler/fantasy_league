#ifndef USER_H
#define USER_H

#include "Team.hpp"
#include "Player.hpp"
#include "Person.hpp"

class User: public Person
{
public:
    User(string personID, string password, int budget, Team userBudget);
    int getBudget();
    void setBudget(int budget);
    Team getTeam();

    void seePlayers();
    Player buyPlayer(int playerID);
    Player sellPlayer(int playerID);
    void seeLineup();
    Player changeStatusPlayer(int playerID);
    void displayScoreboard();

private:
    int _budget;
    Team _userTeam;
};

#endif // USER_H
