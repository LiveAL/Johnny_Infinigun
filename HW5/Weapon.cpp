/*
* Weapon.cpp
* HW 5
* Implementations of weapon fields and functions
*/

#include <iostream>
#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
    rarity = Rarity::COMMON;
    damage = 0;
}

Weapon::Weapon(Rarity minimum)
{
    rarity = static_cast<Rarity>(rand() % RARITY_LENGTH + static_cast<int>(minimum));
    damage = 0;
}

void Weapon::PrintActions()
{
    cout << " | [P] Display Properties | [S] Switch to other weapon | [N] New loot drop | [Q] Quit" << endl;
}

void Weapon::Attack()
{
    cout << "Hit for " << damage << " damage." << endl;
}

void Weapon::Service() {}

string Weapon::Properties()
{
    string properties = "";

    properties += "Damage: " + to_string(damage) + ". |";

    properties += " Rarity: ";
    switch (rarity)
    {
    case Rarity::COMMON:
        properties += "[COMMON]";
        break;
    case Rarity::RARE:
        properties += "[RARE]";
        break;
    case Rarity::EPIC:
        properties += "[EPIC]";
        break;
    case Rarity::LEGENDARY:
        properties += "[LEGENDARY]";
        break;
    }
    properties += ". ";

    return properties;
}