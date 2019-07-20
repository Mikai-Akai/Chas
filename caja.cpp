#include "caja.h"
//funcion constructor de gemas, crea una de 6 gemas, basado en un random
Caja::Caja(){
	switch (1 + rand() %(7-1)){
		case 1:
			nombre = "espacio";
			gBloqueado = false;
			valor += 0;
			break;
		case 2:
			nombre = "tiempo";
			gBloqueado = false;
			valor += 0;
			break;
		case 3:
			nombre = "realidad";
			gBloqueado = false;
			valor += 0;
			break;
		case 4:
			nombre = "mente";
			gBloqueado = true;
			color = "azul";
			valor += 0;
			break;
		case 5:
			nombre = "alma";
			gBloqueado = false;
			valor += 0;
			break;
		case 6:
			nombre = "poder";
			gBloqueado = false;
			valor += 0;
			break;
		default:
			break;
	}
}
Caja::~Caja(){
	//
}
void Caja::desbloquear(){
	//esta funcion se usa para desbloquear las gemas mente cuando sea necesario
	gBloqueado = false;
}