#ifndef SQUARE_H
#define SQUARE_H

#endif // SQUARE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class square
{
    public:
        square();
        ~square();
        int& getOwner();
        void setOwner(int player);
        square* N_link();
        square* E_link();
        square* W_link();
        square* S_link();
        square* NE_link();
        square* NW_link();
        square* SE_link();
        square* SW_link();
        square* ptrNull();
        square* ptr(square &location);
        void setN(square *location);
        void setE(square *location);
        void setW(square *location);
        void setS(square *location);
        void setNE(square *location);
        void setNW(square *location);
        void setSW(square *location);
        void setSE(square *location);
        int getCount();
        void setCount(int count);




    private:
        int owner,ai;
        square *N,*S,*E,*W,*NW,*NE,*SW,*SE;

};
