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
 * </table>
 ******************************************************************
 */     

#include "soldat.hpp"

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
}


/**
 * @brief Displays the attributes of the Cavalerie object
 * 
 * Calls the Afficher function of the parent class Soldat to display the common attributes of the unit
 * and adds the specific attributes of the Cavalerie unit.
 */
void Cavalerie::Afficher()
{
    cout << "Cavalerie :" << endl;
    Soldat::Afficher();
}