/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "timer.h"


timer::timer()
{
	tiempoComienzo = 0;
	tiempoPausa = 0;
	enPausa = false;
	corriendo = false;
}

void timer::comenzar()
{
	tiempoComienzo = SDL_GetTicks();
	tiempoPausa = 0;
	corriendo = true;
	enPausa = false;
}

void timer::pausa()
{
	if (corriendo && !enPausa)
	{
		enPausa = true;
		tiempoPausa = SDL_GetTicks() - tiempoComienzo;
		tiempoComienzo = 0;
	}
	else if (corriendo && enPausa)
	{
		enPausa = false;
		tiempoComienzo = SDL_GetTicks() - tiempoPausa;
		tiempoPausa = 0;
	}

}

void timer::parar()
{
	tiempoComienzo = 0;
	tiempoPausa = 0;
	corriendo = false;
	enPausa = false;
}


Uint32 timer::tiempoActual()
{
	Uint32 tiempo = 0;
	if (corriendo)
	{
		if (enPausa)
		{
			tiempo= tiempoPausa;
		}
		else
		{
			tiempo = SDL_GetTicks() - tiempoComienzo;
		}

	}

	return tiempo;
}
