#include<stdio.h>
#include<stdlib.h>
#include "answer06.h"
#define NORTH  78
#define SOUTH  83
#define WEST   87
#define EAST   69
#define BACKWARD 7
#define FORWARD 9

 
void print_directions(char** maze,int w,int h)
{
  int row;
  int col;
  int startrow = 0;
  int startcol;
  int exitrow = h - 1;
  int exitcol;
  int finding;
  startcol = findcol(maze,w,startrow);
  exitcol = findcol(maze,w,exitrow);
  row = startrow;
  col = startcol;
  finding = FORWARD;
  findExit(maze,row+1,col,SOUTH,&finding,startrow,exitrow,w);
  return;
}

int movable( char ** maze , int row,int col,int direction,int startrow,int exitrow,int w)
{
  int upperlimit;
  int lowerlimit;
  int leftlimit;
  int rightlimit;
  char dest;
  switch(direction)
  {
  case NORTH:
    row --;
    break;
  case SOUTH:
    row ++;
    break;
  case WEST:
    col --;
    break;
  case EAST:
    col ++;
    break;
  }
  upperlimit = ( row >= startrow);
  lowerlimit = ( row <= exitrow);
  leftlimit = (col > 0);
  rightlimit = ( col < w);
  if( upperlimit && lowerlimit && leftlimit && rightlimit )
    {
       dest = maze[row][col];
       if (dest == ' ') 
       {
	 return 1;
       }
    }
  return 0 ;
}

void findExit(char ** maze,int row,int col,int dir,int * mode,int startrow,int exitrow ,int w)
{
  printf("%c 1\n",dir);
  if( movable(maze,row,col,EAST,startrow,exitrow, w) && ( dir != WEST))
    {
      ( * mode ) = FORWARD; 
      findExit(maze,row,col+1,EAST,mode,startrow,exitrow,w);
      if((*mode) == BACKWARD )
	{    printf("W 1\n");
	}
    }

  if(movable(maze,row,col,SOUTH,startrow,exitrow,w)&&(dir != NORTH))
    {
      ( * mode ) = FORWARD;
        findExit(maze,row+1,col,SOUTH,mode,startrow,exitrow,w);
         if((*mode) == BACKWARD)
	{  printf("N 1\n");
        }
    }

  if( movable(maze,row,col,WEST,startrow,exitrow, w) && (dir != EAST))
    {
      ( * mode ) = FORWARD;
      findExit(maze,row,col-1,WEST,mode,startrow,exitrow,w);
        if((*mode) == BACKWARD)
	{ 
             printf("E 1\n");
        }
    }
  if(movable(maze,row,col,NORTH,startrow,exitrow, w) && (dir!=SOUTH))
    {
        ( * mode ) = FORWARD;
	findExit(maze,row -1,col,NORTH,mode,startrow,exitrow,w);
	  if((*mode) == BACKWARD)
	{  
           printf("S 1\n");
	}
     }     
    (* mode) = BACKWARD;
} 

int findcol(char ** maze,int w,int start)
{
  int n=0;
  while( maze[start][n] != ' ')
    {
      n++;
    }
  return n;
}

 








    
    
  
  
