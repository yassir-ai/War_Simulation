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
            i = genrand_int32() % taille;
            j = genrand_int32() % taille;

            while (occupe[i][j])
            {
                i = genrand_int32() % taille;
                j = genrand_int32() % taille;
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
            if(  Carte_Guerre[i][j] &&  !Carte_Guerre[i][j]->estMort()) carte_etat[i][j] = Carte_Guerre[i][j];
            else if( !Carte_Guerre[i][j] || Carte_Guerre[i][j]->estMort()) carte_etat[i][j] = nullptr;
        }
    }

    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            Carte_Guerre[i][j] = carte_etat[i][j];;
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
                    //cout << ennemi->getId() << " a la position " << i << ", " << j << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second << endl;
                    Carte_Guerre[i][j] = nullptr;                                // l'eliminer de la carte de guerre
                    incrementer_mort(ennemi);                                             //incrementer le nombre de soldats morts    
                    carte[i / TAILLE_T][j / TAILLE_T].nb_mort++;
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
                   // cout << ennemi->getId() << " a la position " << i << ", " << j << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                    Carte_Guerre[i][j] = nullptr;  // l'eliminer de la carte de guerre
                    incrementer_mort(ennemi);                                                  //incrementer le nombre de soldats morts   
                    carte[i / TAILLE_T][j / TAILLE_T].nb_mort++;
                }
            }
            
            break;

        case 2:                 //char
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
                           // cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                             Carte_Guerre[ti][tj] = nullptr;  // l'eliminer de la carte de guerre
                            incrementer_mort( carte_etat[ti][tj]);                                                 //incrementer le nombre de soldats morts 
                            carte[ti / TAILLE_T][tj / TAILLE_T].nb_mort++;
                        }
                    }

                    if (carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(k+taille)%taille][(pos_soldat_cour.second-2*dj+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        tj = (pos_soldat_cour.second-2*dj+taille)%taille;

                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[ti][tj]->estMort())
                        {
                         //   cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;             // l'eliminer de la carte de guerre
                            incrementer_mort(carte_etat[ti][tj]);                                                //incrementer le nombre de soldats morts 
                            carte[ti / TAILLE_T][tj / TAILLE_T].nb_mort++;
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
                           // cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                             Carte_Guerre[ti][tj] = nullptr;                        // l'eliminer de la carte de guerre
                            incrementer_mort( carte_etat[ti][tj] );                                               //incrementer le nombre de soldats morts 
                            carte[ti / TAILLE_T][tj / TAILLE_T].nb_mort++;
                        }
                    }

                    if (carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille] && !soldat_cour->est_Ami(*carte_etat[(pos_soldat_cour.first-2*di+taille)%taille][(k+taille)%taille])) // si il esxiste un soldat et qui n'est pas ami avec sol_cour
                    {
                        ti = (pos_soldat_cour.first-2*di+taille)%taille;

                        carte_etat[ti][tj]->reduireHp( soldat_cour->tirer());

                        if (carte_etat[ti][tj]->estMort())
                        {
                          //  cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;                                    // l'eliminer de la carte de guerre
                            incrementer_mort( carte_etat[ti][tj] );                                                              //incrementer le nombre de soldats morts 
                            carte[ti / TAILLE_T][tj / TAILLE_T].nb_mort++;
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
                           // cout << carte_etat[ti][tj]->getId() << " a la position " << ti << ", " << tj << " sera mort" << " par " << soldat_cour->getId() << " a la position " << pos_soldat_cour.first << ", " << pos_soldat_cour.second  << endl;
                            Carte_Guerre[ti][tj] = nullptr;                     // l'eliminer de la carte de guerre
                            incrementer_mort( carte_etat[ti][tj] );                                                //incrementer le nombre de soldats morts 
                            carte[ti / TAILLE_T][tj / TAILLE_T].nb_mort++;
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


void Simulation::afficher_episode()
{
    int taille = TAILLE_C * TAILLE_T;

    for (int i = 0; i < taille;  i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if(!carte_etat[i][j]) cout << "[ ]" << " ";
            else
            {
                if (carte_etat[i][j]->getId() < 4)
                    cout<< "[" <<BLE<< carte_etat[i][j]->getType() << INIT<<"]" << " ";
                else
                    cout<< "[" <<RED2<< carte_etat[i][j]->getType() << INIT<<"]" << " ";
            }
        }
        cout<<endl;
    }
    
}


void Simulation::simuler(int tour, SDL_Renderer* render)
{
    Progression();
    int tmp = 0;
    // nombre_mort = 0;   //pour une nouvelle simulation, le compteur est mis à 0

    bool play = false;
    bool pause = false;
    SDL_Event event;

    while( !play && tmp < tour && (getNombreMort(0) != TAILLE_A  || getNombreMort(1) != TAILLE_A -2 || getNombreMort(2) != 2*TAILLE_A - 2 ))
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

        if (!pause && !play)
        {
            // cout << " le nombre de mort de la premiere armée jusqu à mntn est : " << getNombreMort(0) << endl;
            // cout << " le nombre de mort de la deuxième armée jusqu à mntn est : " << getNombreMort(1) << endl;
            cout << "TOUR " << tmp++ << endl;
            afficher_episode();
            SDL_display(render);
            episode();
        }

    }
   // cout << "le nombre de mort est : " << getNombreMort() << endl;
}


void Simulation::SDL_display(SDL_Renderer* render)
{
    SDL_Rect rectangle = { 0, 0, 20 * TAILLE_T, 20 * TAILLE_T };
    pair cond;

    for(int j = 0; j < TAILLE_C && rectangle.x + rectangle.w <= TAILLE_C * TAILLE_T * 20 ; j++)
    {
        for (int i = 0; i < TAILLE_C && rectangle.y <= TAILLE_C * TAILLE_T * 20; i++)
        {
            cond = carte[i][j].conditions();

            if(cond.first == SOLEIL && cond.second == PLAINE) SDL_SetRenderDrawColor(render, 0, 212, 4, 255); //0
            else if(cond.first == SOLEIL && cond.second == FORET) SDL_SetRenderDrawColor(render, 194, 133, 48, 255); //1
            else if(cond.first == SOLEIL && cond.second == MONTAGNE) SDL_SetRenderDrawColor(render, 175, 179, 162, 255); //2
            else if(cond.first == TEMPETE && cond.second == PLAINE) SDL_SetRenderDrawColor(render, 0, 77, 1, 255); //3
            else if(cond.first == TEMPETE && cond.second == FORET) SDL_SetRenderDrawColor(render, 84, 58, 21, 255); //4
            else if(cond.first == TEMPETE && cond.second == MONTAGNE) SDL_SetRenderDrawColor(render, 70, 71, 65, 255); //5
            else if(cond.first == BROUILLARD && cond.second == PLAINE) SDL_SetRenderDrawColor(render, 0, 135, 2, 255); //6
            else if(cond.first == BROUILLARD && cond.second == FORET) SDL_SetRenderDrawColor(render, 120, 83, 30, 255); //7
            else SDL_SetRenderDrawColor(render, 112, 115, 104, 255); //8

            SDL_RenderDrawRect(render, &rectangle);
			SDL_RenderFillRect(render, &rectangle);

			rectangle.y = rectangle.y + rectangle.h;
        }
        rectangle.y = 0;
		rectangle.x = rectangle.x + rectangle.w;
    }

	rectangle = { 0, 0, 20, 20 };
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

int Simulation::getNombreMort(int numero_armee)
{
    if(numero_armee == 0) return les_morts0.size();
    else if(numero_armee == 1) return les_morts1.size();

    return les_morts0.size() + les_morts1.size();
}


void Simulation::incrementer_mort(Soldat * s)
{
    int num_armee = s->getId() / 4;

    if(num_armee  == 0) les_morts0.insert(s);
    else if(num_armee == 1) les_morts1.insert(s);
}



