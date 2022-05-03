#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Player.hpp"
#include "Person.hpp"
#include "User.hpp"
#include "Admin.hpp"
#include "User.hpp"

class Application
{
public:
    Application();
    ~Application();
    vector<Player*>* getAllPlayers();
    vector<Player*>* getAllPlayersOnMarket();
    int getSizeAllPlayers();
    int getSizeAllPlayersOnMarket();
    void displayAllPlayers();
    void displayAllPlayersOnMarket();
    void displayAllPeople();
    int assignCurrentPlayerID();
    string assignCurrentPersonID(bool isAdmin);
    User* getUserPtrFromID(string ID);
    Player* getPlayerPtrFromID(int playerID);
//With this Function you'll receive the current ID to assign it to a newly created player and immediately increment the currentPlayerID
private:
    int currentPlayerID; //Each player will have an ID with 5 digits,  10000 is the first to be given to a player
    int currentPersonID; //Each person will get assigned a 7 digit ID doesnt matter if User or Admin

    //TODO -> dynamic Memory here please!
    vector<Player*> _allPlayers; // Stores all players
    vector<Player*> _allPlayersOnMarket; // Stores all players, which are on the marketplace
    vector<Person*> _allPeople; //Stores all users and admins
    string randomFirstNames [20] = {"Paul", "Hans", "Peter", "Waldo", "Luca", "Guenther", "Kemal", "Jonah", "Johnny", "Herald", "Freddy","Patrick", "Dirk", "Lorence", "Pablo", "Gerald", "Steve", "Kobe", "Derrick","James"};
    string randomLastNames [20] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Hernandez", "Lopez", "Gonzales", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin"};
};

#endif // APPLICATION_H
