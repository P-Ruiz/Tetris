#include "funciones.h"


int main(int argc, char* argv[])
{
	int running = TRUE;
	SDL_Event event;
	SDL_Rect *rectrender = malloc(sizeof(SDL_Rect));
	Uint32 Tick;
	struct matrizpant *m = (struct matrizpant*)malloc(sizeof(struct matrizpant));
	struct pieza *piezactual = (struct pieza*)malloc(sizeof(struct pieza));

	resetmatriz(m);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen = SDL_SetVideoMode(SWIDTH,SHEIGHT,32,SDL_SWSURFACE);

	nuevapieza(piezactual);
	
	while(running)
	{
		Tick = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				running = 0;
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = 0;
						break;
					case SDLK_RIGHT:
						borrarpieza(piezactual,m);
						if(piezactual->columna<9)
							movimientoderecha(piezactual);
						break;
					case SDLK_LEFT:
						borrarpieza(piezactual,m);
						if(piezactual->columna>0)
							movimientoizquierda(piezactual);
						break;
					case SDLK_UP:
						borrarpieza(piezactual,m);
						cambiorotacion(piezactual);
						break;
					case SDLK_SPACE:
						borrarpieza(piezactual,m);
						nuevapieza(piezactual);
					default:
						break;
				}
			}
		}

		renderfondo(screen);
		rendermatriz(screen,m,piezactual);
		SDL_Flip(screen);

		if(1000/FPS > SDL_GetTicks()-Tick)
		{
			SDL_Delay(1000/FPS-(SDL_GetTicks()-Tick));
		}

	}	

	SDL_Quit();
	return 0;
}
