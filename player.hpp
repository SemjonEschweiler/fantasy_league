#include <iostream>
#include <string>
#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;

class Player
{
public:
    Player();
    string getName();
    int getPlayerID();
    bool getHealthStatus();
    string getOwningUserID();
    int getMarketValue();
    bool isStarterPlayer();
    int getPosition();
    void setName(string name);
    void setPlayerID(int playerID);
    void setHealthStatus(bool isHealthy);
    void setOwningUserId(string userID);
    void setMarketValue(int marketValue);
    void setIsStarter(bool isStarter);
    void setPosition(int position);

private:
    string name;
    int playerID;
    bool healthStatus; //true for healthy false for not playing/unhealthy
    string userID;
    int marketValue;
    bool isStarter;
    int position; //0: Center, 1: Power Forward, 2: Small Forward, 3: Point Guard, 4: Shooting Guard

};

#endif // PLAYER_HPP
