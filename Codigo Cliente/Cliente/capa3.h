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
#include "particulas.h"
#include <math.h>
#include <map>

class capa3
{
public:
	capa3(resource* recursosParam, SDL_Renderer* renderParam);
	void dibujar(int x, int y, int nroTrigger, int scrollX, int scrollY);
	void setMapaActual(mapa* mapaActual);
	~capa3();
private:
	int nroCapa;
	int altoVision = 13;
	int anchoVision = 17;
	mapa* mapaActual;
	resource* recursos;
	SDL_Renderer* render;
	void renderGrafico(int indexGrafico, int x, int y, int scrollX, int scrollY, double px, double py, int alpha);
	std::map <int, grafico*>* graficos;
};

