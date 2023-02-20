#include "soldat.hpp"

Char::Char()
{
    this->hp = 500;
    this->strength = 200;
    this->precision = 0.8;
    this->speed = 10;
}

void Char::Afficher()
{
    cout << "Char :" << endl;
    this->Afficher();
}