#include "tablero.h"
Tablero::Tablero(){}
Tablero::~Tablero(){}
void Tablero::mostrarTiempo(){
	// funcion que cuenta cada segundo para ser mostrado en un timer en pantalla
	int hh = 0, mm = 0, ss = 0;
	while(1){
		ss++;
		if(ss == 60){
			mm++;
			if(mm == 60){
				hh++;
			}
		}
		system("cls");
		cout << hh<< ":" << mm << ":" << ss;
		//aqui deberia ir la funcion sleep de (windows.h) pero el compilador no acepta el comando
	}
}