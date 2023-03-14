/**  @file     Char.cpp    
 * @brief Implements the Char class                                                                                                                            
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
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>Solution (membre hérité non autoriséC/C++(298)) and the change of the virtual method
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */   

#include "soldat.hpp"

const int Char::type = 2; /**< The soldier's type.(2) */

/**
 * @brief Constructor for the Char class
 * 
 * Initializes the Char object with default values.
 */
Char::Char()
{
    this->hp = 500;
    this->strength = 200;
    this->precision = 0.8;
    this->speed = 10;
    id = type;
}

/**
 * @brief Displays the details of a Char object
 * 
 * Displays the hit points, strength, precision, and speed of a Char object.
 */
void Char::AfficherSoldat() 
{
    cout << "Char :" << endl;
    Soldat::AfficherSoldat();
}

/**
 * @brief Return Soldier Type(Char)
 * 
 * @return type Returns which type of soldier it belongs to
 */
int Char::getType()
{
    return type;
}

/**
 * @brief After being affected by terrain weather, keep this state to prevent, multiple weather and terrain effects make the attribute stacked
 */
void Char::restituer()
{
    this->precision = 0.8;
    this->speed = 10;
}

  /**
    * @brief Change Location(se deplace avec un pas de 2)
    *
    * @param position Initial Location
    * 
    * @return nv_position new Location 
    */
pair Char::bouger(pair position)                
{ 
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 2*x, position.second + 2*x);

    return nv_position;
}

  /**
    * @brief Attack Location(il choisit une direction parmi 4 dir, puis elle tue 2 ligne(oucolomnes) de 6 personne)
    *
    * @param position Own position
    * 
    * @return nv_position Location of the enemy
    */
pair Char::Position_Tir(pair position)        
{
    int x, y;
    int choix = rand() % 2;
    if (choix) // 1 : x==0
    {
        x = 0;
        y = (rand()%2)? 1 : -1;
    }
    else // 0   : y==0 
    {
        y = 0;
        x = (rand()%2)? 1 : -1;
    }
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}