/*
* Sword.h
* HW 5
* Methods and fields for swords
*/

#pragma once

#include "Weapon.h"

class Sword : public Weapon
{
public: 
    Sword();
    Sword(int minimumRarity);

    void Attack() override;
    void PrintActions() override;
    /// <summary>
    /// Get the properties of the sword.
    /// </summary>
    /// <returns>A string with the properties.</returns>
    string Properties() override;
    /// <summary>
    /// Sharpen the sword.
    /// </summary>
    void Service() override;
private:
    float sharpness;
    float maxSharpness;
};