#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define longest 2001 

int main(int argc, char * * argv)
{
  int ind = 1;
  char* pattern=argv[argc-1];
  int invert = 0;//print no-matching lines
  int plineno = 0;//print line numbers with output
  int quiet = 0;//suppress all output
  
  if(pattern[0] == '-')
  {
    fprintf(stderr,"patten should not start with '-'\n");
    return 2;
  }
  if(argc == 1)
  {
    fprintf(stderr,"need more arguments\n");
    return 2;
  }
  for(ind = 1; ind < argc-1;ind++)
  {
    if(strcmp(argv[ind],"--help") == 0)
    {
      printf("Usage: grep-lite [OPTION]... PATTERN\n"
             "Search for PATTERN in standard input. PATTERN is a\n"
             "string. grep-lite will search standard input line by\n"
             "line, and (by default) print out those lines which\n"
             "contain pattern as a substring.\n\n"

             "-v, --invert-match     print non-matching lines\n"
             "-n, --line-number      print line numbers with output\n"
             "-q, --quiet            suppress all output\n"

             "Exit status is 0 if any line is selected, 1 otherwise;\n"
             "if any error occurs, then the exit status is 2.\n");
	     return EXIT_SUCCESS;
    }
    else if(strcmp(argv[ind],"-v") == 0)
    {
      invert = 1;
    }
    else if(strcmp(argv[ind],"--invert-match") == 0)
    {
      invert = 1;
    }
    else if((strcmp(argv[ind],"-n") == 0) ||(strcmp(argv[ind],"--line-number") == 0))
    {
      plineno = 1;
    }
    else if((strcmp(argv[ind],"-q") == 0) ||(strcmp(argv[ind],"--quiet") == 0))
    {
      quiet = 1;
    }
    else
    {
      fprintf(stderr,"wrong argument\n");
      return 2;
    } 
  }
  char oneLine[longest];
  int numline = 0;
  int match = 0;
  while(fgets(oneLine,longest,stdin) != NULL)
  {
    numline++;
    int found = strstr(oneLine,pattern) != NULL;
    if(found)
    {
      match++;
    }
    if((found && !invert && !quiet)||(!found && invert && !quiet))
    {
      if(plineno)
      {
	printf("%d:%s",numline,oneLine);
      }
      else
      {
	printf("%s",oneLine);
      }
    }
  }
  return match ? 0:1;
}
  
    