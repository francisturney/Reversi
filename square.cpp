#include "square.h"

square::square()
{
    owner = 0;
    ai = 0;
}

square::~square()
{

}
int& square::getOwner()
{
    return owner;
}

void square::setOwner(int player)
{
    owner = player;
}

square* square::ptr(square& location)
{
    square *datPointpoint;
    datPointpoint = &location;
    //cout<< "\n data point = " << datPointpoint <<endl;
    return datPointpoint;
}

square* square::N_link()
{
   return N;
}

square* square::E_link()
{
   return E;
}

square* square::W_link()
{
    return W;
}

square* square::S_link()
{
    return S;
}

square* square::NE_link()
{
    return NE;
}

square* square::NW_link()
{
    return NW;
}

square* square::SE_link()
{
    return SE;
}

square* square::SW_link()
{
    return SW;
}
void square::setN(square *location)
{
    N = location;
}

void square::setE(square *location)
{
    E = location;
    //cout<< "\n in this = " << this << "\n location = " << location <<endl;

}

void square::setW(square *location)
{
    W = location;
}
void square::setS(square *location)
{
    S = location;
}
void square::setNE(square *location)
{
    NE = location;
}
void square::setNW(square *location)
{
    NW = location;
}
void square::setSW(square *location)
{
    SW = location;
}
void square::setSE(square *location)
{
    SE = location;
}
square* square::ptrNull()
{
    square *pointToNull;
    pointToNull = NULL;
    return pointToNull;
}

int square::getCount()
{
    return ai;
}

void square::setCount(int count)
{
    ai = count;
}
