#include "tablero.h"
Tablero::Tablero(){
}
Tablero::~Tablero(){
}
/* 
Debido a incompatibilidad con replit la funcion cronometro esta en comentada
void Tablero::cronometro(int limite){
	// funcion que cuenta cada segundo para ser mostrado en un timer en pantalla
	int mm = 0, ss = 0;
	while (mm < limite) {
		ss++;
		if (ss == 60) {
			ss = 0;
			mm++;
			tiempoJuego -= 1
		}
		system("cls");
		cout << mm << ":" << ss << endl;
		Sleep(1000);
	}
	
}
*/
//Esta funcion revisa si se ha hecho un chasquido y retorna un true o false de acuerdo a esto
bool Tablero::ganar() {
	if (tiempoJuego == 0) {
		return false;
	}else 
  if(chasquido){
    return true;}
}
//Esta funcion selecciona el nivel a jugar y extrae lo datos del txt para mostrar el nivel
void Tablero::selectLevel(stfilembre_archivo) {
	ifstream aif ifstreamo(archivo, ios::noreplace);ifsarchivo >> tiempoJuego; ifstream
  archivo >> tiempoJuego;
  archivo >> gemasifstream
  for(int i = 0;i<5;i++){
    archivo >> otrasGemas[i];
  }
	for (int i = 0; i < 7;i++)ma		for ([j]ifstream; i < 7; i++) {
			Mamatriz[i]]] < archivo;
		}
	}
}