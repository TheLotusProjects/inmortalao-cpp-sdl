/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "textura.h"


textura::textura(SDL_Renderer* newRenderer)
{
	imagen = NULL;
	alto = 0;
	ancho = 0;
	renderer = newRenderer;
}

bool textura::cargarImagen(std::string path)
{
	liberarMemoria();

	SDL_Texture* texturaNueva = NULL;

	SDL_Surface* imagenNueva = IMG_Load(path.c_str());

	SDL_SetColorKey(imagenNueva, SDL_TRUE, SDL_MapRGB(imagenNueva->format, 0, 0, 0));

	
	texturaNueva = SDL_CreateTextureFromSurface(renderer, imagenNueva);
	
	alto = imagenNueva->h;
	ancho = imagenNueva->w;

	SDL_FreeSurface(imagenNueva);

	imagen = texturaNueva;

	return imagen!=NULL;
}

//Seteamos el modo de Blending para poder jugar con el Alpha despues
void textura::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(imagen, blending);
}

//Modificamos los niveles de transparencia de la imagen
void textura::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(imagen, alpha);
}

void textura::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//armamos un rectangulo de la textura para dibujar en la pantalla
	SDL_Rect renderQuad = { x, y, ancho, alto };

	//Si hicimos un clip para cortar la imagen seteamos sus dimensiones
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_SetRenderTarget(renderer, NULL);
	//Plasmamos la textura en la pantalla
	SDL_RenderCopyEx(renderer, imagen, clip, &renderQuad, angle, center, flip);
}

void textura::liberarMemoria()
{
	if (imagen != NULL)
	{
		SDL_DestroyTexture(imagen);
		imagen = NULL;
		ancho = 0;
		alto = 0;
	}
}

void textura::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(imagen, red, green, blue);
}

int textura::getAlto()
{
	return alto;
}

int textura::getAncho()
{
	return ancho;
}

textura::~textura()
{
	liberarMemoria();
}
