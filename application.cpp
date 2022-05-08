#include "Application.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include<chrono>
#include<thread>
#include <fstream>
#include <single_include/nlohmann/json.hpp>

//1.0.0
using namespace std;
using json = nlohmann::json;

Application::Application(){
    string peopleFilePath, playerFilePath;
    #ifdef _WIN32
     /* Windows code */
        peopleFilePath = ".\\docs\\people.json";
        playerFilePath = ".\\docs\\players.json";

    #else
     /* GNU/Linux code */
        peopleFilePath = "./docs/people.json";
        playerFilePath = "./docs/players.json";
    #endif

    currentPlayerID = 10000; //ID with 5 digits for players
    currentPersonID = 1000000;

    bool isTestingMode = false;
    bool quitSignal = false;

    this->loadFromFiles(peopleFilePath, playerFilePath);

    User* u = getUserPtrFromID("U000000");
    u->seePlayers();
    u->seeLineup();

    while (1){
        if (quitSignal == true){
            break;
        }
        if (isTestingMode){
            _currentLoggedInID = "U000000";
        }else{
            this->login();
        }
        cout << "Current Logged In ID: " << this->getCurrentLoggedInID() << endl;

        quitSignal = this->mainMenu();

    }

    this->storeToFiles(peopleFilePath, playerFilePath);
    cout << "Program Finished!" << endl;
}

Application::~Application(){
    //Deletes all Players, all Teams, all People (Users and Admins)

    for (int i=0;i<(int)_allPlayers.size(); i++){
        Player* p = _allPlayers.at(i);

        delete p;
    }

    for (int i=0;i<(int)_allPeople.size();i++){
        if ((_allPeople[i]->getID())[0] == 'U'){
            User* u = dynamic_cast<User*>(_allPeople[i]);
            Team* t = u->getTeam();

            delete t;
        }
        delete _allPeople[i];
    }

}

void Application::loadFromFiles(string peoplePath, string playerPath) {
    string jID, jPassword;
    double jScore;
    int jBudget;

    //cout << "At least that worked: "<< peoplePath << endl;

    std::ifstream i(peoplePath);
    //cout << i.rdbuf() << endl;
    json j = json::parse(i);

    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        json jPerson = *it;
        if (it->size() == 2){
            //cout << "element has two variables therefore is admin"  << jPerson["ID"] << endl;
            jPerson.at("ID").get_to(jID);
            jPerson.at("password").get_to(jPassword);

            Admin* a = new Admin(jID, jPassword, &currentPlayerID, &currentPersonID, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

            cout << "Application: Admin was successfully loaded from file..." << endl;
        }else if (it->size() == 4){
            //cout << "element has 4 variables therefore is user" << endl;
            jPerson.at("ID").get_to(jID);
            jPerson.at("password").get_to(jPassword);
            jPerson.at("budget").get_to(jBudget);
            jPerson.at("score").get_to(jScore);

            Team* t = new Team(jScore);
            User* u = new User(jID, jPassword, jBudget, t, &_allPlayers, &_allPlayersOnMarket, &_allPeople);

            cout << "Application: User was successfully loaded from file..." << endl;
        }else{
            cout << "This is a problem!" << endl;
        }
    }


    ifstream txtPlayers(playerPath);
    json jPlayers = json::parse(txtPlayers);

    for (json::iterator it = jPlayers.begin(); it != jPlayers.end(); ++it) {
        json jPlayer = *it;
        string userID;
        int isStarter;
        jPlayer.at("Owning User ID").get_to(userID);
        jPlayer.at("Is Starter").get_to(isStarter);
        Player* p = new Player(jPlayer["Name"].get<string>(),jPlayer["ID"].get<int>(),jPlayer["Health Status"].get<int>(), jPlayer["Owning User ID"].get<string>(), jPlayer["Market Value"].get<int>(), jPlayer["Is Starter"].get<int>(),jPlayer["Position"].get<int>(),jPlayer["Score"],&_allPlayers, &_allPlayersOnMarket);
        //if he has a User ID and is starter add to starters of that team
        // if he has a User ID and not is starter add to substitutes
        if  (userID != ""){
            User* u = getUserPtrFromID(userID);
            if (isStarter == true){
                if (!(u->getTeam()->getTeamStarters()->size() > 5)){
                    u->getTeam()->getTeamStarters()->push_back(p);
                }
            }else {
                if (!(u->getTeam()->getTeamSubstitutes()->size() > 10)){
                    u->getTeam()->getTeamSubstitutes()->push_back(p);
                }
            }
            for (int i =0; i<(int)_allPlayersOnMarket.size(); i++){
                if (_allPlayersOnMarket[i]->getPlayerID() == p->getPlayerID()){
                    _allPlayersOnMarket.erase(_allPlayersOnMarket.begin() + i);
                }
            }
        }
        cout << "Application: Player was successfully loaded from file..." << endl;
    }
}

void Application::storeToFiles(string peoplePath, string playerPath) {
    json people = json::object();

    for (int i=0; i< (int)_allPeople.size(); i++){
        Person* pers = _allPeople[i];
        if (pers->getID()[0] == 'A'){
            Admin* a = dynamic_cast<Admin*>(pers);
            json jEntry = json::object();
            jEntry = {{"ID", a->getID()}, {"password", a->getPassword()}};
            people.push_back({"Admin" + to_string(i), jEntry});
        }else if (pers->getID()[0] == 'U'){
            User* u = dynamic_cast<User*>(pers);
            json jEntry = json::object();
            jEntry = {{"ID", u->getID()}, {"password", u->getPassword()}, {"budget", u->getBudget()}, {"score", u->getTeam()->getScore()}};
            people.push_back({"User" + to_string(i), jEntry});
        }
    }
    cout << "Application: People have been successfully stored in the files..." << endl;
    //cout << people.dump(4) << endl;

    std::ofstream peopleOutput(peoplePath);
    peopleOutput << std::setw(4) << people << endl;


    json players = json::object();

    for (int i=0; i<(int)_allPlayers.size(); i++){
        Player* p = _allPlayers[i];
        json player = json::object();
        player = {{"ID",p->getPlayerID()}, {"Name", p->getName()}, {"Score", p->getScore()}, {"Health Status", p->getHealthStatus()}, {"Owning User ID", p->getOwningUserID()}, {"Market Value", p->getMarketValue()}, {"Is Starter", p->isStarterPlayer()}, {"Position", p->getPosition()}};

        players.push_back( {"Player" + to_string(i), player});
    }
    //cout << players.dump(4) << endl;

    std::ofstream playerOutput(playerPath);
    playerOutput << std::setw(4) << players << endl;

    cout << "Application: Successfully stored all Players in file..." << endl;


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

