#include "User.hpp"
#include <vector>

User::User(string personID, string password, int budget, Team* team, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople):Person(personID, password, _allPlayers, _allPlayersOnMarket, _allPeople){
    _budget = budget;
    _userTeam = team;

    //Update Person and add functions from admin there, so user can also access it.
    //Test functionality of update score
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

int User::changeStatusPlayer(int playerID){
    Player* p = getPlayerPtrFromID(playerID);
    vector<Player*>* starters = _userTeam->getTeamStarters();
    vector<Player*>* subs = _userTeam->getTeamSubstitutes();
    if (p->isStarterPlayer() == true){
        if (subs->size() >= 10){
            cout << "You cannot have more than 10 players on the bench. Try adding a player to the starters or sell a player" << endl;
        }else {
            for (int i=0; i< (int)starters->size();i++){
                if ((*starters)[i]->getPlayerID() == playerID){
                    Player* p = (*starters)[i];
                    subs->push_back(p);
                    starters->erase(starters->begin() + i);
                    p->setIsStarter(false);
                    cout << "Player was found in the starters, now he is a substitute!" << endl;
                }
            }
        }
    }else{
        if (starters->size() >= 5){
            cout << "You cannot have more than 5 players starting. Try adding a player to the substitutes or sell a player" << endl;

        }else{
            for (int i=0; i< (int)subs->size();i++){
                if ((*subs)[i]->getPlayerID() == playerID){
                    Player* p = (*subs)[i];
                    starters->push_back(p);
                    subs->erase(subs->begin() + i);
                    p->setIsStarter(true);
                    cout << "Player was found in the substitutes, now he is a starter!" << endl;
                }
            }
        }
    }
}

void User::displayScoreboard(){

}


void User::displayPerson(){
    cout << "User:  " << this->getID() << endl;
}

Team* User::getTeam(){
    return _userTeam;
}

/*
void User::addPlayer(Player newPlayer){

}
*/
