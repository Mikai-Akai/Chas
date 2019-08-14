#include "tablero.h"
using namespace std;
Tablero::Tablero(){
	nivel = 0;
	tiempoJuego = 0;
	gemasMente = 0;
	Puntaje.resize(6);
	for(int i=0;i<5;i++){
		Puntaje[i] = 0;
	}
	chasquido = false;
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
bool Tablero::victoria() {
	if(chasquido){return true;}else{return false;}
}
//Esta funcion selecciona el nivel a jugar y extrae lo datos del txt para mostrar el nivel
void Tablero::selectLevel(string nombre_archivo) {
	ifstream archivo(nombre_archivo.c_str());
	int aux = 0;

	archivo >> aux;
	nivel = aux;

	archivo >> aux;
	tiempoJuego = aux;

  	for(int i = 0;i<=5;i++){
    archivo >> Puntaje[i];
  	}
	for(int i=0;i<7;i++){
		for(int j = 0; j<7; j++){
			archivo >> matriz[i][j];
		}
	}
}
void Tablero::mostrarTablero(){
	for(int i=0;i<7;i++){
		for(int j = 0; j<7; j++){
			 cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Tablero::guardarTablero(){
	ofstream Guardando;
	cout << "ingresa el nombre de esta partida" << endl;

	string aux;
	cin >> aux;
	Guardando.open(aux + ".txt");

	Guardando << nivel << endl;
	Guardando << tiempoJuego << endl;

	for(int i = 0;i<=5;i++){
    Guardando << Puntaje[i] << endl;
  	}

	for(int i=0;i<7;i++){
		for(int j = 0; j<7; j++){
			Guardando << matriz[i][j] << " ";
		}
		Guardando << endl;
	}
}
void Tablero::match(){
	int posX1,posY1,posX2,posY2;
	cout << "ingrese la posicion X,Y del primer punto" << endl;
	cin >> posX1;
	cin >> posY1;
	cout << "["<< posX1 <<"]["<< posY1 <<"]" << endl;
	cout << "ingrese la posicion X,Y del segundo punto" << endl;
	cin >> posX2;
	cin >> posY2;
	if(posX1 > 6){posX1 = 6;}
	if(posX1 < 0){posX1 = 0;}
	if(posX2 > 6){posX2 = 6;}
	if(posX2 < 0){posX2 = 0;}
	if(posY1 > 6){posY1 = 6;}
	if(posY1 < 0){posY1 = 0;}
	if(posY2 > 6){posY2 = 6;}
	if(posY2 < 0){posY2 = 0;}
	cout << "["<< posX2 <<"]["<< posY2 <<"]" << endl;
	if(posX1 == posX2 && posY1 == posY2){
		cout << "no puedes realizar este intercambio" << endl;
	}else 
	if((posX1 == posX2 || posY1 == posY2) && ((posX1+1 == posX2 || posX1-1 == posX2) || (posY1+1 == posY2 || posY1-1 == posY2))){
		swap(matriz[posX1][posY1],matriz[posX2][posY2]);
		mostrarTablero();
	}
	else{cout << "no puedes realizar este intercambio" << endl;
	}
	/* incompleto, ya recorre el tablero analizando igualdad entre las gemas de los lados, pero aun no tiene un proceso a realizar
	for(int i = 6;i > 0; i--){
		for(int j = 6; j > 0; j--){
			if(matriz[i][j] == matriz[i-1][j] && matriz[i][j] == matriz[i+1][j]){}
			if(matriz[i][j] == matriz[i][j-1] && matriz[i][j] == matriz[i][j+1]){}

		}
	}
	*/
}