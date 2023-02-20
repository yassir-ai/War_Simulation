#include "terrain.hpp"

Terrain::Terrain()
{
    int random_meteo = rand() % 3;
    int random_topo = rand() % 3;

    meteo = random_meteo;
    topo = random_topo;
}

Topographie Terrain::getTopographie()
{
    return topo;
}

Meteo Terrain::getMeteo()
{
    return meteo;
}

void Terrain::setTopographie(Topographie topo)
{
    this->topo = topo;
}

void Terrain::setMeteo(Meteo meteo)
{
    this->meteo = meteo;
}