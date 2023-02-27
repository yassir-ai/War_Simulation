#include "soldat.hpp"

const int Char::type = 2;

Char::Char()
{
    this->hp = 500;
    this->strength = 200;
    this->precision = 0.8;
    this->speed = 10;
    id = type;
}

void Char::AfficherSoldat() 
{
    cout << "Char :" << endl;
    Soldat::AfficherSoldat();
}


int Char::getType()
{
    return type;
}


void Char::restituer()
{
    this->precision = 0.8;
    this->speed = 10;
}


pair Char::bouger(pair position)                  // se deplace avec un pas de 2
{ 
    int x = rand() % 3;
    int y = rand() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 2*x, position.second + 2*x);

    return nv_position;
}

pair Char::Position_Tir(pair position)        // il choisit une direction parmi 4 dir, puis elle tue 2 ligne(oucolomnes) de 6 personne
{
    int x, y;
    int choix = rand() % 2;
    if (choix) // 1 : x==0
    {
        x = 0;
        y = (rand()%2)? 1 : -1;
    }
    else // 0   : y==0 
    {
        y = 0;
        x = (rand()%2)? 1 : -1;
    }
    pair nv_position = std::make_pair(position.first + x, position.second + y);

    return nv_position;
}