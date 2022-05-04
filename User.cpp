#include "User.hpp"
#include <vector>
#include <iomanip>
#include <algorithm>

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

void User::seePlayers(int displayOption){

    cout << "\n\n---------------" << endl;
    cout << "These are all players on the Market: " << endl;
    cout << left << setw(10) << "Number" << left << setw(25) << "Name" << left << setw(8) << "ID" << left << setw(15) << "Market Value" << left << setw(10) << "Position" << endl;
    vector<Player*> allPlayers;
    for (int i=0; i<(int)_allPlayersOnMarketPtr->size(); i++){
        allPlayers.push_back((*_allPlayersOnMarketPtr)[i]);
    }
    switch (displayOption) {
    case 1:
        sort(allPlayers.begin(), allPlayers.end(), [](Player* p1, Player* p2){
            return p1->getMarketValue() > p2->getMarketValue();
        });
        break;
    case 2:
        sort(allPlayers.begin(), allPlayers.end(), [](Player* p1, Player* p2){
            return p1->getPosition() < p2->getPosition();
        });
        break;
    default:
        break;
    }

    for (int i=0; i<(int)allPlayers.size(); i++){
        Player* p = allPlayers[i];
        cout << left << setw(10) << i+1 << left << setw(25) << p->getName() << left << setw(8) << p->getPlayerID() << left << setw(15) << p->getMarketValue() << left << setw(10) << p->getPosition()  << endl;
    }
}

void User::buyPlayer(int playerID){
    //subtract (if budget allows) the market value
    //erase player from marketplace
    //check if player is on marketplace and not belonging to someone
    //add player to substitutes
    //check if user has space in substitutes
    //add correct UserID
    Player* p_buy = this->getPlayerPtrFromID(playerID);
    if(p_buy){
        if (p_buy->getOwningUserID() != ""){
            cout << "Sorry this doesn't work, as the Player belongs to another User, try with a Player that is on the marketplace... " << endl;
        } else if (p_buy->getMarketValue() > this->_budget){
            cout << "Sorry, you cannot afford this player(Marketvalue: " << p_buy->getMarketValue() << ", Your Budget: " << this->_budget << "), try another one." << endl;
        } else if (this->getTeam()->getTeamSubstitutes()->size() >= 10){
            cout << "Sorry, you already have 10 substitutes, change a sub to a starter or sell a player" << endl;
        } else {
            p_buy->setOwningUserId(this->getID());
            this->setBudget(this->getBudget() - p_buy->getMarketValue());
            this->getTeam()->getTeamSubstitutes()->push_back(p_buy);
            p_buy->setIsStarter(false);
            for (int i=0; i<(int)_allPlayersOnMarketPtr->size();i++){
                if ((*_allPlayersOnMarketPtr)[i]->getPlayerID()==playerID){
                    _allPlayersOnMarketPtr->erase(_allPlayersOnMarketPtr->begin() + i);
                }
            }
        }
    }else{
       cout << "Sorry this Player does not exist" << endl;
    }

}

void User::sellPlayer(int playerID){
    //Put player on Market
    //Erase player from either subs or starters
    //check if player is part of user Team
    //Add Marketvalue to budget
    //Erase User ID
    Player* p_sell = this->getPlayerPtrFromID(playerID);
    if(p_sell){
        if (p_sell->getOwningUserID() != this->getID()){
            cout << "Sorry, this player does not belong to you, you cannot sell him." << endl;
        }else {
            this->setBudget(this->getBudget() + p_sell->getMarketValue());
            _allPlayersOnMarketPtr->push_back(p_sell);
            vector<Player*>* subs = this->getTeam()->getTeamSubstitutes();
            vector<Player*>* starters = this->getTeam()->getTeamStarters();
            p_sell->setOwningUserId("");
            p_sell->setIsStarter(false);
            for (int i=0; i<(int)subs->size();i++){
                if ((*subs)[i]->getPlayerID()==playerID){
                    cout << "Erased Player from subs" << endl;
                    subs->erase(subs->begin() + i);
                }
            }
            for (int i=0; i<(int)starters->size();i++){
                if ((*starters)[i]->getPlayerID()==playerID){
                    cout << "Erased Player from starters" << endl;
                    starters->erase(starters->begin() + i);
                }
            }
        }
    }else{
        cout << "Sorry this Player does not exist" << endl;
    }

}

void User::seeLineup(){
    cout << "\n---------------\n" << endl;
    cout << "This is the lineup: \n" << endl;

    cout << "--------Starters--------" <<endl;
    cout << left << setw(10) << "Number" << left << setw(25) << "Name" << left << setw(8) << "ID" << left << setw(12) << "Market Value" << endl;

    for (int i=0; i<(int)this->getTeam()->getTeamStarters()->size(); i++){
        Player* p = (*this->getTeam()->getTeamStarters())[i];
        cout << left << setw(10) << i << left << setw(25) << p->getName() << left << setw(8) << p->getPlayerID() << left << setw(12) << p->getMarketValue() << endl;
    }
    cout << endl;

    cout << "--------Substitutes--------" <<endl;
    cout << left << setw(10) << "Number" << left << setw(25) << "Name" << left << setw(8) << "ID" << left << setw(12) << "Market Value" << endl;

    for (int i=0; i<(int)this->getTeam()->getTeamSubstitutes()->size(); i++){
        Player* p = (*this->getTeam()->getTeamSubstitutes())[i];
        cout << left << setw(10) << i << left << setw(25) << p->getName() << left << setw(8) << p->getPlayerID() << left << setw(12) << p->getMarketValue() << endl;
    }

}

int User::changeStatusPlayer(int playerID) {
    Player* p = getPlayerPtrFromID(playerID);
    if (p->getOwningUserID() != this->getID()){
        cout << "You cannot change the Status of a Player that does not belong to your team!" << endl;
    }else{
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
}

void User::displayScoreboard(){
    vector<User*> userRanking;
    cout << "\n-------------" << endl;
    cout << "This is the scoreboard: " << endl << endl;
    cout << left << setw(10) << "Ranking" << left << setw(15) << "User ID" << left << setw(15) << "Score" << endl;
    for (int i=0;i<(int)_allPeoplePtr->size();i++){
        if ((*_allPeoplePtr)[i]->getID()[0] == 'U'){
                User* u = dynamic_cast<User*>((*_allPeoplePtr)[i]);
                userRanking.push_back(u);
        }
    }

    //sort(userRanking->begin(), userRanking->end(), compareRanking);
    sort(userRanking.begin(), userRanking.end(), [](const User* u1, const User* u2){
        return u1->_userTeam->getScore() > u2->_userTeam->getScore();
    });
    for (int i=0;i<(int)userRanking.size();i++){
        cout << left << setw(10) << i+1 << left << setw(15) << userRanking[i]->getID() << left << setw(15) << userRanking[i]->getTeam()->getScore() << endl;
    }
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
