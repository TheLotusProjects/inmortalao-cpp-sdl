/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "grafico.h"

grafico::grafico(resource* recursosParam, SDL_Renderer* renderParam, int indexGrafico)
{
	recursos = recursosParam;
	render = renderParam;
}

void grafico::definirTextura(int indexGrafico)
{
	rectImg = getDimensionesGrafico(indexGrafico);
	graficoTextura = cargarImagen(indexGrafico);
}

textura* grafico::cargarImagen(int indexGrafico)
{
	std::string strNumeroGrafico;
	int numeroGrafico;
	numeroGrafico = recursos->GetGrafico(indexGrafico);
	std::stringstream stream; stream << numeroGrafico;
	strNumeroGrafico = stream.str();

	return cargarGrafico(numeroGrafico, strNumeroGrafico);
}

SDL_Rect* grafico::getDimensionesGrafico(int indexGrafico)
{
	int xGrafico, yGrafico, wGrafico, hGrafico;
	SDL_Rect* rect = new SDL_Rect();
	xGrafico = recursos->GetXGrafico(indexGrafico);
	yGrafico = recursos->GetYGrafico(indexGrafico);
	wGrafico = recursos->GetWGrafico(indexGrafico);
	hGrafico = recursos->GetHGrafico(indexGrafico);
	rect->x = xGrafico; rect->y = yGrafico; rect->w = wGrafico; rect->h = hGrafico;
	return rect;
}

void grafico::dibujar(int x, int y)
{
	graficoTextura->render(x, y, rectImg);
}

textura* grafico::cargarGrafico(int numeroGrafico, std::string strNumeroGrafico)
{
	return recursos->cargarGrafico(numeroGrafico, strNumeroGrafico, render);
}

void grafico::setAlpha(int alphaInicial)
{
	graficoTextura->setAlpha(alphaInicial);
}

grafico::~grafico()
{
}
