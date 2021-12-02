/*
* Sword.cpp
* HW 5
* Implementations of sword fields and functions
*/

#include <iostream>
#include "Sword.h"

using namespace std;

Sword::Sword()
{
    damage = 0;
    sharpness = 0;
    maxSharpness = 0;
}

Sword::Sword(int minimumRarity)
{
    // Randomize the rarity of the dropped sword
    int lowerPercent = 0;
    switch (static_cast<Rarity>(minimumRarity))
    {
    case Rarity::LEGENDARY:
        lowerPercent= 30;
        break;
    case Rarity::EPIC:
        lowerPercent = 20;
        break;
    }

    int randomRarity = (rand() % 100);
    
    // Determine rarity based on percentage
    if (randomRarity > 90 - lowerPercent)
    {
        rarity = Rarity::LEGENDARY;
    }
    else if (randomRarity > 70 - lowerPercent)
    {
        rarity = Rarity::EPIC;
    }
    else if (randomRarity > 40 )
    {
        rarity = Rarity::RARE;
    }
    else
    {
        rarity = Rarity::COMMON;
    }

    // Default values
    damage = 0;
    sharpness = 0;
    maxSharpness = 0;

    float dull = 0; // Percent dulled the sword is

    // Adjust starting values to rarity
    switch (rarity)
    {
    case Rarity::COMMON:
        damage = 10;
        maxSharpness = 0.7; // Max sharpness of 70%
        dull = (float)(rand() % 60) / 100;
        break;
    case Rarity::RARE:
        damage = 15;
        maxSharpness = 0.8; // Max sharpness of 80%
        dull = (float)(rand() % 40) / 100;
        break;
    case Rarity::EPIC:
        damage = 20;
        maxSharpness = 0.9; // Max sharpness of 90%
        dull = (float)(rand() % 20) / 100;
        break;
    case Rarity::LEGENDARY:
        damage = 50;
        maxSharpness = 1; // Max sharpness of 100%
        dull = 0;
        break;
    }

    sharpness = maxSharpness - dull;

}

void Sword::PrintActions()
{
    cout << "Sword actions: ";
    cout << "[A] Slash | [R] Sharpen " + to_string((int)(sharpness * 100)) + "%";
    Weapon::PrintActions();
}

void Sword::Attack()
{
    if (sharpness > 0)
    {
        cout << "Slashed with the sword. ";

        /*
        if (sharpness < 0.1) cout << "Hit for " << (int)(damage / 2) << " damage." << endl;
        else Weapon::Attack();*/

        cout << "Hit for " << (int)(damage * ((1 - maxSharpness) + sharpness)) << " damage." << endl;

        sharpness -= 0.1;
        if (sharpness < 0)
        {
            sharpness = 0;
            cout << "Sword has been dulled and cannot cut." << endl;
        }
        else cout << "Sharpness at: " << to_string((int)(sharpness * 100)) << "%" << endl;
    }
    else
    {
        trackFailedAttempts++;

        if (trackFailedAttempts > 3)
        {
            cout << "Do you just enjoy the feeling of pretending to swing a sword " << trackFailedAttempts << " times?";
        }
        else
        {
            cout << "Your dull sword can't even cut air.";
        }

        cout << endl;
    }
}

void Sword::Service()
{
    cout << "Sharpened. ";
    trackFailedAttempts = 0;

    sharpness += 0.1;
    if (sharpness > maxSharpness) // Sword is at maximum sharpness
    {
        cout << "Reached maximum sharpness. Watch your fingers.";
        sharpness = maxSharpness;
    }

    cout << endl;
}

string Sword::Properties()
{
    return "SWORD. | Sharpness: " + to_string((int)(sharpness * 100)) + "% | Current Damage: " + to_string((int)(damage * ((1 - maxSharpness) + sharpness))) 
        + " | Max " + Weapon::Properties();
}