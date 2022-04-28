#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include "Player.hpp"

class Team
{
public:
    Team();
    //--> TODO change to dynamic memory
    Player * getTeamStarting();
    Player * getTeamSubstitutes();
    Player * getAllPlayers();
    void displayAllPlayers();
    void displayAllStarters();
    void displayAllSubstitutes();
    int getScore();
    void setScore(int score);

private:
    Player _starters[5];
    Player _substitutes[10];//Stores up to 10 substitutes, to store all players at the beginning in there
    int _score;

};

#endif // TEAM_HPP
