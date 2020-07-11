/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "screenResolution.h"


screenResolution::screenResolution(bool modoVentana)
{
	if (!modoVentana)
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
	}

}

int screenResolution::getHeight()
{
	return height;
}

int screenResolution::getWith()
{
	return width;
}

screenResolution::~screenResolution()
{
}
