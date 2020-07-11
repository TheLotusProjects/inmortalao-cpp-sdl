/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include <iostream>
#include "programa.h"

int main(int argc, char **argv)
{
	try
	{
		programa* prg = new programa();
		prg->run();
	}
	catch (std::exception e)
	{
		std::cout << "Error al iniciar InmortalAO: " << e.what() << "\n";
	}
	
	return 0;
}

