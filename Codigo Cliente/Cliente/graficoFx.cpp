/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "graficoFx.h"


graficoFx::graficoFx(resource* recursosParam, SDL_Renderer* renderParam, int indexGrafico) : grafico(recursosParam,renderParam,indexGrafico)
{
	fxs = new std::map<int,textura*>();
	rects = new std::map<int, SDL_Rect*>();
	totalFrames = recursos->GetFrameCount(indexGrafico);
	speed = 0.05;//recursos->GetSpeedGrh(indexGrafico);
}

void graficoFx::definirTextura(int indexGrafico)
{
	int indexFrame;
	for (int i = 0; i < totalFrames; i++)
	{
		indexFrame = recursos->getIndexFrame(indexGrafico, i);
		(*fxs)[i] = cargarImagen(indexFrame);
		(*rects)[i] = getDimensionesGrafico(indexFrame);
	}
}

void graficoFx::dibujar(int x, int y)
{
	if (frameCounter < totalFrames-1)frameCounter+=speed;
	else{ frameCounter = 0; }
	(*fxs)[frameCounter]->render(x, y, (*rects)[frameCounter]);
}

graficoFx::~graficoFx()
{
	delete fxs;
}
