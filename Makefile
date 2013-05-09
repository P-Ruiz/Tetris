tetris: main.o funciones.o
	gcc -o tetris main.o funciones.o -lSDLmain -lSDL -Wall

main.o: main.c funciones.h
	gcc -c main.c
funciones.o: funciones.c funciones.h
	gcc -c funciones.c

clean: 
	rm tetris main.o funciones.o
