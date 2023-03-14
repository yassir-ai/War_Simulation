/**  @file     simulation.cpp                                                                                                                                
 * @author     Yassir, Achraf, Xuanzhe                                                                                                        
 * @version    1.0.0.1                                                
 * @date       2023.01.31                                                                                
 * @copyright  Copyright (c)
 *****************************************************************
 * @attention
 * Development environment: Windows
 * @par Modification log:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2023/01/31  <td>1.0      <td>Achraf    <td>Creating the initial version(Array and vector selection needs to be discussed)
 * <tr><td>2023/02/10  <td>2.0      <td>Xuanzhe   <td>modification of cart(impossible d'assigner une valeur de type "Terrain (*)[3]" à une entité de type "Terrain **")(Still need to discuss)
 * <tr><td>2023/02/20  <td>3.0      <td>Yassir   <td>Problem solving and optimization
 * </table>
 ******************************************************************
 */ 
#include "simulation.hpp"

/**
 * @brief Constructs a new Simulation object.
 *
 * This constructor initializes the armies and the terrain for the simulation.
 */
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
            ((Infanterie *) a[1][i])->incremId(4);               //pour ditinguer entre les soldats des deux armees
        }
        else if ( i < N_INFA + N_CAVA )
        {
            a[0].push_back( new Cavalerie() );
            a[1].push_back( new Cavalerie() );

            ((Cavalerie *) a[1][i])->incremId(4); 
            
            
        }
        else if ( i < N_INFA + N_CAVA + N_CHAR)
        {
            a[0].push_back( new Char() );
            a[1].push_back( new Char() );
            ((Char *) a[1][i])->incremId(4);
            
        }
        else 
        {
            a[0].push_back( new Force_Aerienne() );
            a[1].push_back( new Force_Aerienne() );
            ((Force_Aerienne *) a[1][i])->incremId(4);       
        }
    }

    for (int i = 0; i < TAILLE_C * TAILLE_T; i++)
    {
        for (int j = 0; j < TAILLE_C * TAILLE_T; j++)
        {
            Carte_Guerre[i][j] = nullptr;
        }
        
    }
}

/**
 * @brief Gets the first army.
 *
 * @return The first army.
 */
Armee Simulation::getA1()
{
    return a[0];
}

/**
 * @brief Gets the second army.
 *
 * @return The second army.
 */
Armee Simulation::getA2()
{
    return a[1];
}

/**
 * @brief Sets the first army.
 *
 * @param a1 The new value for the first army.
 */
void Simulation::setA1(Armee a)
{
    this->a[0] = a;
}

/**
 * @brief Sets the second army.
 *
 * @param a2 The new value for the second army.
 */
void Simulation::setA2(Armee a)
{
    this->a[1] = a;
}

/**
 * @brief Displays the armies in the simulation.
 */
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

/**
 * @brief Random distribution of two armies, that is, the initialization of two 
 * armies on the map. Include the effect of terrain on soldiers' attributes
 */
void Simulation::DisperserArmee()
{
    //initialisation des positions 
    bool occupe[TAILLE_C * TAILLE_T][TAILLE_C * TAILLE_T] =  {false};   // false == 0

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
            carte[i/TAILLE_T][j/TAILLE_T].matrice[i%TAILLE_T][j%TAILLE_T] = a[k][compteur];         // soldat *
            carte[i/TAILLE_T][j/TAILLE_T].InfluenceSoldat( *a[k][compteur] );                       // influence du terrain (meteo et topographie)
            Carte_Guerre[i][j] = a[k][compteur];                                                    // placer le soldat dans la carte de guerre
            compteur++;        
            occupe[i][j] = true;
        }

        compteur = 0;      //pour l'autre armee
    }
}

/**
 * @brief Destroys the Simulation object.
 *
 * This destructor frees the memory used by the terrain.
 */
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

/**
* @brief Mise à jour de la carte simulée avec les deux armées
*
*/
void Simulation::Progression()
{
    int taille = TAILLE_C * TAILLE_T;

    // remplissage de la carte temp
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            carte_etat[i][j] = Carte_Guerre[i][j];
        }
    }
}

/**
 * @brief Exportation des conditions météorologiques du terrain de la carte
 *
 */
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

/**
 * @brief Soldat Mort Effacer Soldat<This function has been replaced with other functions>
 *
 * @param sol_mort Objets du soldat mort
 * 
 */
void Simulation::supprimer_soldat(Soldat* sol_mort)
{
   // int id = sol_mort->getId() / 4;   //recuperer numero de l'armée

    // auto it = find(a[id].begin(), a[id].end(), sol_mort); // Cherche l'élément dans le vecteur

    // if (it != a[id].end())                       // Si l'élément est trouvé
    // { 
    //     //a[id].erase(it);                         // Supprime l'élément du vecteur
    //     //delete sol_mort;                            // Libère la mémoire allouée pour l'élément
    // }
}


/**
 * @brief Simulation of two armies sending war
 * 
 * @param pos_soldat_cour The location of the soldier being traversed
 * 
 */
void Simulation::executer_tir(pair pos_soldat_cour)
{
    int taille = TAILLE_C * TAILLE_T;
    Soldat * soldat_cour = carte_etat[pos_soldat_cour.first][pos_soldat_cour.second];
    int type = soldat_cour->getType();
    pair nv_positio = soldat_cour->Position_Tir(pos_soldat_cour);       //avoir la nouvelle position
    int i = (nv_positio.first+taille)%taille;
    int j = (nv_positio.second+taille)%taille;
    Soldat * ennemi =  carte_etat[i][j];                               //recuperer l'ennemi à cet position (peut etre null)
    int di, dj;

    switch (type)
    {
        case 0:                 //Infanterie
            if (ennemi && !soldat_cour->est_Ami(*ennemi))          // si il esxiste un soldat et qui n'est pas ami avec sol_cour
            {
                ennemi->reduireHp( soldat_cour->tirer());

                //virifier s'il est mort 
                if (ennemi->estMort())
                {
                    cout << ennemi->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second << endl;
                    Carte_Guerre[i][j] = nullptr;                                // l'eliminer de la carte de guerre
                    supprimer_soldat(ennemi);                                     //supprimer l'ennemi de l'armée
                }
            }
            
            break;

        case 1:                // Cavalerie
            if (ennemi && !soldat_cour->est_Ami(*ennemi)) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
            {
                ennemi->reduireHp( soldat_cour->tirer());

                //virifier s'il est mort 
                if (ennemi->estMort())
                {
                    cout << ennemi->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                    Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                    supprimer_soldat(ennemi);                                     //supprimer l'ennemi de l'armée
                }
            }
            
            break;

        case 2:     //char
            di = pos_soldat_cour.first - nv_positio.first;
            dj = pos_soldat_cour.second - nv_positio.second;

            if (di == 0)     // direction horizental
            {
                for (int k = nv_positio.first - 1; k <= nv_positio.first + 1; k++)
                {
                    if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille]->reduireHp( soldat_cour->tirer());
                        //virifier s'il est mort 
                        if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille]->estMort())
                        {
                            cout << carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille]->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                            supprimer_soldat(carte_etat[(k+taille)%taille][(nv_positio.second-dj+taille)%taille]);                                     //supprimer l'ennemi de l'armée
                        }
                    }

                    if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille]->estMort())
                        {
                            cout << carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille]->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                            supprimer_soldat(carte_etat[(k+taille)%taille][(nv_positio.second-2*dj+taille)%taille]);                                     //supprimer l'ennemi de l'armée
                        }
                    }
                }
            }
            else      // direction vertical
            {
                for (int k = nv_positio.second - 1; k <= nv_positio.second + 1; k++)
                {
                    if (carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille]->estMort())
                        {
                            cout << carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille]->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                            supprimer_soldat(carte_etat[(nv_positio.first-di+taille)%taille][(k+taille)%taille]);                                     //supprimer l'ennemi de l'armée
                        }
                    }

                    if (carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille]->estMort())
                        {
                            cout << carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille]->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                            supprimer_soldat(carte_etat[(nv_positio.first-2*di+taille)%taille][(k+taille)%taille]);                                     //supprimer l'ennemi de l'armée
                        }
                    }
                }
            }

            break;
        
        case 3:         //force aerienne
            for (int u = -1; u <= 1; u++)
            {
                for (int v = -1; v <= -1; v++)
                {
                    if (carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]))
                    {
                        carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]->reduireHp( soldat_cour->tirer());   //reduire hp de l'ennemi

                        if (carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]->estMort())
                        {
                            cout << carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]->getId() << " a la position " << i << ", " << j << " est mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                            supprimer_soldat(carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]);                                     //supprimer l'ennemi de l'armée
                        }
                    }
                }
                
            }
            

            break;
        default:
            break;
    }

}

/**
 * @brief The move and attack simulation functions, along with the 
 * executer_tir(pair pos_soldat_cour) function, are the two main 
 * functions of this simulation
 * 
 */
void Simulation::episode()
{
    Soldat * soldat_cour = nullptr;
    pair destination;                                     // de deplacemnt ou de tir
    int taille = TAILLE_C * TAILLE_T;
    int dest_i, dest_j;

    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            soldat_cour = carte_etat[i][j];

            if (soldat_cour)             //un soldat existe dans cette case
            {
                if (soldat_cour->decider())    //==1  -> bouger
                {
                    destination = soldat_cour->bouger(std::make_pair(i,j));           //recuperer la case de destination
                    dest_i = (destination.first + taille)%taille;
                    dest_j = (destination.second + taille)%taille;

                    if (!Carte_Guerre[dest_i][dest_j])        // verifier si l'enplacement est vide
                    {
                        Carte_Guerre[dest_i][dest_j] = soldat_cour;      //placer le soldat dans à nouvelle case
                        Carte_Guerre[i][j] = nullptr;   // la case est vide maintenant
                        
                        // influence du nv terrain si le soldat change de terrain
                        if (i / taille != (dest_i / taille) || j / taille != (dest_j / taille))  //si au moin l'une des coordonnées change => il a changé de terrain
                        {
                            soldat_cour->restituer();                              // restituer ses conditions de départ
                            carte[dest_i / taille][dest_j / taille].InfluenceSoldat(*soldat_cour);    //influence du nouveau terrain
                        }
                    }
                }
                else    //==0  -> tirer
                {
                    executer_tir(std::make_pair(i,j));
                }
            }
        }
        
    }
    
    Progression(); // actualisation de la carte d'etat

}

/**
 * @brief Exporting army movements and the occurrence of war
 * 
 */
void Simulation::afficher_episode()
{
    int taille = TAILLE_C * TAILLE_T;

    for (int i = 0; i < taille;  i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if(!Carte_Guerre[i][j]) cout << "[ ]" << " ";
            else cout<< "[" << Carte_Guerre[i][j]->getId() << "]" << " ";
        }
        cout<<endl;
    }
    
}

/**
 * @brief Simulate each round of war or movement
 * 
 */
void Simulation::simuler(int tour)
{
    Progression();
    int tmp = 0;

    while (tmp<tour)
    {
        cout << "TOUR " << tmp++ << endl;
        afficher_episode();
        episode();
    }
}