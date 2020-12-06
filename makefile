all : myBank.o main.o
       gcc -Wall -o all main.o myBank.o

myBank.o: myBank.c myBank.h
        gcc -Wall -c myBank.c -o myBank.o

main.o: main.c myBank.h
      gcc -Wall -c main.o

.PHONY: clean all

clean :
      rm -f*.o*.out
