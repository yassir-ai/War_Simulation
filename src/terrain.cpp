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
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
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

    meteo = (Meteo) random_meteo;
    topo = (Topographie) random_topo;

    for (int i = 0; i < TAILLE_T; i++)
    {
        for (int j = 0; j < TAILLE_T; j++)
        {
            matrice[i][j] = nullptr;
        }
        
    }

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

/**
 * @brief Displays the terrain with the soldiers present on each square.
 */
void Terrain::AfficherTerrain()
{
    for (int i = 0; i < TAILLE_T; i++)
    {
        for (int j = 0; j < TAILLE_T; j++)
        {
            // if ( matrice[i][j] != nullptr ) cout << matrice[i][j]->getId() << " " ;
            if ( matrice[i][j] != nullptr )  matrice[i][j]->AfficherSoldat()  ;
        }
        cout << endl;
    }
}

/**
 * @brief Modifie les caractéristiques d'un soldat en fonction de la météo et de la topographie.
 * @param soldat Soldat dont les caractéristiques sont modifiées.
 */
void Terrain::InfluenceSoldat( Soldat& soldat )
{
    float taux = meteo * soldat.getPrecision() * 0.25;
    int taux_speed = topo * soldat.getType();

    float nv_precision = soldat.getPrecision() - taux;
    int nv_speed = soldat.getSpeed() - taux_speed;

    soldat.setPrecision(nv_precision);
    if (soldat.getType() != Force_Aerienne::type) soldat.setSpeed(nv_speed); // les forces aerienne ne sont pas influence par la topographie (ils volent)
}


