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

int Soldat::getId()
{
    return id;
}


void Soldat::setId(int nv_id)
{
    id = nv_id;
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
    float random = genrand_real1();

    if (random <= precision)
        resultat = strength;
    
    return resultat;
}


void Soldat::reduireHp(int tir)
{
    int random = genrand_int32() % 100;
    
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


void Soldat::incremId(int pas)
{
    id += pas;
}


int Soldat::decider() // 0 = tirer, 1 = bouger
{
    return genrand_int32() % 2;
}


bool Soldat::estMort()
{
    return (hp <= 0);
}

bool Soldat::est_Ami(Soldat& sol)
{
    return ( (this->getId() / 4) == (sol.getId() / 4) );
}


Soldat::~Soldat()
{}