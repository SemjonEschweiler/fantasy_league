#include "User.hpp"

User::User(string personID, string password, int budget, Team userBudget):Person(personID, password){

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
