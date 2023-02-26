#include "simulation.hpp"

int main(int, char**)
{

    srand(time(NULL));

    Simulation s;

    s.DisperserArmee();

    //s.AffichageCarte2();

    //s.AfficherCarte();

    //s.AfficherArmees();


    s.Progression();

    s.episode();


    return 0;
}