all: Concordance

Concordance: concordance.o linked_list.o
	gcc concordance.o linked_list.o -o Concordance

concordance.o: concordance.c list.h
	gcc -c concordance.c 

list_dummy_head.o: linked_list.c list.h 
	gcc -c linked_list.c

clean:
	rm *.o
