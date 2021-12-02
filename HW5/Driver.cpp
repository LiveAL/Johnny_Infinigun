/*
* Driver.cpp
* HW 5
* Functionality for a loot drop and using a weapon picked up.
*/

#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <ctime>

#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main()
{
    int currentLevel = -1; // Current level of weapons
    bool quit = false; // User exit

    // Welcome player
    cout << "Welcome, Johnny Infinigun to this make believe weapons test." << endl;
    cout << "The weapons exist on in your mind, and they can't do anything." << endl;
    cout << "Fortunately for you, this is a 4D taste experience as well. Just lick something metal nearby." << endl;
    cout << "It's like you're really here!" << endl << endl;

    while (!quit)
    {
        currentLevel++;
        if (currentLevel > 3) currentLevel = 3;

        // Prompt player to equip starter weapon
        cout << "Equip your weapon." << endl;

        // Generate two weapons
        Gun newGun(currentLevel);
        sleep_for(nanoseconds(15)); // Buffer the random seed
        Sword newSword(currentLevel);

        // Default to gun so pointer isn't empty
        Weapon* weapon = &newGun;
        bool sword = false;

        // Player selects weapon
        bool selected = false;
        while (!selected)
        {
            // Display properties of weapons
            cout << "[1] " << newGun.Properties() << endl;
            cout << "[2] " << newSword.Properties() << endl;

            char entry;
            cin >> entry;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (entry)
            {
            case '1': // Selected gun
                selected = true;
                sword = false;
                break;
            case '2': // Selected sword
                weapon = &newSword;
                selected = true;
                sword = true;
                break;
            default:
                cout << "Please input 1 or 2." << endl;
                break;
            }
        }

        cout << endl;

        bool useCurrent = true; // Do not change weapon
        while (useCurrent)
        {
            // Get player action
            weapon->PrintActions();
            char entry;
            
            cin >> entry;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            entry = toupper(entry);

            cout << endl;

            // Output time of the action for clarity
            {
                auto now = time(NULL);
                char buffer[26] = {};
                ctime_s(buffer, sizeof buffer, &now);
                cout << buffer;
            }

            // Enact action
            switch (entry)
            {
            case 'A':
                weapon->Attack();
                break;
            case 'R':
                weapon->Service();
                break;
            case 'P':
                cout << weapon->Properties() << endl;
                break;
            case 'S':
                if (sword)
                {
                    weapon = &newGun;
                    sword = false;
                    cout << "Switched to gun. " << endl << endl << endl;
                }
                else
                {
                    weapon = &newSword;
                    sword = true;
                    cout << "Switched to sword. " << endl << endl << endl;
                }
                cout << weapon->Properties() << endl;
                break;
            case 'Q':
                quit = true;
            case 'N':
                useCurrent = false;
                cout << endl;
                break;
            default:
                cout << "Please enter a supported action." << endl;
                break;
            }

            cout << "-------------------------------------------" << endl;
        }
    }
    
    cout << "Application Quit." << endl;
}