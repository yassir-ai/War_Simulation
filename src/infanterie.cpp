#include "soldat.hpp"

Infanterie::Infanterie()
{
    this->hp = 100;
    this->strength = 5;
    this->precision = 0.5;
    this->speed = 20;
}

void Infanterie::AfficherSoldat()
{
    cout << "Infanterie :" << endl;
    Soldat::AfficherSoldat();
}

int Infanterie::TypeSoldat()
{
    return type;
}
