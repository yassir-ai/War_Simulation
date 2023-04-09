#ifndef SIMULATION__H
#define SIMULATION__H

#include <iostream>
#include <ctime>
#include <algorithm>
#include "soldat.hpp"
#include "terrain.hpp"
#include <SDL2/SDL.h>

const int TAILLE_A = 162;                //taille armee
const int TAILLE_C = 3;                 //racine de taille de la carte
const int N_INFA = 80;
const int N_CAVA = 42;
const int N_CHAR = 30;
const int N_AERI = 10;

#define BLE     "\x1b[44m"
#define INIT    "\x1b[0m"
#define RED     "\x1b[31m"
#define RED2	"\x1b[41;5;1m"



// const int TAILLE_A = 20;                //taille armee
// const int TAILLE_C = 3;                 //racine de taille de la carte
// const int N_INFA = 10;
// const int N_CAVA = 5;
// const int N_CHAR = 2;
// const int N_AERI = 3;

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
    void executer_tir(pair);
    void episode();
    void afficher_episode();
    void simuler(int , SDL_Renderer*);
    void SDL_display(SDL_Renderer* );
    ~Simulation();
};

#endif