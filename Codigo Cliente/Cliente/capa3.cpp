/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa3.h"


capa3::capa3(resource* recursosParam, SDL_Renderer* renderParam)
{
	recursos = recursosParam;
	render = renderParam;
	graficos = new std::map<int, grafico*>();
	nroCapa = 2;
}

void capa3::dibujar(int x0, int y0, int nroTrigger,int scrollX, int scrollY)
{
	int indexGrafico, indexGraficoObj, indexGraficoNpc, indexParticle,indexGrhParticle;
	int xParticle, yParticle;
	particula* tempParticula;
	int ytemp;

	for (int y = -4; y<altoVision+4; y++)
	{
		for (int x = -4; x<anchoVision+4; x++)
		{
			indexGraficoObj = mapaActual->getObjGrhIndex(x0 + x, y0 + y);
			renderGrafico(indexGraficoObj, x, y, scrollX, scrollY,0,0,0);
			
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y,scrollX,scrollY,0,0,0);
			
			if (mapaActual->hayParticula(x0 + x, y0 + y))
			{
				tempParticula = mapaActual->getParticula(x0 + x, y0 + y);
			
				tempParticula->setLifeCounter(tempParticula->getLifeCounter()+0.3);
				
				if (tempParticula->getLifeCounter() > tempParticula->getSpeed()){
					tempParticula->setLifeCounter(0); tempParticula->setMovement(true);
				}
				else{ tempParticula->setMovement(false); }

				for (int i = 0; i<tempParticula->getNumParticles(); i++){
					tempParticula->dibujar(i);
					indexGrhParticle = tempParticula->getParticleGrhIndex(i);
					xParticle = tempParticula->getParticleX(i);
					yParticle = tempParticula->getParticleY(i);

					renderGrafico(indexGrhParticle, x, y, scrollX, scrollY,xParticle,yParticle,tempParticula->getAlphaBlend());
				}

			}
		}
	}
}

void capa3::renderGrafico(int indexGrafico, int x, int y, int scrollX, int scrollY, double px , double py,int alpha)
{

	if (indexGrafico > 0)
	{
		int cantidadPosicionesX = recursos->GetTileWGrafico(indexGrafico);
		if (cantidadPosicionesX != 1)x = x * 32 - cantidadPosicionesX * (32 / 2) + 32 / 2 + scrollX;
		else{ x = x * 32 + scrollX; }
		int cantidadPosicionesY = recursos->GetTileHGrafico(indexGrafico);
		if (cantidadPosicionesY != 1)y = y * 32 - cantidadPosicionesY * 32 + 32 + scrollY;
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

		if (alpha>0)(*graficos)[indexGrafico]->setAlpha(30);
		

		(*graficos)[indexGrafico]->dibujar(x+px, y+py);
	}
}

void capa3::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa3::~capa3()
{
}
