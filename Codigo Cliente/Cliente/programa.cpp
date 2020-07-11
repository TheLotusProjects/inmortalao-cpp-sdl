/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "programa.h"
#include "resource.h"
#include "personaje.h"

programa::programa()
{

}


void programa::run()
{
	personaje* pj = new personaje();

	Cliente::frmMain frmMAIN;
	frmMAIN.Show();
	frmMAIN.setPersonaje(pj);
	
	HWND hWnd = static_cast<HWND>(frmMAIN.pictureBox1->Handle.ToPointer());
	
	HWND hWndMinimap = static_cast<HWND>(frmMAIN.picMiniMap->Handle.ToPointer());
	
	
	resource* recursos = new resource();
	if (!recursos->cargar()) return;

	
	motorGrafico = new engine(hWnd, recursos, pj, GetDC(hWndMinimap));
	//motorGrafico->setMiniMap();
	

	while(motorGrafico->isRunning())
	{
		motorGrafico->rendering();
		motorGrafico->getSDLEvents(frmMAIN.getKey());
		//frmMAIN.pictureBox4->Refresh();
	}
}

programa::~programa()
{
}
