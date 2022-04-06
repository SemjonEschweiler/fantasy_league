#ifndef APPLICATION_H
#define APPLICATION_H

#include "Player.hpp"

class Application
{
public:
    Application();
    Player * getAllPlayers();
    Player * getAllPlayersOnMarket();
    void displayAllPlayers();
    void displayAllPlayersOnMarket();

private:
    //TODO -> dynamic Memory here please!
    Player _allPlayers[1000];
    Player _allPlayersOnMarket[1000];

};

#endif // APPLICATION_H
