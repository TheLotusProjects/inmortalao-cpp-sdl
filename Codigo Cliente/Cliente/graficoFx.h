/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "grafico.h"

class graficoFx : public grafico
{
	private:
		double frameCounter = 0;
		int totalFrames;
		double speed;
		std::map <int, textura*>* fxs;
		std::map <int, SDL_Rect*>* rects;
	public:
		graficoFx(resource* recursosParam, SDL_Renderer* renderParam, int indexGrafico);
		void dibujar(int x, int y) override;
		void definirTextura(int indexGrafico) override;
		~graficoFx();
};

