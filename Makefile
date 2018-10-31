#Makefile

all: prog

prog: lista.o matriz.o main.o
	gcc main.o lista.o matriz.o -o prog

main.o: main.c
	gcc -c main.c

lista.o: lista.c
	gcc -c lista.c

matriz.o: matriz.c
	gcc -c matriz.c