#include <iostream>
#include "Application.hpp"
#include "Admin.hpp"
#include "Person.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "User.hpp"

using namespace std;

int main() // calls the application
{
    Application app = Application();

    Team dallas = Team();
    Admin admin = Admin("A1234567", "helloworld");
    User user = User("U1234567", "helloworld", 100000, dallas);
    Player nowitzki = Player("Dirk Nowitzki", 1234567, true, "U1234567", 2000, true, 2);
    cout << "Hello World!" << endl;

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

    return 0;
}
