/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "resource.h"
#include "personaje.h"
#include "mapa.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include "SDL2/SDL_image.h"
#include "textura.h"
#include "capa1.h"
#include "capa2.h"
#include "capa3.h"
#include "capa4.h"

class administradorRecursos
{
private:
	int nroMapaActual;
	resource* recursos;
	mapa* mapaActual;
	capa1* Capa1;
	capa2* Capa2;
	capa3* Capa3;
	capa4* Capa4;
	int nroTrigger,x0,y0;
	int scrollX,scrollY;
	bool pararScrolling;
	personaje* pj;
public:
	administradorRecursos(resource* recursosParam, SDL_Renderer* renderParam,personaje* pjParam);
	void dibujarRangoMapaActual(int x, int y);
	void dibujarPersonajeActual();
	void dibujarPersonajesRango();
	void dibujarItemsRango();
	void dibujarParticulasRango();
	void dibujarEfectosRango();
	void setScrolling();
	void dibujarTextoRango();
	void setMapaActual(int numeroMapa);
};

