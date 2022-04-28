#ifndef USER_H
#define USER_H

#include "Team.hpp"
#include "Player.hpp"
#include "Person.hpp"
#include "Application.hpp"

class User: public Person
{
public:
    User(std::string personID, std::string password, int budget, Team userBudget, Application* applicationPtr);
    int getBudget();
    void setBudget(int budget);
    Team getTeam();

    void seePlayers();
    Player buyPlayer(int playerID);
    Player sellPlayer(int playerID);
    void seeLineup();
    Player changeStatusPlayer(int playerID);
    void displayScoreboard();
    void displayPerson();

private:
    int _budget;
    Team _userTeam;
};

#endif // USER_H
