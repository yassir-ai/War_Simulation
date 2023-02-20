#ifndef SOLDAT__HPP
#define SOLDAT__HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

typedef Vector<Soldat>* Armee;

class Soldat
{
protected:
    int hp;
    int strength;
    float precision;
    int speed;

public:
    Soldat();
    int getHp();
    int getStrength();
    float getPrecision();
    int getSpeed();

    void setHp(int );
    void setStrength(int );
    void setPrecision(float );
    void setSpeed(int );

    int tirer();
    void reduireHp(int );

    void Afficher();
};

class Infanterie : public Soldat
{
public:
    Infanterie();
};

class Cavalerie : public Soldat
{
public:
    Cavalerie();
};

class Char : public Soldat
{
public:
    Char();
};

class Force_Aerienne : public Soldat
{
public:
    Force_Aerienne();
};

#endif