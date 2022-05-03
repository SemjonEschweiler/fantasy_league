#include "Team.hpp"

Team::Team(){
    _score = 0;
}
vector<Player*>* Team::getTeamStarters(){
    return &_starters;
}

vector<Player*>* Team::getTeamSubstitutes(){
    return &_substitutes;
}

vector<Player*> Team::getAllPlayers(){
    vector<Player*> allPlayers;
    allPlayers.reserve( _starters.size() + _substitutes.size() ); // preallocate memory
    allPlayers.insert( allPlayers.end(), _starters.begin(), _starters.end() );
    allPlayers.insert( allPlayers.end(), _substitutes.begin(), _substitutes.end() );
    return allPlayers;
}

void Team::displayAllPlayers(){

}

void Team::displayAllStarters(){

}

void Team::displayAllSubstitutes(){

}

int Team::getScore(){
    return _score;
}

void Team::setScore(int score){
    _score = score;
}
