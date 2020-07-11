/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "engine.h"

engine::engine(HWND hwnd, resource* recursosParam, personaje* pjParam, HDC hdcMiniMapParam)
{
	//atexit(SDL_Quit);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	IMG_Init(SDL_INIT_EVERYTHING);

	//int X = SDL_WINDOWPOS_CENTERED;
	//int Y = SDL_WINDOWPOS_CENTERED;
	
	//window2 = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_BORDERLESS);
	window = SDL_CreateWindowFrom(hwnd);


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	pj = pjParam;
	administrador = new administradorRecursos(recursosParam,renderer,pj);
	
	timerTiempoLoop = new timer();
	timerTiempoTotal = new timer();
	hdcMiniMap= hdcMiniMapParam;


	//Cuadros por segundo
	int fps = 100;
	//Cantidad de segundos por cuadro
	tiempoPorFrame = 1000 / fps;
	cantidadCuadros = 0;
}

//FALTARIA LIMITAR FPS PARA NO COMER USO DE CPU AL DOPE
void engine::rendering()
{
	administrador->setMapaActual(pj->getNroMapa());

	SDL_RenderClear(renderer);

	this->dibujarElementos();

	SDL_RenderPresent(renderer);
	
	
	//////////REGULAMOS LOS FRAMES POR SEGUNDO///////////////
	int tiempoTardanzaFrame = timerTiempoLoop->tiempoActual();
	if (tiempoTardanzaFrame < tiempoPorFrame)
	{
		//Hacemos un retraso de lo que la CPU adelanto
		SDL_Delay(tiempoPorFrame - tiempoTardanzaFrame);
	}

	
}

void engine::dibujarElementos()
{
	/////////////////////
	//dibujamos elementos
	/////////////////////

	//RANGO DE VISION DE MAPA ACTUAL
	administrador->dibujarRangoMapaActual(pj->getPossX(),pj->getPossY());
	//PERSONAJE ACTUAL
	administrador->dibujarPersonajeActual();
	//PERSONAJES EN EL RANGO
	administrador->dibujarPersonajesRango();
	//ITEMS
	administrador->dibujarItemsRango();
	//PARTICULAS
	administrador->dibujarParticulasRango();
	//EFECTOS
	administrador->dibujarEfectosRango();
	//TEXTO
	administrador->dibujarTextoRango();
	/////////////////////
}



void engine::getSDLEvents(int key)
{
	if (!pj->estaCaminando())
	{
		if (key == 37)
		{
			pj->caminarIzquierda();
			administrador->setScrolling();
		}
		else if (key == 39)
		{
			pj->caminarDerecha();
			administrador->setScrolling();
		}
		else if (key == 38)
		{
			pj->caminarArriba();
			administrador->setScrolling();
		}
		else if (key == 40)
		{
			pj->caminarAbajo();
			administrador->setScrolling();
		}	
	}
	

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
				running = false;
				}
				break;
		}
	}
}

bool engine::isRunning()
{
	return running;
}

void engine::setMiniMap()
{
	for (int i = 0; i < 100; i++){
		SetPixel(hdcMiniMap, i, 10, RGB(0, 255, 255));
	}
}

engine::~engine()
{
}
