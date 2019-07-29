#include "caja.h"
//funcion constructor de gemas, crea una de 6 gemas, basado en un random
Caja::Caja(int a){
	switch (a) {
	case 1:
		numero = 1;
		valor = 0;
		break;
	case 2:
		numero = 2;
		valor = 0;
		break;
	case 3:
		numero = 3;
		valor = 0;
		break;
	case 4:
		numero = 4;
		valor = 0;
		break;
	case 5:
		numero = 5;
		valor = 0;
		break;
	case 5:
		numero = 5;
		valor = 0;
		break;
	case 6:
		numero = 6;
		valor = 0;
		break;
	}
}
Caja::~Caja(){
	//
}
