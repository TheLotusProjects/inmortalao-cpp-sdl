/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "armas.h"


armas::armas()
{
	Armas = new std::map<int, weaponanimdata>();
}


void armas::cargar()
{
	short int numarmas,tempint;

	std::ifstream fentrada("./Recursos/Init/armas.ind", std::ios::in | std::ios::binary);
	fentrada.read(reinterpret_cast<char *>(&numarmas), sizeof(short int));
	
	weaponanimdata weaponTemp;
	
	for (int i = 0; i<numarmas; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		weaponTemp.weaponanim[NORTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		weaponTemp.weaponanim[EAST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		weaponTemp.weaponanim[SOUTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		weaponTemp.weaponanim[WEST].grhindex = tempint;

		(*Armas)[i] = weaponTemp;
	}
	fentrada.close();
}

armas::~armas()
{
}
