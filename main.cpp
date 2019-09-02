#include "tablero.h"
#include <iostream>
using namespace std;
int main() {
	//iniciar la semilla de random en hora del sistema
	srand(time(NULL));
	//generar tablero de juego
	Tablero tab1;
  	cout << "Bienvenido al juego de match3: las Gemas del infinito:" << endl;
	cout << "Tu mision es completar las 6 gemas en linea recta y ayudar a thanos a destruir la mitad de la vida existente, para esto, debes mover las gemas segun sus coordenadas con gemas identicas formando filas y columnas, las gemas mente estan bloqueadas, debes hacer matchs junto a ellas de otras gemas para desbloquearlas..." << endl;
	cout << "completa el guantelete, une las 6 gemas y ayuda a Thanos, tu misión inicia ahora...."<<endl;
	cout << "deseas jugar un nivel predeterminado? o una partida ya existente?" << endl;
	cout << "[1] nivel" << endl;
	cout << "[2] existente" << endl;
	int seleccion = 0;
	string jugado = "";
	cin >> seleccion;
	if(seleccion == 1){
		seleccion = 0;
		cout << "que nivel deseas jugar?" << endl;
		cout << "[1] Nivel1" << endl;
		cin >> seleccion;
		if(seleccion == 1){
			tab1.selectLevel("Nivel1.txt");
		}
		else{
			cout << "aun no hay mas niveles precargados, por default se carga el nivel 1" << endl;
			tab1.selectLevel("Nivel1.txt");
		}
	}
	else if(seleccion == 2){
		cout << "ingrese el nombre de su partida" << endl;
		cin >> jugado;
		tab1.selectLevel(jugado+".txt");
	}
	tab1.mostrarTablero();
	int x = 1;
	while(x == 1){
		cout << "deseas mover? si/no" << endl;
		string aux;
		cin >> aux;
		if(aux == "si"){
			tab1.movimiento();
		}
		else{
			x++;
		}
	}
	tab1.guardarTablero();
	//iniciar timer
	//tab1.cronometro();
	/*ADVERTENCIA-------JUEGO INCOMPLETO*/
	return 0;
}