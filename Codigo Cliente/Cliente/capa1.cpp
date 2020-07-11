/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa1.h"

capa1::capa1(resource* recursosParam, SDL_Renderer* renderParam)
{
	recursos = recursosParam;
	render = renderParam;
	graficos = new std::map<int, grafico*>();
	nroCapa = 0;
}

void capa1::dibujar(int x0,int y0,int nroTrigger,int scrollX,int scrollY)
{
	int indexGrafico;
	for (int y = -1; y<altoVision+1; y++)
	{
		for (int x = -1; x<anchoVision+1; x++)
		{	
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y,scrollX,scrollY);
		}
	}
}

void capa1::renderGrafico(int indexGrafico, int x, int y,int scrollX,int scrollY)
{
	if (indexGrafico > 0)
	{
		x = x * 32 + scrollX; y = y * 32 + scrollY;
		if (!(graficos->find(indexGrafico) != graficos->end())){
			if (recursos->GetFrameCount(indexGrafico) > 1){
				(*graficos)[indexGrafico] = new graficoFx(recursos, render, indexGrafico);
			}
			else{
				(*graficos)[indexGrafico] = new grafico(recursos, render, indexGrafico);
			}
			(*graficos)[indexGrafico]->definirTextura(indexGrafico);
		}

		(*graficos)[indexGrafico]->dibujar(x, y);
	}
}

void capa1::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa1::~capa1()
{
}
