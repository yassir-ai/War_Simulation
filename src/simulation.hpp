#ifndef SIMULATION__H
#define SIMULATION__H

#include <iostream>
#include <ctime>
#include <algorithm>
#include "soldat.hpp"
#include "terrain.hpp"

const int TAILLE_A = 100;                //taille armee
const int TAILLE_C = 3;                 //racine de taille de la carte
const int N_INFA = 60;
const int N_CAVA = 20;
const int N_CHAR = 10;
const int N_AERI = 10;

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

    ~Simulation();
};

#endif