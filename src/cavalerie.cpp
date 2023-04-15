#include "soldat.hpp"


const int Cavalerie::type = 1;

Cavalerie::Cavalerie()
{
    this->hp = 150;
    this->strength = 5;
    this->precision = 0.3;
    this->speed = 60;
    id = type;
}


void Cavalerie::AfficherSoldat()
{
    cout << "Cavalerie :" << endl;
    Soldat::AfficherSoldat();
}


int Cavalerie::getType()
{
    return type;
}


void Cavalerie::restituer()
{
    this->precision = 0.3;
    this->speed = 60;
}


pair Cavalerie::bouger(pair position)           // se deplace avec un pas de 3
{
    //choisir une direction parmi les 9 possibles (position actuelle incluse)
    int x = genrand_int32() % 3;
    int y = genrand_int32() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 3*x, position.second + 3*y);

    return nv_position;
}

pair Cavalerie::Position_Tir(pair position)   // il choisit l'un des 8 soldats qu'ils l'entourent
{
    int x = genrand_int32() % 3;
    int y = genrand_int32() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}
Cavalerie::~Cavalerie()
{}