#include "tablero.h"
Tablero::Tablero(){
	new Caja mente(1);
	new Caja poder(2);
	new Caja alma(3);
	new Caja realidad(4);
	new Caja tiempo(5);
	new Caja espacio(6);
}
Tablero::~Tablero(){
	delete Caja mente(1);
	delete Caja poder(2);
	delete Caja alma(3);
	delete Caja realidad(4);
	delete Caja tiempo(5);
	delete Caja espacio(6);
}
void Tablero::cronometro(int limite){
	// funcion que cuenta cada segundo para ser mostrado en un timer en pantalla
	int mm = 0, ss = 0;
	while (mm < limite) {
		ss++;
		if (ss == 60) {
			ss = 0;
			mm++;
		}
		system("cls");
		cout << mm << ":" << ss << endl;
		Sleep(1000);
	}
	
}
void Tablero::selectLevel(int a) {
	archivo.open("Nivel1.txt", noreplace);
}