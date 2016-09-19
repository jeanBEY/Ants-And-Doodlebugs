/*************************************************************
 **Class:                DOODLEBUG
 **
 **Description:          HPP FILE
 **
 **Derived class from base class Critter.
 *************************************************************/

#ifndef DOODLEBUG_hpp
#define DOODLEBUG_hpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include "critter.hpp"
#include "world.hpp"
using namespace std;

class World;

class Doodlebug:public Critter
{
private:
    
    int starve;
    
public:
    Doodlebug(int, int, string, int);
    
    int getStarve();
    
    virtual void move(Critter ***&, int, int);
    
    virtual void breed(Critter ***&, int, int, int);
    
    void starveDie(Critter ***&, int, int, int);
};
#endif
