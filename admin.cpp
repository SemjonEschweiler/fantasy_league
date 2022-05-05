#include "Admin.hpp"
#include "User.hpp"
#include "Team.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

Admin::Admin(string personID, string password, int* currentPlayerID, int* currentPersonID, vector<Player*>* _allPlayers, vector<Player*>* _allPlayersOnMarket, vector<Person*>* _allPeople): Person(personID, password, _allPlayers, _allPlayersOnMarket, _allPeople){

    _currentPlayerIDPtr = currentPlayerID;
    _currentPersonIDPtr = currentPersonID;
    _allPlayersPtr = _allPlayers;
    _allPlayersOnMarketPtr = _allPlayersOnMarket;
    _allPeoplePtr = _allPeople;
}

Admin::~Admin(){

}

Player* Admin::createNewPlayer(int ID, string name, int position, bool is_able_playing, int market_value){
    Player* newplayer = new Player(name, ID, is_able_playing, "", market_value, false, position, 0, _allPlayersPtr, _allPlayersOnMarketPtr);

    //TODO add to different lists market and allplayers
    cout << "Creation of player worked: " << endl;
    newplayer->displayPlayer();
    return newplayer;
}

void Admin::deletePlayer(int playerID){
    // Frees Player from both vectors and releases memory
    // Add functionality: Give User the amount of money what the deleted player is worth.


    //This for loop deletes the Player from the _allPlayers vector and deletes Player from User vectors(starters or substitutes)
    string owningUserID;
    for (int i=0;i < (int) _allPlayersPtr->size(); i++){
        if ((*_allPlayersPtr)[i]->getPlayerID() == playerID){
            bool searchInUser = true;
            owningUserID = (*_allPlayersPtr)[i]->getOwningUserID();
            User* owningUser;
            Team* owningTeam;
            try {
                owningUser = getUserPtrFromID(owningUserID);
                owningTeam = owningUser->getTeam();
            } catch (...) {
                searchInUser = false;
            }

            if (searchInUser == true){
                int deleteIndex = -1;
                //Search in Substitutes if player exists there
                vector<Player*>* substitutes = owningTeam->getTeamSubstitutes();
                for (int i=0; i<(int) substitutes->size(); i++){
                    if ((*substitutes)[i]->getPlayerID() == playerID){
                        cout << "Found Player in Substitutes! " << endl;
                        int marketValuePlayer = (*substitutes)[i]->getMarketValue();
                        owningUser->setBudget(owningUser->getBudget()+marketValuePlayer);
                        deleteIndex = i;
                        //(*owningTeam->getTeamSubstitutes())[i] = new Player();
                    }
                }

                if (deleteIndex != -1){
                    substitutes->erase(substitutes->begin() + deleteIndex);
                }
                deleteIndex = -1;
                vector<Player*>* starters = owningTeam->getTeamStarters();
                //Search in Starters if player exists there
                for (int i=0; i<(int) starters->size(); i++){
                    if ((*starters)[i]->getPlayerID() == playerID){
                        cout << "Found Player in Starters! " << endl;
                        int marketValuePlayer = (*starters)[i]->getMarketValue();
                        owningUser->setBudget(owningUser->getBudget()+marketValuePlayer);
                        deleteIndex = i;
                    }
                }
                if (deleteIndex != -1){
                    starters->erase(starters->begin() + deleteIndex);
                }
            }
            cout << "delete this guy: " << (*_allPlayersPtr)[i]->getName() << endl;
           _allPlayersPtr->erase(_allPlayersPtr->begin() + i); // remove Player from all Players vector

        }
    }

    //This loop deletes the Player from _allPlayersOnMarket vector
    for (int i=0;i < (int) _allPlayersOnMarketPtr->size(); i++){
        if ((*_allPlayersOnMarketPtr)[i]->getPlayerID() == playerID){
            delete (*_allPlayersOnMarketPtr)[i]; // delete PLayer to avoid memory leak
            _allPlayersOnMarketPtr->erase(_allPlayersOnMarketPtr->begin() + i); // remove Player from all Players vector

        }
    }
}

void Admin::addPersonToSystem(bool isAdmin, string numericID, string password, int budget){

    //Adds a person to the system (either User or Admin) if it is a Person it will get a budget too
    if (isAdmin == 1){
        cout << "this->assignCurrentPersonID(isAdmin): " << this->assignCurrentPersonID(isAdmin) << endl;
        cout << "this->getAllPeoplePtr(): " << this->getAllPeoplePtr() << endl;
        Admin* newadmin = new Admin(numericID, password, _currentPlayerIDPtr, _currentPersonIDPtr, _allPlayersPtr, _allPlayersOnMarketPtr, this->getAllPeoplePtr());
    }else{
        if ((*_allPlayersOnMarketPtr).size() >= 7){
            Team* newteam = new Team();
            srand ( time(NULL) );
            User* newuser = new User(numericID, password, budget, newteam, _allPlayersPtr, _allPlayersOnMarketPtr, this->getAllPeoplePtr());
            int randIndex;
            bool wasPlayerAdded;
            cout << "All declarations worked" << endl;
            for (int i=0; i<7; i++){//Adding 7 players
                //add Player to User(to do so add the UserID to Player/Team (Add Player to Substitutes of a team)
                randIndex = rand() % _allPlayersOnMarketPtr->size();
                (*_allPlayersOnMarketPtr)[randIndex]->setOwningUserId(newuser->getID());
                //newuser.addPlayer(*(*_allPlayersOnMarketPtr)[randIndex]);
                wasPlayerAdded = false;
                for (int i=0; i< (int) sizeof(newuser->getTeam()->getTeamSubstitutes()); i++){
                    if (wasPlayerAdded == false){
                        if (newuser->getTeam()->getTeamSubstitutes()->size() <= 10)
                        {
                        Player* addThisPlayer = (*_allPlayersOnMarketPtr)[randIndex];
                        (*newuser->getTeam()->getTeamSubstitutes()).push_back( addThisPlayer);
                        wasPlayerAdded = true;
                        cout << "Player has been added to substitutes" << endl;
                        }else{

                        }

                     }
                }

                _allPlayersOnMarketPtr->erase(_allPlayersOnMarketPtr->begin() + randIndex);
            }
        }else {
            cout << "Marketplace has less than 7 players, therefore new User cannot be created." << endl;
        }
    }
}

void Admin::updateScorePlayer(int playerID, int points, int rebounds, int assists, int steals, int blocks, int turnovers){
    //score will get calculated according to this website: https://sports.yahoo.com/how-to-navigate-fantasy-basketball-points-leagues-in-202021-182530803.html
    //And then will the score devided by 5, if the score is higher then 10
    double score = points * 1 + rebounds * 1.2 + assists * 1.5 + steals * 3 + blocks * 3 + turnovers * -1;
    score /= 5;
    if (score > 10){
        score = 10;
    }

    cout << "Changing the Score of Player(" << playerID << ") to " << score << "... ";
    string owningUserID;
    //This for loop obtains the owning UserID of the User who owns the Player

    for (int i=0; i< (int) _allPlayersPtr->size();i++){
        if (playerID == (*_allPlayersPtr)[i]->getPlayerID()){
            owningUserID = (*_allPlayersPtr)[i]->getOwningUserID();
        }
    }
    if (owningUserID == ""){
        cout << "Player does not belong to a User therefore score doesn't get updated. --> Done!" << endl;
        return;
    }else{

        //this finds the User by the UserID
        User* cUser = getUserPtrFromID(owningUserID);
        Player* player = getPlayerPtrFromID(playerID);
        if ((player->isStarterPlayer() == true) && (player->getHealthStatus() == true)){
            cUser->getTeam()->setScore(cUser->getTeam()->getScore() + score);
            player->setScore(player->getScore()+score);
        }
        cout << "Done!" << endl;
        cout << "This is the updated score now: (TeamScore: " << cUser->getTeam()->getScore() << ", PlayerScore: " << player->getScore() << ")" << endl;
    }
}


void Admin::changeHealthStatusPlayer(int playerID, bool isHealthy){
    cout << "Changing the Healthstatus of Player(" << playerID << ") to " << isHealthy << "... ";
    Player* p = getPlayerPtrFromID(playerID);
    p->setHealthStatus(isHealthy);
    cout << "Done!" << endl;
}

void Admin::setCurrentPlayerIDPtr(int *newCurrentPlayerIDPtr)
{
    _currentPlayerIDPtr = newCurrentPlayerIDPtr;
}

int* Admin::getCurrentPlayerIDPtr() const
{
    return _currentPlayerIDPtr;
}

int *Admin::currentPersonIDPtr() const
{
    return _currentPersonIDPtr;
}

void Admin::setCurrentPersonIDPtr(int *newCurrentPersonIDPtr)
{
    _currentPersonIDPtr = newCurrentPersonIDPtr;
}

int Admin::assignCurrentPlayerID(){
    //this function assigns the next PlayerID and updates the currentPlayerID
    *_currentPlayerIDPtr += 1;
    return (*_currentPlayerIDPtr - 1);
}

string Admin::assignCurrentPersonID(bool isAdmin){
    //this function assigns the next PersonID and updates the currentPersonID
    stringstream aux;
    if (isAdmin){
        aux << "A" << *_currentPersonIDPtr;
    }else{
        aux << "U" << *_currentPersonIDPtr;
    }
    *_currentPersonIDPtr += 1;
    return aux.str();
}


void Admin::displayPerson(){
    cout << "Admin: " << this->getID() << endl;
}

void Admin::createRandomPlayers(int amountOfPlayers, string *firstNames, string *lastNames, int sizeFirstNames, int sizeLastNames)
{
    int randIndexFirstName, randIndexLastName, randPosition, randHealthy, randMarketValueMultiplication, marketValue;
    string firstName, lastName, fullName;
    stringstream fullNameSs;
    bool isHealthy;

    srand ( time(NULL) );

    cout << "Declaration of variables worked" << endl;

    for (int i=0; i<amountOfPlayers; i++){
        fullNameSs.str(std::string());
        randIndexFirstName = rand() % sizeFirstNames;
        randIndexLastName = rand() % sizeLastNames;
        randPosition = rand() % 5; //As there are 5 positions
        randHealthy = rand() % 100; //95% probability that person is healthy
        randMarketValueMultiplication = (rand() % 20) + 1;

        firstName = (*(firstNames + randIndexFirstName));
        lastName = (*(lastNames + randIndexLastName));
        fullNameSs << firstName << " " << lastName;
        fullName = fullNameSs.str();


        if (randHealthy >= 95){
            isHealthy = false;
        }else {
            isHealthy = true;
        }
        marketValue = randMarketValueMultiplication * 50000; //Marketvalue is a random number between 1 and 20 multiplied by 50000

        //this->createNewPlayer(fullName, randPosition, isHealthy, marketValue);
    }
}

User* Admin::getUserPtrFromID(string personID){
    char firstChar = personID[0];
    if (firstChar == 'A'){
        throw "Error: You can not obtain a User if you are giving an Admin ID";
    }
    for (int i=0; i < (int) _allPeoplePtr->size();i++){
        if (personID == (*_allPeoplePtr)[i]->getID()){
            return dynamic_cast<User*> ((*_allPeoplePtr)[i]);
        }
    }

    throw "Error: Person not found";
}

void Admin::addPlayerToUser(int playerID, string personID)
{
    User* u = dynamic_cast<User*>(getPersonPtrFromID(personID));
    for (int i=0;i<(int)_allPlayersOnMarketPtr->size();i++){
        if ((*_allPlayersOnMarketPtr)[i]->getPlayerID() == playerID){
            Player* p = (*_allPlayersOnMarketPtr)[i];
            u->getTeam()->getTeamSubstitutes()->push_back(p);
            _allPlayersOnMarketPtr->erase(_allPlayersOnMarketPtr->begin() + i);
        }
    }

}

void Admin::displayAllPlayers(){
    this->displayPlayerHeader();
    for (int i=0; i<(int)_allPlayersPtr->size(); i++){
        Player* p = (*_allPlayersPtr)[i];
        this->displayPlayerData(p, i);
    }
}

void Admin::displayAllPeople(){
    for (int i=0; i<(int)_allPeoplePtr->size(); i++){
        cout << i +1 << ":" << (*_allPeoplePtr)[i]->getID() << endl;
    }
}
