#include "soldat.hpp"

Infanterie::Infanterie()
{
    this->hp = 100;
    this->strength = 5;
    this->precision = 0.5;
    this->speed = 20;
}

void Infanterie::Afficher()
{
    cout << "Infanterie :" << endl;
    this->Afficher();
}