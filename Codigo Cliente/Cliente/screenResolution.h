/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/


#pragma once
#include <windows.h>

class screenResolution
{
public:
	screenResolution(bool modoVentana);
	int getWith();
	int getHeight();
	~screenResolution();
private:
	int width;
	int height;
};

