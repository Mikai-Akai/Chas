#include "caja.h"
//funcion constructor de gemas, crea una de 6 gemas, basado en un random
Caja::Caja(){
  numero = 1 + rand() %(7-1);
}
Caja::~Caja(){
	//
}
