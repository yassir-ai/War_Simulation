/**  @file     cavalerie.cpp    
 * @brief Implements the Cavalerie class                                                                                                                            
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


const int Cavalerie::type = 1; /**< The soldier's type.(1) */

/**
 * @brief Constructs a new Cavalerie object
 * 
 * Initializes the attributes of the Cavalerie object to default values.
 */
Cavalerie::Cavalerie()
{
    this->hp = 150;
    this->strength = 5;
    this->precision = 0.3;
    this->speed = 60;
    id = type;
}

/**
 * @brief Displays the attributes of the Cavalerie object
 * 
 * Calls the Afficher function of the parent class Soldat to display the common attributes of the unit
 * and adds the specific attributes of the Cavalerie unit.
 */
void Cavalerie::AfficherSoldat()
{
    cout << "Cavalerie :" << endl;
    Soldat::AfficherSoldat();
}

/**
 * @brief Return Soldier Type(Cavalerie)
 * 
 * @return type Returns which type of soldier it belongs to
 */
int Cavalerie::getType()
{
    return type;
}

/**
 * @brief After being affected by terrain weather, keep this state to prevent, multiple weather and terrain effects make the attribute stacked
 */
void Cavalerie::restituer()
{
    this->precision = 0.3;
    this->speed = 60;
}

  /**
    * @brief Change Location(se deplace avec un pas de 3)
    *
    * @param position Initial Location
    * 
    * @return nv_position new Location 
    */

pair Cavalerie::bouger(pair position)           
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 3*x, position.second + 3*x);

    return nv_position;
}

     /**
    * @brief Attack Location(il choisit l'un des 8 soldats qu'ils l'entourent)
    *
    * @param position Own position
    * 
    * @return nv_position Location of the enemy
    */
pair Cavalerie::Position_Tir(pair position)   
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}