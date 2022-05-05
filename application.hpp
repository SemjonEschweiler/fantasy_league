#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Player.hpp"
#include "Person.hpp"
#include "User.hpp"
#include "Admin.hpp"

class Application
{
public:
    Application();
    ~Application();
    void loadFromFiles(string peoplePath, string playerPath);
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
    Person* getPersonPtrFromID(string personID);
    Player* getPlayerPtrFromID(int playerID);
    void login();
    int mainMenu();
    const string &getCurrentLoggedInID() const;
    void setCurrentLoggedInID(const string &newCurrentLoggedInID);

    void storeToFiles(string peoplePath, string playerPath);
private:
    int currentPlayerID; //Each player will have an ID with 5 digits,  10000 is the first to be given to a player
    int currentPersonID; //Each person will get assigned a 7 digit ID doesnt matter if User or Admin
    string _currentLoggedInID;

    vector<Player*> _allPlayers; // Stores all players
    vector<Player*> _allPlayersOnMarket; // Stores all players, which are on the marketplace
    vector<Person*> _allPeople; //Stores all users and admins
    string randomFirstNames [20] = {"Paul", "Hans", "Peter", "Waldo", "Luca", "Guenther", "Kemal", "Jonah", "Johnny", "Herald", "Freddy","Patrick", "Dirk", "Lorence", "Pablo", "Gerald", "Steve", "Kobe", "Derrick","James"};
    string randomLastNames [20] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Hernandez", "Lopez", "Gonzales", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin"};
};

#endif // APPLICATION_H
