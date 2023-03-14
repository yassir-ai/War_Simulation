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
 * <tr><td>2023/02/20  <td>2.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */
#include "soldat.hpp"


/**
 * @brief Construct a new Soldier object
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
 * @brief Get the soldier's ID.
 * @return The soldier's ID.
 */
int Soldat::getId()
{
    return id;
}

/**
 * @brief Set the soldier's ID.
 * @param id The new value of the soldier's ID.
 */
void Soldat::setId(int nv_id)
{
    id = nv_id;
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
* @brief Set the Health points that may be reduced by an attack. 
* @param tir Possible reduction of health points.
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
void Soldat::AfficherSoldat()
{
    cout << "HP : " << hp;
    cout << " STR : " << strength;
    cout << " PRC : " << precision;
    cout << " SPD : " << speed << endl;
}

/**
 * @brief Overlay operation on the soldier's id where the specified step size
 * @param  pas The new value of the soldier's ID.
 */
void Soldat::incremId(int pas)
{
    id += pas;
}

/**
 * @brief At this point the soldier decides whether to move or launch an attack, returning 0 for an attack and 1 for a move
 * @param  pas The new value of the soldier's ID.
 * @return 0/1 => tirer/bouger
 */
int Soldat::decider() // 0 = tirer, 1 = bouger
{
    return rand() % 2;
}

/**
 * @brief Determining if a soldier is dead
 * @return true/false => Dead/Live
 */
bool Soldat::estMort()
{
    return (hp <= 0);
}

/**
 * @brief Determine if another soldier is a friendly or enemy soldier
 * @param sol another soldier
 * @return true/false => friendly soldier / enemy soldier
 */
bool Soldat::est_Ami(Soldat& sol)
{
    return ( (this->getId() / 4) == (sol.getId() / 4) );
}

/**
 * @brief Default destructor
 */
Soldat::~Soldat()
{}