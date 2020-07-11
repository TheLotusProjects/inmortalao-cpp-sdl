/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

class textura
{
public:
	textura(SDL_Renderer* newRenderer);
	bool cargarImagen(std::string path);
	void cambiarColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void liberarMemoria();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	int getAlto();
	int getAncho();
	~textura();

private:
	SDL_Texture* imagen;
	int alto;
	int ancho;
	SDL_Renderer* renderer;
};

