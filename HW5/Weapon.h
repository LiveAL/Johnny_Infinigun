/*
* Weapon.h
* HW 5
* Base class for weapons
*/

#pragma once

#include <string>

using namespace std;

class Weapon
{
public:
    enum class Rarity { COMMON = 1, RARE, EPIC, LEGENDARY };
    const int RARITY_LENGTH = 4;

    Weapon();
    Weapon(Rarity rarity);

    /// <summary>
    /// Get the properties of the weapon.
    /// </summary>
    /// <returns>A string with the properties.</returns>
    virtual string Properties();
    /// <summary>
    /// Print out the actions the player can do with this weapon.
    /// </summary>
    virtual void PrintActions();
    virtual void Attack();
    virtual void Service();
protected:
    Rarity rarity; // Rarity of this weapon
    int damage; // Damage on attack
    int trackFailedAttempts = 0;
};