#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Player.hpp"
#include "Person.hpp"
#include "Admin.hpp"

class Application
{
public:
    Application();
    ~Application();
    std::vector<Player*>* getAllPlayersPtr();
    std::vector<Player*>* getAllPlayersOnMarketPtr();
    std::vector<Person*>* getAllPeoplePtr();
    void displayAllPlayers();
    void displayAllPlayersOnMarket();
    int assignCurrentPlayerID();
    std::string assignCurrentPersonID(bool isAdmin);

    //With this Function you'll receive the current ID to assign it to a newly created player and immediately increment the currentPlayerID
    int getCurrentPlayerID() const;
    void setCurrentPlayerID(int newCurrentPlayerID);

    int getCurrentPersonID() const;
    void setCurrentPersonID(int newCurrentPersonID);

private:
    int currentPlayerID; //Each player will have an ID with 5 digits,  10000 is the first to be given to a player
    int currentPersonID; //Each person will get assigned a 7 digit ID doesnt matter if User or Admin

    std::vector<Player*> _allPlayers; // Stores all players
    std::vector<Player*> _allPlayersOnMarket; // Stores all players, which are on the marketplace
    std::vector<Person*> _allPeople; //Stores all users and admins

};

#endif // APPLICATION_H
