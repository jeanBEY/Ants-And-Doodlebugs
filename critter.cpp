/*************************************************************
 **Class:                CRITTER
 **
 **Description:          CPP FILE
 **
 **Base class to Ant and Doodlebug.  Contains
 **data and functions common to ants/doodlebugs and also
 **virtual methods.
 *************************************************************/

#include "critter.hpp"

/*************************************************************
 **Function:          Critter()
 **Description:     Constructor initializes survived to zero
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Critter::Critter()
{
    survived = 0;
}

/*************************************************************
 **Function:          Critter(int, int, string, int)
 **Description:     Constructor uses parameters, sends them 
 **to set methods
 **Parameters:      int(x-coord), int (y-coord), string (name),
 **int (type)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
Critter::Critter(int x, int y, string name, int t)
{
    setX(x);
    setY(y);
    setName(name);
    setCritterType(t);
    survived = 0;
}

/*
 *GET METHODS
 */

/*************************************************************
 **Function:           getX()
 **Description:     Returns x member variable
 **Parameters:          N/A
 **Pre-Conditions:      x has to be initialized with a value
 **Post-Conditions:     N/A
 *************************************************************/
int Critter::getX()
{
    return x;
}

/*************************************************************
 **Function:           getY()
 **Description:     Returns y member variable
 **Parameters:          N/A
 **Pre-Conditions:      y has to be initialized with a value
 **Post-Conditions:     N/A
 *************************************************************/
int Critter::getY()
{
    return y;
}

/*************************************************************
 **Function:           getSurvived()
 **Description:     Returns survived member variable
 **Parameters:          N/A
 **Pre-Conditions:      survived has to be initialized with 
 **a value
 **Post-Conditions:     N/A
 *************************************************************/
int Critter::getSurvived()
{
    return survived;
}

/*************************************************************
 **Function:           getName()
 **Description:     Returns name member variable
 **Parameters:          N/A
 **Pre-Conditions:      name has to be initialized with
 **a value
 **Post-Conditions:     N/A
 *************************************************************/
string Critter::getName()
{
    return name;
}

/*************************************************************
 **Function:           getCritterType()
 **Description:     Returns type member variable
 **Parameters:          N/A
 **Pre-Conditions:      type has to be initialized with
 **a value
 **Post-Conditions:     N/A
 *************************************************************/
int Critter::getCritterType()
{
    return type;
}
 
/*
 *SET METHODS
 */

/*************************************************************
 **Function:           setCoords(int, int)
 **Description:     Sets x & y coordinates
 **Parameters:          int (x-coord), int (y-coord)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Critter::setCoords(int x, int y)
{
    setX(x);
    setY(y);
}

/*************************************************************
 **Function:           setX(int)
 **Description:     Sets x coordinate
 **Parameters:          int (x-coord)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Critter::setX(int xCoord)
{
    x = xCoord;
}

/*************************************************************
 **Function:           setY(int)
 **Description:     Sets y coordinate
 **Parameters:          int (y-coord)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Critter::setY(int yCoord)
{
    y = yCoord;
}

/*************************************************************
 **Function:           setName(string)
 **Description:     Sets name
 **Parameters:          string (name)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Critter::setName(string cName)
{
    name = cName;
}

/*************************************************************
 **Function:           setCritterType(int)
 **Description:     Sets type
 **Parameters:          int (type)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void Critter::setCritterType(int t)
{
    type = t;
}








