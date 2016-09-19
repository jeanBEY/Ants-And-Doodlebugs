/*************************************************************
 **Class:                ANT
 **
 **Description:          CPP FILE
 **
 **Derived class from base class Critter.
 *************************************************************/

#include "ant.hpp"

/*************************************************************
 **Function:          Ant(int, int, string, int)
 **Description:     Constructor uses parameters, sends them
 **to set methods
 **Parameters:      int(x-coord), int (y-coord), string (name),
 **int (type)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Ant::Ant(int xCoord, int yCoord, string name, int t):Critter(xCoord, yCoord, name, t)
{
        //SETS INHERITED MEMBERS
        //survived is automatically set to ZERO
}

/*************************************************************
 **Function:          move(Critter ***&, int, int)
 **Description:    Virtual Move Method
 **Takes a 2D array by reference as a parameter.
 **
 **Ant tries to move randomy up, down, left, or right.
 **If neighboring cell in the selected direction is occupied or
 **would move the ant off the grid, then the ant stays in current 
 **cell.
 **
 **Parameters:      Critter ***& (worldArray), int (rows), 
 **int (columns)
 **
 **Pre-Conditions:    2D Array has already been initialized
 **
 **Post-Conditions:   2D Array changed since it's passed by
 **reference
 *************************************************************/
void Ant::move(Critter ***& wArray, int ROWS, int COLS)
{
    int random = rand()%4;
    
    //try to move up
    if(random == 0 && x > 0)
    {
        if(wArray[x-1][y] == NULL)
        {
            //move ant up
            wArray[x-1][y] = wArray[x][y];
            //set old cell to NULL
            wArray[x][y] = NULL;
            //set new x-coord
            x = x-1;
        }
    }
    //try to move down
    else if(random == 1 && x < (ROWS-2))
    {
        if(wArray[x+1][y] == NULL)
        {
            //move ant down
            wArray[x+1][y] = wArray[x][y];
            //set old cell to NULL
            wArray[x][y] = NULL;
            //set new x-coord
            x = x+1;
        }
    }
    //try to move left
    else if(random == 2 && y > 0)
    {
        if(wArray[x][y-1] == NULL)
        {
            //move ant left
            wArray[x][y-1] = wArray[x][y];
            //set old cell to NULL
            wArray[x][y] = NULL;
            //set new x-coord
            y = y-1;
        }
    }
    //try to move right
    else if(random == 3 && y < (COLS - 2))
    {
        if(wArray[x][y+1] == NULL)
        {
            //move ant right
            wArray[x][y+1] = wArray[x][y];
            //set old cell to NULL
            wArray[x][y] = NULL;
            //set new x-coord
            y = y+1;
        }
    }
    
    //each move, adds 1 to survived, meaning the ant has survived one step
    survived += 1;
}


/*************************************************************
 **Function:          move(Critter ***&, int, int, int)
 **Description:    Virtual Breed Method
 **Takes a 2D array by reference as a parameter & survived.
 **
 **If survived member of Ant is divisible by 3, and does not
 **equal to zero, then they can breed.  Based on Ant's location,
 **it first checks, up, down, left, and right.  Whichever 
 **direction finds an empty cell first, the ant will breed
 **in that cell
 **
 **Parameters:      Critter ***& (worldArray), int (rows),
 **int (columns), int (# of times Ant survived)
 **
 **Pre-Conditions:    2D Array has already been initialized
 **
 **Post-Conditions:   2D Array changed since it's passed by
 **reference
 *************************************************************/
void Ant::breed(Critter ***& wArray, int ROWS, int COLS, int surviveNum)
{
    //breeding only occurs when survived is evenly divisible by 3
    if(surviveNum != 0 && surviveNum % 3 == 0)
    {
        //try to breed UP
        if(x > 0 && wArray[x-1][y] != NULL)
        {
            //breed new ant up
            wArray[x-1][y] = new Ant(x-1, y, "O", 1);
        }
        //try to breed DOWN
        else if(x < (ROWS - 1) && wArray[x+1][y] != NULL)
        {
            //breed new ant down
            wArray[x+1][y] = new Ant(x+1, y, "O", 1);
        }
        //try to breed LEFT
        else if(y > 0 && wArray[x][y-1] != NULL)
        {
            //breed new ant to left
            wArray[x][y-1] = new Ant(x, y-1, "O", 1);
        }
        //try to breed RIGHT
        else if(y < (COLS - 1) && wArray[x][y+1] != NULL)
        {
            //breed new ant to right
            wArray[x][y+1] = new Ant(x, y+1, "O", 1);
        }
    }
}
    

