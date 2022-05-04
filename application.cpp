#include "Application.hpp"
#include <string>
#include <iostream>
#include <sstream>

//1.0.0
using namespace std;

Application::Application(){
    currentPlayerID = 10000; //ID with 5 digits for players
    currentPersonID = 1000000;


//Initializes all Users, Admins (maybe also Teams and Player -> could also be done by an Admin)
/* These should be created by the Admin
    Player nowitzki = Player("Dirk Nowitzki", 1000001, true, "U1234567", 2000, false, 2);
    Player bryant = Player("Kobe Bryant", 1000002, true, "U1234567", 2000, true, 2);
    Player durant = Player("Kevin Durant", 1000003, true, "U1234567", 2000, true, 2);
*/
    //Team dallas = Team();
    Admin admin = Admin(assignCurrentPersonID(true), "helloworld", &currentPlayerID, &currentPersonID, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

    //User user = User(assignCurrentPersonID(false), "helloworld", 100000, dallas, &_allPeople);
    //cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;
    //cout << "assignCurrentPersonID(true): " << assignCurrentPersonID(true) << endl;
    //cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;

    admin.createNewPlayer("Dirk Nowitzki", 2, true, 10000);
    cout << "application: admin created Player" << endl;
    admin.createNewPlayer("Kobe Bryant", 2, true, 20000);
    admin.createNewPlayer("Kevin Durant", 2, true, 10000);

    this->displayAllPlayers();
    this->displayAllPlayersOnMarket();

    admin.deletePlayer(10001);

    this->displayAllPlayers();
    this->displayAllPlayersOnMarket();

    //this->displayAllPeople();

    //start of
    admin.createRandomPlayers(5, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));

    //admin.addPersonToSystem(true, 123, "hello", 1000000);
    admin.addPersonToSystem(false, 123, "hello", 1000000);

    admin.createRandomPlayers(7, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));
    admin.addPersonToSystem(false, 123, "hello", 1000000);
    admin.createRandomPlayers(21, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));
    admin.addPersonToSystem(false, 123, "hello", 1000000);
    admin.addPersonToSystem(false, 123, "hello", 1000000);

    //_allPeople[2]->displayPerson();


    this->displayAllPeople();
    this->displayAllPlayers();


    cout << "Updating Score now --> 10000" << endl;
    getPlayerPtrFromID(10000)->displayPlayer();

    User* mainUser = this->getUserPtrFromID("U1000001");
    cout << "Starting Budget is: " << mainUser-> getBudget() << endl;


    Player* firstPlayer = getPlayerPtrFromID(10003);

    firstPlayer->displayPlayer();
    admin.deletePlayer(10003);

    cout << "After first deletion: " << mainUser-> getBudget() << endl;


    this->displayAllPlayers();
    mainUser->changeStatusPlayer(10007);
    mainUser->changeStatusPlayer(10006);
    mainUser->changeStatusPlayer(10004);
    mainUser->changeStatusPlayer(10000);

    admin.changeHealthStatusPlayer(10000, false);
    admin.updateScorePlayer(10000, 10);
    admin.changeHealthStatusPlayer(10000, true);
    admin.updateScorePlayer(10000, 8);
    admin.updateScorePlayer(10000, 3);
    mainUser->changeStatusPlayer(10000);
    admin.updateScorePlayer(10000, 1);

    admin.updateScorePlayer(10010, 32);
    srand ( time(NULL) );
    cout << "_allPlayers.size(): " << _allPlayers.size() << endl;
    for (int i=0; i<(int)_allPlayers.size();i++){
        int randNum = rand() % 100 + 1;
        if (randNum <= 60){
            User* u = this->getUserPtrFromID(_allPlayers[i]->getOwningUserID());
            if (u){
                u->changeStatusPlayer(_allPlayers[i]->getPlayerID());
            }else{
                cout << "This player doesn't have a user, therefore he cannot change status." << endl;
            }

        }
        admin.updateScorePlayer(_allPlayers[i]->getPlayerID(), randNum);
    }

    cout << "Score of Team: " << getUserPtrFromID("U1000001")->getTeam()->getScore() << endl;

    mainUser->seePlayers();

    this->displayAllPlayers();


    admin.createNewPlayer("Kobe Bryant", 2, true, 1000);
    mainUser->seePlayers();
    mainUser->buyPlayer(10008);
    mainUser->changeStatusPlayer(10008);
    mainUser->seeLineup();

    mainUser->seePlayers();
    cout << "Print Budget of User after buy: " << mainUser->getBudget() << endl;
    mainUser->sellPlayer(10008);
    mainUser->seePlayers();
    cout << "Print Budget of User after sell: " << mainUser->getBudget() << endl;

    mainUser->seeLineup();
    mainUser->displayScoreboard();
    mainUser->seePlayers();
    mainUser->seePlayers(1);
    mainUser->seePlayers(2);

    cout << "Program Finished!" << endl;
}

Application::~Application(){

}

vector<Player*>* Application::getAllPlayers(){
    return &_allPlayers;
}

vector<Player*>* Application::getAllPlayersOnMarket(){
    return &_allPlayersOnMarket;
}

void Application::displayAllPlayers(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players (" << _allPlayers.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPlayers.size(); i++){
        _allPlayers[i]->displayPlayer();
    }
    cout << "-------------------\n";
}

void Application::displayAllPlayersOnMarket(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players on Market (" << _allPlayersOnMarket.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPlayersOnMarket.size(); i++){
        _allPlayersOnMarket[i]->displayPlayer();
    }
    cout << "-------------------\n";
}

void Application::displayAllPeople(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all People registered in System (" << _allPeople.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPeople.size(); i++){
        _allPeople[i]->displayPerson();
    }
    cout << "-------------------\n";
}

/*
int Application::assignCurrentPlayerID(){
    currentPlayerID += 1;
    return (currentPlayerID - 1);
}
*/
string Application::assignCurrentPersonID(bool isAdmin){
    //this function assigns the next PersonID and updates the currentPersonID
    stringstream aux;
    if (isAdmin){
        aux << "A" << currentPersonID;
    }else{
        aux << "U" << currentPersonID;
    }
    currentPersonID += 1;
    return aux.str();
}

User* Application::getUserPtrFromID(string personID){
    char firstChar = personID[0];
    if (firstChar == 'A'){
        cout << "Error: You can not obtain a User if you are giving an Admin ID" << endl;
        return nullptr;
    }

    for (int i=0; i < (int) _allPeople.size();i++){
        if (personID == _allPeople[i]->getID()){
            return dynamic_cast<User*> (_allPeople[i]);
        }
    }
    cout << "Error: Person not found" << endl;
    return nullptr;
}

Player* Application::getPlayerPtrFromID(int playerID){
    for (int i=0; i < (int) _allPlayers.size(); i++){
        if (playerID == _allPlayers[i]->getPlayerID()){
            return _allPlayers[i];
        }
    }
}

