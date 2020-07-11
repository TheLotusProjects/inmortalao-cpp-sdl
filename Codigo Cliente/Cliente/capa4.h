/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "superficie.h"
#include "grafico.h"
#include "graficoFx.h"
#include <map>

#define ALPHA_INICIAL 250
#define INCREMENTO_ALPHA_TECHO 10
#define CONTADOR_ALPHA_TECHO 1

class capa4
{
public:
	capa4(resource* recursosParam, SDL_Renderer* renderParam);
	void dibujar(int x, int y, int nroTrigger, int scrollX, int scrollY);
	void setMapaActual(mapa* mapaActual);
	void controlAphaTecho(int nroTrigger);
	~capa4();
private:
	int nroCapa;
	int alphaInicial = ALPHA_INICIAL;
	int altoVision = 13;
	int anchoVision = 17;
	int contador = 0;
	mapa* mapaActual;
	resource* recursos;
	SDL_Renderer* render;
	void renderGrafico(int indexGrafico, int x, int y, int scrollX, int scrollY);
	std::map <int, grafico*>* graficos;
};

