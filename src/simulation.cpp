/**  @file     simulation.cpp                                                                                                                                
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
 * <tr><td>2023/01/31  <td>1.0      <td>Achraf    <td>Creating the initial version(Array and vector selection needs to be discussed)
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>modification of cart(impossible d'assigner une valeur de type "Terrain (*)[3]" à une entité de type "Terrain **")(Still need to discuss)
 * </table>
 ******************************************************************
 */ 
#include "simulation.hpp"

/**
* @brief Constructs a new Simulation object.
*
* This constructor initializes the armies and the terrain for the simulation.
*/
Simulation::Simulation()
{
    a1 = new vector<Soldat>();
    a2 = new vector<Soldat>();
    
    for(int i = 0; i < TAILLE_T; i++){
        carte[i] = new Terrain;
    }
    /*carte = new Terrain[TAILLE_T][TAILLE_T];*/
}

/**
* @brief Gets the first army.
*
* @return The first army.
*/
Armee Simulation::getA1()
{
    return a1;
}

/**
* @brief Gets the second army.
*
* @return The second army.
*/
Armee Simulation::getA2()
{
    return a2;
}

/**
* @brief Sets the first army.
*
* @param a1 The new value for the first army.
*/
void Simulation::setA1(Armee a)
{
    a1 = a;
}

/**
* @brief Sets the second army.
*
* @param a2 The new value for the second army.
*/
void Simulation::setA2(Armee a)
{
    a2 = a;
}

/**
* @brief Displays the armies in the simulation.
*/
void AfficherArmees()
{
    cout << "-> ARMEE 1 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a1.Afficher();
    }

    cout << "-> ARMEE 2 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a2[i].Afficher();
    }
}

/**
* @brief Destroys the Simulation object.
*
* This destructor frees the memory used by the terrain.
*/
Simulation::~Simulation()
{
    delete[] carte; // a changer
    delete[] a1;
    delete[] a2;
}