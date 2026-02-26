#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //For _getch()
#include <time.h>
#define GRID_SIZE 10

//Struct to store positions
typedef struct 
{
    int x,y;
}Position;
//Function to initialize positions
void Initialize(Position *police,Position *thief) 
{
    police->x=0;
    police->y=0;
    thief->x=GRID_SIZE-1;
    thief->y=GRID_SIZE-1;
}
//Function to display the grid
void DisplayGrid(Position police,Position thief) 
{
    system("cls"); //Clear screen 
    for (int i=0;i<GRID_SIZE;i++) 
    {
        for (int j=0;j<GRID_SIZE;j++) 
        {
            if (i==police.x && j==police.y)
                printf("P "); //Police
            else if (i==thief.x && j==thief.y)
                printf("T "); //Thief
            else
                printf(". ");
        }
        printf("\n");
    }
}
//Function for police movement
void movePolice(Position *police,char move) 
{
    switch(move) 
   {
        case 'w':if(police->x > 0) 
                        police->x--; 
                 break;
        case 's':if(police->x < GRID_SIZE - 1) 
                        police->x++; 
                 break;
        case 'a':if(police->y > 0) 
                        police->y--; 
                 break;
        case 'd':if(police->y < GRID_SIZE - 1) 
                        police->y++; 
                 break;
    }
}
//Function for random thief movement
void moveThief(Position *thief) 
{
    int direction=rand()%4;
    switch(direction) 
    {
        case 0: if(thief->x>0) 
                    thief->x--;
                break;
        case 1: if(thief->x<GRID_SIZE-1)
                    thief->x++; 
                break;
        case 2: if(thief->y>0) 
                    thief->y--;
                break;
        case 3: if(thief->y<GRID_SIZE-1)
                    thief->y++; 
                break;
    }
}
int main() 
{
    Position police,thief;
    char move;
    srand(time(NULL));

    Initialize(&police,&thief);
    while(police.x!=thief.x || police.y!=thief.y) 
    {
        DisplayGrid(police,thief);
        printf("Move (WASD): ");
        move=_getch(); //Capture key press
        movePolice(&police,move);
        moveThief(&thief);
    }
    DisplayGrid(police,thief);
    printf("\nPolice caught the thief! Game over.\n");
    return 0;
}
