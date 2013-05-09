#include "funciones.h"


int rotaciones[7][4][5][5]=
{
	/*TIPO 0 BARRA*/
	
		/*derecha*/
		0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,1,0,0,0,0,1,0,0,
		/*abajo*/
		0,0,0,0,0,0,0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,
		/*izquierda*/
		0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,
		/*arriba*/
		0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0,0,0,0,0,0,0,
	
	/*TIPO 1 CUAD*/
	
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,1,1,0,0,0,0,0,0,

	/*TIPO 2 _|_*/
		0,0,0,0,0,0,0,0,1,0,0,0,2,1,0,0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,0,1,2,0,0,0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,1,1,0,0,0,0,0,0,
	/*TIPO 3 L inv*/
		0,0,0,0,0,0,1,1,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,

	/*TIPO 4 L*/
		0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,

	/*TIPO 5 _|-*/
		0,0,0,0,0,0,0,0,1,0,0,0,2,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,0,0,0,2,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,1,1,0,0,0,0,0,0,	
	/*TIPO 6 -|_*/
		0,0,0,0,0,0,0,1,0,0,0,0,2,1,0,0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,1,1,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,1,0,0,0,0,2,1,0,0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,1,1,0,0,0,0,0,0,0
};
void renderfondo(SDL_Surface *screen)
{
	SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,255,255,255));
}
void rendermatriz(SDL_Surface *screen, struct matrizpant *m,struct pieza *p)
{
	int a,b;
	SDL_Rect *r = malloc(sizeof(SDL_Rect));
	r->w = SWIDTH/COLUMNAS;
	r->h = r->w;

	
	for(a=0;a<5;a++)
	{
		for(b=0;b<5;b++)
		{
			if(p->rotacion[a][b] != 0)
			{
				switch(p->rotacion[a][b])
				{
					case 1:
						m->pantalla[p->fila-2+b][p->columna-2+a] = 1;
						break;
					case 2:
						m->pantalla[p->fila-2+b][p->columna-2+a] = 2;
						break;
					default:
						break;
				}
			}
		}
	}
	for(a=0;a<FILAS;a++)
	{
		for(b=0;b<COLUMNAS;b++)
		{
			if(m->pantalla[a][b] != 0)
			{
				r->y = a*r->w;
				r->x = b*r->w;
				switch(m->pantalla[a][b])
				{
					case 1:
						SDL_FillRect(screen,r,SDL_MapRGB(screen->format,0,0,0));
						break;
					case 2:
						SDL_FillRect(screen,r,SDL_MapRGB(screen->format,255,0,0));
						break;
					default:
						break;
				}
			}
		}
	}
}
void resetmatriz(struct matrizpant *m)
{
	int a,b;
	for(a=0;a<FILAS;a++)
	{
		for(b=0;b<COLUMNAS;b++)
		{
			m->pantalla[a][b] = 0;
		}
	}

}
void nuevapieza(struct pieza *p)
{
	int a,b;
	srand(time(NULL));
	p->fila = 2;
	p->columna = 5;
	p->tipo = rand()%7;
	p->numrotacion = derecha;
	for(a=0;a<5;a++)
	{
		for(b=0;b<5;b++)
		{
			p->rotacion[a][b] = rotaciones[p->tipo][p->numrotacion][a][b];
		}
	}
}

void cambiorotacion(struct pieza *p)
{
	int a,b;
	if(p->numrotacion<3)
		p->numrotacion++;
	else 
		p->numrotacion = 0;
	for(a=0;a<5;a++)
	{
		for(b=0;b<5;b++)
		{
			p->rotacion[a][b] = rotaciones[p->tipo][p->numrotacion][a][b];
		}
	}
}
void borrarpieza(struct pieza *p, struct matrizpant *m)
{
	int a,b;

	for(a=0;a<5;a++)
	{
		for(b=0;b<5;b++)
		{
			if(p->rotacion[a][b] != 0)
			{
				m->pantalla[p->fila-2+b][p->columna-2+a] = 0;
			}
		}
	}
}

void movimientoderecha(struct pieza *p)
{
	int a;
	if(p->columna==8)
	{
		for(a=0;a<5;a++)
		{
			if(p->rotacion[3][a] != 0)
			{
				goto final;
			}
		}
		p->columna++;
	}
	else if(p->columna ==7)
	{
		for(a=0;a<5;a++)
		{
			if(p->rotacion[4][a] != 0)
			{
				goto final;
			}
		}
		p->columna++;
	}

	else 
		p->columna++;
	final: ;
}
void movimientoizquierda(struct pieza *p)
{
	int a;
	if(p->columna == 1)
	{
		for(a=0;a<5;a++)
		{
			if(p->rotacion[1][a] != 0)
			{
				goto end;
			}
		}
		p->columna--;
	}
	else if(p->columna == 2)
	{
		for(a=0;a<5;a++)
		{
			if(p->rotacion[0][a] != 0)
			{
				goto end;
			}
		}
		p->columna--;
	}
	else 
		p->columna--;
	end: ;
}
