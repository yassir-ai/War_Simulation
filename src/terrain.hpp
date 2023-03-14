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
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */                                                                

#ifndef TERRAIN__HPP
#define TERRAIN__HPP

#include <iostream>
#include <ctime>
#include "soldat.hpp"


const int TAILLE_T = 5;

/**
 * @brief An enumeration of possible weather conditions.
 *
 * This enumeration represents three possible weather conditions: storm, sunshine,
 * and fog.
 */
enum Meteo
{
    SOLEIL,   /**< Sunny weather. */
    TEMPETE,  /**< Stormy weather. */
    BROUILLARD   /**< Foggy weather. */
};

/**
 * @brief An enumeration of possible types of terrain.
 *
 * This enumeration represents three possible types of terrain: plain, forest,
 * and hill.
 */
enum Topographie
{
    PLAINE,  /**< A plain. */
    FORET,   /**< A forest. */
    MONTAGNE   /**< A hill. */
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

    Topographie topo; /**< The topography of the terrain. */
    Meteo  meteo;  /**< The weather condition of the terrain. */

public:

    Soldat * matrice[TAILLE_T][TAILLE_T];
    Terrain();
    Topographie getTopographie();
    Meteo getMeteo();

    void setTopographie(Topographie );
    void setMeteo(Meteo );
    void AfficherTerrain();
    void InfluenceSoldat( Soldat&  );

};

#endif