#ifndef _CAJA_H_
#define _CAJA_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;
// clase Caja contiene una gema, la unica interaccion que tiene es debloquearse, sus estados internos son los requeridos en la guia:	1.valor numero entero para identificarla internamente	2.bool gBloqueado indica el estado de bloqueo o desbloqueo de la gema	3.entero valor que almacena el puntaje de cada gema		4. string nombre de la gema		5.string color de la gema
class Caja{
	public:
	Caja();
	~Caja();
	private:
	int numero;
};
#endif //_CAJA_H_