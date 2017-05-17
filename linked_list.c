#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>


struct node{            

	int num;
	char *word;
    	Node *next;
};

/*
 * purpose: create a new linked list
 * input:   nothing!
 * output:  an empty linked list 
 */
List *list_create()
{
	Node *dummy =  malloc(sizeof(Node));
   	if (dummy == NULL)
     	{
       		fprintf(stderr, "Out of memory\n");
       		exit(-1);
     	}
    	dummy->num = -1;
	dummy->word = NULL; // new bit
    	dummy->next = NULL;
    	return dummy;
}

/*
 * purpose: print a linked list
 * input:   a description and the list to print!
 * output:  nothing
 */
void list_print(char *description, List *head)
{
  	printf("%s", description);
  	if (head == NULL) 
    	{     
      		printf("Warning list == NULL someone didn't call create!\n");
    	}
  	else 
    	{
      		Node *tmp; 
       		// [[ head->next skips the dummy header ]] 
      		for( tmp = head->next; tmp != NULL; tmp = tmp->next)
         		printf("\n%s %d", tmp->word, tmp->num); //new bit
      			printf("\n");
    	}
}

/*
 * purpose: delete an entry from a linked list
 * input:   the head of the list and the value to delete 
 * output:  the updated list
 */
List *list_delete(List *head, int num, char *word)
{
	Node *tmp;
  // this should not happen (the "empty" list still contains the dummy
  // header), but just in case
  	if (head == NULL) 
    	{
      		return NULL;
    	}
  // again we never delete the first node
  	for(tmp = head; tmp->next != NULL; tmp = tmp->next) 
    	{
      		if ((tmp->next->num ==  num) && (tmp->next->word == word))
		{
	  		Node *rm = tmp->next;
	 		tmp->next = tmp->next->next;
	  		free(rm);
	  		return head;
		}
    	}


  	return head;
}


/*
 * purpose: insert a value into a linked list
 * input:   the head of the list and the value to insert!
 * output:  the updated list
 */
List *list_insert(List *head, char *new_word)
{
  	Node *new_node = malloc(sizeof(Node));
  	if (new_node == NULL) 
    	{
      		fprintf(stderr, "Out of memory\n");  
      		exit(-1); 
    	} 

  	new_node->num = 1; 
  

	new_node->word = (char*)malloc(sizeof(char)*strlen(new_word)+1);
	strcpy(new_node->word, new_word);

  	new_node->next = NULL;

 	// head should not be null, but in case it is .... 
  	if (head == NULL) 
    	{
      		head = list_create();
    	}


 // we never insert before the dummy header, so only the 'insert middle li
 // and end' cases are needed!
  	Node *tmp;
	

 	for(tmp = head; tmp->next != NULL; tmp = tmp->next) {


   		if (strcmp(new_word, tmp->next->word) < 0 ) 
     		{
		
       			new_node->next = tmp->next; 
			tmp->next = new_node;
		
       			return head;
		}
	}
	tmp->next = new_node;	
	return head;
}


/*
 * purpose: increment when the same word is sent to the list
 * input:   the head of the list and the word to increment
 * output:  the updated incrementation
 */
int list_increment(List *head, char *search_word) {
	Node *tmp;
 	for(tmp = head; tmp->next != NULL; tmp = tmp->next) {
		if(strcmp(tmp->next->word, search_word) == 0) {

			tmp->next->num += 1;
	
			return 0;
		}
	}
	return 1;
}





