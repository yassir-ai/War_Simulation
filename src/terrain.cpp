/**  @file     terrain.cpp                                                                                                                                
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
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>Resolving enum assignment conflicts
 * </table>
 ******************************************************************
 */   

#include "terrain.hpp"

/**
* @brief Constructs a new Terrain object with a random topography and weather condition
*/
Terrain::Terrain()
{
    int random_meteo = rand() % 3;
    int random_topo = rand() % 3;

    meteo = (Meteo)random_meteo;
    topo = (Topographie)random_topo;
}

/**
 * @brief Gets the topography of the terrain
 * @return The topography of the terrain
 */
Topographie Terrain::getTopographie()
{
    return topo;
}

/**
 * @brief Gets the weather condition of the terrain
 * @return The weather condition of the terrain
 */
Meteo Terrain::getMeteo()
{
    return meteo;
}

/**
 * @brief Sets the topography of the terrain
 * @param topo The topography to set
 */
void Terrain::setTopographie(Topographie topo)
{
    this->topo = topo;
}


/**
 * @brief Sets the weather condition of the terrain
 * @param meteo The weather condition to set
 */
void Terrain::setMeteo(Meteo meteo)
{
    this->meteo = meteo;
}