/**  @file     char.cpp    
 * @brief Implements the char class                                                                                                                            
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
}


/**
 * @brief Displays the details of a Char object
 * 
 * Displays the hit points, strength, precision, and speed of a Char object.
 */
void Char::Afficher()
{
    cout << "Char :" << endl;
    Soldat::Afficher();
}