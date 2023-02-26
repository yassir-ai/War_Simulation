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


pair Cavalerie::bouger(pair position)
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x + 2, position.second + y + 2);

    return nv_position;
}

pair Cavalerie::Position_Tir(pair position)
{
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}