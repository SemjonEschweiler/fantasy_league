#include "Player.hpp"

Player::Player(){
    _name = "";
    _playerID = -1;
    _healthStatus = false;
    _userID = "";
    _marketValue = -1;
    _isStarter = false;
    _position = -1;

}

Player::Player(string name, int playerID, bool healthStatus, string userID, int marketValue, bool isStarter, int position)//creates a dummy player
{
    _name = name;
    _playerID = playerID;
    _healthStatus = healthStatus;
    _userID = userID;
    _marketValue = marketValue;
    _isStarter = isStarter;
    _position = position;

}

string Player::getName(){
    return _name;
}

int Player::getPlayerID(){
    return _playerID;
}

bool Player::getHealthStatus(){
    return _healthStatus;
}

string Player::getOwningUserID(){
    return _userID;
}

int Player::getMarketValue(){
    return _marketValue;
}

bool Player::isStarterPlayer(){
    return _isStarter;
}

int Player::getPosition(){
    return _position;
}

void Player::setName(string name){
    _name = name;
}

void Player::setPlayerID(int playerID){
    _playerID = playerID;
}

void Player::setHealthStatus(bool isHealthy){
    _healthStatus = isHealthy;
}

void Player::setOwningUserId(string userID){
    _userID = userID;
}

void Player::setMarketValue(int marketValue){
    _marketValue = marketValue;
}

void Player::setIsStarter(bool isStarter){
    _isStarter = isStarter;
}

void Player::setPosition(int position){
    _position = position;
}
