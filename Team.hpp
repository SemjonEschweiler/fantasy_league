#include <iostream>
#include "Player.hpp"

#ifndef TEAM_HPP
#define TEAM_HPP

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
    Player _substitutes[5];
    int _score;

};

#endif // TEAM_HPP
