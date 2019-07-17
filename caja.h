#ifndef _CAJA_H_
#define _CAJA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
class Caja{
	public:
	Caja();
	~Caja();
	void desbloquear();
	private:
	int numero;
	bool gBloqueado;
	int valor;
	string nombre;
	string color;
};
#endif //_GEMA_H_