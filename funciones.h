#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"

enum boolean{FALSE=0,TRUE=1};
enum screen{SWIDTH = 240,SHEIGHT = 480};
enum cuadricula{FILAS = 20,COLUMNAS = 10};
enum frames{FPS=30};
enum rotaciones{derecha=0,abajo=1,izquierda=2,arriba=3};
struct matrizpant
{
	int pantalla[FILAS][COLUMNAS];
};

struct pieza
{
	int fila;
	int columna;
	int tipo;
	int numrotacion;
	int rotacion[5][5];
};
//funciones

void renderfondo(SDL_Surface *screen);
void rendermatriz(SDL_Surface *screen,struct matrizpant *m,struct pieza *p);
void resetmatriz(struct matrizpant *m);
void nuevapieza(struct pieza *p);
void cambiorotacion(struct pieza *p);
void borrarpieza(struct pieza *p, struct matrizpant *m);
void movimientoderecha(struct pieza *p);
void movimientoizquierda(struct pieza*p);
#endif
