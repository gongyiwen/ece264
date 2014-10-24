//Part of the code is using the code from image-bmp.c
#include "answer07.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>


Image * Image_load(const char * filename)
{
    FILE * fp = NULL;
    size_t read;
    ImageHeader header;
    Image * ece264_im = NULL, * im = NULL;
    int err = 0;

    fp = fopen(filename, "rb");
    if(!fp) {
      fprintf(stderr, "Failed to open file '%s'\n", filename);
      err = 1;
	}

    if(!err) { // Read the header
	read = fread(&header, sizeof(ImageHeader), 1, fp);
	if(read != 1) 
	{
	  err = 1;
	}
	if(header.magic_number != ECE264_IMAGE_MAGIC_NUMBER)
	{
	  err = 1;
	}
	if((header.width == 0) || (header.height == 0) || (header.comment_len = 0))
	{
	  err = 1;
	}
	if(err)
	{
	  fprintf(stderr, "Failed to read header from '%s'\n", filename);
        }
    }

    if(!err) { // Allocate Image struct
	ece264_im = malloc(sizeof(Image));			
	if(ece264_im == NULL) {
	    fprintf(stderr, "Failed to allocate im structure\n");
	    err = 1;}
	} 

    if(!err) { // Initiate the Image struct
	ece264_im->width = header.width;
	ece264_im->height = header.height;
	ece264_im -> comment = malloc(sizeof(char)*header.comment_len);
	ece264_im -> data = malloc(sizeof(uint8_t)*header.width*header.height);
	if(ece264_im ->comment == NULL)
	{
	  fprintf(stderr,"Failed to allocate comment\n");}
	if(ece264_im ->data == NULL)
	{
	  fprintf(stderr,"Failed to allocate data\n");
	}
    }
    
    if(!err)//Read the comment
    {
      read = fread(ece264_im -> comment,sizeof(char),header.comment_len,fp);//read the entire comment
      err = ((read != header.comment_len) || (ece264_im->comment[header.comment_len - 1] != '\0'));
      if(err){
	fprintf(stderr,"Failed to read entire comment\n");
      }
    }
    
    if(!err)//Read the pixels
    {
      read = fread(ece264_im -> data, sizeof(uint8_t),header.width*header.height, fp);//read all width*height pixels
      if(read != header.width*header.height){
	err = 1;
	fprintf(stderr,"Failed to read entire data\n");
      }
      
      fgetc(fp);
      if(!feof(fp))
      {
	err = 1;
	fprintf(stderr,"Failed to reach the end of file\n");
      }
    }
    
    if(!err)
    {
      im = ece264_im;
      ece264_im = NULL;
      return im;
    }
    
    Image_free(ece264_im);
    
    if(fp)
    {fclose(fp);}
    
    return NULL;
}
int Image_save(const char * filename, Image * image)
{ 
    FILE * fp = NULL;
    
    // Attempt to open file for writing
    fp = fopen(filename, "wb");
    if(fp == NULL) {
	fprintf(stderr, "Failed to open '%s' for writing\n", filename);
	return 0; // No file ==> out of here.
    }

    // Prepare the header
    ImageHeader iheader;
    iheader.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
    iheader.width = image ->width;
    iheader.height = image -> height;
    iheader.comment_len = strlen(image ->comment)+1;
    
    fwrite(&iheader, sizeof(ImageHeader), 1, fp);
    fwrite(image -> comment ,sizeof(char),iheader.comment_len,fp);
    fwrite(image -> data, sizeof(uint8_t),iheader.width*iheader.height,fp);
    if(fp){
    fclose(fp);}
    return 1;
}
void Image_free(Image * image)
{
  if(image != NULL){
  free(image -> comment);
  free(image -> data);
  free(image);}
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int total = width * height;
  int max=intensity[0];
  int min=intensity[0];
  int ind;
  for(ind = 0;ind < total;ind++);
  {
    if(intensity[ind]< min)
    {
      min = intensity[ind];
    }
    if( intensity[ind]> max)
    {
      max = intensity[ind];
    }
  }
  for(ind = 0; ind < total;ind++)
  {
    intensity[ind] = (intensity[ind] - min) * 255.0 / (max - min);
  }
}
