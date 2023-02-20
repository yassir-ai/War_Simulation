/**  @file     soldat.hpp                                                                                                                                
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
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>Solution (Vector n'est pas un modèleC/C++(864))
 * </table>
 ******************************************************************
 */

#ifndef SOLDAT__HPP
#define SOLDAT__HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef vector<Soldat>* Armee; /**< Soldiers can form armies so use vectors to help store soldiers and the name is army*/

/**
 * @brief The Soldier class represents a generic soldier in the army.
 *
 * This class contains the attributes and methods that all soldiers share,
 * such as hit points, strength, precision, and speed. It also includes
 * methods for firing and reducing hit points.
 */
class Soldat
{
protected:
    int hp; /**< The soldier's health points. */
    int strength;  /**< The soldier's attack strength. */
    float precision; /**< The soldier's shooting precision. */
    int speed;  /**< The soldier's movement speed. */

public:

    /**
     * @brief Construct a new Soldier object
     */
    Soldat();

    /**
     * @brief Get the soldier's HP.
     * @return The soldier's HP.
     */
    int getHp();

    /**
     * @brief Get the soldier's strength.
     * @return The soldier's strength.
     */
    int getStrength();

    /**
     * @brief Get the soldier's precision.
     * @return The soldier's precision.
     */
    float getPrecision();

    /**
     * @brief Get the soldier's speed.
     * @return The soldier's speed.
     */
    int getSpeed();
    
    /**
     * @brief Set the soldier's HP.
     * @param hp The new value of the soldier's HP.
     */
    void setHp(int );

    /**
     * @brief Set the soldier's strength.
     * @param strength The new value of the soldier's strength.
     */
    void setStrength(int );

    /**
     * @brief Set the soldier's precision.
     * @param precision The new value of the soldier's precision.
     */
    void setPrecision(float );

    /**
     * @brief Set the soldier's speed.
     * @param speed The new value of the soldier's speed.
     */
    void setSpeed(int );

    /**
     * @brief Make the soldier shoot and return the damage dealt.
     * @return The amount of damage dealt, if the shot hits.
     */
    int tirer();

    /**
     * @brief Reduce the soldier's HP by a certain amount, if the soldier is hit.
     * @param damage The amount of damage dealt.
     */
    void reduireHp(int );

    /**
     * @brief Print the soldier's attributes to the console.
     */
    virtual void Afficher();
};

/**
 * @brief The Infantry class represents an infantry soldier.
 *
 * This class is a subclass of the Soldier class, and it includes
 * attributes and methods that are specific to infantry soldiers.
 */
class Infanterie : public Soldat
{
public:
    Infanterie();
    void Afficher();
};

/**
 * @brief The Cavalry class represents a cavalry soldier.
 *
 * This class is a subclass of the Soldier class, and it includes
 * attributes and methods that are specific to cavalry soldiers.
 */
class Cavalerie : public Soldat
{
public:
    Cavalerie();
    void Afficher();
};

/**
 * @brief The Tank class represents a tank.
 *
 * This class is a subclass of the Soldier class, and it includes
 * attributes and methods that are specific to tanks.
 */
class Char : public Soldat
{
public:
    Char();
    void Afficher();
};

/**
 * @brief The AirForce class represents an air force soldier.
 *
 * This class is a subclass of the Soldier class, and it includes
 * attributes and methods that are specific to air force soldiers.
 */
class Force_Aerienne : public Soldat
{
public:
    Force_Aerienne();
    void Afficher();
};

#endif