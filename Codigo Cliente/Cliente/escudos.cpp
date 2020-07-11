/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "escudos.h"


escudos::escudos()
{
	Escudos = new std::map<int, shielddata>();
}

void escudos::cargar()
{
	short int numescudos, tempint;

	std::ifstream fentrada("./Recursos/Init/escudos.ind", std::ios::in | std::ios::binary);
	fentrada.read(reinterpret_cast<char *>(&numescudos), sizeof(short int));
	
	shielddata tempEscudo;
	for (int i = 0; i<numescudos; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempEscudo.shieldwalk[NORTH].grhindex= tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempEscudo.shieldwalk[EAST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempEscudo.shieldwalk[SOUTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempEscudo.shieldwalk[WEST].grhindex = tempint;

		(*Escudos)[i] = tempEscudo;
	}
	fentrada.close();
}

escudos::~escudos()
{
}
