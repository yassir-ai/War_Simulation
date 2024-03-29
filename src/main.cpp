#include "statistique.hpp"

int main(int , char** )
{
    //Initialisation du générateur MT
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    //Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* fenetre = SDL_CreateWindow("War Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_C * TAILLE_T * 20, TAILLE_C * TAILLE_T * 20, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //Initialisation simulation
    Statistique stat(1, 600, renderer);  // 1 simulation de 1000 tour (épisodes)
    stat.Moyenne_mort_general();
    //stat.nombre_mort_moyen_par_terrain({SOLEIL,PLAINE});
    //stat.nombre_mort_par_terrain_general();

    //Liberation
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(fenetre);
    // SDL_Quit();


    return 0;
}