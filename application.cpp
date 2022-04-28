#include "Application.hpp"
#include "Player.hpp"
#include "Admin.hpp"
#include "User.hpp"
#include <string>
#include <iostream>
#include <sstream>

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
    Team dallas = Team();
    //Admin* admin = new Admin(assignCurrentPersonID(true), "helloworld", this);

    User user = User(assignCurrentPersonID(false), "helloworld", 100000, dallas, this);
    cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;
    cout << "assignCurrentPersonID(true): " << assignCurrentPersonID(true) << endl;
    cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;

    /*
    admin.createNewPlayer("Dirk Nowitzki", 2, true, 10000);
    cout << "application: admin created Player" << endl;
    admin.createNewPlayer("Kobe Bryant", 2, true, 20000);
    admin.createNewPlayer("Kevin Durant", 2, true, 10000);

    admin.deletePlayer(10001);
*/


    this->displayAllPlayers();
    this->displayAllPlayersOnMarket();
}

Application::~Application(){

}

vector<Player*>* Application::getAllPlayersPtr(){
    return &_allPlayers;
}

vector<Player*>* Application::getAllPlayersOnMarketPtr(){
    return &_allPlayersOnMarket;
}

vector<Person*>* Application::getAllPeoplePtr(){
    return &_allPeople;
}

void Application::displayAllPlayers(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players (" << _allPlayers.size() << "): " << endl;
    cout << "-------------------\n\n";
    for (int i=0; i< (int)_allPlayers.size(); i++){
        _allPlayers[i]->displayPlayer();
    }
}

void Application::displayAllPlayersOnMarket(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players on Market (" << _allPlayersOnMarket.size() << "): " << endl;
    cout << "-------------------\n\n";
    for (int i=0; i< (int)_allPlayersOnMarket.size(); i++){
        _allPlayersOnMarket[i]->displayPlayer();
    }
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

int Application::getCurrentPlayerID() const
{
    return currentPlayerID;
}

void Application::setCurrentPlayerID(int newCurrentPlayerID)
{
    currentPlayerID = newCurrentPlayerID;
}

int Application::getCurrentPersonID() const
{
    return currentPersonID;
}

void Application::setCurrentPersonID(int newCurrentPersonID)
{
    currentPersonID = newCurrentPersonID;
}
