#include <iostream>
#include "Player.hpp"
#include <vector>

#ifndef TEAM_HPP
#define TEAM_HPP

class Team
{
public:
    Team();
    //--> TODO change to dynamic memory
    vector<Player*>* getTeamStarters();
    vector<Player*>* getTeamSubstitutes();
    vector<Player*> getAllPlayers();
    void displayAllPlayers();
    void displayAllStarters();
    void displayAllSubstitutes();
    double getScore();
    void setScore(double score);

private:
    vector<Player*> _starters;
    vector<Player*> _substitutes;//Stores up to 10 substitutes, to store all players at the beginning in there
    double _score;

};

#endif // TEAM_HPP
