/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once

class personaje
{
public:
	personaje();
	int getPossX();
	int getPossY();
	int getNroMapa();
	void setNroMapa(int nroMapaParam);
	int getSentidoX();
	int getSentidoY();
	void setMovimiento(bool caminandoParam);
	bool estaCaminando();
	void caminarArriba();
	void caminarAbajo();
	void caminarDerecha();
	void caminarIzquierda();
	void setSentidoX(int sentidoParam);
	void setSentidoY(int sentidoParam);
private:
	int possX;
	int possY;
	int sentidoX;
	int sentidoY;
	bool caminando = false;
	int nroMapa, cuerpo, cabeza, arma, escudo;
};