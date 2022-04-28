#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player
{
public:
    Player();
    ~Player();
    Player(std::string name, int playerID, bool healthStatus, std::string userID, int marketValue, bool isStarter, int position);
    std::string getName();
    int getPlayerID();
    bool getHealthStatus();
    std::string getOwningUserID();
    int getMarketValue();
    bool isStarterPlayer();
    int getPosition();
    void setName(std::string name);
    void setPlayerID(int playerID);
    void setHealthStatus(bool isHealthy);
    void setOwningUserId(std::string userID);
    void setMarketValue(int marketValue);
    void setIsStarter(bool isStarter);
    void setPosition(int position);
    void displayPlayer();

private:
    std::string _name;
    int _playerID;
    bool _healthStatus; //true for fit; false for not playing/not fit
    std::string _userID;
    int _marketValue;
    bool _isStarter;
    int _position; //0: Center, 1: Power Forward, 2: Small Forward, 3: Point Guard, 4: Shooting Guard

};

#endif // PLAYER_H
