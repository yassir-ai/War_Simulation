#include "simulation.hpp"

int main(int , char** )
{

    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* fenetre = SDL_CreateWindow("War Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_C * TAILLE_T * 20, TAILLE_C * TAILLE_T * 20, SDL_WINDOW_OPENGL);

    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    





    Simulation s;

    s.DisperserArmee();

    //s.AffichageCarte2();

    //s.AfficherCarte();

    //s.AfficherArmees();


    // s.Progression();

    // s.episode();
    s.simuler(1000, renderer);
        







    return 0;
}