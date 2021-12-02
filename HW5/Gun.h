/*
* Gun.h
* HW 5
* Methods and fields for guns
*/

#pragma once

#include "Weapon.h"

class Gun : public Weapon
{
public: 
    Gun();
    Gun(int minimumRarity);

    void Attack() override;
    void PrintActions() override;
    /// <summary>
    /// Get the properties of the gun.
    /// </summary>
    /// <returns>A string with the properties.</returns>
    string Properties() override;
    /// <summary>
    /// Reload the gun.
    /// </summary>
    void Service() override;
private:
    int capacity;
    int bulletsLeft;
};