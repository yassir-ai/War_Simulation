#include "soldat.hpp"

Force_Aerienne::Force_Aerienne()
{
    this->hp = 400;
    this->strength = 300;
    this->precision = 0.9;
    this->speed = 90;
}

void Force_Aerienne::AfficherSoldat()
{
    cout << "Force aerienne :" << endl;
    Soldat::AfficherSoldat();
}


int Force_Aerienne::TypeSoldat()
{
    return type;
}
