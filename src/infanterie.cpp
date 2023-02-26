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


pair Infanterie::bouger(pair position)
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}

pair Infanterie::Position_Tir(pair position)
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}