/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "SDL2/SDL.h"
#include "resource.h"

class grafico
{
protected:
	resource* recursos;
	SDL_Renderer* render;
	SDL_Rect* rectImg;
	textura* graficoTextura;
	textura* cargarImagen(int indexGrafico);
	SDL_Rect* getDimensionesGrafico(int indexGrafico);
public:
	grafico(resource* recursosParam, SDL_Renderer* renderParam, int indexGrafico);
	textura* cargarGrafico(int numeroGrafico, std::string strNumeroGrafico);
	virtual void definirTextura(int indexGrafico);
	virtual void dibujar(int x, int y);
	void setAlpha(int alphaInicial);
	~grafico();
};

