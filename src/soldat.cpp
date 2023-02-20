/**  @file     soldat.cpp                                                                                                                                
 * @author     Yassir, Achraf, Xuanzhe                                                                                                        
 * @version    1.0.0.1                                                
 * @date       2023.01.31                                                                                
 * @copyright  Copyright (c)
 *****************************************************************
 * @attention
 * Development environment: Windows
 * @par Modification log:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2023/01/31  <td>1.0      <td>Achraf    <td>Creating the initial version
 * </table>
 ******************************************************************
 */
#include "soldat.hpp"

/**
 * @brief The Soldier class represents a generic soldier.
 * 
 * This class contains the attributes and methods that all soldiers share,
 * such as hit points, strength, precision, and speed. It also includes
 * methods for firing and reducing hit points.
 */
Soldat::Soldat()
{}

/**
* @brief Get the soldier's HP.
* @return The soldier's HP.
*/
int Soldat::getHp()
{
    return hp;
}
/**
* @brief Get the soldier's strength.
* @return The soldier's strength.
*/
int Soldat::getStrength()
{
    return strength;
}

/**
* @brief Get the soldier's precision.
* @return The soldier's precision.
*/
float Soldat::getPrecision()
{
    return precision;
}

/**
* @brief Get the soldier's speed.
* @return The soldier's speed.
*/
int Soldat::getSpeed()
{
    return speed;
}

/**
* @brief Set the soldier's HP.
* @param hp The new value of the soldier's HP.
*/
void Soldat::setHp(int hp)
{
    this->hp = hp;
}

/**
* @brief Set the soldier's strength.
* @param strength The new value of the soldier's strength.
*/
void Soldat::setStrength(int strength)
{
    this->strength = strength;
}

/**
* @brief Set the soldier's precision.
* @param precision The new value of the soldier's precision.
*/
void Soldat::setPrecision(float precision)
{
    this->precision = precision;
}

/**
* @brief Set the soldier's speed.
* @param speed The new value of the soldier's speed.
*/
void Soldat::setSpeed(int speed)
{
    this->speed = speed;
}

/**
* @brief Make the soldier shoot and return the damage dealt.
* @return The amount of damage dealt, if the shot hits.
*/
int Soldat::tirer()
{
    int resultat = 0;
    float random = rand() / (float) RAND_MAX;

    if (random <= precision)
        resultat = strength;
    
    return resultat;
}

/**
* @brief Set the soldier's hit points.
* @param hp The new value of the soldier's hit points.
*/
void Soldat::reduireHp(int tir)
{
    int random = rand() % 100;
    
    if (random >= speed)
        hp -= tir;
}

/**
* @brief Print the soldier's attributes to the console.
*/
void Soldat::Afficher()
{
    cout << "HP : " << hp;
    cout << " STR : " << strength;
    cout << " PRC : " << precision;
    cout << " SPD : " << speed << endl;
}