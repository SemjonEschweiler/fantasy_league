#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "player.hpp"

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
    Player allPlayers[1000];
    Player allPlayersOnMarket[1000];
};

#endif // APPLICATION_HPP
