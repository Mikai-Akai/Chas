#ifndef _CAJA_H_
#define _CAJA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;
using namespace ios;
// clase Caja contiene una gema, la unica interaccion que tiene es debloquearse, sus estados internos son los requeridos en la guia:	1.valor numero entero para identificarla internamente	2.bool gBloqueado indica el estado de bloqueo o desbloqueo de la gema	3.entero valor que almacena el puntaje de cada gema		4. string nombre de la gema		5.string color de la gema
class Caja{
	public:
	Caja(int a);
	~Caja();
	private:
	int numero = 0;
	int valor = 0;
};
#endif //_GEMA_H_