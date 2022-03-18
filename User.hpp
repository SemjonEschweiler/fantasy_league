#ifndef USER_H
#define USER_H

#include "Team.hpp"
#include "player.hpp"
#include "person.hpp"

class User: public Person
{
public:
    User();
    int getBudget();
    void setBudget(int budget);
    void seePlayers();
    Player buyPlayer(int playerID);
    Player sellPlayer(int playerID);
    void seeLineup();
    Player changeStatusPlayer(int playerID);
    void displayScoreboard();

private:
    int budget;
    Team userTeam;
};

#endif // USER_H
