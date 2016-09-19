/*************************************************************
 **Class:                CRITTER
 **
 **Description:          HPP FILE
 **
 **Base class to Ant and Doodlebug.  Contains
 **data and functions common to ants/doodlebugs and also
 **virtual methods.
 *************************************************************/

#ifndef CRITTER_hpp
#define CRITTER_hpp
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class World;

enum CritterType {ANT, DOODLEBUG};

class Critter
{
protected:
    int x;
    int y;
    int survived;
    string name;
    int type;

public:
    Critter();
    Critter(int, int, string, int);
    
    int getX();
    int getY();
    int getSurvived();
    string getName();
    int getCritterType();
    
    void setCoords(int, int);
    void setX(int);
    void setY(int);
    void setName(string);
    void setCritterType(int);
    
    //VIRTUAL FUNCTIONS
    virtual void move(Critter ***&, int, int) = 0;
    virtual void breed(Critter ***&, int, int, int) = 0;
    
    
};
#endif
