/**  @file     Force_Aerienne.cpp    
 * @brief Implements the Force_Aerienne class                                                                                                                            
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

const int Force_Aerienne::type = 3;  /**< The soldier's type.(3) */

/**
 * @brief Constructor for the Force_Aerienne class
 * 
 * Initializes the Force_Aerienne object with default values.
 */
Force_Aerienne::Force_Aerienne()
{
    this->hp = 400;
    this->strength = 300;
    this->precision = 0.9;
    this->speed = 90;
    id = type;
}

/**
 * @brief Displays the details of a Force_Aerienne object
 * 
 * Displays the hit points, strength, precision, and speed of a Force_Aerienne object.
 */
void Force_Aerienne::AfficherSoldat()
{
    cout << "Force aerienne :" << endl;
    Soldat::AfficherSoldat();
}

/**
 * @brief Return Soldier Type(Force_Aerienne)
 * 
 * @return type Returns which type of soldier it belongs to
 */
int Force_Aerienne::getType()
{
    return type;
}

/**
 * @brief After being affected by terrain weather, keep this state to prevent, multiple weather and terrain effects make the attribute stacked
 */
void Force_Aerienne::restituer()
{
    this->precision = 0.9;
    this->speed = 90;
}

  /**
    * @brief Change Location(se deplace avec un pas de 5)
    *
    * @param position Initial Location
    * 
    * @return nv_position new Location 
    */
pair Force_Aerienne::bouger(pair position)                
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 5*x, position.second + 5*y);

    return nv_position;
}

  /**
    * @brief Attack Location(elle tue 8 personne autour de lui)
    *
    * @param position Own position
    * 
    * @return nv_position Location of the enemy
    */
pair Force_Aerienne::Position_Tir(pair position)  
{
    return position;
}