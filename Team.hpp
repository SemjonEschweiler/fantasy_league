#include <iostream>
#include "player.hpp"

#ifndef TEAM_HPP
#define TEAM_HPP

class Team
{
public:
    Team();
    //--> TODO
    Player * getTeamStarting();
    Player * getTeamSubstitutes();
    Player * getAllPlayers();
    void displayAllPlayers();
    void displayAllStarters();
    void displayAllSubstitutes();
    int getScore();
    void setScore(int score);

private:
    Player starters[5];
    Player substitutes[5];
    int score;

};

#endif // TEAM_HPP
