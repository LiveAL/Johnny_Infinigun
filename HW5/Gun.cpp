/*
* Gun.cpp
* HW 5
* Implementations of gun fields and functions
*/

#include  <iostream> 
#include "Gun.h"

Gun::Gun()
{
    damage = 0;
    capacity = 0;
    bulletsLeft = capacity;
}

Gun::Gun(int minimumRarity)
{
    // Randomize the rarity of the dropped gun
    int lowerPercent = 0;
    switch (static_cast<Rarity>(minimumRarity))
    {
    case Rarity::LEGENDARY:
        lowerPercent = 30;
        break;
    case Rarity::EPIC:
        lowerPercent = 20;
        break;
    }

    srand(time(NULL));
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
    else if (randomRarity > 40 - lowerPercent)
    {
        rarity = Rarity::RARE;
    }
    else
    {
        rarity = Rarity::COMMON;
    }
    
    // Default values
    damage = 0;
    capacity = 0;
    bulletsLeft = capacity;

    // Adjust starting values to rarity
    switch (rarity)
    {
    case Rarity::COMMON:
        damage = 3;
        capacity = 4;
        break;
    case Rarity::RARE:
        damage = 10;
        capacity = 6;
        break;
    case Rarity::EPIC:
        damage = 20;
        capacity = 12;
        break;
    case Rarity::LEGENDARY:
        damage = 50;
        capacity = 25;
        break;
    }

    bulletsLeft = capacity;
}

void Gun::PrintActions()
{
    cout << "Gun actions: ";
    cout << "[A] Shoot | [R] Reload " + to_string(bulletsLeft) + "/" + to_string(capacity) + " ";
    Weapon::PrintActions();
}

void Gun::Attack()
{
    if (bulletsLeft > 0) // Shot the gun
    {
        cout << "Shot the gun. ";
        Weapon::Attack();

        bulletsLeft--;

        if (bulletsLeft < 1) cout << "Clip empty. Congratulations on your new paperweight." << endl;
        else cout << "Clip: " << bulletsLeft << "/" << capacity << endl;
    }
    else // Out of bullets
    {
        trackFailedAttempts++;
        cout << "Clip empty.";

        if (trackFailedAttempts == 5)
        {
            cout << " You don't actually get anything by making the number of failed attempts go up, so I've removed it to set you free.";
        }
        else if (trackFailedAttempts > 1 && trackFailedAttempts < 5)
        {
            cout << " You've tried to shoot an empty gun " << trackFailedAttempts << " times now. Why??";
        }
        cout << endl;
    }
}

void Gun::Service()
{
    bulletsLeft = capacity;
    trackFailedAttempts = 0;

    cout << "Reloaded." << endl;
}

string Gun::Properties()
{
    return "GUN. | Clip: " + to_string(bulletsLeft) + "/" + to_string(capacity) + ". | " + Weapon::Properties();
}