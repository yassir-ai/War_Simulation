#include "simulation.hpp"


Simulation::Simulation()
{
    carte = new Terrain *[TAILLE_C];

    for ( int i = 0; i < TAILLE_C; i++)
    {
        carte[i] = new Terrain[TAILLE_C];
    }

    for ( int i = 0; i < TAILLE_A; i++)
    {
        if ( i < N_INFA ) 
        {
            a[0].push_back( new Infanterie() );
            a[1].push_back( new Infanterie() );
            ((Infanterie *) a[1][i])->type += 4;               //pour ditinguer entre les soldats des deux armees
        }
        else if ( i < N_INFA + N_CAVA )
        {
            a[0].push_back( new Cavalerie() );
            a[1].push_back( new Cavalerie() );
            ((Cavalerie *) a[1][i])->type += 4; 
        }
        else if ( i < N_INFA + N_CAVA + N_CHAR)
        {
            a[0].push_back( new Char() );
            a[1].push_back( new Char() );
            ((Char *) a[1][i])->type += 4;             
        }
        else 
        {
            a[0].push_back( new Force_Aerienne() );
            a[1].push_back( new Force_Aerienne() );
            ((Force_Aerienne *) a[1][i])->type += 4; 
        }
    }
}

Armee Simulation::getA1()
{
    return a[0];
}

Armee Simulation::getA2()
{
    return a[1];
}

void Simulation::setA1(Armee a)
{
    this->a[0] = a;
}

void Simulation::setA2(Armee a)
{
    this->a[1] = a;
}

void Simulation::AfficherArmees()
{
    cout << "-> ARMEE 1 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a[0][i]->AfficherSoldat();
    }

    cout << "-> ARMEE 2 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a[1][i]->AfficherSoldat();
    }
}



void Simulation::DisperserArmee()
{
    //initialisation des positions 
    bool occupe[TAILLE_C * TAILLE_T][TAILLE_C * TAILLE_T] =  {false};   // false === 0

    //disperser armee1

    int compteur = 0;
    int i = 0, j = 0;
    int taille = TAILLE_C * TAILLE_T;

    //dispersion sur les terrains
    for ( int k = 0; k < 2; k++)
    {
        while ( compteur != TAILLE_A )
        {
            i = rand() % taille;
            j = rand() % taille;

            while (occupe[i][j])
            {
                i = rand() % taille;
                j = rand() % taille;
            }
            carte[i/TAILLE_T][j/TAILLE_T].matrice[i%TAILLE_T][j%TAILLE_T] = a[k][compteur];  // soldat *
            carte[i/TAILLE_T][j/TAILLE_T].InfluenceSoldat( *a[k][compteur] );
            compteur++;        
            occupe[i][j] = true;
        }

        compteur = 0;      //pour l'autre armee
    }



    //influence du meteo
    





}


Simulation::~Simulation()
{
    //liberer armee
    for ( int i = 0; i < TAILLE_A; i++)
    {
        delete a[0][i];
        delete a[1][i];
    }



    //liberer carte
    for ( int i = 0; i < TAILLE_C; i++ )
    {
        delete [] carte[i];
    }
    
    delete [] carte;
}




void Simulation::AfficherCarte()
{
    int cmpt = 0;
    for (int i = 0; i < TAILLE_C; i++)
    {
        for (int j = 0; j < TAILLE_C; j++)
        {
            cout<< "Terrain " << cmpt << endl;
            cout << "Meteo " << carte[i][j].getMeteo() << endl;
            cout << "Topologie " << carte[i][j].getTopographie() << endl;
            carte[i][j].AfficherTerrain();
            cmpt++;
        }
    }
}