/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "resource.h"


resource::resource()
{
	mapas = new std::map<int, mapa*>();
	graficosCargados = new std::map<int, textura*>();
	Particulas = new particulas();
	indexGraficos = new ini();
	Fuentes = new fuentes();
	Clima = new clima();
	Cuerpos = new cuerpos();
	Cabezas = new cabezas();
	Cascos = new cascos();
	Fxs = new fxs();
	Armas = new armas();
	Escudos = new escudos();
	Objetos = new objetos();
}

mapa* resource::getMapa(int nroMapa)
{
	if (!(mapas->find(nroMapa) != mapas->end()))
		cargarMapa(nroMapa);

	return (*mapas)[nroMapa];
}

void resource::setGrafico(textura* grafico,int nroGrafico)
{
	(*graficosCargados)[nroGrafico] = grafico;
}

textura* resource::getTexturaGrafico(int nroGrafico)
{
	return (*graficosCargados)[nroGrafico];
}

bool resource::estaGraficoCargado(int nroGrafico)
{
	return (graficosCargados->find(nroGrafico) != graficosCargados->end());
}

bool resource::cargar()
{
	Objetos->cargar();
	return (cargarIni()&cargarArmas()&cargarCabezas()&cargarCascos()&cargarClima()&cargarCuerpos()&cargarEscudos()&cargarFuentes()&cargarFxs()&cargarParticulas());
}

bool resource::cargarMapa(int nroMapa)
{
	try
	{
		mapa* elMapa = new mapa(nroMapa,Objetos,Particulas);
		(*mapas)[nroMapa] = elMapa;
	}
	catch (std::exception error)
	{
		return false;
	}
	
	return true;
}

bool resource::cargarIni()
{
	try
	{
		indexGraficos->cargarIndicesGraficos();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarArmas()
{
	try
	{
		Armas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}
bool resource::cargarCabezas()
{
	try
	{
		Cabezas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}
bool resource::cargarCascos()
{
	try
	{
		Cascos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarClima()
{
	try
	{
		Clima->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarCuerpos()
{
	try
	{
		Cuerpos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarEscudos()
{
	try
	{
		Escudos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarFuentes()
{
	try
	{
		Fuentes->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarFxs()
{
	try
	{
		Fxs->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool resource::cargarParticulas()
{
	try
	{
		Particulas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

int resource::GetGrafico(int index)
{
	return indexGraficos->getNumeroArchivo(index);
}

int resource::GetXGrafico(int index)
{
	int x=indexGraficos->getXindex(index);
	return x;
}

int resource::GetYGrafico(int index)
{
	int y = indexGraficos->getYindex(index);
	return y;
}

int resource::GetWGrafico(int index)
{
	return indexGraficos->getWindex(index);
}

int resource::GetHGrafico(int index)
{
	return indexGraficos->getHindex(index);
}

int resource::GetTileWGrafico(int index)
{
	return indexGraficos->getTileW(index);
}


int resource::GetTileHGrafico(int index)
{
	return indexGraficos->getTileH(index);
}


textura* resource::cargarGrafico(int numeroGrafico, std::string strNumeroGrafico, SDL_Renderer* render)
{
	textura* graficoActual;
	if (!estaGraficoCargado(numeroGrafico))
	{
		graficoActual = new textura(render);
		graficoActual->cargarImagen("./Recursos/Graficos/" + strNumeroGrafico + ".bmp");
		setGrafico(graficoActual, numeroGrafico);
	}
	else
	{
		graficoActual = getTexturaGrafico(numeroGrafico);
	}
	return graficoActual;
}

int resource::GetFrameCount(int index)
{
	return indexGraficos->getFrameCount(index);
}

int resource::GetSpeedGrh(int index)
{
	return indexGraficos->getGrhSpeed(index);
}

int resource::getIndexFrame(int index, int frame)
{
	return indexGraficos->getIndexFrame(index, frame);
}

particula* resource::getParticula(int indexParticula)
{
	return Particulas->getParticula(indexParticula);
}

resource::~resource()
{
}
