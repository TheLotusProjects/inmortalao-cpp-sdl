/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa4.h"


capa4::capa4(resource* recursosParam, SDL_Renderer* renderParam)
{
	recursos = recursosParam;
	render = renderParam;
	graficos = new std::map<int, grafico*>();
	nroCapa = 3;
}

void capa4::dibujar(int x0, int y0, int nroTrigger,int scrollX, int scrollY)
{
	int indexGrafico;
	for (int y = -4; y<altoVision+4; y++)
	{
		for (int x = -3; x<anchoVision+3; x++)
		{
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y,scrollX, scrollY);
		}
	}
	controlAphaTecho(nroTrigger);
}

void capa4::renderGrafico(int indexGrafico, int x, int y,int scrollX, int scrollY)
{
	if (indexGrafico > 0)
	{
		int cantidadPosicionesX = recursos->GetTileWGrafico(indexGrafico);
		if (cantidadPosicionesX != 1)x = x * 32 - cantidadPosicionesX * (32 / 2) + 32 / 2+scrollX;
		else{ x = x * 32 + scrollX; }
		int cantidadPosicionesY = recursos->GetTileHGrafico(indexGrafico);
		if (cantidadPosicionesY != 1)y = y * 32 - cantidadPosicionesY * 32 + 32+scrollY;
		else{ y = y * 32 + scrollY; }

		if (!(graficos->find(indexGrafico) != graficos->end())){
			if (recursos->GetFrameCount(indexGrafico) > 1){
				(*graficos)[indexGrafico] = new graficoFx(recursos, render, indexGrafico);
			}
			else{
				(*graficos)[indexGrafico] = new grafico(recursos, render, indexGrafico);
			}
			(*graficos)[indexGrafico]->definirTextura(indexGrafico);
		}

		(*graficos)[indexGrafico]->setAlpha(alphaInicial);
		(*graficos)[indexGrafico]->dibujar(x, y);
	}
}


void capa4::controlAphaTecho(int nroTrigger)
{
	if (nroTrigger > 0 && alphaInicial >0 && contador == CONTADOR_ALPHA_TECHO){
		alphaInicial -= INCREMENTO_ALPHA_TECHO;
		contador = 0;
	}
	else if (contador == CONTADOR_ALPHA_TECHO && alphaInicial < ALPHA_INICIAL && nroTrigger == 0){ alphaInicial += INCREMENTO_ALPHA_TECHO; contador = 0; }

	if (contador < CONTADOR_ALPHA_TECHO){ contador++; }
	else{ contador = 0; }
}


void capa4::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa4::~capa4()
{
}
