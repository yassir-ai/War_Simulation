#include "statistique.hpp"



Statistique::Statistique(int nb_simu, int nb_tour, SDL_Renderer* r) : nombre_simulation(nb_simu), nombre_tour(nb_tour)
{
    tableau = new Simulation[nb_simu];

    for (int i = 0; i < nombre_simulation; i++)
    {
        tableau[i].DisperserArmee();
        tableau[i].simuler(nombre_tour, r);
    }
}

double Statistique::Moyenne_mort_general()
{
    double moyenne = 0;
 
    for (int i = 0; i < nombre_simulation; i++)
    {
        moyenne += tableau[i].getNombreMort();
    }

    moyenne /= (double) nombre_simulation;

    cout << "la moyenne de nombre de mort durant " << nombre_simulation << " simulations est : " << moyenne << endl;

    return moyenne;
}

double  Statistique::nombre_mort_moyen_par_terrain(pair t)
{
    double resultat = 0;

    for (int i = 0; i < nombre_simulation; i++)
    {
        for (int j = 0; j < TAILLE_C; j++)
        {
            for (int k = 0; k < TAILLE_C; k++)
            {
                if (t == (tableau[i].carte[j][k]).conditions())
                {
                    resultat += (tableau[i].carte[j][k]).nb_mort;
                }
            }
        }
    }
    
    cout<< "le nombre de mort moyen  dans ce terrain est : " << resultat / (double) nombre_simulation << endl;
    return resultat / (double) nombre_simulation;
}

double * Statistique::nombre_mort_par_terrain_general()
{
    double tab[3][3];


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j] = nombre_mort_moyen_par_terrain({i,j});
            cout << " nombre de mort dans le terrain "<< i << " , " << j << " apres X simulations est : " << tab[i][j] << endl;  
        }
    }
    
    return *tab;
}

Statistique::~Statistique()
{
    delete [] tableau;
}


