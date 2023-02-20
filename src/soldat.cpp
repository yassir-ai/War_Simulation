#include "soldat.hpp"

Soldat::Soldat() 
{}

int Soldat::getHp()
{
    return hp;
}

int Soldat::getStrength()
{
    return strength;
}

float Soldat::getPrecision()
{
    return precision;
}

int Soldat::getSpeed()
{
    return speed;
}

void Soldat::setHp(int hp)
{
    this->hp = hp;
}

void Soldat::setStrength(int strength)
{
    this->strength = strength;
}

void Soldat::setPrecision(float precision)
{
    this->precision = precision;
}

void Soldat::setSpeed(int speed)
{
    this->speed = speed;
}

int Soldat::tirer()
{
    int resultat = 0;
    float random = rand() / (float) RAND_MAX;

    if (random <= precision)
        resultat = strength;
    
    return resultat;
}

void Soldat::reduireHp(int tir)
{
    int random = rand() % 100;
    
    if (random >= speed)
        hp -= tir;
}

void Soldat::AfficherSoldat()
{
    cout << "HP : " << hp;
    cout << " STR : " << strength;
    cout << " PRC : " << precision;
    cout << " SPD : " << speed << endl;
}


Soldat::~Soldat()
{}