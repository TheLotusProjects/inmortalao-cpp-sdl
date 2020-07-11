/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include "SDL2/SDL_image.h"
#include "textura.h"
#include "screenResolution.h"
#include "administradorRecursos.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "personaje.h"
#include "frmMain.h"

//#define WINDOW_CAPTION "InmortalAO"

class engine
{
public:
	engine(HWND hwnd, resource* recursosParam, personaje* pjParam, HDC hdcMiniMapParam);
	void rendering();
	bool isRunning();
	void getSDLEvents(int key);
	void controlFrame();
	void setMiniMap();
	~engine();
	textura* fondo;
private:
	int WIDTH;
	int HEIGHT;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	screenResolution* resolucion;
	bool running=true;
	void dibujarElementos();
	administradorRecursos* administrador;
	int tiempoPorFrame;
	int cantidadCuadros;
	timer* timerTiempoLoop;
	timer* timerTiempoTotal;
	float cuadrosPromedioPorSegundo;
	int possX=50;
	int possY=50;
	personaje* pj;
	HDC hdcMiniMap;
};