#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;
class Tablero {
	//clase tablero, contiene las funciones de seleccion,y guardado de    niveles,verifica movimientos y matches,cuenta las variables del     juego y las modifica.
public:
	Tablero();//Constructor
	~Tablero();//Destructor
	void cronometro(int limite);//cronometro
	void selectLevel(string nombre_archivo);//Metodo para seleccion de nivel
	void mostrarTablero();//Metodo para imprimir el tablero
	void guardarTablero();//Metodo para guardar partida
	void movimiento();//Metodo encargado de los movimientos del usuario
  void match();//Metodo que verifica match entre gemas
	void victoria();//Metodo que revisa si se cumplen las condiciones de victoria
	void menu();//No se utiliza,menu en el main
  void contador();//Metodo de conteo de gemas
  void desbloqueo();//Metodo para hacer el desbloqueo de las gemas mente
	void ordenarlos(int temporal);//No se utiliza
private:
	int nivel; //Variable que representa el numero del nivel
	int matriz[7][7];//array que representa el tablero de juego
	int tiempoJuego;//Variable en desuso,representaba el timepo de juego
	int gemasMente;//Variable que representa la cantidad de gemas mente
  bool chasquido;//Varaible en desuso representaba si se realizo un chasquido
	int Puntaje;//Variable que representa el Puntaje del jugador
  int jugadas;//variable que representa el numero de movimientos restantes del jugador
};
#endif //_TABLERO_H_
