#include "soldat.hpp"

const int Infanterie::type = 0;

Infanterie::Infanterie()
{
    this->hp = 100;
    this->strength = 5;
    this->precision = 0.5;
    this->speed = 20;
    id = type;
}


void Infanterie::AfficherSoldat()
{
    cout << "Infanterie :" << endl;
    Soldat::AfficherSoldat();
}


int Infanterie::getType()
{
    return type;
}


void Infanterie::restituer()
{
    this->precision = 0.5;
    this->speed = 20;
}


pair Infanterie::bouger(pair position)   // se deplace avec un pas de 1
{
    //choisir une direction parmi les 9 possibles (position actuelle incluse)
    int x = genrand_int32() % 3;
    int y = genrand_int32() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);



    return nv_position;
}

pair Infanterie::Position_Tir(pair position)           // elle tue un seul soldat parmi les 8 autour de lui 
{
    int x = genrand_int32() % 3;
    int y = genrand_int32() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);
    
    return nv_position;
}

Infanterie::~Infanterie()
{}