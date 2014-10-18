#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

// int canMove(char** maze,  int row, int column,int dir)/row, col is the current position 
// switch(dir)
// {
//   case North:
//     row ++;
//     break;
//   case South:
//     row --;
//     break;
//   case West:
//     column --;
//     break;
//   case East:
//     column ++;
//     break;
//   int dest = maze[row][column];
//   if (dest == ' ')
//   {  return 1;}
//   return 0;//not able to move to that dir
// }
// 
// 
// void getout(char** maze, int row,int column,int dir, int * mode)
//   if(canMove(maze,row,column,EAST) && (dir != WEST))
//   {
//     (*mode) = FORWARD;
//     getout(maze,row,column+1,EAST,mode);
//   }
//   if(canMove(maze,row,column,SOUTH) && (dir != NORTH))
//   {
//     (*mode) = FORWARD;
//     getout(maze,row-1,column,SOUTH,mode);
//   }
//   if(canMove(maze,row,column,WEST) && (dir != EAST))
//   {
//     (*mode) = FORWARD;
//     getout(maze,row,column-1,WEST,mode);
//   }
//   if(canMove(maze,row,column,NORTH) && (dir != SOUTH))
//   {
//     (*mode) = FORWARD;
//     getout(maze,row+1,column,NORTH,mode);
//   }
//   (*mode) = BACKWARD;
// }
traverseMaze( int x, int y )
{
    maze[x][y]++; /* mark square as used */
    if( !maze[x][y-1] ) traverseMaze( x, y-1 );
    if( !maze[x+1][y] ) traverseMaze( x+1, y );
    if( !maze[x][y+1] ) traverseMaze( x, y+1 );
    if( !maze[x-1][y] ) traverseMaze( x-1, y );
}

void print_directions(char** maze, int w, int h)
{
  int row = h - 1;
  int column;
  int pos;
    //find the entrance
  for(column = 0;column < w;column++)
  {
    if(maze[row][column] == ' ')
    {
      maze[row][column] = '.';
    }
  }
  getout(maze,row,column,SOUTH,FORWARD);
  printf("%c %d\n",direction,n);
}




    
    
  
  