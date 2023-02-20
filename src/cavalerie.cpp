#include "soldat.hpp"

Cavalerie::Cavalerie()
{
    this->hp = 150;
    this->strength = 5;
    this->precision = 0.3;
    this->speed = 60;
}

void Cavalerie::Afficher()
{
    cout << "Cavalerie :" << endl;
    this->Afficher();
}