/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include <iostream>
#include "SDL2/SDL.h"

class timer
{
public:
	timer();
	void comenzar();
	void pausa();
	void parar();
	Uint32 tiempoActual();

private:
	Uint32 tiempoComienzo;
	Uint32 tiempoPausa;
	bool enPausa;
	bool corriendo;

};

