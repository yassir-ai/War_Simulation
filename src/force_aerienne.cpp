/**  @file     force_aerienne.cpp    
 * @brief      Implements the force_aerienne class                                                                                                                            
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
 * </table>
 ******************************************************************
 */  
#include "soldat.hpp"

/**
 * @brief Constructor for the Air Force class.
 * 
 * Initializes the health, strength, precision, and speed values.
 */
Force_Aerienne::Force_Aerienne()
{
    this->hp = 400;
    this->strength = 300;
    this->precision = 0.9;
    this->speed = 90;
}

/**
 * @brief Displays the details of a  Air Force object
 * 
 * Displays the hit points, strength, precision, and speed of a Char object.
 */
void Force_Aerienne::Afficher()
{
    cout << "Force aerienne :" << endl;
    Soldat::Afficher();
}