CC=gcc
	
all : myBank.o main.o
	$(CC) -Wall -o all main.o myBank.o		
         

myBank.o: myBank.c myBank.h
	$(CC) -Wall -c myBank.c -o myBank.o
           

main.o: main.c myBank.h
	$(CC) -Wall -c main.c -o main.o					
		
          

.PHONY: clean all

clean :
	      rm -f *.o *.out

