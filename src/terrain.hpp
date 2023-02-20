#ifndef TERRAIN__HPP
#define TERRAIN__HPP

#include <iostream>
#include <ctime>

enum Meteo
{
    TEMPETE,
    SOLEIL,
    BROUILLARD
};

enum Topographie
{
    PLAINE,
    FORET,
    COLINE
};

class Terrain
{
protected:
    Topographie topo;
    Meteo meteo;

public:
    Terrain();
    Topographie getTopographie();
    Meteo getMeteo();

    void setTopographie(Topographie );
    void setMeteo(Meteo );
};

#endif