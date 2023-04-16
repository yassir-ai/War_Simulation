#ifndef STATISTIQUE_HPP
#define STATISTIQUE_HPP

#include "simulation.hpp"



class Statistique
{
private :
    Simulation * tableau;
    int nombre_simulation;
    int nombre_tour;

public: 
    Statistique(int, int, SDL_Renderer*);
    double Moyenne_mort_general();
    double nombre_mort_moyen_par_terrain(pair);
    double * nombre_mort_par_terrain_general();
};

#endif