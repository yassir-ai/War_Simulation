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

class Simulation
{
private:
    Armee a1;
    Armee a2;
    Terrain** carte;

public:
    Simulation();
    
    Armee getA1();
    Armee getA2();

    void setA1(Armee );
    void setA2(Armee );

    void AfficherArmees();
    

    ~Simulation();
};