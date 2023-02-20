#ifndef SIMULATION__H
#define SIMULATION__H

#include <iostream>
#include <ctime>
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

public:

    Simulation();
    
    Armee getA1();
    Armee getA2();

    void setA1(Armee );
    void setA2(Armee );

    void AfficherArmees();

    void DisperserArmee();

    void AfficherCarte();

    ~Simulation();
};

#endif