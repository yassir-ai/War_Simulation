#ifndef TERRAIN__HPP
#define TERRAIN__HPP

#include <iostream>
#include <ctime>
#include "soldat.hpp"


const int TAILLE_T = 6;

enum Meteo
{
    SOLEIL,
    TEMPETE,
    BROUILLARD
};

enum Topographie
{
    PLAINE,
    FORET,
    MONTAGNE
};

class Terrain
{

protected:

    Topographie topo;
    Meteo meteo;

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