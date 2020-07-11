#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"


class escudos
{
public:
	escudos();
	void cargar();
	~escudos();
private:
	std::map<int, shielddata>* Escudos;
};

