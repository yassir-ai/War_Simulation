#ifndef SOLDAT__HPP
#define SOLDAT__HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;




class Soldat
{

protected:

    int hp;                         //nombre de coeur
    int strength;                   //force
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

    virtual void AfficherSoldat() = 0;

    virtual int TypeSoldat() = 0;

    virtual ~Soldat();
};

class Infanterie : public Soldat  //0
{

public:

    int type = 0;
    Infanterie();
    void AfficherSoldat() override;
    int TypeSoldat() override;
};

class Cavalerie : public Soldat   //1
{

public:

    int type = 1;
    Cavalerie();
    void AfficherSoldat() override;
    int TypeSoldat() override;
};

class Char : public Soldat     //2
{

public:

    int type = 2;
    Char();
    void AfficherSoldat() override;
    int TypeSoldat() override;
};

class Force_Aerienne : public Soldat    //3
{

public:

    int type = 3;
    Force_Aerienne();
    void AfficherSoldat() override;
    int TypeSoldat() override;
};

#endif