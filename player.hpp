#include <iostream>
#include <string>
#include <vector>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
public:
    Player();
    ~Player();
    Player(string name, int playerID, bool healthStatus, string userID, int marketValue, bool isStarter, int position, vector<Player*>* _allPlayersPtr, vector<Player*>* _allPlayersOnMarketPtr);
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
    void displayPlayer();

    double getScore() const;
    void setScore(double newScore);

private:
    string _name;
    double _score;
    int _playerID;
    bool _healthStatus; //true for fit; false for not playing/not fit
    string _userID;
    int _marketValue;
    bool _isStarter;
    int _position; //0: Center, 1: Power Forward, 2: Small Forward, 3: Point Guard, 4: Shooting Guard

};

#endif // PLAYER_H
