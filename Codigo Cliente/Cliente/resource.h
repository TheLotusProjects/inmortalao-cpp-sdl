
/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once

#include "ini.h"
#include "mapa.h"
#include "ini.h"
#include "textura.h"
#include "particulas.h"
#include "fuentes.h"
#include "clima.h"
#include "cuerpos.h"
#include "cabezas.h"
#include "cascos.h"
#include "fxs.h"
#include "armas.h"
#include "escudos.h"
#include "objetos.h"
#include <map>

class resource
{
public:
	resource();
	bool cargar();
	mapa* getMapa(int nroMapa);
	int GetGrafico(int index);
	int GetXGrafico(int index);
	int GetYGrafico(int index);
	int GetWGrafico(int index);
	int GetHGrafico(int index);
	int GetTileHGrafico(int index);
	int GetTileWGrafico(int index);
	int GetFrameCount(int index);
	int GetSpeedGrh(int index);
	int getIndexFrame(int index, int frame);
	bool estaGraficoCargado(int nroGrafico);
	void setGrafico(textura* grafico, int nroGrafico);
	particula* getParticula(int indexParticula);
	textura* getTexturaGrafico(int nroGrafico);
	textura* cargarGrafico(int numeroGrafico, std::string strNumeroGrafico, SDL_Renderer* render);
	~resource();
private:
	bool cargarMapa(int nroMapa);
	bool cargarIni();
	std::map <int, mapa*>* mapas;
	std::map <int, textura*>* graficosCargados;
	particulas* Particulas;
	ini* indexGraficos;
	fuentes* Fuentes;
	clima* Clima;
	cuerpos* Cuerpos;
	cabezas* Cabezas;
	cascos* Cascos;
	fxs* Fxs;
	armas* Armas;
	escudos* Escudos;
	objetos* Objetos;
	bool cargarArmas();
	bool cargarCabezas();
	bool cargarCascos();
	bool cargarClima();
	bool cargarCuerpos();
	bool cargarEscudos();
	bool cargarFuentes();
	bool cargarFxs();
	bool cargarParticulas();
};

