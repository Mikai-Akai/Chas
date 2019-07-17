#include "caja.h"
Caja::Caja(){
	switch (1 + rand() %(7-1)){
		case 1:
			nombre = "espacio";
			gBloqueado = false;
			break;
		case 2:
			nombre = "tiempo";
			gBloqueado = false;
			break;
		case 3:
			nombre = "realidad";
			gBloqueado = false;
			break;
		case 4:
			nombre = "mente";
			gBloqueado = true;
			color = "azul";
			break;
		case 5:
			nombre = "alma";
			gBloqueado = false;
			break;
		case 6:
			nombre = "poder";
			gBloqueado = false;
			break;
		default:
			break;
	}
}
Caja::~Caja(){
	//
}
void Caja::desbloquear(){
	gBloqueado = false;
}