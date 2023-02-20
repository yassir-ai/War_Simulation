/**  @file     simulation.hpp                                                                                                                                
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
#ifndef SIMULATION__H
#define SIMULATION__H

#include <iostream>
#include <ctime>
#include "soldat.hpp"
#include "terrain.hpp"

const int TAILLE_A = 100;
const int TAILLE_T = 3;

using std::cout;
using std::endl;


/**
 * @brief The Simulation class represents a simulation of two armies fighting on a terrain.
 *
 * The simulation consists of two armies and a terrain, and provides methods for initializing the
 * armies and the terrain, displaying the armies, and running the simulation.
 */
class Simulation
{
private:
    Armee a1;  ///< The first army.
    Armee a2;  ///< The second army.
    Terrain* carte[TAILLE_A];   ///< The terrain.

public:
    /**
     * @brief Constructs a new Simulation object.
     *
     * This constructor initializes the armies and the terrain for the simulation.
     */
    Simulation();
    
    /**
     * @brief Gets the first army.
     *
     * @return The first army.
     */
    Armee getA1();

    /**
     * @brief Gets the second army.
     *
     * @return The second army.
     */
    Armee getA2();


    /**
     * @brief Sets the first army.
     *
     * @param a1 The new value for the first army.
     */
    void setA1(Armee );

    
    /**
     * @brief Sets the second army.
     *
     * @param a2 The new value for the second army.
     */
    void setA2(Armee );


    /**
     * @brief Displays the armies in the simulation.
     */
    void AfficherArmees();
    
    /**
     * @brief Destroys the Simulation object.
     *
     * This destructor frees the memory used by the terrain.
     */
    ~Simulation();
};

#endif