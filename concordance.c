#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <ctype.h>

#define BUFFER_SIZE 1024

/*
 * purpose: make a word lower case and clean it of symbols and numbers
 * input:   the word to be "cleaned"
 * output:  the word that is now lower case and cleaned of symbols and numbers
 */
char *clean_word(char *input) {
  int i,j;
  char *output=input;
  
  for (i = 0, j = 0; i<strlen(input); i++,j++)
    {
      *input = tolower(*input);
      
      if (isalpha(input[i]))
	output[j]=input[i];
      
      else
	j--;
    }
  
  output[j]=0;
  
  return output;
}

/*
 * purpose: to create the concordance by delimiting and inserting
 * input:   the list to be inserted into and the file name
 * output:  nothing
 */
void concordance_create(List *wordList, char* file_name) {
	const char *delimiter_characters = " ";
	char *last_token;
  
	FILE* in_file = NULL;				//FILE POINTER SET TO NULL

	in_file = fopen(file_name, "r");
  
  
	if(in_file == NULL){				//IF FILE DOESNT EXIST END PROGRAM
		printf("Could not open the file");
		exit(-1);
	}
  
	char buffer[ BUFFER_SIZE ];
  
	
	while( fgets(buffer, BUFFER_SIZE, in_file) != NULL ){
		
		last_token = strtok(buffer, delimiter_characters );
		
		while( last_token != NULL ){
	    		
			last_token = clean_word(last_token);
		
			if(list_increment(wordList, last_token) == 1) {

				wordList = list_insert(wordList, last_token);	  
                	
			}

			last_token = strtok( NULL, delimiter_characters );

		}
    
	}

	list_print("Concordance: ", wordList);
}


int main(int argc, char *argv[]) {

	if (argc < 2) {
    		fprintf(stderr, "Usage: Concordance <file name>\n");
    		exit(1);
  	}

	char *file_name = (char *) malloc(sizeof(char));
	
	sscanf(argv[1], "%s", file_name);
	printf("%s ", file_name);
	
	List *wlist = list_create();

	concordance_create(wlist, file_name );

}
