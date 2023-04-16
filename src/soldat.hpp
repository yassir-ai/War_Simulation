#ifndef SOLDAT__HPP
#define SOLDAT__HPP

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <utility>
#include <set>
#include "mt19937ar.h"

using std::cout;
using std::cin;
using std::endl;
using pair = std::pair<int, int>;




class Soldat
{

protected:

    int hp;                         //nombre de coeur
    int strength;                   //force
    float precision;
    int speed;
    int id;   

public:

    Soldat();


    int getHp();
    int getStrength();
    float getPrecision();
    int getSpeed();
    int getId();

    void setHp(int );
    void setStrength(int );
    void setPrecision(float );
    void setSpeed(int );
    void setId(int );
    void incremId(int );
    bool estMort();
    bool est_Ami(Soldat&);
    int decider(); // 0 = tirer, 1 = bouger
    int tirer();
    void reduireHp(int );
    virtual void restituer() = 0; 
    virtual pair bouger(pair ) = 0;                        
    virtual pair Position_Tir(pair ) = 0;
    virtual void AfficherSoldat() = 0;
    virtual int getType() = 0;
    virtual ~Soldat();
};

class Infanterie : public Soldat  //0
{

public:

    static const int type;
    Infanterie();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
    ~Infanterie();
};

class Cavalerie : public Soldat   //1
{

public:

    static const int type;
    Cavalerie();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
    ~Cavalerie();
};

class Char : public Soldat     //2
{

public:

    static const int type;
    Char();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
    ~Char();
};

class Force_Aerienne : public Soldat    //3
{

public:

    static const int type;
    Force_Aerienne();
    void AfficherSoldat() override;
    int getType() override;
    void restituer() override;
    pair bouger(pair ) override;
    pair Position_Tir(pair ) override;
    ~Force_Aerienne();
};

#endif