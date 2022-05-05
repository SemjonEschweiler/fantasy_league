#include <iostream>
#include "Application.hpp"
#include "Admin.hpp"
#include "Person.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "User.hpp"
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]) // calls the application
{
    std::cout << argv[0] << endl;;
    #ifdef _WIN32
     /* Windows code */
        cout << "\nYou are working on windows!" << endl;

    #else
     /* GNU/Linux code */
        cout << "You are working on UNIX" << endl;
    #endif
    Application app = Application();
    vector<Player*> _starters(5,nullptr);

    return 0;
}
