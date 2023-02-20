#include "terrain.hpp"

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


void Terrain::AfficherTerrain()
{
    for (int i = 0; i < TAILLE_T; i++)
    {
        for (int j = 0; j < TAILLE_T; j++)
        {
            if ( matrice[i][j] != nullptr ) cout << matrice[i][j]->TypeSoldat() << " " ;
        }
        cout << endl;
    }
}


void Terrain::InfluenceSoldat( Soldat& soldat )
{
    float taux = meteo * soldat.getPrecision() * 0.25;
    int taux_speed = topo * soldat.TypeSoldat();

    float nv_precision = soldat.getPrecision() - taux;
    int nv_speed = soldat.getSpeed() - taux_speed;

    soldat.setPrecision(nv_precision);
    soldat.setSpeed(nv_speed);
}


