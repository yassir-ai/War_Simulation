#include "terrain.hpp"

Terrain::Terrain()
{
    int random_meteo = genrand_int32() % 3;
    int random_topo = genrand_int32() % 3;

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
            // if ( matrice[i][j] != nullptr ) cout << matrice[i][j]->getId() << " " ;
            if ( matrice[i][j] != nullptr )  matrice[i][j]->AfficherSoldat()  ;
        }
        cout << endl;
    }
}


void Terrain::InfluenceSoldat( Soldat& soldat )
{
    float taux = meteo * soldat.getPrecision() * 0.25;
    int taux_speed = topo * soldat.getType();

    float nv_precision = soldat.getPrecision() - taux;
    int nv_speed = soldat.getSpeed() - taux_speed;

    soldat.setPrecision(nv_precision);
    if (soldat.getType() != Force_Aerienne::type) soldat.setSpeed(nv_speed); // les forces aerienne ne sont pas influence par la topographie (ils volent)
}

pair Terrain::conditions()
{
    return std::make_pair(getMeteo(), getTopographie());
}