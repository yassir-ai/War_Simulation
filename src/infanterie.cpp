/**  @file     Infanterie.cpp    
 * @brief Implements the Infanterie class                                                                                                                            
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

const int Infanterie::type = 0;  /**< The soldier's type.(0) */

/**
 * @brief Constructor for the Infanterie class
 * 
 * Initializes the Infanterie object with default values.
 */
Infanterie::Infanterie()
{
    this->hp = 100;
    this->strength = 5;
    this->precision = 0.5;
    this->speed = 20;
    id = type;
}

/**
 * @brief Displays the details of a Infanterie object
 * 
 * Displays the hit points, strength, precision, and speed of a Infanterie object.
 */
void Infanterie::AfficherSoldat()
{
    cout << "Infanterie :" << endl;
    Soldat::AfficherSoldat();
}

/**
 * @brief Return Soldier Type(Infanterie)
 * 
 * @return type Returns which type of soldier it belongs to
 */
int Infanterie::getType()
{
    return type;
}

/**
 * @brief After being affected by terrain weather, keep this state to prevent, multiple weather and terrain effects make the attribute stacked
 */
void Infanterie::restituer()
{
    this->precision = 0.5;
    this->speed = 20;
}

/**
    * @brief Change Location(se deplace avec un pas de 1)
    *
    * @param position Initial Location
    * 
    * @return nv_position new Location 
    */
pair Infanterie::bouger(pair position)   
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}

  /**
    * @brief Attack Location(elle tue un seul soldat parmi les 8 autour de lui )
    *
    * @param position Own position
    * 
    * @return nv_position Location of the enemy
    */
pair Infanterie::Position_Tir(pair position)           
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}