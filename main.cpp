#include <iostream>
#include "Application.hpp"
#include "Admin.hpp"
#include "Person.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "User.hpp"

using namespace std;

void func1(int numVal) {
    numVal++;
}

// function that takes reference as parameter
// notice the & before the parameter
void func2(int &numRef) {
    numRef++;
}

int main() // calls the application
{
    Application app = Application();

    /*int var1 = 1;
    int* pointVar;
    pointVar = &var1;

    *pointVar = 5;
    cout << *pointVar << endl;
    cout << var1 << endl;
    cout << pointVar << endl;
    cout << &var1 << endl;

    int* arrPointer;
    int arr[5] = {0,1,2,3,4};
    arrPointer = arr;
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
    int i = 1;
    cout << i++ << endl;

    cout << arrPointer << endl;
    arrPointer += 2;
    cout << arrPointer << endl;
    cout << *arrPointer << endl;

    cout << "Funcitons & Pointers: " << endl;

    int num = 5;
    cout << num << endl;
    // pass by value
    func1(num);

    cout << num << endl;
    // pass by reference
    func2(num);
    cout << num << endl;

*/
/*
    //Test if functions of Application can be called
    cout << endl << endl << "Test Application:" << endl;
    cout << app.getAllPlayers() << endl;
    cout << app.getAllPlayersOnMarket() << endl;


    //Test if functions of Admin can be called
    cout << endl << endl << "Test Admin:" << endl;
    admin.deletePlayer(1234567); // right now nothing will be deleted
    cout << admin.getID() << endl;
    cout << admin.getPassword() << endl;

    //Test if functions of User can be called
    cout << endl << endl << "Test User:" << endl;
    cout << user.getID() << endl;
    cout << user.getPassword() << endl;
    cout << user.getBudget() << endl;
    cout << user.getID() << endl;

    //Test if functions of Team can be called
    cout << endl << endl << "Test Team:" << endl;
    cout << dallas.getTeamStarting() << endl;

    //Test if functions of Player can be called
    cout << endl << endl << "Test Player Nowitzki before setter calling:" << endl;
    cout << nowitzki.getName() << endl;
    cout << nowitzki.getPlayerID() << endl;
    cout << nowitzki.getHealthStatus() << endl;
    cout << nowitzki.getOwningUserID() << endl;
    cout << nowitzki.getMarketValue() << endl;
    cout << nowitzki.isStarterPlayer() << endl;
    cout << nowitzki.getPosition() << endl;

    //Set diverse
    nowitzki.setName("kobe");
    nowitzki.setPlayerID(1234123);
    nowitzki.setHealthStatus(false);
    nowitzki.setOwningUserId("U2398123");
    nowitzki.setMarketValue(4000);
    nowitzki.setIsStarter(false);
    nowitzki.setPosition(3);

    //Test if functions of Player can be called
    cout << endl << endl << "Test Player Nowitzki after setter calling:" << endl;
    cout << nowitzki.getName() << endl;
    cout << nowitzki.getPlayerID() << endl;
    cout << nowitzki.getHealthStatus() << endl;
    cout << nowitzki.getOwningUserID() << endl;
    cout << nowitzki.getMarketValue() << endl;
    cout << nowitzki.isStarterPlayer() << endl;
    cout << nowitzki.getPosition() << endl;
*/
    return 0;
}
