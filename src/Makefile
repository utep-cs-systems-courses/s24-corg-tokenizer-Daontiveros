CFLAGS=-g -O3

all: inputUser

inputUser: inputUser.o
	gcc inputUser.o -o inputUser

inputUser.o: inputUser.c
	gcc -c inputUser.c -o inputUser.o

clean:
	rm -f *.o inputUser
	rm -f Makefile~
	rm -f inputUser.c~
	rm -f #Makefile#

run:inputUser
	./inputUser
