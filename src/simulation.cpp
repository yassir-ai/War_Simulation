#include "simulation.hpp"

Simulation::Simulation()
{
    a1 = new Vector<Soldat>();
    a2 = new Vector<Soldat>();

    carte = new Terrain[TAILLE_T][TAILLE_T];
}

Armee Simulation::getA1()
{
    return a1;
}

Armee Simulation::getA2()
{
    return a2;
}

void Simulation::setA1(Armee a)
{
    a1 = a;
}

void Simulation::setA2(Armee a)
{
    a2 = a;
}

void AfficherArmees()
{
    cout << "-> ARMEE 1 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a1[i].Afficher();
    }

    cout << "-> ARMEE 2 :" << endl;
    for (int i = 0; i < TAILLE_A; i++)
    {
        a2[i].Afficher();
    }
}

Simulation::~Simulation()
{
    delete[][] carte; // a changer
    delete[] a1;
    delete[] a2;
}