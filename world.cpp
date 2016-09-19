/*************************************************************
 **Class:                WORLD
 **
 **Description:          CPP FILE
 **
 **Derived class from base class Critter.
 *************************************************************/

#include "world.hpp"

/*************************************************************
 **Function:          World()
 **Description:     Constructor displays welcome message only
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
World::World()
{
    cout << "Welcome to the World! " <<endl <<endl;
    
}

Critter *** World::getWorld()
{
    return worldArray;
}

/*************************************************************
 **Function:          menu()
 **Description:     Displays menu for user to choose from
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void World::menu()
{
    int choice;
    
    cout << "Would you like to play or quit? " <<endl;
    cout << "Enter 1 to play OR 2 to quit. " <<endl;
    cin >> choice;
    
    if(choice == 1) {
        play();
    }
    else if(choice ==2) {
        quit();
    }
    else {
        cout << "Please enter valid input, try again..." <<endl <<endl;
        menu();
    }
}

/*************************************************************
 **Function:          quit()
 **Description:     Quits program
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
int World::quit()
{
    return 0;
}

/*************************************************************
 **Function:          play()
 **Description:     Asks user for steps, rows, columns, # of
 **ants and # of doodlebugs.  It dynamically allocates 2D array,
 **initializes all elements to null.  Specified # of ants
 **& # of doodlebugs are placed randomly throughout array.
 **Then for loop, using # of steps, calls Doodlebug's move(),
 **breed() & starve function.  Afterwards, it calls Ant's 
 **move() & breed function.  
 **The display shows when the # of steps has completed and asks
 **the user if they want to play again or quit the program.
 **Parameters:          N/A
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void World::play()
{
    cout << "How many steps would you like to play?" <<endl ;
    cin >> steps;
    cout << "How many ROWS would you like?" <<endl;
    cin >> ROWS;
    cout << "How many COLUMNS would you like?" <<endl;
    cin >> COLS;
    cout << "How many ANTS would you like?" <<endl;
    cin >> numberOfAnts;
    cout << "How many DOODLEBUGS would you like?" <<endl;
    cin >> numberOfDoodlebugs;
    
    //ALLOCATE MEMORY FOR 2D ARRAY
    worldArray = new Critter**[ROWS];
    for(int i = 0; i < ROWS; i++)
    {
        worldArray[i] = new Critter*[COLS];
    }
    
    //INITIALIZE CELLS TO BE NULL POINTERS
    for(int k = 0; k < ROWS; k++)
    {
        for(int m = 0; m < COLS; m++)
        {
            worldArray[k][m] = NULL;
        }
    }
    
    //RANDOMLY PLACE DOODLEBUGS
    for(int i = 0; i < numberOfDoodlebugs; i++)
    {
        int x;
        int y;
        
        x = rand()%ROWS;
        y = rand()%COLS;
        
        worldArray[x][y] = new Doodlebug(x, y, "X", 2);
    }
    
    
    //RANDOMLY PLACE ANTS
    for(int i = 0; i < numberOfAnts; i++)
    {
        int x;
        int y;
        
        x = rand()%ROWS;
        y = rand()%COLS;
        
        worldArray[x][y] = new Ant(x, y, "O", 1);
    }
    
    
    //GO THROUGH # OF STEPS SPECIFIED BY USER
    for(int i = 0; i < steps; i ++)
    {
        //1ST - DOODLEBUG MOVE, BREED, STARVE
        //DOODLEBUG MOVE
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(worldArray[i][j] != NULL && worldArray[i][j]->getName() == "X")
                {
                    worldArray[i][j]->move(worldArray, ROWS, COLS);
                }
            }
        }
        
        //DOODLEBUG BREED
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(worldArray[i][j] != NULL && worldArray[i][j]->getName() == "X")
                {
                    worldArray[i][j]->breed(worldArray, ROWS, COLS, worldArray[i][j]->getSurvived());
                }
            }
        }
        
        //DOODLEBUG STARVE DIE
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(worldArray[i][j] != NULL && worldArray[i][j]->getName() == "X")
                {
                    //In order to access member of derived Doodlebug, need to case base pointer
                    Doodlebug * dptr = static_cast<Doodlebug *>(worldArray[i][j]);
                    //Accessing the starveDie method via a casted Doodlebug pointer
                    dptr->starveDie(worldArray, ROWS, COLS, dptr->getStarve());
                }
            }
        }
        
        
        //2ND - ANT MOVE, BREED
        //ANT MOVE
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(worldArray[i][j] != NULL && worldArray[i][j]->getName() == "O")
                {
                    worldArray[i][j]->move(worldArray, ROWS, COLS);
                }
            }
        }
        
        //ANT BREED
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(worldArray[i][j] != NULL && worldArray[i][j]->getName() == "O")
                {
                    worldArray[i][j]->breed(worldArray, ROWS, COLS, worldArray[i][j]->getSurvived());
                }
            }
        }
        

        //AFTER ALL DOODLEBUGS & ANTS ARE DONE, THEN WE DISPLAY SCREEN
        printWorld(worldArray, ROWS, COLS);
     
        usleep(150000);
        system("clear");
    }
    
    
    
    //FREE DYNAMIC. ALLOCATED MEMORY
    for( int i = 0 ; i < ROWS ; i++ )
    {
        //delete each individual array
        delete[] worldArray[i];
    }
    // delete actual 2D array
    delete[] worldArray;
    
    
    //PLAY METHOD IS FINISHED.  LET USER KNOW WE WENT THROUGH ALL STEPS, AND ASK IF THEY
    //WOULD LIKE TO PLAY AGAIN, OR QUIT GAME
    cout << "Thanks for playing, you've gone through all the steps!" <<endl <<endl;
    menu();
     
}

/*************************************************************
 **Function:          printWorld(Critter ***, int x, int y)
 **Description:     Displays 2D grid
 **Parameters:    Critter *** (array), int (rows), int (columns)
 **Pre-Conditions:      N/A
 **Post-Conditions:     N/A
 *************************************************************/
void World::printWorld(Critter ***, int x, int y)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(worldArray[i][j] == NULL)
            {
                cout << "*" ;
            }
            else
            {
                cout << worldArray[i][j]->getName();
            }
        }
        cout <<endl;
    }
    cout <<endl;
}

