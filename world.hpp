/*************************************************************
 **Class:                WORLD
 **
 **Description:          HPP FILE
 **
 **Contains the menu and 2D array for the Ant/Doodlebug 
 **Program
 *************************************************************/

#ifndef WORLD_HPP
#define WORLD_HPP
#include <iostream>
#include <string>
#include <stdlib.h>
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
using namespace std;

class World
{

    friend class Ant;
    friend class Critter;
    
private:
    int numberOfAnts;
    int numberOfDoodlebugs;
    
    int ROWS;
    int COLS;
    int steps;
    
    Critter ***worldArray;       //POINTER TO 2D ARRAY, pointer to Critter is the element,
                                 //and since an array(starting point is already a pointer),
                                 //then we need a pointer to a pointer, hence the 3 asterisks
    
public:
    World();
    
    void menu();
    
    void play();
    
    void printWorld(Critter ***, int, int);
    
    Critter *** getWorld();
    
    int quit();
    
    
};
#endif
