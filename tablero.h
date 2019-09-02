#include "caja.h"
#ifndef _TABLERO_H_
#define _TABLERO_H_
class Tablero {
	//clase tablero, contiene la funcion de mostrar tiempo		2.funcion match detecta cuando se reunen los requisitos para generar un match, sacar las gemas en cuestion del tablero, y hacer bajar de posicion las gemas de arriba 	3.funcion ganar produce un mensaje y detecta cuando se ha ganado el juego		4.funcion perder muetra un mensaje y detecta cuando se ha acabado el tiempo		5.funcion menu permite reiniciar el juego y contiene las distintas opciones de nivel y tiempo
	// esta clase tiene los valores internos: 1. array de 2 dimensiones de tipo caja, con los valores 7 y 7 de largo y ancho preestablecidos para el tablero, tiempo juego es un entero en el cual se almacena el tiempo jugado y gemas mente, es el contado en el cual se cuenta cuantas gemas mente se han completado
public:
	Tablero();
	~Tablero();
	void cronometro(int limite);
	void selectLevel(string nombre_archivo);
	void mostrarTablero();
	void guardarTablero();
	void movimiento();
  	void match();
	bool victoria();
	void menu();
  	void contador();
  	void desbloqueo();
	void ordenarlos(int temporal);
private:
	int nivel;
	int matriz[7][7];
	int tiempoJuego;
	int gemasMente;
  	bool chasquido;
	int Puntaje;
};
#endif //_TABLERO_H_
