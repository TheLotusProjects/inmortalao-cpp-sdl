/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "personaje.h"

personaje::personaje()
{
	possX = 50;
	possY = 50;
	nroMapa = 59;
	cuerpo = 1;
	cabeza = 1;
	arma = 1;
	escudo = 1;
	caminando = false;
}

void personaje::caminarArriba()
{
	sentidoY = -1;
	possY--;
}

void personaje::caminarAbajo()
{
	sentidoY = 1;
	possY++;
}

void personaje::caminarDerecha()
{
	sentidoX = 1;
	possX++;
}

void personaje::caminarIzquierda()
{
	sentidoX = -1;
	possX--;
}

int personaje::getPossX()
{
	return possX;
}

int personaje::getPossY()
{
	return possY;
}

int personaje::getNroMapa()
{
	return nroMapa;
}

void personaje::setNroMapa(int nroMapaParam)
{
	nroMapa= nroMapaParam;
}

void personaje::setSentidoX(int sentidoParam)
{
	sentidoX = sentidoParam;
}

void personaje::setSentidoY(int sentidoParam)
{
	sentidoY = sentidoParam;
}

int personaje::getSentidoX()
{
	return sentidoX;
}

int personaje::getSentidoY()
{
	return sentidoY;
}

bool personaje::estaCaminando()
{
	return caminando;
}

void personaje::setMovimiento(bool caminandoParam)
{
	caminando = caminandoParam;
}