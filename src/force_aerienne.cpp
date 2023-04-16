#include "soldat.hpp"

const int Force_Aerienne::type = 3;

Force_Aerienne::Force_Aerienne()
{
    this->hp = 400;
    this->strength = 300;
    this->precision = 0.9;
    this->speed = 90;
    id = type;
}


void Force_Aerienne::AfficherSoldat()
{
    cout << "Force aerienne :" << endl;
    Soldat::AfficherSoldat();
}


int Force_Aerienne::getType()
{
    return type;
}


void Force_Aerienne::restituer()
{
    this->precision = 0.9;
    this->speed = 90;
}


pair Force_Aerienne::bouger(pair position)                // se deplace avec un pas de 5
{
    //choisir une direction parmi les 9 possibles (position actuelle incluse)
    int x = genrand_int32() % 3;
    int y = genrand_int32() % 3;
    x--;
    y--;
    pair nv_position = std::make_pair(position.first + 5*x, position.second + 5*y);

     //MAJ des coord de notre soldat
    this->coordonne_soldat = nv_position;

    return nv_position;
}

pair Force_Aerienne::Position_Tir(pair position)   //elle tue 8 personne autour de lui
{
    return position;
}

Force_Aerienne::~Force_Aerienne()
{}