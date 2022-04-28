#include "User.hpp"
#include <vector>

User::User(string personID, string password, int budget, Team team, vector<Person*>* _allPeople):Person(personID, password, _allPeople){
    _budget = budget;
    _userTeam = team;
}

int User::getBudget(){
    return _budget;
}

void User::setBudget(int budget){
    _budget = budget;
}

void User::seePlayers(){

}

Player User::buyPlayer(int playerID){

}

Player User::sellPlayer(int playerID){

}

void User::seeLineup(){

}

Player User::changeStatusPlayer(int playerID){

}

void User::displayScoreboard(){

}


void User::displayPerson(){
    cout << "User:  " << this->getID() << endl;
}
