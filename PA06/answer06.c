#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void traverseMaze(char** maze, int x, int y ,int w,int h)
{
  while(((x <  h) && (x > -1)) && ((y < w) &&( y > -1)))
  {
    maze[x][y]++; /* mark square as used */
    if( maze[x][y-1] == SPACE ) 
    {
      traverseMaze(maze,x, y-1,w,h );
      printf("%c %d\n",'W','1');
    }
    if( maze[x+1][y] == SPACE ) 
    {
      traverseMaze(maze, x+1, y,w,h );
      printf("%c %d\n",'S','1');
    }
    if( maze[x][y+1] == SPACE ) 
    {
      traverseMaze(maze, x, y+1,w,h );
      printf("%c %d\n",'E','1');
    }
    if( maze[x-1][y] == SPACE ) 
    {
      traverseMaze(maze x-1, y,w,h );
      printf("%c %d\n",'N','1');
    }
  }
}

void print_directions(char** maze, int w, int h)
{
  int column;
    //find the entrance
  while(maze[0][column] !=' ')
  {
   column++;
  }
  traverseMaze(maze,0,column,w,h);
  //return EXIT_SUCCESS;
}




    
    
  
  