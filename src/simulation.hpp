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
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */ 
#ifndef SIMULATION__H
#define SIMULATION__H

#include <iostream>
#include <ctime>
#include <algorithm>
#include "soldat.hpp"
#include "terrain.hpp"

// const int TAILLE_A = 100;                //taille armee
// const int TAILLE_C = 3;                 //racine de taille de la carte
// const int N_INFA = 60;
// const int N_CAVA = 20;
// const int N_CHAR = 10;
// const int N_AERI = 10;



const int TAILLE_A = 20;                /**< taille armee. */
const int TAILLE_C = 3;                /**< racine de taille de la carte. */
const int N_INFA = 10;
const int N_CAVA = 5;
const int N_CHAR = 2;
const int N_AERI = 3;

using std::cout;
using std::endl;

typedef std::vector<Soldat *> Armee;

class Simulation
{

private:

    Armee a[2];

    Terrain** carte;

    Soldat * Carte_Guerre[TAILLE_T * TAILLE_C][TAILLE_T * TAILLE_C];

    Soldat* carte_etat[TAILLE_T * TAILLE_C][TAILLE_T * TAILLE_C];

public:

    Simulation();
    
    Armee getA1();
    Armee getA2();

    void setA1(Armee );
    void setA2(Armee );

    void AfficherArmees();

    void DisperserArmee();

    void Progression();

    void AfficherCarte();

    void supprimer_soldat(Soldat*);   //supprimer un soldat mort de l'armée

    void executer_tir(pair);

    void episode();

    void afficher_episode();

    void simuler(int );

    ~Simulation();
};

#endif