#include "Player.hpp"
#include "Person.hpp"
#include <iostream>
#include <string>

#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin: public Person
{
public:
    Admin();
    Player createNewPlayer(string name, int position, bool is_able_playing, int market_value);
    void deletePlayer(int playerID);
    void addPersonToSystem(bool isAdmin, int numericID, string password, int budget);
    void updateScorePlayer(int playerID, int score);
    void changeHealthStatusPlayer(int playerID, bool isHealthy);
};

#endif // ADMIN_H
