#include "tablero.h"
#include <iostream>
using namespace std;
int main() {
	//iniciar la semilla de random en hora del sistema
	srand(time(NULL));
	//generar tablero de juego
	Tablero tab1;
	tab1.selectLevel("Nivel1.txt");
  for(int i= 0;i<5;i++){
    for(int j=0;j<5;j++){
      cout << matriz[i][j];
    }
  }
	//iniciar timer
	//tab1.cronometro();
	/*ADVERTENCIA-------JUEGO INCOMPLETO*/
	return 0;
}