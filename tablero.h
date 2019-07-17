#include "caja.h"
#ifndef _TABLERO_H_
#define _TABLERO_H_
class Tablero{
	public:
	Tablero();
	~Tablero();
	void mostrarTiempo();
	void match();
	void ganar();
	void perder();
	void menu();
	private:
	Caja tamaño[7][7];
	int tiempoJuego;
	int GemasMente = 0;
};
#endif //_TABLERO_H_