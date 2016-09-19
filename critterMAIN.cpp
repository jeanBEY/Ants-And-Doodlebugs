/*************************************************************
**Program Filename:         ANTS & DOODLEBUGS
**
**Author:               Jeanvally G.Beato
**
**Date:                 2/7/16
**
**Description:     This program utilizes cellular atomata 
**using a 2D predator-prey simulation.  The user is asked
**how many steps, rows, columns, ants, and doodlebugs to 
**use for the program.  The program then goes through
**the simulation the amount of steps specified by user.  
**Once each step is done, the 2D array is displayed.
**
**Input:  Steps, Rows, Columns, # of Ants, # of Doodlebugs
**
**Output:  2D Array * # of times specified by user
*************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "world.hpp"

int main()
{
    //TO USE RANDOM # GENERATOR
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    World world;
    world.menu();
    
    return 0;
}
