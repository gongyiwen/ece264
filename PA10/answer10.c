#include "answer10.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct treenode{
  struct treenode* left;
  struct treenode* right;
  struct Business* business;
}Treenode;

struct YelpDataBST{
   FILE * businesses;
   FILE * reviews;
   Treenode * head;
   int len;//file offset of the same business from the head of the tree
};

Treenode * Treenode_create(Business * business)
{
  Treenode * tn = malloc(sizeof(Treenode));
  tn -> left = NULLl
  tn -> right = NILL;
  tn -> business = business;
  return(tn);
}

Treenode * Tree_insert(Treenode * tn, Business * business)
{
  if(tn == 0)
  {
    return(Treenode_create(business);
  }
  if((business -> name) < ((tn -> business )-> name))
  {
    tn -> left = Tree_insert(tn -> left, business);
  }
  if((business -> name) >((tn -> business) -> name))
  {
    tn -> right = Tree_insert(tn -> right, business);
  }
  if((business -> name) ==((tn -> business) -> name))
  {
    (tn -> business) -> locations[1] = 
    
}

  
char * * explode(char * str)
{  
  int ind;
  int N = 0;
  int arrInd = 0; // this is the next position where we'll create a string
  int last = 0; // 1 + the last index we saw a delimiter. Init to 0.
  if(str == NULL)
  {
    return NULL;
  }
  for(ind = 0;ind < strlen(str);ind++)
  {
    if(str[ind]=='\t')
    {
      N++;
    }
  }
  int arrLen = N+1; //if there is one delim, there should be two arrays in the string.
  //printf("arrLen = %d",arrLen);
  char * * strArr = malloc((arrLen) * sizeof(char *));//create the return array
  if(N != 0)
  {
    while(arrInd < N)
    {
      for(ind = 0; ind <strlen(str) ; ind++)
      {
	if(str[ind] == '\t')
	{
	  strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));
	  memcpy(strArr[arrInd],str+last,ind-last);
	  strArr[arrInd][ind-last] = '\0';
	  last = ind + 1;
	  arrInd++;
	}
      }
    }
    strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));//To create the array for the last word
    memcpy(strArr[arrInd],str+last,ind-last);
    strArr[arrInd][ind-last] = '\0';
  }
  else
  {
    strArr[arrInd] = malloc(sizeof(char) * (ind-last+1));
    memcpy(strArr[arrInd],str+last,ind-last);
    strArr[arrInd][ind-last] = '\0';
  }
  return strArr;
}

struct Location * create_location(char * add, char * city, char* state, char * zip)
{
  struct Location * pos = malloc(sizeof(Location));
  pos -> address = strdup(add);
  pos -> city = strdup(city);
  pos -> state = strdup(state);
  pos -> zip_code = strdup(zip);

  
}
struct Review * create_rev(char* text,uint8_t stars)
{
  struct Review * rev = malloc(sizeof(Review));
  rev -> text = strdup(text);
  rev -> stars = stars;
}

struct YelpDataBST* create_business_bst(const char* businesses_path,
                                        const char* reviews_path)
{  
  FILE* bizfptr = fopen(businesses_path,"r");
  FILE* revfptr = fopen(reviews_path,"r");
  struct YelpDataBST * bst = NULL;
  bst = malloc(sizeof(struct YelpDataBST));
  int ID = 0;
  int ind = 0;
  while(! feof(revfptr))
  {
    char ch[3005];
    fgets(ch, 3000, revfptr);
    char * * strArr = explode(ch);
    struct Review * rev = create_rev(strArr[5],strArr[1]);
    do
    {
      char dh[520];
      fgets(dh, 500,bizfptr);
      char ** strBrr = explode(dh);
      if(ind == 0)
      {
        struct Location * pos = create_location(strBrr[2],strBrr[3],strBrr[4],strBrr[5],rev,ind+1);
      }
      pos -> reviews[ind] = rev;
      pos -> num_reviews = ind+1;
      ind++;
    }while((strArr[0] == strBrr[0]) && !feof(bizfptr))

  Tree_insert();
  Treenode * head = malloc(sizeof(Treenode));
  
  bst -> head = head;
    
}

					  
/* This function reads the two files and creates an index that can be used
 * to search the data and quickly retrieve the reviews.  You must *not* store
 * all of the review text in memory.  Your structure should store the file
 * offsets where the review text can be found.

 */

struct Business* get_business_reviews(struct YelpDataBST* bst,
                                      char* name, char* state, char* zip_code);
/* get_business_reviews(...) should return a pointer to a Business struct object
 * on the heap.  That object will include links to the individual locations.
 * For example, if "McDonald's" is the business, then there would be thousands
 * of locations.  Each Location struct object in turn contains links to
 * reviews of that location.
 *
 * bst - the object returned by create_business_bst(..)
 * name - name of the business to search for (e.g., "McDonald's"); search is
 *     case insensitive.
 * state - two-letter (uppercase) state code to filter locations by, or NULL
 *     to include all states.
 * zip_code - five digit ZIP code to filter locations by, or NULL to include
 *     all ZIP codes.
 *
 * Locations must be sorted by state >> city >> address.
 *
 * Reviews must be sorted by star rating (descending) >> text of review.
 *
 * Matching of names, cities, and states must be case-insensitive.  You
 * may use functions from strings.h for that, if you wish.
 */


void destroy_business_bst(struct YelpDataBST* bst)
{
  if(bst -> head == NULL) 
  {
    fclose(bst -> businesses);
    fclose(bst -> reviews);
    return;
  }
  destory_business_bst((bst -> head) -> left);
  destory_business_bst((bst -> head) -> right);
  free(bst -> head);
}
  
/* Deallocate all memory allocated for the object returned
 * by create_business_bst(..) and close the files. */

void destroy_business_result(struct Business* b);
/* Deallocate all heap memory tied to an object returned
 * by get_business_reviews(..). */