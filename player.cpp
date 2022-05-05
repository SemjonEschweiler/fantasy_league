#include "Player.hpp"
#include <vector>

Player::Player(){
    _name = "";
    _playerID = -1;
    _healthStatus = false;
    _userID = "";
    _marketValue = -1;
    _isStarter = false;
    _position = -1;

}

Player::Player(string name, int playerID, bool healthStatus, string userID, int marketValue, bool isStarter, int position, double score, vector<Player*>* _allPlayersPtr, vector<Player*>* _allPlayersOnMarketPtr)
{
    _name = name;
    _playerID = playerID;
    _healthStatus = healthStatus;
    _userID = userID;
    _marketValue = marketValue;
    _isStarter = isStarter;
    _position = position;
    _score = score;
    allPlayersPtr = _allPlayersPtr;
    _allPlayersPtr->push_back(this);
    _allPlayersOnMarketPtr->push_back(this);

}

Player::~Player(){/*
    for (int i=0;i< allPlayersPtr->size(); i++){
       delete (*allPlayersPtr)[i];
    }*/

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

void Player::displayPlayer(){
    cout << "Player (" << _playerID << "): " << _name << "\n\tHealth Status: " << _healthStatus << "\n\tUser Owning: " << _userID << "\n\tMarketValue: " << _marketValue << "\n\tStarting Player: " << _isStarter << "\n\tPosition: " << _position << endl << endl;
}

double Player::getScore() const
{
    return _score;
}

void Player::setScore(double newScore)
{
    _score = newScore;
}
