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

Treenode * Treeinsert(Treenode * tn, Business * business)
{
  if(
}

  
struct YelpDataBST* create_business_bst(const char* businesses_path,
                                        const char* reviews_path)
{  
  FILE* bizfptr = fopen(businesses_path,"r");
  FILE* revfptr = fopen(reviews_path,"r");
  struct YelpDataBST * bst = NULL;
  bst = malloc(sizeof(struct YelpDataBST));
  Treeinsert();
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