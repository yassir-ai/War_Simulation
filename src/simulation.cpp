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


void Simulation::supprimer_soldat(Soldat* sol_mort)
{
   // int id = sol_mort->getId() / 4;   //recuperer numero de l'arm??e

    // auto it = find(a[id].begin(), a[id].end(), sol_mort); // Cherche l'??l??ment dans le vecteur

    // if (it != a[id].end())                       // Si l'??l??ment est trouv??
    // { 
    //     //a[id].erase(it);                         // Supprime l'??l??ment du vecteur
    //     //delete sol_mort;                            // Lib??re la m??moire allou??e pour l'??l??ment
    // }
}



void Simulation::executer_tir(pair pos_soldat_cour)
{
    int taille = TAILLE_C * TAILLE_T;
    Soldat * soldat_cour = carte_etat[pos_soldat_cour.first][pos_soldat_cour.second];
    int type = soldat_cour->getType();
    pair nv_positio = soldat_cour->Position_Tir(pos_soldat_cour);       //avoir la nouvelle position
    int i = (nv_positio.first+taille)%taille;
    int j = (nv_positio.second+taille)%taille;
    Soldat * ennemi =  carte_etat[i][j];                               //recuperer l'ennemi ?? cet position (peut etre null)
    int di, dj;
    int ti, tj;

    switch (type)
    {
        case 0:                 //Infanterie
            if (ennemi && !soldat_cour->est_Ami(*ennemi))          // si il esxiste un soldat et qui n'est pas ami avec sol_cour
            {
                ennemi->reduireHp( soldat_cour->tirer());

                //virifier s'il est mort 
                if (ennemi->estMort())
                {
                    cout << ennemi->getId() << " a la position " << i << ", " << j << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second << endl;
                    Carte_Guerre[i][j] = nullptr;                                // l'eliminer de la carte de guerre
                    supprimer_soldat(ennemi);                                     //supprimer l'ennemi de l'arm??e
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
                    cout << ennemi->getId() << " a la position " << i << ", " << j << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                    Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                    supprimer_soldat(ennemi);                                     //supprimer l'ennemi de l'arm??e
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
                    ti = (k + taille) % taille;

                    if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(k+taille)%taille][(pos_soldat_cour.second-dj+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        tj = (pos_soldat_cour.second-dj+taille)%taille;


                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());
                        //virifier s'il est mort 
                        if (carte_etat[ti][tj]->estMort())
                        {
                            cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            //supprimer_soldat(carte_etat[(k+taille)%taille][(nv_positio.second-dj+taille)%taille]);                                     //supprimer l'ennemi de l'arm??e
                        }
                    }

                    if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        tj = (pos_soldat_cour.second-2*dj+taille)%taille;

                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[ti][tj]->estMort())
                        {
                            cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            //supprimer_soldat(carte_etat[(k+taille)%taille][(nv_positio.second-2*dj+taille)%taille]);                                     //supprimer l'ennemi de l'arm??e
                        }
                    }
                }
            }
            else      // direction vertical
            {
                for (int k = nv_positio.second - 1; k <= nv_positio.second + 1; k++)
                {
                    tj = (k + taille) % taille;
                    if (carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first-di+taille)%taille][(k+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        ti = (pos_soldat_cour.first-di+taille)%taille;

                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[ti][tj]->estMort())
                        {
                            cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            //supprimer_soldat(carte_etat[(nv_positio.first-di+taille)%taille][(k+taille)%taille]);                                     //supprimer l'ennemi de l'arm??e
                        }
                    }

                    if (carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        ti = (pos_soldat_cour.first-2*di+taille)%taille;

                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[ti][tj]->estMort())
                        {
                            cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            //supprimer_soldat(carte_etat[(nv_positio.first-2*di+taille)%taille][(k+taille)%taille]);                                     //supprimer l'ennemi de l'arm??e
                        }
                    }
                }
            }

            break;
        
        case 3:         //force aerienne
            for (int u = -1; u <= 1; u++)
            {
                ti = (pos_soldat_cour.first + u + taille) % taille;
                for (int v = -1; v <= -1; v++)
                {
                    tj = (pos_soldat_cour.second + v + taille) % taille;

                    if (carte_etat[ti][tj] && !soldat_cour->est_Ami(*carte_etat[ti][tj]))
                    {
                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());   //reduire hp de l'ennemi

                        if (carte_etat[ti][tj]->estMort())
                        {
                            cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            //supprimer_soldat(carte_etat[(pos_soldat_cour.first + u + taille) % taille ][(pos_soldat_cour.second + v + taille) % taille]);                                     //supprimer l'ennemi de l'arm??e
                        }
                    }
                }
                
            }
            

            break;
        default:
            break;
    }

}


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
                        Carte_Guerre[dest_i][dest_j] = soldat_cour;      //placer le soldat dans ?? nouvelle case
                        Carte_Guerre[i][j] = nullptr;   // la case est vide maintenant
                        
                        // influence du nv terrain si le soldat change de terrain
                        if (i / taille != (dest_i / taille) || j / taille != (dest_j / taille))  //si au moin l'une des coordonn??es change => il a chang?? de terrain
                        {
                            soldat_cour->restituer();                              // restituer ses conditions de d??part
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


void Simulation::afficher_episode()
{
    int taille = TAILLE_C * TAILLE_T;

    for (int i = 0; i < taille;  i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if(!Carte_Guerre[i][j]) cout << "[ ]" << " ";
            else
            {
                if (Carte_Guerre[i][j]->getId() < 4)
                    cout<< "[" <<BLE<< Carte_Guerre[i][j]->getId() << INIT<<"]" << " ";
                else
                    cout<< "[" <<RED2<< Carte_Guerre[i][j]->getId() << INIT<<"]" << " ";
            }
        }
        cout<<endl;
    }
    
}


void Simulation::simuler(int tour, SDL_Renderer* render)
{
    Progression();
    int tmp = 0;

    bool play = false;
    bool pause = false;
    SDL_Event event;

    while( !play && tmp<tour)
    {    
        while(SDL_PollEvent(&event))
        {
          switch(event.type)
          {
            case SDL_QUIT:                                     //fermeture du fenetre 
                play = true;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    pause = !pause;
                }
                break;
            default:
                break;
          }
        }

        while (!pause)
        {
            cout << "TOUR " << tmp++ << endl;
            afficher_episode();
            SDL_display(render);
            episode();
        }
    }
}


void Simulation::SDL_display(SDL_Renderer* render)
{
	SDL_Rect rectangle = { 0, 0, 20, 20 };
	int i = 0, j = 0;

	while (j < TAILLE_C * TAILLE_T && rectangle.x + rectangle.w <= TAILLE_C * TAILLE_T * 20)
	{
		while (i < TAILLE_C * TAILLE_T && rectangle.y <= TAILLE_C * TAILLE_T * 20)
		{
			if (carte_etat[i][j])
			{
                if (carte_etat[i][j]->getId() < 4)
                {
				    if (SDL_SetRenderDrawColor(render, 0, 0, 255, 255) != 0) std::cerr << "erreur";
                
                }
                else
                {
				    if (SDL_SetRenderDrawColor(render, 255, 0, 0, 255) != 0) std::cerr << "erreur";
                    
                }
				if (SDL_RenderDrawRect(render, &rectangle) != 0) std::cerr << "erreur";
				SDL_RenderFillRect(render, &rectangle);
			}

			rectangle.y = rectangle.y + rectangle.h;
			i++;
		}
		rectangle.y = 0;

		rectangle.x = rectangle.x + rectangle.w;
		j++;
		i = 0;
	}

	SDL_RenderPresent(render);
	SDL_Delay(1000);

	if (SDL_SetRenderDrawColor(render, 0, 0, 0, 255) != 0) std::cerr << "erreur";
	SDL_RenderClear(render);
}