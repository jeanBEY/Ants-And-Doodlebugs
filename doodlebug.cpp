/*************************************************************
 **Class:                DOODLEBUG
 **
 **Description:          CPP FILE
 **
 **Derived class from base class Critter.
 *************************************************************/

#include "doodlebug.hpp"

/*************************************************************
 **Function:          Doodlebug(int, int, string, int)
 **Description:     Constructor uses parameters, sends them
 **to set methods.  Also initializes starve to zero.
 **Parameters:      int(x-coord), int (y-coord), string (name),
 **int (type)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Doodlebug::Doodlebug(int xCoord, int yCoord, string name, int t):Critter(xCoord, yCoord, name, t)
{
    //SETS INHERITED MEMBERS:)
    //survived is automatically set to ZERO
    starve = 0;
}

/*************************************************************
 **Function:          getStarve()
 **Description:     Returns Doodlebug member, starve
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int Doodlebug::getStarve()
{
    return starve;
}

/*************************************************************
 **Function:          move(Critter ***&, int, int)
 **Description:    Virtual Move Method
 **Takes a 2D array by reference as a parameter.
 **
 **Doodlebug checks up, down left and right for any ants.
 **If there is an ant, it "eats" the ant by replacing the cell
 **the ant was in.  The member starve is set to zero, and 1 
 **is added to survived.
 **
 **If there is no ant, the doodlebug moves in the same manner
 **as the ant (if neighboring cell in the selected direction 
 **is occupied or would move the doodlebug off the grid, then the
 **doodlebug stays in current cell).  1 is added to both members,
 **starve and survived.
 **
 **Parameters:      Critter ***& (worldArray), int (rows),
 **int (columns)
 **Pre-Conditions:    2D Array has already been initialized
 **Post-Conditions:   2D Array changed since it's passed by
 **reference
 *************************************************************/
void Doodlebug::move(Critter ***& wArray, int ROWS, int COLS)
{
    /*
    **IF THERE ARE ANTS IN ANY ADJACENT CELL, DOODLE BUG EATS THE ANT BY MOVING TO ANTS POSITION,
    **AND SETTING OLD CELL TO NULL.
    **IF IT FINDS ANT TO EAT, SET STARVE BACK TO ZERO.
    **ELSE MOVE DOODLEBUG IN SAME MANNER AS ANT AND + 1 TO STARVE.
    */
     
    //try to eat UP
    if(x > 0 && wArray[x-1][y] != NULL && wArray[x-1][y]->getCritterType() == 1)
    {
        //doodle bug eats up
        wArray[x-1][y] = wArray[x][y];
        //set old cell to NULL
        wArray[x][y] = NULL;
        //set new x-coord for doodlebug
        x = x-1;
        //set starve back to zero since doodlebug has eaten ant
        starve = 0;
        survived += 1;
        
    }
    //try to eat DOWN
    else if(x < (ROWS - 1) && wArray[x+1][y] != NULL && wArray[x+1][y]->getCritterType() == 1)
    {
        //doodle bug eats down
        wArray[x+1][y] = wArray[x][y];
        //set old cell to NULL
        wArray[x][y] = NULL;
        //set new x-coord for doodlebug
        x = x+1;
        //set starve back to zero since doodlebug has eaten ant
        starve = 0;
        survived += 1;
    }
    //try to eat LEFT
    else if(y > 0 && wArray[x][y-1] != NULL && wArray[x][y-1]->getCritterType() == 1)
    {
        //doodle bug eats left
        wArray[x][y-1] = wArray[x][y];
        //set old cell to NULL
        wArray[x][y] = NULL;
        //set new y-coord for doodlebug
        y = y-1;
        //set starve back to zero since doodlebug has eaten ant
        starve = 0;
        survived += 1;
    }
    //try to eat RIGHT
    else if(y < (COLS - 1) && wArray[x][y+1] != NULL && wArray[x][y+1]->getCritterType() == 1)
    {
        //doodle bug eats right
        wArray[x][y+1] = wArray[x][y];
        //set old cell to NULL
        wArray[x][y] = NULL;
        //set new y-coord for doodlebug
        y = y+1;
        //set starve back to zero since doodlebug has eaten ant
        starve = 0;
        survived += 1;
    }
    else{
    
        /*
        **IF THERE ARE NO ANTS, THEN THEY MOVE IN THE SAME MANNER AS THE ANTS
        */
        int random = rand()%4;
    
        //try to move up
        if(random == 0 && x > 0)
        {
            if(wArray[x-1][y] == NULL)
            {
                //move doodlebug up
                wArray[x-1][y] = wArray[x][y];
                //set old cell to NULL
                wArray[x][y] = NULL;
                //set new x-coord
                x= x-1;
                starve += 1;
                survived += 1;
            }
        }
        //try to move down
        else if(random == 1 && x < (ROWS-2))
        {
            if(wArray[x+1][y] == NULL)
            {
                //move doodlebug down
                wArray[x+1][y] = wArray[x][y];
                //set old cell to NULL
                wArray[x][y] = NULL;
                //set new x-coord
                x = x+1;
                starve += 1;
                survived += 1;
            }
        }
        //try to move left
        else if(random == 2 && y > 0)
        {
            if(wArray[x][y-1] == NULL)
            {
                //move doodlebug left
                wArray[x][y-1] = wArray[x][y];
                //set old cell to NULL
                wArray[x][y] = NULL;
                //set new y-coord
                y = y-1;
                starve += 1;
                survived += 1;
            }
        }
        //try to move right
        else if(random == 3 && y < (COLS - 2))
        {
            if(wArray[x][y+1] == NULL)
            {
                //move doodlebug right
                wArray[x][y+1] = wArray[x][y];
                //set old cell to NULL
                wArray[x][y] = NULL;
                //set new y-coord
                y = y+1;
                starve += 1;
                survived += 1;
            }
        }
    }
}


/*************************************************************
 **Function:          breed(Critter ***&, int, int, int)
 **Description:    Virtual Breed Method
 **Takes a 2D array by reference as a parameter & survived.
 **
 **If survived member of Doodlebug is divisible by 8, and 
 **does not equal to zero, then they can breed.  Based on 
 **Doodlebug's location, it first checks, up, down, left, and 
 **then right.  Whichever direction finds an empty cell first, 
 the Doodlebug will breed in that cell.
 **
 **Parameters:      Critter ***& (worldArray), int (rows),
 **int (columns), int (# of times Doodlebug survived)
 **
 **Pre-Conditions:    2D Array has already been initialized
 **
 **Post-Conditions:   2D Array changed since it's passed by
 **reference
 *************************************************************/
void Doodlebug::breed(Critter ***& wArray, int ROWS, int COLS, int surviveNum)
{
    //breeding only occurs when survived is evenly divisible by 8
    if(surviveNum != 0 && surviveNum % 8 == 0)
    {
        //try to breed UP
        if(x > 0 && wArray[x-1][y] != NULL)
        {
            //breed new doodlebug up
            wArray[x-1][y] = new Doodlebug(x-1, y, "X", 2);
        }
        //try to breed DOWN
        if(x < (ROWS - 1) && wArray[x+1][y] != NULL)
        {
            //breed new doodlebug down
            wArray[x+1][y] = new Doodlebug(x+1, y, "X", 2);
        }
        //try to breed LEFT
        else if(y > 0 && wArray[x][y-1] != NULL)
        {
            //breed new doodlebug to left
            wArray[x][y-1] = new Doodlebug(x, y-1, "X", 2);
        }
        //try to breed RIGHT
        else if(y < (COLS - 1) && wArray[x][y+1] != NULL)
        {
            //breed new doodlebug to right
            wArray[x][y+1] = new Doodlebug(x, y+1, "X", 2);
        }
    }
}


/*************************************************************
 **Function:          starveDie(Critter ***&, int, int, int)
 **Description:
 **Takes a 2D array by reference as a parameter & starve.
 **
 **If starve member of Doodlebug is divisible by 3, and
 **does not equal to zero, then Doodlebug starves and dies.  
 **The location of Doodlebug turns into a NULL pointer.
 **
 **Parameters:      Critter ***& (worldArray), int (rows),
 **int (columns), int (# of times Doodlebug starved)
 **
 **Pre-Conditions:    2D Array has already been initialized
 **
 **Post-Conditions:   2D Array changed since it's passed by
 **reference
 *************************************************************/
void Doodlebug::starveDie(Critter ***& wArray, int ROWS, int COLS, int starveNum)
{
    if(starveNum != 0 && starveNum % 3 == 0)
    {
        wArray[x][y] = NULL;
    }
}




