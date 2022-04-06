#include "Team.hpp"

Team::Team(){

}
Player * Team::getTeamStarting(){
    return _starters;
}

Player * Team::getTeamSubstitutes(){
    return _substitutes;
}

Player * Team::getAllPlayers(){

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
