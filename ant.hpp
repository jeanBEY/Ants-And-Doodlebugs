/*************************************************************
 **Class:                ANT
 **
 **Description:          HPP FILE
 **
 **Derived class from base class Critter.
 *************************************************************/

#ifndef ANT_hpp
#define ANT_hpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include "critter.hpp"
#include "world.hpp"
using namespace std;

class World;

class Ant:public Critter
{
private:
    
public:
    Ant(int, int, string, int);
    
    virtual void move(Critter ***&, int, int);
    
    virtual void breed(Critter ***&, int, int, int);
    
};
#endif
