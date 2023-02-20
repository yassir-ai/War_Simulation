                                                                           
/**  @file     terrain.hpp                                                                                                                                
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
 * </table>
 ******************************************************************
 */                                                                

#ifndef TERRAIN__HPP
#define TERRAIN__HPP
#include <iostream>
#include <ctime>

/**
 * @brief An enumeration of possible weather conditions.
 *
 * This enumeration represents three possible weather conditions: storm, sunshine,
 * and fog.
 */
enum Meteo
{
    TEMPETE, /**< Stormy weather. */
    SOLEIL,  /**< Sunny weather. */
    BROUILLARD /**< Foggy weather. */
};

/**
 * @brief An enumeration of possible types of terrain.
 *
 * This enumeration represents three possible types of terrain: plain, forest,
 * and hill.
 */
enum Topographie
{
    PLAINE, /**< A plain. */
    FORET, /**< A forest. */
    COLINE /**< A hill. */
};


/**
 * @brief A class representing a terrain object.
 *
 * This class represents a terrain object with a specific topography and weather
 * condition. It provides methods to get and set the topography and weather
 * condition of the terrain.
 */
class Terrain
{
protected:
    Topographie topo;/**< The topography of the terrain. */
    Meteo meteo;/**< The weather condition of the terrain. */

public:

    /**
     * @brief Default constructor.
     *
     * This constructor initializes a terrain object with default values for its
     * topography and weather condition.
     */
    Terrain();

    /**
     * @brief Gets the topography of the terrain.
     *
     * This method returns the topography of the terrain object.
     *
     * @return The topography of the terrain object.
     */
    Topographie getTopographie();

    /**
     * @brief Gets the weather condition of the terrain.
     *
     * This method returns the weather condition of the terrain object.
     *
     * @return The weather condition of the terrain object.
     */
    Meteo getMeteo();
 
    /**
     * @brief Sets the topography of the terrain.
     *
     * This method sets the topography of the terrain object to the specified
     * topography value.
     *
     * @param topo The new topography for the terrain object.
     */
    void setTopographie(Topographie );

    
    /**
     * @brief Sets the weather condition of the terrain.
     *
     * This method sets the weather condition of the terrain object to the specified
     * weather value.
     *
     * @param meteo The new weather condition for the terrain object.
     */
    void setMeteo(Meteo );
};

#endif