#include "Application.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include<chrono>
#include<thread>

//1.0.0
using namespace std;

Application::Application(){
    currentPlayerID = 10000; //ID with 5 digits for players
    currentPersonID = 1000000;


//Initializes all Users, Admins
/* These should be created by the Admin
    Player nowitzki = Player("Dirk Nowitzki", 1000001, true, "U1234567", 2000, false, 2);
    Player bryant = Player("Kobe Bryant", 1000002, true, "U1234567", 2000, true, 2);
    Player durant = Player("Kevin Durant", 1000003, true, "U1234567", 2000, true, 2);
*/
    /*ALL THE THINGS IN HERE ARE FOR TESTING PURPOSES
    //Team dallas = Team();
    Admin admin = Admin(assignCurrentPersonID(true), "helloworld", &currentPlayerID, &currentPersonID, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

    //User user = User(assignCurrentPersonID(false), "helloworld", 100000, dallas, &_allPeople);
    //cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;
    //cout << "assignCurrentPersonID(true): " << assignCurrentPersonID(true) << endl;
    //cout << "assignCurrentPersonID(false): " << assignCurrentPersonID(false) << endl;

    admin.createNewPlayer("Dirk Nowitzki", 2, true, 10000);
    cout << "application: admin created Player" << endl;
    admin.createNewPlayer("Kobe Bryant", 2, true, 20000);
    admin.createNewPlayer("Kevin Durant", 2, true, 10000);

    this->displayAllPlayers();
    this->displayAllPlayersOnMarket();

    admin.deletePlayer(10001);

    this->displayAllPlayers();
    this->displayAllPlayersOnMarket();

    //this->displayAllPeople();

    //start of
    admin.createRandomPlayers(5, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));

    //admin.addPersonToSystem(true, 123, "hello", 1000000);
    admin.addPersonToSystem(false, 123, "hello", 1000000);

    admin.createRandomPlayers(7, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));
    admin.addPersonToSystem(false, 123, "hello", 1000000);
    admin.createRandomPlayers(21, randomFirstNames, randomLastNames, sizeof(randomFirstNames)/sizeof(randomFirstNames[0]), sizeof(randomLastNames)/sizeof(randomFirstNames[0]));
    admin.addPersonToSystem(false, 123, "hello", 1000000);
    admin.addPersonToSystem(false, 123, "hello", 1000000);

    //_allPeople[2]->displayPerson();


    this->displayAllPeople();
    this->displayAllPlayers();


    cout << "Updating Score now --> 10000" << endl;
    getPlayerPtrFromID(10000)->displayPlayer();

    User* mainUser = this->getUserPtrFromID("U1000001");
    cout << "Starting Budget is: " << mainUser-> getBudget() << endl;


    Player* firstPlayer = getPlayerPtrFromID(10003);

    firstPlayer->displayPlayer();
    admin.deletePlayer(10003);

    cout << "After first deletion: " << mainUser-> getBudget() << endl;


    this->displayAllPlayers();
    mainUser->changeStatusPlayer(10007);
    mainUser->changeStatusPlayer(10006);
    mainUser->changeStatusPlayer(10004);
    mainUser->changeStatusPlayer(10000);

    admin.changeHealthStatusPlayer(10000, false);
    admin.updateScorePlayer(10000, 8, 2, 6, 2, 3, 2);
    admin.changeHealthStatusPlayer(10000, true);
    admin.updateScorePlayer(10000, 8, 2, 6, 2, 3, 2);
    admin.updateScorePlayer(10000, 8, 2, 6, 2, 3, 2);
    mainUser->changeStatusPlayer(10000);
    admin.updateScorePlayer(10000, 8, 2, 6, 2, 3, 2);

    admin.updateScorePlayer(10000, 8, 2, 6, 2, 3, 2);
    srand ( time(NULL) );
    cout << "_allPlayers.size(): " << _allPlayers.size() << endl;
    for (int i=0; i<(int)_allPlayers.size();i++){
        int randNum = rand() % 100 + 1;
        int randPoints = rand() % 31;
        int randAssists = rand() % 20;
        int randTurnovers = rand() % 6;
        int randBlocks = rand() % 7;
        int randSteals = rand() & 6;
        if (randNum <= 60){
            User* u = this->getUserPtrFromID(_allPlayers[i]->getOwningUserID());
            if (u){
                u->changeStatusPlayer(_allPlayers[i]->getPlayerID());
            }else{
                cout << "This player doesn't have a user, therefore he cannot change status." << endl;
            }

        }
        admin.updateScorePlayer(_allPlayers[i]->getPlayerID(), randNum, randPoints, randAssists, randSteals, randBlocks, randTurnovers);
    }

    cout << "Score of Team: " << getUserPtrFromID("U1000001")->getTeam()->getScore() << endl;

    mainUser->seePlayers();

    this->displayAllPlayers();


    admin.createNewPlayer("Kobe Bryant", 2, true, 1000);
    mainUser->seePlayers();
    mainUser->buyPlayer(10008);
    mainUser->changeStatusPlayer(10008);
    mainUser->seeLineup();

    mainUser->seePlayers();
    cout << "Print Budget of User after buy: " << mainUser->getBudget() << endl;
    mainUser->sellPlayer(10008);
    mainUser->seePlayers();
    cout << "Print Budget of User after sell: " << mainUser->getBudget() << endl;

    mainUser->seeLineup();
    mainUser->displayScoreboard();
    mainUser->seePlayers();
    mainUser->seePlayers(1);
    mainUser->seePlayers(2);
    */
    Admin admin = Admin("A000000", "admin1", &currentPlayerID, &currentPersonID, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

    Team dallas = Team();
    User user = User("U000000", "user1", 10000000, &dallas, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

    Player p1 = Player("Dirk", 0, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p2 = Player("Hans", 1, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p3 = Player("Max", 2, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p4 = Player("Leon", 3, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p5 = Player("Pablo", 4, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p6 = Player("Vince", 5, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p7 = Player("Gerry", 6, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p8 = Player("Arnold", 7, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p9 = Player("Beggy", 8, 1,"U000000",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p10 = Player("Corke", 9, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p11 = Player("Argon", 10, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p12 = Player("Methy", 11, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p13 = Player("Howy", 12, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p14 = Player("Odonald", 13, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p15 = Player("Pedro", 14, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);
    Player p16 = Player("Kenny", 15, 1,"",1000000,0,0, &_allPlayers, &_allPlayersOnMarket);

    //Adding Player to User
    for (int i=0; i<9; i++){
        admin.addPlayerToUser(i, "U000000");
    }
    for (int i=0; i<5;i++){
        user.changeStatusPlayer(i);
    }

    user.seeLineup();
    user.seePlayers();

    bool quitSignal = false;
    while (1){
        this->login();
        cout << "Current Logged In ID: " << this->getCurrentLoggedInID() << endl;

        quitSignal = this->mainMenu();
        if (quitSignal == true){
            break;
        }
    }
    cout << "Program Finished!" << endl;
}

Application::~Application(){
    //TODO:
/*
    for (int i=0;i<(int)_allPlayers.size(); i++){
        delete _allPlayers[i];
    }
    for (int i=0;i<(int)_allPeople.size();i++){
        if (_allPeople[i]->getID()[0] == 'U'){
            delete dynamic_cast<User*>(_allPeople[i])->getTeam();
            //delete dynamic_cast<User*>(_allPeople[i]);
        }else if (_allPeople[i]->getID()[0] == 'A'){
            //delete dynamic_cast<Admin*>(_allPeople[i]);
        }
    }
    */
}

vector<Player*>* Application::getAllPlayers(){
    return &_allPlayers;
}

vector<Player*>* Application::getAllPlayersOnMarket(){
    return &_allPlayersOnMarket;
}

void Application::displayAllPlayers(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players (" << _allPlayers.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPlayers.size(); i++){
        _allPlayers[i]->displayPlayer();
    }
    cout << "-------------------\n";
}

void Application::displayAllPlayersOnMarket(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all Players on Market (" << _allPlayersOnMarket.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPlayersOnMarket.size(); i++){
        _allPlayersOnMarket[i]->displayPlayer();
    }
    cout << "-------------------\n";
}

void Application::displayAllPeople(){
    cout << "\n\n-------------------\n";
    cout << "Displaying all People registered in System (" << _allPeople.size() << "): " << endl;
    cout << "\n";
    for (int i=0; i< (int)_allPeople.size(); i++){
        _allPeople[i]->displayPerson();
    }
    cout << "-------------------\n";
}

/*
int Application::assignCurrentPlayerID(){
    currentPlayerID += 1;
    return (currentPlayerID - 1);
}
*/
string Application::assignCurrentPersonID(bool isAdmin){
    //this function assigns the next PersonID and updates the currentPersonID
    stringstream aux;
    if (isAdmin){
        aux << "A" << currentPersonID;
    }else{
        aux << "U" << currentPersonID;
    }
    currentPersonID += 1;
    return aux.str();
}

User* Application::getUserPtrFromID(string personID){
    char firstChar = personID[0];
    if (firstChar == 'A'){
        cout << "Error: You can not obtain a User if you are giving an Admin ID" << endl;
        return nullptr;
    }

    for (int i=0; i < (int) _allPeople.size();i++){
        if (personID == _allPeople[i]->getID()){
            return dynamic_cast<User*> (_allPeople[i]);
        }
    }
    cout << "Error: Person not found" << endl;
    return nullptr;
}

Player* Application::getPlayerPtrFromID(int playerID){
    for (int i=0; i < (int) _allPlayers.size(); i++){
        if (playerID == _allPlayers[i]->getPlayerID()){
            return _allPlayers[i];
        }
    }
    cout << "Didnt find Player";
    return nullptr;
}

Person* Application::getPersonPtrFromID(string personID){
    for (int i=0; i < (int) _allPeople.size();i++){
        if (personID == _allPeople[i]->getID()){
            return _allPeople[i];
        }
    }
    cout << "Error: Person not found" << endl;
    return nullptr;
}

void Application::login(){
    string uiPersonID;
    string uiPassword;
    for (int i=0; i<3; i++){
        cout << "--------Login "<< i+1 << ". out of 3 attempts--------" << endl;
        cout << "Please enter your username: ";
        cin >> uiPersonID;

        Person* p;
        //User* u;
        //Admin* a;
        try{
            p = getPersonPtrFromID(uiPersonID);
            if (!p){
                throw "Error: Person was not found...";
            }

        }catch(...){
            cout << "This ID was not found unfortunately... Try again..." << endl;
            continue;
        }
        /*
        if (uiPersonID[0] == 'U'){
            u = dynamic_cast<User*> (p);
        }else if (uiPersonID[1] == 'A'){
            a = dynamic_cast<Admin*> (p);
        }
        */
        cout << p->getID() << ": Please enter your password: ";
        cin >> uiPassword;
        if (uiPassword == p->getPassword()){
            if (uiPersonID[0] == 'U'){
                cout << "Authorized! You are logged in as a User (" << p->getID() << ")!" << endl;
            }else if (uiPersonID[1] == 'A'){
                cout << "Authorized! You are logged in as an Admin(" << p->getID() << ")!"  << endl;
            }
            _currentLoggedInID = p->getID();
            break;
        }

    }

}

int Application::mainMenu() {
    int userInput;
    bool quitSignal = false;
    while (1){
        if (_currentLoggedInID[0] == 'A'){
            Admin* a;
            User* u;
            Player* p;
            int uiPlayerID;
            int uiIsHealthy;
            string namePlayer;
            string numericID, password;
            try {
                a = dynamic_cast<Admin*>(getPersonPtrFromID(_currentLoggedInID));
                u = getUserPtrFromID("U000000");
                if (!a){
                    throw "Error: Admin couldn't be obtained from currentLoggedInID";
                }
            }catch (...) {
                cout << "Error: Admin couldn't be obtained from currentLoggedInID" << endl;
            }
            cout << "\n-------Admin Menu (ID: " << a->getID() << ")-------\n" << endl;
            cout << "You have following options: \n\n" << endl;
            cout << "Press 1: Create a new Player" << endl;
            cout << "Press 2: Delete an existing Player" << endl;
            cout << "Press 3: Add Person to the system" << endl;
            cout << "Press 4: Update Score of a Player" << endl;
            cout << "Press 5: Change if a player is fit to play" << endl;
            cout << "Press 6: See all Players" << endl;
            cout << "Press 7: See all People" << endl;
            cout << "Press 8: Logout" << endl;
            cout << "Press 9: Quit Program" << endl;

            userInput = 0;
            while (!(userInput > 0 && userInput <= 9)){
                cout << "\nPut in a number between 1 and 9: ";
                cin >> userInput;
            }

            cout << "\n\n" << endl;
            switch (userInput) {
            case 1:
                cout << "You chose option 1: Create a new Player" << endl;
                int idPlayer, position, healthStatus, marketValue;
                bool isIdVal;
                isIdVal = false;
                namePlayer = "";
                idPlayer = -1;
                position = -1;
                healthStatus = -1;
                marketValue = -1;


                while (!(idPlayer >= 0 && idPlayer <= 10000000 && isIdVal)){
                    cout << "What shall the ID of the new player be: ";
                    cin >> idPlayer;
                    isIdVal = true;
                    for (int i=0; i<(int)_allPlayers.size();i++){
                        if (_allPlayers[i]->getPlayerID() == idPlayer){
                            cout << "Figured out that ID is not valid" << endl;
                            isIdVal = false;
                        }
                    }
                }

                while (!(namePlayer!="")){
                    cout << "[Enter a name] Whats the name of the player: ";
                    cin >> namePlayer;
                }
                while (!(position >= 0 && position <= 4)){
                    cout << "[Enter a number between 0-4] What position does player play at [0: C, 1: PF, 2: SF, 3: PG, 4: SG]: ";
                    cin >> position;
                }
                while (!(healthStatus >= 0 && healthStatus <= 1)){
                    cout << "[Enter a number between 0-1] Is Player healthy [1] or unhealthy [0]: ";
                    cin >> healthStatus;
                }
                while (!(marketValue >= 0 && marketValue <= 10000000)){
                    cout << "[Enter a number between 0-10000000] What is the market value of the player: ";
                    cin >> marketValue;
                }


                a->createNewPlayer(idPlayer, namePlayer, position, healthStatus, marketValue);
                u->seePlayers();
                break;
            case 2:
                cout << "You chose option 2: Delete a Player by ID" << endl << endl;

                cout << "Please Enter the player ID of the player that you want to delete" << endl;
                cin >> uiPlayerID;
                try {
                    p = getPlayerPtrFromID(uiPlayerID);
                    if (!p){
                        throw "Error: User couldn't be obtained from currentLoggedInID";
                    }else{
                        a->deletePlayer(uiPlayerID);

                    }
                }catch (...) {
                    cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
                    break;
                }
                cout << "Deletion of Player was successful" << endl;
                break;
            case 3:
                numericID = "";
                bool numericIdValid;
                numericIdValid = false;
                password = "";
                bool isAdmin;
                int budget;
                budget = -1;
                cout << "You chose option 3: Add Person to the system" << endl;

                while (!(numericID.length() == 7 && (numericID[0] == 'A' || numericID[0] == 'U') && numericIdValid)){
                    cout << "What shall the ID of the new person be: ";
                    cin >> numericID;
                    numericIdValid = true;
                    for (int i=0; i<(int)_allPeople.size();i++){
                        if (_allPeople[i]->getID() == numericID){
                            cout << "Error: That ID already exists..." << endl;
                            numericIdValid = false;
                        }
                    }
                }
                if (numericID[0] == 'A'){
                    isAdmin = true;
                    budget = 0;
                }else if (numericID[0] == 'U'){
                    isAdmin = false;
                } else{
                    cout << "Error: ID does not begin with an 'A' or a 'U'..." << endl;
                }

                while (!(password!="")){
                    cout << "[Enter a password] Whats the password of the Person: ";
                    cin >> password;
                }

                while (!(budget >= 0 && budget <= 100000000)){
                    cout << "[Enter a number between 0-10000000] What is the budget of the User: ";
                    cin >> budget;
                }

                a->addPersonToSystem(isAdmin, numericID, password, budget);
                break;

            case 4:
                cout << "You chose option 4: Update Score of a Player" << endl;
                int id, points, rebounds, assists, steals, blocks, turnovers;
                bool isIdValid;
                isIdValid = false;
                id = -1;
                points = -1;
                rebounds = -1;
                assists = -1;
                steals = -1;
                blocks = -1;
                turnovers = -1;

                while (!(id >= 0 && id <= 10000000 && isIdValid)){
                    cout << "What shall the ID of the player be: ";
                    cin >> id;
                    isIdValid = false;
                    for (int i=0; i<(int)_allPlayers.size();i++){
                        if (_allPlayers[i]->getPlayerID() == id){
                            isIdValid = true;
                        }
                    }
                }
                while (!(points >= 0 && points <= 100)){
                    cout << "[Enter a number between 0-100] How many points did the player score: ";
                    cin >> points;
                }
                while (!(rebounds >= 0 && rebounds <= 50)){
                    cout << "[Enter a number between 0-50] How many rebounds did the player score: ";
                    cin >> rebounds;
                }
                while (!(assists >= 0 && assists <= 50)){
                    cout << "[Enter a number between 0-50] How many assists did the player score: ";
                    cin >> assists;
                }
                while (!(steals >= 0 && steals <= 50)){
                    cout << "[Enter a number between 0-50] How many steals did the player score: ";
                    cin >> steals;
                }
                while (!(blocks >= 0 && blocks <= 50)){
                    cout << "[Enter a number between 0-50] How many blocks did the player score: ";
                    cin >> blocks;
                }
                while (!(turnovers >= 0 && turnovers <= 50)){
                    cout << "[Enter a number between 0-50] How many turnovers did the player score: ";
                    cin >> turnovers;
                }


                a->updateScorePlayer(id, points, rebounds, assists, steals, blocks, turnovers);
                u->seeLineup();
                break;
            case 5:
                cout << "You chose option 5: Change if a player is fit to play" << endl;

                cout << "Please Enter the player ID of the player that you want to change his/her fitness: ";
                cin >> uiPlayerID;
                try {
                    p = getPlayerPtrFromID(uiPlayerID);
                    if (!p){
                        throw "Error: User couldn't be obtained from currentLoggedInID";
                    }
                }catch (...) {
                    cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
                    break;
                }
                cout << "Please Enter 0 if player should be unfit and 1 (or any other number) if player should be unfit: ";
                cin >> uiIsHealthy;

                a->changeHealthStatusPlayer(uiPlayerID, uiIsHealthy);
                cout << "Changed Health Status of Player successfully" << endl;

                u->seeLineup();

                break;
            case 6:
                cout << "You chose option 6: See all Players" << endl;
                a->displayAllPlayers();

                break;
            case 7:
                cout << "You chose option 7: See all People" << endl;
                a->displayAllPeople();
                break;
            case 8:
                cout << "You chose option 8: Logout" << endl;
                quitSignal = false;
                return quitSignal;

                break;
            case 9:
                cout << "You chose option 9: Quit Program" << endl;
                quitSignal = true;
                return quitSignal;

                break;
            default:
                cout << "Error occurred: Wrong User Input"<< endl;
                break;
            }


        }else if (_currentLoggedInID[0] == 'U'){
            User* u;
            Player* p;
            int uiPlayerID;
            int userOption;
            try {
                u = getUserPtrFromID(_currentLoggedInID);
                if (!u){
                    throw "Error: User couldn't be obtained from currentLoggedInID";
                }
            }catch (...) {
                cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
            }
            cout << "\n-------User Menu (ID: " << u->getID() << ")-------\n" << endl;
            cout << "Budget available: " << u->getBudget() << endl;
            cout << "Current Score: " << u->getTeam()->getScore() << endl;

            cout << "\n\nYou have following options: \n\n" << endl;
            cout << "Press 1: See your Lineup" << endl;
            cout << "Press 2: Change if a Player is Starting or a Substitute" << endl;
            cout << "Press 3: See Players in the market" << endl;
            cout << "Press 4: Buy a player from the Marketplace" << endl;
            cout << "Press 5: Sell a player to the Marketplace" << endl;
            cout << "Press 6: See Leaderboard" << endl;
            cout << "Press 8: Logout" << endl;
            cout << "Press 9: Quit Program" << endl;

            userInput = 0;
            while (!(userInput >= 1 && userInput <= 9)){
                cout << "\nPut in a number between 1 and 9: ";
                cin >> userInput;
            }

            cout << "\n\n" << endl;
            switch (userInput) {
            case 1:
                cout << "You chose option 1: See Lineup" << endl;
                u->seeLineup();
                break;
            case 2:
                cout << "You chose option 2: Change if a Player is Starting or a Substitute" << endl;

                cout << "Please Enter the player ID of the player of which you want to change the Status" << endl;
                cin >> uiPlayerID;
                try {
                    p = getPlayerPtrFromID(uiPlayerID);
                    if (!p){
                        throw "Error: User couldn't be obtained from currentLoggedInID";
                    }else{
                        u->changeStatusPlayer(uiPlayerID);
                    }
                }catch (...) {
                    cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
                }

                break;
            case 3:
                cout << "You chose option 3: See Player in Market" << endl << endl;
                cout << "Press 1: Unsorted" << endl;
                cout << "Press 2: Sort by Marketvalue" << endl;
                cout << "Press 3: Sort by Position" << endl;

                userOption = 0;
                while (!(userOption >= 1 && userOption <= 3)){
                    cout << "\nPut in a number between 1 and 3: ";
                    cin >> userOption;
                }
                switch (userOption) {
                case 1:
                    u->seePlayers(0);
                    break;
                case 2:
                    u->seePlayers(1);
                    break;
                case 3:
                    u->seePlayers(2);
                    break;
                default:
                    cout << "Something went wrong -> Wrong User Input...";
                    break;
                }
                break;
            case 4:
                cout << "You chose option 4: Buy a player from the Marketplace" << endl << endl;
                cout << "Please Enter the player ID of the player that you want to buy: ";
                cin >> uiPlayerID;
                try {
                    p = getPlayerPtrFromID(uiPlayerID);
                    if (!p){
                        throw "Error: User couldn't be obtained from currentLoggedInID";
                    }else{
                        u->buyPlayer(uiPlayerID);
                    }
                }catch (...) {
                    cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
                }

                break;
            case 5:
                cout << "You chose option 5: Sell a player to the Marketplace" << endl << endl;
                cout << "Please Enter the player ID of the player that you want to sell: ";
                cin >> uiPlayerID;
                try {
                    p = getPlayerPtrFromID(uiPlayerID);
                    if (!p){
                        throw "Error: User couldn't be obtained from currentLoggedInID";
                    }else{
                        u->sellPlayer(uiPlayerID);
                    }
                }catch (...) {
                    cout << "Error: User couldn't be obtained from currentLoggedInID" << endl;
                }

                break;
            case 6:
                cout << "You chose option 6: See Leaderboard" << endl << endl;
                u->displayScoreboard();
                break;
            case 8:
                cout << "You chose option 8: Logout" << endl;
                quitSignal = false;
                return quitSignal;

                break;
            case 9:
                cout << "You chose option 9: Quit Program" << endl;
                quitSignal = true;
                return quitSignal;

                break;
            default:
                cout << "Error occurred: This is not a viable input"<< endl;
                break;
            }

        }else {
            cout << "Abbort: The currentLoggedInID is not recognized..." << endl;
            break;
        }
        std::cout << "\nPress ENTER to continue... \n";
        fgetc(stdin);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //cin.ignore();
    }
    return false;
}

const string &Application::getCurrentLoggedInID() const
{
    return _currentLoggedInID;
}

void Application::setCurrentLoggedInID(const string &newCurrentLoggedInID)
{
    _currentLoggedInID = newCurrentLoggedInID;
}

