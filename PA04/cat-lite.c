#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int open(char *name,FILE* output)
{
  FILE* input;
  int ch;
  if(strcmp(name,"-") == 0)
  {
    input = stdin;
    do
    {
      ch = fgetc(input);
      if(ch != EOF)
      {
	fputc(ch,output);
      }
    }while(ch != EOF);
  }
  
  else 
  {
    input = fopen(name,"r");
    if(input == NULL){
      return 0;}
    do
    {
      ch = fgetc(input);
      if(ch != EOF)
      {
	fputc(ch,output);
      }
    }while(ch != EOF);
  fclose(input);
  }
  return 1;
}
      
int main(int argc, char * * argv)
{
  int ind = 1;
  for(ind = 1; ind < argc;ind++)
  {
    if(strcmp(argv[ind],"--help") == 0)
    {
      printf("Usage: cat-lite [--help] [FILE]...\n"
             "With no FILE, or when FILE is -, read standard input.\n"
             "Examples:\n"
             "cat-lite README   Print the file README to standard output.\n"
             "cat-lite f - g    Print f's contents, then standard input,\n" 
                               "then g's contents.\n"
             "cat-lite          Copy standard input to standard output.\n");
      return EXIT_SUCCESS;
    }
  }
  for(ind = 1; ind < argc;ind++)
  {
    int ifopen = open(argv[ind],stdout);
    if(ifopen == 0)
    {
      fprintf(stderr,"cat cannot open %s\n",argv[ind]);
      return EXIT_FAILURE;
    }
  }
  if(argc == 1)//cat-lite          Copy standard input to standard output.
  {
    FILE* input = stdin;
    int ch;
    while(!feof(input))
    {
      ch = fgetc(input);
      if(ch != EOF)
      {
	fprintf(stdout,"%c",ch);
      }
    }
  }
  return EXIT_SUCCESS;
}