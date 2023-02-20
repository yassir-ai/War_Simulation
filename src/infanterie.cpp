/**  @file     infanterie.cpp    
 * @brief      Implements the infanterie class                                                                                                                            
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
 * @brief Constructor for the infanterie class.
 * 
 * Initializes the health, strength, precision, and speed values.
 */
Infanterie::Infanterie()
{
    this->hp = 100;
    this->strength = 5;
    this->precision = 0.5;
    this->speed = 20;
}

/**
 * @brief Displays the details of a  infanterie object
 * 
 * Displays the hit points, strength, precision, and speed of a Char object.
 */
void Infanterie::Afficher()
{
    cout << "Infanterie :" << endl;
    Soldat::Afficher();
}