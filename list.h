
typedef struct node Node;
typedef Node List; //list data structure    
                      
                      

/*
 * purpose: create a new linked list
 * input:   nothing!
 * output:  an empty linked list 
 */
 List *list_create();

/*
 * purpose: print a linked list
 * input:   a description and the list to print!
 * output:  nothing
 */
void list_print(char *description, List *head);

/*
 * purpose: delete an entry from a linked list
 * input:   the head of the list and the value to delete 
 * output:  the updated list
 */
List *list_delete(List *head, int num, char *word);

/*
 * purpose: insert a value into a linked list
 * input:   the head of the list and the value to insert!
 * output:  the updated list
 */
List *list_insert(List *head, char *new_word);

/*
 * purpose: increment when the same word is sent to the list
 * input:   the head of the list and the word to increment
 * output:  the updated incrementation
 */
int list_increment(List *head, char *search_word);
